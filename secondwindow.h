#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>



namespace Ui {
class SecondWindow;
}

class SecondWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SecondWindow *ui;

};

#endif // SECONDWINDOW_H
