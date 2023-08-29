#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>
#include <QFileDialog>
#include <QLibraryInfo>
#include <QEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , db(QSqlDatabase::addDatabase("QPSQL"))

    // выделение памяти
    , queryModelprojects(new QSqlQueryModel(this))
    , queryModelDataBase(new QSqlQueryModel(this))

{
    ui->setupUi(this);

    qApp->installTranslator(&appTranslator);

    ui->tableViewprojects->setModel(queryModelprojects);

    // вызов окна с информацией о Qt
    connect(ui->actionAbout_Qt, &QAction::triggered, qApp, &QApplication::aboutQt);

// проверка наличия драйвера PSQL
#ifdef QT_DEBUG
    if (QSqlDatabase::isDriverAvailable("QPSQL"))
        qDebug() << "SUCCESS: PostgreSQL Database driver found.";
    else
        qDebug() << "FAILURE: No PostgreSQL Database driver available.";
#endif

    // Привязка нажатия указателя мыши по строке таблицы,
    // для сброса данных из неё в поля формы редактирования информации
    // о проектах
    connect(ui->tableViewprojects, &QTableView::clicked,
        this, &MainWindow::fillingInGroupBoxprojectsFields);

}

MainWindow::~MainWindow()
{
    delete queryModelprojects;
    delete queryModelDataBase;
    delete ui;
}

// подключение к БД и загрузка данных в tableView
void MainWindow::on_actionConnect_triggered()
{
    // задаем параметры для подключения к серверу с БД
    db.setDatabaseName("proects_db");
    db.setUserName("postgres");
    db.setPassword("12345678");

    bool opened = db.open();
    if(!opened)
        QMessageBox::critical(this, tr("App Name"), db.lastError().text());

    //Вывод таблицы с объектами
    queryModelprojects->setQuery(" SELECT * FROM projects", db);
    if (queryModelprojects->lastError().type() == QSqlError::NoError) {
        ui->tableViewprojects->setModel(queryModelprojects);
        ui->tableViewprojects->resizeColumnsToContents();
    }
    else
        QMessageBox::critical(this,
                              tr("Erorr select!"),
                              queryModelprojects->lastError().text());
}

// действие сбора значений из строки таблицы
// Проекты в lineEdit/spinBox при нажатии мыши
// по строке
void MainWindow::fillingInGroupBoxprojectsFields()
{
    QSqlQuery queryGetRowprojects(db);

    // Определяем выбранную пользователем строку в таблице
    int currentRowprojects = ui->tableViewprojects->currentIndex().row();
    selectedRowprojects = currentRowprojects;

    // Определение id записи этой строки
    int id = queryModelprojects->record(currentRowprojects).value("id").toInt();

    queryGetRowprojects.prepare(" SELECT * FROM projects"
                            " WHERE id = :id");
    queryGetRowprojects.bindValue(":id", id);
    qDebug() << queryGetRowprojects.lastQuery();
    queryGetRowprojects.exec();
    if (queryGetRowprojects.lastError().type() != QSqlError::NoError) {
        QMessageBox::critical(this,
                              tr("Erorr select!"),
                              queryGetRowprojects.lastError().text());
        return;
    }

    while (queryGetRowprojects.next()) {
        // Заполняем поля редактирования информации
        ui->lineEditName->setText(queryGetRowprojects.value(1).toString());
        ui->lineEditaddress->setText(queryGetRowprojects.value(2).toString());
        ui->lineEditphonenumber->setText(queryGetRowprojects.value(3).toString());
        ui->spinBoxmoney->setValue(queryGetRowprojects.value(4).toInt());
        ui->lineEditmanager->setText(queryGetRowprojects.value(5).toString());
        ui->spinBoxtype->setValue(queryGetRowprojects.value(6).toInt());
        ui->lineEditingener->setText(queryGetRowprojects.value(7).toString());
    }
}

// Метод для удаления строки из таблицы Проекты
void MainWindow::on_pushButtonDeleteprojects_clicked()
{
    QSqlQuery queryDeleteRowprojects(db);

    // Определение выбранной пользователем строки в таблице
    int currentRowprojects = ui->tableViewprojects->currentIndex().row();

    // Определение id записи этой строки
    int id = queryModelprojects->record(currentRowprojects).value("id").toInt();

    queryDeleteRowprojects.prepare(" DELETE FROM projects"
                               " WHERE id = :id");
    queryDeleteRowprojects.bindValue(":id", id);
    qDebug() << queryDeleteRowprojects.lastQuery();
    queryDeleteRowprojects.exec();

    // После удаления записи о проекте, обновим таблицу
    queryModelprojects->setQuery("SELECT * FROM projects", db);
}

