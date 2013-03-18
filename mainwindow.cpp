/*
 Copyright (C) Pramod S G <pramod.xyle@gmail.com>

 */

#include<QString>
#include <qregexp.h>
#include<stdlib.h>
#include<QTextStream>
#include<QFile>
#include <fstream>
#include <string>
#include<QProcess>
#include<QLabel>
#include<QString>
#include<unistd.h>
#include<QStringMatcher>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QDebug>
# include <QProcess>


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

void MainWindow::hack()
{

}

void MainWindow::finished()
{

         ui->pushButton_2->setChecked(false);


}


void MainWindow::caldist()
{
    QProcess *proc;
        proc = new QProcess( this ); // memory allocation from heap, created with parent

        {

                static int offset = 0, count;
                static int abc = 0;
                QString address,quality,level,level2,level3,address2,address3;//quality2,quality3;
                QChar add[18],qul[3],lev[4];
                QFile file1("/home/user/Tese/2.txt");
                file1.open(QIODevice::ReadWrite | QIODevice::Text );
                QRegExp search1("\\bAddress\\b");
                QRegExp search2("\\bQuality\\b");
                QRegExp search3("\\blevel\\b");


                if(file1.isOpen())
                {

                        QTextStream in(&file1);
                        system("iwlist wlan0 scan > /home/user/Tese/2.txt");
                        while(!(in.atEnd()))
                        {

                                QString line = in.readAll();

                                offset =  search1.indexIn(line, abc);

                                qDebug() << "----------->"<<offset;

                                {
                                        for(count=0;count<17;count++)
                                        {
                                                add[count]=line[offset+9+count];

                                        }
                                        add[++count]='\0';
                                        for(int i=0;i<=16;i++)
                                        {
                                            address[i]=add[i];

                                        }
                                        qDebug() << address;
                                        if(address=="00:24:01:BA:4C:CD")

                                        {ui->label_5->setText(address);
                                            address2=address;
                                        }

                                        else
                                           if(address=="00:24:01:24:55:0D")

                                        {
                                            ui->label_6->setText(address);
                                            address3=address;
                                        }

                                }

                                abc=offset;
                               offset =  search2.indexIn(line, abc );
                               if (offset == -1) offset=0;
                               qDebug() << "----------->"<<offset;
                                {
                                        for(count=0;count<2;count++)
                                        {
                                                qul[count]=line[offset+8+count];

                                        }
                                        qul[count]='\0';
                                        for(int i=0;i<=2;i++)
                                        {
                                            quality[i]=qul[i];
                                        }

                                            qDebug() << quality;

                                  }



                               abc=offset;
                                offset =  search3.indexIn(line, abc);
                                if (offset == -1) offset=0;

                                   qDebug() << "----------->"<<offset;
                                {
                                        for(count=0;count<3;count++)
                                        {
                                                lev[count]=line[offset+6+count];

                                        }
                                        lev[count]='\0';
                                        for(int i=0;i<=2;i++)
                                        {
                                            level[i]=lev[i];
                                        }

                                            qDebug() << level;

                                     
                                            if(address=="00:24:01:BA:4C:CD")
                                    
                                            {
                                                ui->label_3->setText(level);
                                                level2=level;
                                            }

                                                else
                                               if(address=="00:24:01:24:55:0D")
                                              
                                                {
                                                    ui->label_7->setText(level);

                                                   level3=level;
}


                                }


                        }


                }
                else
                qDebug() <<"Unable to open this file."<<endl;


        if(level2>level3)
            ui->label_8->setText("First Router");
        else if(level3>level2)
            ui->label_8->setText("Second Router");

        if(((level2>"-42") && (level2<"-52")) || ((level3>"-45") && (level3<"-60")))

            ui->label_10->setText("Take Left");
        else

        ui->label_10->setText("Go Straight");

    }

    }

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
