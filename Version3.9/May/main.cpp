#include "mainwindow.h"
#include <QAction>
#include <QApplication>
#include <QFile>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QStatusBar>
#include <QTextEdit>
#include <QWidget>
#include <cstdlib>
#include <ctime>
#include <QLineEdit>
#include <QLabel>
#include <QStyleFactory>
#include <QCommandLinkButton>
#include <QThread>
#include <QRadioButton>
#include <QStatusBar>
#include <QMessageBox>
#include <QKeySequence>
#include <QImage>
#include <QSettings>
#include <QPainter>
#include <QVBoxLayout>

class Master : public MainWindow{//Class for check Master-password
public:
    Master(QWidget *parent = 0);
};

Master::Master(QWidget *parent) : MainWindow(parent)
{

    QLabel *masterWindowTmp = new QLabel;
    masterWindowTmp->setFixedSize(700, 470);
    masterWindowTmp->setWindowOpacity(0.87);
    masterWindowTmp->show();

    QStatusBar *textDataPass = new QStatusBar(masterWindowTmp);
    textDataPass->showMessage("Enter master-key. Default key =  'admin'");
    textDataPass->setGeometry(40, 90, 350, 40);
    textDataPass->show();

    QLineEdit *lineCheckPassword = new QLineEdit(masterWindowTmp);
    lineCheckPassword->setGeometry(40, 120, 300, 40);
    lineCheckPassword->setEchoMode(QLineEdit::Password);
    lineCheckPassword->show();

    QPushButton *checkMasterPass = new QPushButton(masterWindowTmp);
    checkMasterPass->setText("Enter");
    checkMasterPass->setGeometry(250, 250, 150, 50);
    connect(checkMasterPass, &QPushButton::clicked, this, [=](){
        check_password_in_master_label(*masterWindowTmp ,*lineCheckPassword); //belong passwords with password that save in program
    });
    checkMasterPass->show();

}

void MainWindow::check_password_in_master_label(QLabel &deleteLabelCheck, QLineEdit &password){
    QSettings settings( "settings.ini", QSettings::IniFormat );
    settings.beginGroup( "settings" );

  QString datacomp = settings.value("masterKey", "admin").toString();
    settings.endGroup();



    if(password.text().toUtf8() == datacomp){

    deleteLabelCheck.hide();
    MainWindow *mainWinApp = new MainWindow;
    mainWinApp->setWindowTitle("My Passwords");
    mainWinApp->setFixedSize(1000, 600);
    mainWinApp->setWindowOpacity(0.97);

    QSettings settings( "settings.ini", QSettings::IniFormat );
    settings.beginGroup( "settings" );// set theme in app
   bool setThemeBo= settings.value("theme", false).toBool(); //Default value
   if(setThemeBo == true){

       mainWinApp->on_actionDark_Material_triggered();
   }

    settings.endGroup();

    QStatusBar *text = new QStatusBar(mainWinApp);
    text->setGeometry(400, 40, 200, 40);
    text->showMessage("Download app in android: ");
    text->show();

    QCommandLinkButton *generatePassBth= new QCommandLinkButton(mainWinApp);
    generatePassBth->setText("Generate passwords");
    generatePassBth->setStyleSheet("font: 12pt  MS Shell Dlg 2");
    generatePassBth->setGeometry(40, 50, 300, 50);
    generatePassBth->show();

    QCommandLinkButton *viewUserPassBth = new QCommandLinkButton( mainWinApp);
    viewUserPassBth->setText("View passwords");
    viewUserPassBth->setStyleSheet("font: 12pt  MS Shell Dlg 2");
    viewUserPassBth->setGeometry(40, 150, 300, 50);
    viewUserPassBth->show();

    connect(generatePassBth, &QPushButton::clicked, this, &MainWindow::generate_passwords_clicked);
    connect(viewUserPassBth, &QPushButton::clicked, this, &MainWindow::read_pass_in_file_clicked);

    mainWinApp->show();

    }

   else{
        QMessageBox *errorIfPassDontFitMbox = new QMessageBox();
        errorIfPassDontFitMbox->setWindowTitle("My passwords");
        errorIfPassDontFitMbox->setGeometry(250, 200, 1000, 140);
        errorIfPassDontFitMbox->setText(
            "Password dont fit.");
        errorIfPassDontFitMbox->show();
    }
}


int main(int argc, char *argv[]) {

    QCoreApplication::setOrganizationName("JunSun");
     QCoreApplication::setOrganizationDomain("jprogram@bk.ru");
     QCoreApplication::setApplicationName("My passwords");
  QApplication a(argc, argv);
   QApplication::applicationVersion() = "3.9";


  Master pumpkin; 
  pumpkin.setFixedSize(1000, 500);
  pumpkin.setWindowTitle("My passwords");
  pumpkin.setWindowIcon(QIcon("u_tS5YiamdE.jpg"));


  return a.exec();
}