// добавление новой строки в таблицу проекты и перенос в нее данных
// из lineEdit/spinBox
void MainWindow::on_pushButtonAddprojects_clicked()
{
    // Вставка записи о проекте в таблицу
    QSqlQuery queryInserRowprojects(db);
    queryInserRowprojects.prepare("INSERT INTO projects VALUES"
                              " (DEFAULT,"
                              " :name,"
                              " :address,"
                              " :phonenumber,"
                              " :money,"
                              " :manager,"
                              " :type,"
                              " :ingener)");
    queryInserRowprojects.bindValue(":name", ui->lineEditName->text());
    queryInserRowprojects.bindValue(":address", ui->lineEditaddress->text());
    queryInserRowprojects.bindValue(":phonenumber", ui->lineEditphonenumber->text());
    queryInserRowprojects.bindValue(":money", ui->spinBoxmoney->text());
    queryInserRowprojects.bindValue(":manager", ui->lineEditmanager->text());
    queryInserRowprojects.bindValue(":type", ui->spinBoxtype->text());
    queryInserRowprojects.bindValue(":ingener", ui->lineEditingener->text());
    qDebug() << queryInserRowprojects.lastQuery();
    queryInserRowprojects.exec();

    if (queryInserRowprojects.lastError().type() != QSqlError::NoError) {
        QMessageBox::critical(this,
                              tr("Erorr select!"),
                              queryInserRowprojects.lastError().text());
        qDebug() << queryInserRowprojects.lastError().text();
        return;
    }

    // После добавления записи о проекте, обновим таблицы
    queryModelprojects->setQuery("SELECT * FROM projects", db);
}

// внесение изменений в строки таблицы проекты путем переноса значений из
// lineEdit/spinBox
void MainWindow::on_pushButtonUpdateprojects_clicked()
{
    // Определение выбранной пользователем строки в таблице
    int currentRowprojects = selectedRowprojects;

    // Определение id записи этой строки
    int id = queryModelprojects->record(currentRowprojects).value("id").toInt();

    QSqlQuery queryUpdateRowprojects(db);
    queryUpdateRowprojects.prepare("UPDATE projects SET"
                               " name = :name,"
                               " address = :address,"
                               " phonenumber = :phonenumber,"
                               " money = :money,"
                               " manager = :manager,"
                               " type = :type,"
                               " ingener = :ingener"
                               " WHERE id = :id");
    queryUpdateRowprojects.bindValue(":name", ui->lineEditName->text());
    queryUpdateRowprojects.bindValue(":address", ui->lineEditaddress->text());
    queryUpdateRowprojects.bindValue(":phonenumber", ui->lineEditphonenumber->text());
    queryUpdateRowprojects.bindValue(":manager", ui->spinBoxmoney->text());
    queryUpdateRowprojects.bindValue(":manager", ui->lineEditmanager->text());
    queryUpdateRowprojects.bindValue(":type", ui->spinBoxtype->text());;
    queryUpdateRowprojects.bindValue(":ingener", ui->lineEditingener->text());
    queryUpdateRowprojects.bindValue(":id", id);
    qDebug() << queryUpdateRowprojects.lastQuery();
    queryUpdateRowprojects.exec();

    if (queryUpdateRowprojects.lastError().type() != QSqlError::NoError) {
        QMessageBox::critical(this,
                              tr("Erorr select!"),
                              queryUpdateRowprojects.lastError().text());
        qDebug() << queryUpdateRowprojects.lastError().text();
        return;
    }

    // Необходимо обновить данные таблиц
    queryModelprojects->setQuery("SELECT * FROM projects", db);

    // Чтобы выделение строки в таблице не сбрасывалось, после изменения фокуса
    // с таблицы на какое либо поле ввода
    ui->tableViewprojects->setCurrentIndex(ui->tableViewprojects->model()->index(selectedRowprojects, 0));
}

// Вызов пункта меню с информацией об авторе
void MainWindow::on_actionAbout_author_triggered()
{
    QMessageBox::about(this, tr("About author"),
                       tr("Variant Project Firm database, ICTMS-3-5\n"
                          "Orlov Fedor Dmitrievich"));
}

// функция переключение языков
void MainWindow::changeTranslator (QString postfix)
{
    QApplication::removeTranslator(translator);
    translator = new QTranslator(this);
    translator ->load(QApplication::applicationName() + "_" + postfix);
    QApplication::installTranslator(translator);
}

void MainWindow::changeEvent(QEvent *event)
{
   if (event->type() == QEvent::LanguageChange){
        setWindowTitle(tr("My Application"));
        ui->menuLanguage->setTitle(tr("Language"));
        ui->actionEnglish->setText(tr("English"));
        ui->action->setText(tr("Russian")) ;
              }
              else   {
           QMainWindow::changeEvent(event);
         }
  }


void MainWindow::on_actionEnglish_triggered()
{
   changeTranslator("tr\en.ts");
}

void MainWindow::on_action_triggered()
{
    changeTranslator("tr\ru.ts");
}
