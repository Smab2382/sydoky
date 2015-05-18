#include "mainwindow.h"
#include <QtGui>
#include <QComboBox>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QDialog>
#include <QAction>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QMenu>
#include <QMenuBar>
#include <QPalette>
#include <QTime>
#include<QTimer>
#include "polewidget.h"

void MainWindow::setcomplexity(int t){complexity=t;}

void  MainWindow::setezmod(bool b){ezmod=b;}

void  MainWindow::setbmod(bool b){bmod=b;}

 void MainWindow::setn(int t){n=t+2;}

 void MainWindow::pri(){qDebug()<<sim;}

void MainWindow::setnom(int t){nom=t;}

void MainWindow::setsim(int t){sim=t;}

void MainWindow::setpole()
{QString s=""; s.push_back(simvol[sim]+49);
  forwardBtn[nom/(n*n)][nom%(n*n)]->setText(s);
    segBtn->in(nom/(n*n),nom%(n*n),sim+1);
  if(ezmod){
      if( segBtn->checkez()){
  forwardBtn[nom/(n*n)][nom%(n*n)]->setStyleSheet("QPushButton { background-color:; }");}
      else{
   forwardBtn[nom/(n*n)][nom%(n*n)]->setStyleSheet("QPushButton { background-color:red; }");};
  }
  if(bmod){
  forwardBtn[nom/(n*n)][nom%(n*n)]->setEnabled(0);
  }
  segBtn->checkw();
 }


 void  MainWindow::newpol()
 {
        for(int i=0;i<9;i++){for(int g=0;g<9;g++){forwardBtn[i][g]->setStyleSheet("QPushButton { background-color:; }");}};
     for(int i=0;i<n*n;i++){simvol[i]=rand()%50+25;for(int g=0;g<i;g++){if(simvol[i]==simvol[g]){i--;};};};
       for(int i=0;i<3;i++){for(int g=0;g<3;g++){simbtn[i][g]->setVisible(0);}};
        for(int i=0;i<n;i++){for(int g=0;g<n;g++){simbtn[i][g]->setVisible(1);}};
          for(int i=0;i<n;i++){for(int g=0;g<n;g++){QString s=""; s.push_back(simvol[i*n+g]+49);simbtn[i][g]->setText(s);
                  simbtn[i][g]->set(i*n+g);
               connect(simbtn[i][g], SIGNAL( clicked()),simd, SLOT(close()));
               connect(simbtn[i][g], SIGNAL( clicked()),simbtn[i][g], SLOT(setValue()));
               connect(simbtn[i][g], SIGNAL( ValueChanged(int)),this, SLOT(setsim(int)));
               connect(simbtn[i][g], SIGNAL( clicked()),this, SLOT(setpole()));
              };};

       segBtn->setn(n);
segBtn->g(complexity);
 segBtn->setEnabled(1);
 for(int i=0;i<n*n;i++){
     for(int g=0;g<n*n;g++){int fal=i*n*n+g;forwardBtn[i][g]->set(fal);forwardBtn[i][g]->setEnabled(1);
         connect(forwardBtn[i][g], SIGNAL( clicked()),simd, SLOT(show()));
         if(segBtn->out(i,g)>0){QString s=""; s.push_back(simvol[segBtn->out(i,g)-1]+49);
             forwardBtn[i][g]->setText(s);
             forwardBtn[i][g]->setEnabled(0);}else{ forwardBtn[i][g]->setEnabled(1);
             QString s=" ";
             forwardBtn[i][g]->setText(s);
                 };}}
  this->setFixedSize(35*n*n,30*n*n+21);
 }


 void MainWindow::newfunc()
 { QDialog *d=new QDialog(NULL);ezmod=false;bmod=false;n=2;
     QVBoxLayout *f=new QVBoxLayout;
    d->setLayout(f);
   QComboBox *l1=new QComboBox;
   l1->addItem("2");
   l1->addItem("3");
   QComboBox *l2=new QComboBox;
   l2->addItem("easy");
   l2->addItem("normal");
   l2->addItem("hard");
   QLabel *mod1str=new QLabel("ez mod",d);
   QLabel *mod2str=new QLabel("clean mod",d);
 QCheckBox* ez=new QCheckBox;
 QCheckBox* b=new QCheckBox;
   f->addWidget(l1);
   f->addWidget(l2);
    f->addWidget(mod1str);
    f->addWidget(ez);
         connect(ez,SIGNAL(toggled(bool)),this,SLOT(setezmod(bool)));
     f->addWidget(mod2str);
      f->addWidget(b);
      connect(b,SIGNAL(toggled(bool)),this,SLOT(setbmod(bool)));
   connect(l1,SIGNAL( activated(int)),this,SLOT(setn(int)));
    connect(l2,SIGNAL( activated(int)),this,SLOT(setcomplexity(int)));
    QPushButton *l3=new QPushButton;l3->setText("ok");
     f->addWidget(l3);
     connect(l3,SIGNAL(clicked()),this,SLOT(newpol()));
     connect(l3,SIGNAL(clicked()),d,SLOT(close()));
     d->show();

 }
 void MainWindow::newfunc2()
 { QDialog *d=new QDialog(NULL);
     QVBoxLayout *f=new QVBoxLayout;
    d->setLayout(f);
    QSlider* aref=new QSlider(this);
    aref->setFixedWidth(20);aref->setRange(0,100);
    aref->setValue(val);
    aref->setSingleStep(10);
    f->addWidget(aref);
     connect(aref,SIGNAL(valueChanged(int)),player, SLOT(setVolume(int)));
     connect(aref,SIGNAL(valueChanged(int)),this, SLOT(setvalume(int)));
     d->show();

 }
 void MainWindow::setvalume(int t)
 {val=t;}
