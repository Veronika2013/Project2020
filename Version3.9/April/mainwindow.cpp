#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStatusBar>
#include <QLabel>
#include <QMessageBox>
#include <QListView>
#include <QLineEdit>
#include <QLine>
#include <QSettings>
#include <QComboBox>
#include <QTextBrowser>
#include <QImage>
#include <QTranslator>
#include <QLibraryInfo>
#include <QStyleFactory>
#include "cryptograph.h"
#include <QDesktopServices>
#include <QTranslator>
#include <QUrl>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::generate_passwords_clicked()
{

  QLabel *lblReflectingGeneratePass = new QLabel;
  lblReflectingGeneratePass->setFixedSize(700, 470);
  lblReflectingGeneratePass->setWindowTitle("My passwords");
  lblReflectingGeneratePass->setWindowOpacity(0.87);
  lblReflectingGeneratePass->setTextInteractionFlags(Qt::TextSelectableByMouse);

  srand(time(NULL));

  int *a = new int;
  *a = rand();
  QString *s = new  QString;
  *s = QString::number(*a);// Translate in QString

  int *b = new int;
  *b = rand();
  QString *c =new QString;
  *c = QString::number(*b);//Passwords

  char *mass = new char[10];

  for(int i = 0; i <10; i++) {
      mass[i] = rand()   %26+0x61;
  }

  QString *numPass = new QString;// 1th password
  *numPass = mass[1]+ *s + mass[2] + *s + mass[3] + mass[4] + mass[5];
  QString *numpass2 = new QString;//2th password
 *numpass2 = mass[3]+ *c + mass[4] + *c + mass[5] + mass[6] + mass[7];
  QString *numpass3 = new QString;//3th password
 *numpass3 = mass[5]+ *c + mass[6] + *s + mass[7] + mass[8] + mass[9];
  QString *numpass4 = new QString;//4th password
  *numpass4 = mass[7]+ *s + mass[2] + *c + mass[0] + mass[4] + mass[1];
  QString *numpass5 = new QString;//5th passwords
  *numpass5 = mass[9]+ *c +  *s +mass[9] + mass[6] + mass[0] + mass[8];
  QString *numpass6 = new QString;//6th password
  *numpass6 = mass[7]+ *c + mass[6]  + mass[5] + mass[4]  + *s + mass[3];

  lblReflectingGeneratePass->setText(*numPass + "\n" +numpass2 + "\n" + numpass3 + "\n" + numpass4 + "\n" + numpass5 + "\n" + numpass6 );
  lblReflectingGeneratePass->show();

  delete a;
  delete b;
  delete s;
  delete c;
  delete[] mass;
  delete  numPass;
  delete numpass2;
  delete numpass3;
  delete numpass4;
  delete  numpass5;
  delete numpass6;
}

void MainWindow::save(const QString &s) { //Slot for saving passwords(button slot)


  QFile *fileWithPass = new QFile("lib_ptr.dll");//real file
  QFile *bakFileWithPass = new QFile("libgcc7_snt.dll");

  fileWithPass->open(QFile::WriteOnly|QIODevice::Text| QFile::Append);
  bakFileWithPass->open(QFile::WriteOnly| QIODevice::Text| QFile::Append);

  if (fileWithPass->isOpen() && bakFileWithPass->isOpen()) {
  (QIODevice::WriteOnly  | QIODevice::Append);
  bakFileWithPass->write(s.toUtf8() + "\n");
  fileWithPass->write(s.toUtf8() + "\n");

  bakFileWithPass->close();
  fileWithPass->close();

  } else {
  QMessageBox::critical(this,("Error"),("File not found"));
  }

  delete bakFileWithPass;
  delete fileWithPass;

}

void MainWindow::read_pass_in_file_clicked() {//Function shoved passwords of file

  QFile *fileWithPass = new QFile("lib_ptr.dll");
  fileWithPass->open(QFile::ReadOnly);

  if(fileWithPass->isOpen()) {

  QString data = fileWithPass->readAll();

  QLabel *lyrics = new QLabel(data);
  lyrics->setWindowOpacity(0.87);
  lyrics->setText("" + data + "\n    ");
  lyrics->setFixedSize(700, 470);
  lyrics->setWindowTitle("My passwords");
  lyrics->setTextInteractionFlags(Qt::TextSelectableByMouse);
  lyrics->show();

  fileWithPass->close();

 } else {
  QMessageBox::critical(this,("Error"),("Passwords not found"));
    }

    delete fileWithPass;

  }

