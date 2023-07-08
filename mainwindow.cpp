#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    bd = QSqlDatabase::addDatabase("QSQLITE");
    bd.setDatabaseName("/Users/aleks/Qt/Project/autorizaciya/data.db");
    if(bd.open())
        qDebug("open");
    else
        qDebug("no open");

    query = new QSqlQuery(bd);
    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();



    query->prepare("SELECT * FROM data WHERE login = :login");
    query->bindValue(":login", login);

    if (!query->exec()) {
        qDebug() << "Ошибка выполнения запроса";
        return;
    }

    if (query->next()) {
        QString storedPassword = query->value("password").toString();
        if (password == storedPassword) {
            QMessageBox msbx;
            msbx.setText("Успешная авторизация!");
            msbx.exec();
        } else {
            QMessageBox msbx;
            msbx.setText("Неверный пароль");
            msbx.exec();
        }
    } else {
        QMessageBox msbx;
        msbx.setText("Логин не найден");
        msbx.exec();
    }
    bd.close();

}



void MainWindow::on_pushButton_2_clicked()
{
    window = new SecondWindow(this);
    window ->show();
}

