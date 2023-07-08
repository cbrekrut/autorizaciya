#include "secondwindow.h"
#include "ui_secondwindow.h"



SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();
    QString login = ui->lineEdit_2->text();
    QString email = ui->lineEdit_3->text();
    QString password = ui->lineEdit_4->text();

    // Установить соединение с базой данных SQLite
    QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("/Users/aleks/Qt/Project/autorizaciya/data.db");

    if (!database.open()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось установить соединение с базой данных");
        return;
    }
    QSqlQuery query;
    // Вставить данные в таблицу
    query.prepare("INSERT INTO data (login, password, email, name) VALUES (?, ?, ?, ?)");
    query.addBindValue(login);
    query.addBindValue(password);
    query.addBindValue(email);
    query.addBindValue(name);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось выполнить запрос в базу данных");
        return;
    }
    else{
        QMessageBox::information(this, "Успешно", "Успешная авторизация!");
        return;
    }

    // Закрыть соединение с базой данных
    database.close();


}

