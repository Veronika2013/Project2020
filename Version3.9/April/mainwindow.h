#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QTextStream>
#include <QAction>
#include <QTextEdit>
#include <QFile>
#include <QPushButton>
#include <QLabel>
#include <QThread>
#include <QUrl>
#include <QSystemTrayIcon>
#include <QTranslator>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent =0);
    ~MainWindow();

Ui::MainWindow *ui;


private slots:

void on_actionNew_Password_triggered();

void on_actionDelete_all_Passwords_triggered();

void on_actionDark_Material_triggered();

void on_actionLight_triggered();

void on_actionDelete_some_Passwords_triggered();

void on_actionMaster_key_triggered();

void on_toolButton_clicked();

void on_commandLinkButton_clicked();

void about_encryption();

void save_all_master_key(const QString &newpass);

void generate_passwords_clicked();

void change_master_key_bth(QLabel &lbl);

void read_pass_in_file_clicked();

void save(const QString &s);

void remove_some_passwords_bth(QTextEdit &deleteThisText);

void info_about_bak();

void backup_data_real();

public slots:

void check_password_in_master_label(QLabel &deleteLabelCheck, QLineEdit &password);

};
class GUIThread : public QThread{
public:
 //Override method run()
    void run(){

        void generate_passwords_clicked();

        void read_pass_in_file_clicked();
        void save(const QString &s);
         void check_password_in_master_label(QLabel &deleteLabelCheck, QLineEdit &password);
        void remove_some_passwords_bth(QLineEdit &deleteThisText);

    };
};

#endif // MAINWINDOW_H

