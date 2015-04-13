#include "mainwindow.h"
#include <QtGui>
#include <QComboBox>
#include <QVBoxLayout>
#include <QDialog>
#include <QAction>
#include <QLabel>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include "polewidget.h"
 void  MainWindow::newpol()
 {    int simvol[9];
      for(int i=0;i<n*n;i++){simvol[i]=rand()%50+25;};
       segBtn->setn(n);
segBtn->g(complexity);
 segBtn->setEnabled(1);
 for(int i=0;i<n*n;i++){
 for(int g=0;g<n*n;g++){forwardBtn[i][g]->clear();
     if(segBtn->out(i,g)>0){QString s=""; s.push_back(simvol[segBtn->out(i,g)-1]+49);
         forwardBtn[i][g]->addItem(s);
         forwardBtn[i][g]->setEnabled(0);}else{ forwardBtn[i][g]->setEnabled(1);
         QString s=" ";
         forwardBtn[i][g]->addItem(s);
          for(int ii=0;ii<n*n;ii++){s="";
              s.push_back(simvol[ii]+49);
              forwardBtn[i][g]->addItem(s);};}}
 }
  this->setFixedSize(35*n*n,30*n*n+21);
 }

 void MainWindow::setcomplexity(int t){complexity=t;}

  void MainWindow::setn(int t){n=t+2;}

 void MainWindow::newfunc()
 { QDialog *d=new QDialog(NULL);
     QVBoxLayout *f=new QVBoxLayout;
    d->setLayout(f);
   QComboBox *l1=new QComboBox;
   l1->addItem("2");
   l1->addItem("3");
   QComboBox *l2=new QComboBox;
   l2->addItem("easy");
   l2->addItem("normal");
   l2->addItem("hard");
   f->addWidget(l1);
   f->addWidget(l2);
   connect(l1,SIGNAL( activated(int)),this,SLOT(setn(int)));
    connect(l2,SIGNAL( activated(int)),this,SLOT(setcomplexity(int)));
    QPushButton *l3=new QPushButton;l3->setText("ok");
     f->addWidget(l3);
     connect(l3,SIGNAL(clicked()),this,SLOT(newpol()));
     connect(l3,SIGNAL(clicked()),d,SLOT(close()));
     d->show();
 }

 MainWindow::  MainWindow()
{segBtn= new poleWidget(this);
complexity=0;n=3;segBtn->setEnabled(0);
segBtn->setGeometry(0,21,0,0);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(segBtn);
    QMenu * mnNew = new QMenu("New");
    QAction *newAction = new QAction("new",mnNew);
        connect(newAction, SIGNAL(triggered()), this, SLOT(newfunc()));
    this->menuBar()->addAction(newAction);
    QGridLayout *l=new QGridLayout;
    for(int i=0;i<9;i++){
    for(int g=0;g<9;g++){forwardBtn[i][g]=new  QComboBox;
forwardBtn[i][g]->setFixedSize(36,31);
    }};
    segBtn->setLayout(l);
    segBtn->layout()->setSpacing(0);
    segBtn->layout()->setMargin(0);
    for(int i=0;i<9;i++){for(int g=0;g<9;g++){l->addWidget(forwardBtn[i][g],i,g);};};
      for(int i=0;i<9;i++){for(int g=0;g<9;g++){
              connect(forwardBtn[i][g], SIGNAL( activated(int)),&segBtn->p[i][g], SLOT(setValue(int)));
             connect(&segBtn->p[i][g], SIGNAL(ValueChanged(int,int)),segBtn, SLOT( checkw()));

          };};

    segBtn->setFixedSize(35*9,30*9);
    this->setFixedSize(35*9,30*9+21);
}
