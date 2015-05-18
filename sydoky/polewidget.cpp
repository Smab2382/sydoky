#include "polewidget.h"
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QTime>
poleWidget::poleWidget(QWidget *parent) :
    QWidget(parent)
{ for(int i=0;i<9;i++){for(int j=0;j<9;j++){p[i][j].set(-1);}}
     wind=new QDialog(NULL);
     QVBoxLayout *f=new QVBoxLayout;
    wind->setLayout(f);QLabel *l=new QLabel("win",wind);
    f->addWidget(l);
}
void poleWidget::setn(int t)
{n=t;}
void poleWidget::g(int slognost)
{int y=n*n*n*n;int r=y*60/100;QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    int yy=y/20;if (yy<1)yy=2;
        if(slognost==0){r=y-(y*55/100+rand()%yy);};
        if(slognost==1){r=y-(y*50/100+rand()%yy);};
        if(slognost==2){r=y-(y*45/100+rand()%yy);};
    int zz[18];
    for(int j=0;j<n*n;j++){zz[j]=j+1;}
    for(int j=0;j<n*n;j++){zz[j+n*n]=j+1;}
    int i[9][9];
    for(int j=0;j<n*n;j++)
    {for (int z=0;z<n*n;z++) {i[j][z]=zz[z+j/n+(j%n)*n];}}
int k11=rand() % n;
int k12=rand() % n;
int k21=rand() % n;
int k22=rand() % n;
for(int j=0;j<n;j++)
{for (int z=0;z<n*n;z++)
    {int k=i[j+k11*n][z];
     i[j+k11*n][z]=i[j+k12*n][z];
     i[j+k12*n][z]=k;};

};
for(int j=0;j<n;j++)
{for (int z=0;z<n*n;z++)
{int k=i[z][j+k21*n];
 i[z][j+k21*n]=i[z][j+k22*n];
 i[z][j+k22*n]=k;};
}
for(int j=0;j<n;j++)
{int k31=rand() % n;
 int k32=rand() % n;
    for (int z=0;z<n*n;z++)
{int k=i[z][j*n+k31];
 i[z][j*n+k31]=i[z][j*n+k32];
 i[z][j*n+k32]=k;};
}
for(int j=0;j<n;j++)
{int k31=rand() % n;
 int k32=rand() % n;
    for (int z=0;z<n*n;z++)
{int k=i[j*n+k31][z];
 i[j*n+k31][z]=i[j*n+k32][z];
 i[j*n+k32][z]=k;};
}
int e=0;
while(e<r)
{int u=rand()%(y);
if(i[u/(n*n)][u%(n*n)]!=0)
{e++;
 i[u/(n*n)][u%(n*n)]=0;};
};
for(int j=0;j<n*n;j++)
{for(int z=0;z<n*n;z++)
    {p[j][z].set(i[j][z]);}
}
}


bool poleWidget::check()
{int i[9][9];
    for(int j=0;j<n*n;j++)
    {for(int z=0;z<n*n;z++)
        {i[j][z]=out(j,z);}
    }

    for(int j=0;j<n*n;j++)
    {bool b[9]={0,0,0,0,0,0,0,0,0};
        for(int z=0;z<n*n;z++)
        {if(i[j][z]>0)
            {
             if(b[i[j][z]-1]==0)
               {b[i[j][z]-1]=1;}else{return 0;};
            }
            else{return 0;};
        }

    }

    for(int j=0;j<n*n;j++)
    {bool b[9]={0,0,0,0,0,0,0,0,0};
        for(int z=0;z<n*n;z++)
        {if(i[z][j]>0)
            {
             if(b[i[z][j]-1]==0)
               {b[i[z][j]-1]=1;}else{return 0;};
            }
            else{return 0;};
        }

    }

    for(int j=0;j<n;j++)
    {
        for(int z=0;z<n;z++)
        {bool b[9]={0,0,0,0,0,0,0,0,0};
            for(int f=j*n;f<j*n+n;f++)
            {
                 for(int g=z*n;g<z*n+n;g++)
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
bool poleWidget::checkez()
{int i[9][9];
    for(int j=0;j<n*n;j++)
    {for(int z=0;z<n*n;z++)
        {i[j][z]=out(j,z);}
    }

    for(int j=0;j<n*n;j++)
    {bool b[9]={0,0,0,0,0,0,0,0,0};
        for(int z=0;z<n*n;z++)
        {if(i[j][z]>0)
            {
             if(b[i[j][z]-1]==0)
               {b[i[j][z]-1]=1;}else{return 0;};
            }
        }

    }

    for(int j=0;j<n*n;j++)
    {bool b[9]={0,0,0,0,0,0,0,0,0};
        for(int z=0;z<n*n;z++)
        {if(i[z][j]>0)
            {
             if(b[i[z][j]-1]==0)
               {b[i[z][j]-1]=1;}else{return 0;};
            }
        }

    }

    for(int j=0;j<n;j++)
    {
        for(int z=0;z<n;z++)
        {bool b[9]={0,0,0,0,0,0,0,0,0};
            for(int f=j*n;f<j*n+n;f++)
            {
                 for(int g=z*n;g<z*n+n;g++)
                 {
                     if(i[f][g]>0)
                                 {
                                  if(b[i[f][g]-1]==0)
                                    {b[i[f][g]-1]=1;}else{return 0;};
                                 }
                 }
            }
        }

    }

return 1;
}
void poleWidget::checkw()
{
    if(check())
    { 
    wind->show();
    }
}
void poleWidget::pr()
{
    for(int i=0;i<n*n;i++){for(int j=0;j<n*n;j++){p[i][j].print();}}

}
