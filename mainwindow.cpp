#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfile.h"
#include "qtextstream.h"
#include "qdir.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void p5() {
    /*get Data*/
    //jupyter tables

    //15 days per confidant

    //make schedule

    //chariot rank 7 late?

    //chariot rank 7: 5/20, 5/27, 6/29, 7/1, 8/3, 8/12, 10/7, 11/2, 11/4, 11/9, 11 / 11, 11/30, 12/2, 12/7, 12/9
}

void MainWindow::p4g() {
    printf("p4g");

    //1. Get calendar data
    QString calendar_file_name = "input/p4gcalendar";
    QFile file;
    file.setFileName(calendar_file_name +".txt");//file_name is the QString, which I get as aparameter
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream calendar(&file);
    QString startdate;
    QString enddate;
    QString rainydays;
    QString eventdays;
    QString exams;
    //std::string s4 ("A character sequence");
    for (int i = 0; i < 5; ++i) {
        switch (i) {
            case 0: startdate =calendar.readLine();
                break;
            case 1: enddate =calendar.readLine();
                break;
            case 2: rainydays =calendar.readLine();
                break;
            case 3: eventdays =calendar.readLine();
                break;
            case 4: exams =calendar.readLine();
                break;
        }

    }
    printf("startdate:");
    qDebug("%s", qUtf8Printable(startdate));
    printf("enddate:");
    qDebug("%s", qUtf8Printable(enddate));
    printf("rainydays");
    qDebug("%s", qUtf8Printable(rainydays));

    QTextStream(stdout) << calendar_file_name; //To see the name of the file, which has just been typed
    file.close();

    //2. Get Social Link data
    QDir directory("input");
    QStringList sociallinks = directory.entryList(QStringList() << "*.txt" << "*.txt",QDir::Files);
    foreach(QString filename, sociallinks) {
    //do whatever you need to do
        if(filename != "p4gcalendar.txt") {
            file.setFileName(filename +".txt");//file_name is the QString, which I get as aparameter
            file.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream sociallinkstream(&file);

            QString slname;
            for (int i = 0; i < 3; ++i) {
                switch (i) {
                    case 0: slname =sociallinkstream.readLine();
                        break;
                    case 1: slname =sociallinkstream.readLine();
                        break;
                    case 2: slname =sociallinkstream.readLine();
                        break;
                    case 3: slname =sociallinkstream.readLine();
                        break;
                    case 4: slname =sociallinkstream.readLine();
                        break;
                }
            }

            file.close();
        }
    }



    QString file_name = "p4gSL";
    file.setFileName(file_name +".txt");//file_name is the QString, which I get as aparameter
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QTextStream stream(&file);
    stream<<"Create Document";
    QTextStream(stdout) << file_name; //To see the name of the file, which has just been typed
    file.close();
}

void MainWindow::p3fes() {
    //1. Create Social Link Data

    //2. Day to Day

    //3. Output
}

void MainWindow::on_generateButton_clicked()
{
    //generate Button clicked

    //GameChoice->
    //P5
    //parent->p5();
    QString gamechoice = ui->GameChoice->currentItem()->text();
    if(gamechoice == "Persona 4 Golden") {
        MainWindow::p4g();
    } else if(gamechoice == "Persona 3 FES"){
        MainWindow::p3fes();
    }
}
