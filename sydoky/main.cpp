#include "mainwindow.h"
#include <QAction>
#include <QApplication>
#include <QDialog>
#include <QToolButton>
#include <QWidget>
#include <QtGui>
#include <QVBoxLayout>
#include <QBoxLayout>
#include <QGridLayout>
#include <string>
#include <QMenu>
#include <QLabel>
#include <QComboBox>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <QObject>
#include <QPushButton>
using namespace std;
class Counter : public QObject
{
public:
   Counter() { m_value = 0; }
   int value() const { return m_value; }
   void set(int value){ m_value=value;}
public slots:
   void setValue(int value);
signals:
   void valueChanged(int newValue);
private:
   int m_value;
};
void Counter::setValue(int value)
{
   if (value != m_value) {
     m_value = value;
     emit set(value);
   }
}
class pole:public  QObject
{
private:
public:
Counter p[9][9];
void in(int i,int j,int z){p[i][j].set(z);}
int out(int i,int j){return p[i][j].value();}\
void g(int slognost);
signals:

public slots:
    bool check(int ii);
};
void pole::g(int slognost)
{int r=60;
    if(slognost==0){r=81-(30+rand()%5);};
    if(slognost==1){r=81-(25+rand()%5);};
    if(slognost==2){r=81-(20+rand()%5);};
    int i[9][9]={1,2,3,4,5,6,7,8,9,
               4,5,6,7,8,9,1,2,3,
               7,8,9,1,2,3,4,5,6,
               2,3,4,5,6,7,8,9,1,
               5,6,7,8,9,1,2,3,4,
               8,9,1,2,3,4,5,6,7,
               3,4,5,6,7,8,9,1,2,
               6,7,8,9,1,2,3,4,5,
               9,1,2,3,4,5,6,7,8
              };

int k11=rand() % 3;
int k12=rand() % 3;
int k21=rand() % 3;
int k22=rand() % 3;
for(int j=0;j<3;j++)
{for (int z=0;z<9;z++)
    {int k=i[j+k11*3][z];
     i[j+k11*3][z]=i[j+k12*3][z];
     i[j+k12*3][z]=k;};

};
for(int j=0;j<3;j++)
{for (int z=0;z<9;z++)
{int k=i[z][j+k21*3];
 i[z][j+k21*3]=i[z][j+k22*3];
 i[z][j+k22*3]=k;};
}
for(int j=0;j<3;j++)
{int k31=rand() % 3;
 int k32=rand() % 3;
    for (int z=0;z<9;z++)
{int k=i[z][j*3+k31];
 i[z][j*3+k31]=i[z][j*3+k32];
 i[z][j*3+k32]=k;};
}
for(int j=0;j<3;j++)
{int k31=rand() % 3;
 int k32=rand() % 3;
    for (int z=0;z<9;z++)
{int k=i[j*3+k31][z];
 i[j*3+k31][z]=i[j*3+k32][z];
 i[j*3+k32][z]=k;};
}
int e=0;
while(e<r)
{int u=rand()%81;
if(i[u/9][u%9]!=0)
{e++;
 i[u/9][u%9]=0;};
};
for(int j=0;j<9;j++)
{for(int z=0;z<9;z++)
    {in(j,z,i[j][z]);}
}
}


bool pole::check(int ii)
{int i[9][9];
    for(int j=0;j<9;j++)
    {for(int z=0;z<9;z++)
        {i[j][z]=out(j,z);}
    }

    for(int j=0;j<9;j++)
    {bool b[9]={0,0,0,0,0,0,0,0,0};
        for(int z=0;z<9;z++)
        {if(i[j][z]>0)
            {
             if(b[i[j][z]-1]==0)
               {b[i[j][z]-1]=1;}else{return 0;};
            }
            else{return 0;};
        }

    }

    for(int j=0;j<9;j++)
    {bool b[9]={0,0,0,0,0,0,0,0,0};
        for(int z=0;z<9;z++)
        {if(i[z][j]>0)
            {
             if(b[i[z][j]-1]==0)
               {b[i[z][j]-1]=1;}else{return 0;};
            }
            else{return 0;};
        }

    }
    for(int j=0;j<3;j++)
    {
        for(int z=0;z<3;z++)
        {bool b[9]={0,0,0,0,0,0,0,0,0};
            for(int f=j*3;f<j*3+3;f++)
            {
                 for(int g=z*3;g<z*3+3;g++)
                 {
                     if(i[f][g]>0)
                                 {
                                  if(b[i[f][g]-1]==0)
                                    {b[i[f][g]-1]=1;}else{return 0;};
                                 }
                                 else{return 0;};
                 }
            }
        }

    }

return 1;
}

int main(int argc, char *argv[])
{    QApplication a(argc, argv);
     pole p;
      p.g(0);
     int simvol[9];
      for(int i=0;i<9;i++){simvol[i]=rand()%50+25;};
    QWidget *segBtn = new QWidget();
    QComboBox *forwardBtn[81];
    QGridLayout *l=new QGridLayout;
    for(int i=0;i<9;i++){
    for(int g=0;g<9;g++){forwardBtn[i*9+g]=new  QComboBox;
forwardBtn[i*9+g]->setFixedSize(36,31);
if(p.out(i,g)>0){QString s=""; s.push_back(simvol[p.out(i,g)-1]+49); forwardBtn[i*9+g]->addItem(s);
forwardBtn[i*9+g]->setEnabled(0);}else{
QString s=" ";
forwardBtn[i*9+g]->addItem(s);
 for(int ii=0;ii<9;ii++){s="";
     s.push_back(simvol[ii]+49);
     forwardBtn[i*9+g]->addItem(s);};}
    }
    };
 segBtn->setLayout(l);
    segBtn->layout()->setSpacing(0);
    segBtn->layout()->setMargin(0);
    for(int i=0;i<9;i++){for(int g=0;g<9;g++){l->addWidget(forwardBtn[i*9+g],i,g);};};
      for(int i=0;i<9;i++){for(int g=0;g<9;g++){
              QObject::connect(forwardBtn[i*9+g], SIGNAL(activated(int)), &p.p[i][g], SLOT(setValue(int)));
              QObject::connect(&p.p[i][g], SIGNAL(pushh(int)),&p, SLOT( check(int)));
          };};
       Counter a1, b;
        QObject::connect(&a1, SIGNAL(set(int)),
                &b, SLOT(setValue(int)));
        a1.set(12);   // a.value() == 12, b.value() == 12
        b.set(48);   // a.value() == 12, b.value() == 48
    segBtn->setFixedSize(35*9,30*9);
    segBtn->show();
    return a.exec();
}