void MainWindow::on_actionNew_Password_triggered()
{

  QLabel *lblInputPassInFile = new QLabel;
  lblInputPassInFile->setWindowOpacity(0.87);
  lblInputPassInFile->setFixedSize(700, 470);
  lblInputPassInFile->setText( "                Input passwords and account name in english. ");
  lblInputPassInFile->setWindowTitle("My Passwords");
  lblInputPassInFile->show();

  QStatusBar *lyricsInputPass = new QStatusBar(lblInputPassInFile);
  QStatusBar *lyricsInputAccount = new QStatusBar(lblInputPassInFile);

  lyricsInputPass->setGeometry(120, 12, 200, 40);
  lyricsInputAccount->setGeometry(120, 70, 200, 40);

  lyricsInputPass->showMessage("Password: ");
  lyricsInputAccount->showMessage("Account: ");

  lyricsInputPass->show();
  lyricsInputAccount->show();

  QTextEdit *txtetInputPass = new QTextEdit(lblInputPassInFile);//Input passwords in file
  QTextEdit *txtetInputKey = new QTextEdit(lblInputPassInFile);

  txtetInputPass->setGeometry(120, 40, 200, 40);
  txtetInputKey->setGeometry(120, 100, 200, 40);

  txtetInputPass->show();
  txtetInputKey->show();

  QPushButton *savepass = new QPushButton(lblInputPassInFile);
  savepass->setText("Save");
  savepass->setGeometry(250, 250, 150, 50);

  connect(savepass, &QPushButton::clicked, this, [=](){
        save (txtetInputPass->toPlainText ().toUtf8() + "   " +
              txtetInputKey->toPlainText ().toUtf8 () +"     "
              ); });

  savepass->show();
  }
void MainWindow::on_actionDelete_all_Passwords_triggered()
{

  QFile *fileWithPass = new QFile("lib_ptr.dll");
  fileWithPass->remove();//Delete file containing passwords
  QMessageBox *delitefileSuccesful = new QMessageBox(this);

  if (!fileWithPass->exists()) {

  delitefileSuccesful->setWindowTitle("My passwords");
  delitefileSuccesful->setGeometry(800, 500, 100, 40);
  delitefileSuccesful->setText("Passwords delete succesful.");
  delitefileSuccesful->show();

   }  else if (!fileWithPass->remove() || fileWithPass->exists()) {
        QMessageBox::critical(this, ("Error"), ("Failed to remove passwords"));

    }

    delete fileWithPass;
}

void MainWindow::on_actionDark_Material_triggered()

{
  QSettings settings("settings.ini",QSettings::IniFormat);

  QPalette *darkPalette = new QPalette;
  darkPalette->setColor(QPalette::Window, QColor(53, 53, 53));
  darkPalette->setColor(QPalette::WindowText, Qt::blue);
  darkPalette->setColor(QPalette::Base, QColor(25, 25, 25));
  darkPalette->setColor(QPalette::AlternateBase, QColor(53, 53, 53));
  darkPalette->setColor(QPalette::ToolTipBase, Qt::white);
  darkPalette->setColor(QPalette::ToolTipText, Qt::white);
  darkPalette->setColor(QPalette::Text, Qt::white);
  darkPalette->setColor(QPalette::Button, QColor(153, 255, 204));
  darkPalette->setColor(QPalette::ButtonText, Qt::black);
  darkPalette->setColor(QPalette::BrightText, Qt::red);
  darkPalette->setColor(QPalette::Link, QColor(30, 230, 0));
  darkPalette->setColor(QPalette::Highlight, QColor(30, 230, 0));
  darkPalette->setColor(QPalette::HighlightedText, Qt::black);

  qApp->setPalette(*darkPalette);

  settings.setValue("settings/theme", true);
  settings.endGroup();

  delete darkPalette;

}

void MainWindow::on_actionLight_triggered()
{

  qApp->setPalette(style()->standardPalette());

  QSettings *settings = new QSettings("settings.ini",QSettings::IniFormat);
  settings->setValue("settings/theme", false);
  settings->endGroup();

  delete settings;

}

void MainWindow::on_actionDelete_some_Passwords_triggered()
{

  QLabel *lblInputSomePassInFile = new QLabel;
  lblInputSomePassInFile->setWindowOpacity(0.87);
  lblInputSomePassInFile->setFixedSize(700, 470);
  lblInputSomePassInFile->setWindowTitle("My Passwords");
  lblInputSomePassInFile->show();

  QStatusBar *textManual = new QStatusBar(lblInputSomePassInFile);
  textManual->setGeometry(40, 40, 250, 40);
  textManual->showMessage("Edit passwords in  this window: ");
  textManual->show();

  QFile *filePass = new QFile("lib_ptr.dll");
  filePass->open(QFile::ReadOnly);
  QString listWordsInFile = filePass->readAll();

  QTextEdit *inputPassKey = new QTextEdit(lblInputSomePassInFile);
  inputPassKey->setGeometry(40, 120, 390, 290);
  inputPassKey->setText(listWordsInFile);
  inputPassKey->show();

  QPushButton *savepass = new QPushButton(lblInputSomePassInFile);
  savepass->setText("Save edit");
  savepass->setGeometry(450, 400, 150, 50);
  connect(savepass, &QPushButton::clicked, this, [=](){remove_some_passwords_bth(*inputPassKey);});
  savepass->show();
  filePass->close();

  delete filePass;

}
void MainWindow::remove_some_passwords_bth(QTextEdit &deleteThisText){

  QFile *filePass = new QFile("lib_ptr.dll");
  filePass->open(QFile::WriteOnly);

  if(filePass->isOpen()){

  filePass->write(deleteThisText.toPlainText().toUtf8());
  filePass->close();

    } else{
        QMessageBox::critical(this,("Error"),("Failed to save edit passwords"));
    }

  delete filePass;

}

