#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QItemSelection>
#include <QTranslator>
#include <QLocale>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// объявление типа модели SQL-запросов
class QSqlQueryModel;

class QActionGroup;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // действие пункта подключения к БД
    void on_actionConnect_triggered();

    // действие сбора значений из строки таблицы
    // Проекты в lineEdit/spinBox
    void fillingInGroupBoxprojectsFields();

    // удаление строки из таблицы Проекты
    void on_pushButtonDeleteprojects_clicked();

    // добавление новой строки в таблицу
    // Проекты и перенос в нее данных
    // из lineEdit/spinBox
    void on_pushButtonAddprojects_clicked();

    // внесение изменений в строки таблицы
    // Проекты путем переноса значений из
    // lineEdit/spinBox
    void on_pushButtonUpdateprojects_clicked();

    // вызов окна с информацией об авторе
    void on_actionAbout_author_triggered();


    void on_actionEnglish_triggered();

    void on_action_triggered();

private:
    Ui::MainWindow *ui;

    // объект по работе с БД
    QSqlDatabase db;

    // указатели, отвечающие за работу с SQL-моделью
    QSqlQueryModel *queryModelprojects;
    QSqlQueryModel *queryModelDataBase;

    // переменные, хранящие номер строки, выделенной
    // пользователем в таблицах
    int selectedRowprojects;

    QTranslator appTranslator;
    QTranslator* translator;
    QString qmPath;

    void changeEvent (QEvent *event);
    // функция переключение языков
    void changeTranslator(QString postfix);


};
#endif // MAINWINDOW_H