void MainWindow::newfunc3()
{ player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(QDir::toNativeSeparators("./music/1.mp3")));
    player->setVolume(val);
player->play();
}
 MainWindow::  MainWindow()
{segBtn= new poleWidget(this);QTimer *timer=new QTimer(this);
     val=50;
     newfunc3();
     timer->start(343000);
   connect(timer,SIGNAL(timeout()), this, SLOT(newfunc3()));
     simd=new QDialog(NULL);QTime midnight(0,0,0);
     qsrand(midnight.secsTo(QTime::currentTime()));
     QGridLayout *f=new QGridLayout;
   simd->setLayout(f);
     simd->layout()->setSpacing(0);
     simd->layout()->setMargin(0);
  complexity=0;n=2;segBtn->setEnabled(0);
segBtn->setGeometry(0,21,0,0);ezmod=false;bmod=false;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(segBtn);
    QMenu * mnNew = new QMenu("New");
     QMenu * mnVolume = new QMenu("Volume");
    QAction *newAction = new QAction("new",mnNew);
    QAction *newAction2 = new QAction("volume",mnVolume);
        connect(newAction, SIGNAL(triggered()), this, SLOT(newfunc()));
        connect(newAction2, SIGNAL(triggered()), this, SLOT(newfunc2()));
    this->menuBar()->addAction(newAction);
    this->menuBar()->addAction(newAction2);
    QGridLayout *l=new QGridLayout;
    for(int i=0;i<9;i++){
    for(int g=0;g<9;g++){forwardBtn[i][g]=new  Pushbut;
forwardBtn[i][g]->setFixedSize(36,31);
    }};
for(int i=0;i<3;i++){for(int g=0;g<3;g++){simbtn[i][g]=new Pushbut;simbtn[i][g]->setFixedSize(36,31);}}
 for(int i=0;i<3;i++){for(int g=0;g<3;g++){f->addWidget(simbtn[i][g],i,g);};};
    segBtn->setLayout(l);
    segBtn->layout()->setSpacing(0);
    segBtn->layout()->setMargin(0);
    for(int i=0;i<9;i++){for(int g=0;g<9;g++){l->addWidget(forwardBtn[i][g],i,g);};};
      for(int i=0;i<9;i++){for(int g=0;g<9;g++){
              connect(forwardBtn[i][g], SIGNAL( clicked()),forwardBtn[i][g], SLOT(setValue()));
              connect(forwardBtn[i][g], SIGNAL( ValueChanged(int)),this, SLOT(setnom(int)));

          };};
    segBtn->setFixedSize(35*9,30*9);
    this->setFixedSize(35*9,30*9+21);
}