void MainWindow::on_actionMaster_key_triggered()
{

  QLabel *lblSettings = new QLabel;
  lblSettings->setWindowOpacity(0.87);
  lblSettings->setFixedSize(700, 470);
  lblSettings->setWindowTitle("My passwords");
  lblSettings->setTextInteractionFlags(Qt::TextSelectableByMouse);

  QPushButton *changePass = new QPushButton(lblSettings);
  changePass->setGeometry(40, 120, 170, 40);
  changePass->setText("Change master-key");
  connect(changePass, &QPushButton::clicked, this,[=](){change_master_key_bth(*lblSettings);});
  lblSettings->show();

  QPushButton *changeLang = new QPushButton(lblSettings);
  changeLang->setGeometry(40, 180, 170, 40);
  changeLang->setText("Language: english");
  changeLang->show();

  QPushButton *forEncryption = new QPushButton(lblSettings);
  forEncryption->setGeometry(40, 70, 170, 40);
  forEncryption->setText("About encryption");
  connect(forEncryption, &QPushButton::clicked, this, &MainWindow::about_encryption);
  forEncryption->show();


}

void MainWindow::change_master_key_bth(QLabel &lbl){

  QStatusBar *oldPass = new QStatusBar(&lbl);
  oldPass->showMessage("Input new master-key:");
  oldPass->setGeometry(220, 110, 170, 40);
  oldPass->show();

  QLineEdit *inputPassKey = new QLineEdit(&lbl);
  inputPassKey->setGeometry(220, 150, 170, 40);
  inputPassKey->show();

  QPushButton *changePass = new QPushButton(&lbl);
  changePass->setGeometry(400, 344, 170, 40);
  changePass->setText("Save all");
  connect(changePass, &QPushButton::clicked, this,[=](){save_all_master_key(inputPassKey->text().toUtf8());});
  changePass->show();


}


void MainWindow::save_all_master_key(const QString &newpass){

  QSettings *settings = new QSettings("settings.ini",QSettings::IniFormat);
  settings->setValue("settings/masterKey",newpass.toLatin1() );
  settings->endGroup();

  delete settings;

}



void MainWindow::about_encryption(){

  QLabel *aboutWind = new QLabel;
  aboutWind->setWindowOpacity(0.87);
  aboutWind->setFixedSize(700, 470);
  aboutWind->setWindowTitle("My passwords");
  aboutWind->setText("              RC5 is a symmetric key block " "\n"
  "              encryption algorithm designed by Ron" "\n"
  "              Rivest in 1994. It is notable for being simple,""\n"
  "              fast (on account of using only primitive ""\n"
  "              computer operations like XOR, shift, etc.) and consumes less memory.");
  aboutWind->show();

}

void MainWindow::on_toolButton_clicked()//Support button
{

  QDesktopServices::openUrl(QUrl("http://google.com"));//Insert site support


}
void MainWindow::info_about_bak()
{

 QFile *dirBakFile = new QFile("libgcc7_snt.dll");;
 dirBakFile->open(QFile::ReadOnly);
 if(dirBakFile->isOpen() && dirBakFile->size() != 0){

  QMessageBox::information(this, ("My passwords"), ("Backup-file exist and not empty"));

  } else {

  QMessageBox::critical(this, ("Error"), ("File not found or file empty"));

  }

  dirBakFile->close();
  delete dirBakFile;

}
void MainWindow::backup_data_real()
{
//this slot get file in 2 memory and set in directory with program
  QFile *bakFile = new QFile("libgcc7_snt.dll");
  bakFile->copy("libgcc7_snt.dll");
  bakFile->setFileName("lib_ptr.dll");
  bakFile->open(QFile::ReadOnly);

  if(bakFile->isOpen()){

  QMessageBox::information(this, ("My passwords"), ("File recovered sucessful"));

  } else {

  QMessageBox::critical(this, ("Error"), ("File not found or file was broken"));

    }
  bakFile->close();
  delete bakFile;

}
void MainWindow::on_commandLinkButton_clicked()
{

  QLabel *lblBackup = new QLabel;
  lblBackup->setWindowOpacity(0.87);
  lblBackup->setFixedSize(700, 470);
  lblBackup->setWindowTitle("My passwords");
  lblBackup->setTextInteractionFlags(Qt::TextSelectableByMouse);

  QPushButton *bthReturnRemoved = new QPushButton(lblBackup);
  bthReturnRemoved->setGeometry(40, 120, 270, 40);
  bthReturnRemoved->setText("Return removed passwords");
  connect(bthReturnRemoved, &QPushButton::clicked, this,&MainWindow::backup_data_real);

  QPushButton *bthInfoBackup = new QPushButton(lblBackup);
  bthInfoBackup->setGeometry(40, 240, 270, 40);
  bthInfoBackup->setText("Information");
  connect(bthInfoBackup, &QPushButton::clicked, this, &MainWindow::info_about_bak);

  lblBackup->show();


}
