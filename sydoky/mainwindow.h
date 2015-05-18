#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QAction>
#include <QMenu>
#include <QComboBox>
#include <QMediaPlayer>
#include <QDir>
#include <QUrl>
#include "gen.h"
class poleWidget;

namespace Ui {
class MainWindow;
}
class  MainWindow  : public QMainWindow//QWidget
{
    Q_OBJECT

public:
    int simvol[9];
     MainWindow();
     int nom;
     int n;
     int sim;
     bool bmod;
     bool ezmod;
     int val;
     QMediaPlayer *player;
private:
     int complexity;

        Ui::MainWindow *ui;
        Pushbut *forwardBtn[9][9];
        Pushbut *simbtn[3][3];
    poleWidget *segBtn;
     QAction   *newAct, *exitAct;
     QMenu *fileMenu ;
     QDialog *simd;
    signals:
public slots:
     void newpol();
     void setpole();
      void setcomplexity(int t);
       void setn(int t);
       void setnom(int t);
       void setsim(int t);
       void setezmod(bool b);
       void setbmod(bool b);
       void pri();
       void newfunc();
       void newfunc2();
       void newfunc3();
       void setvalume(int);
};
#endif // MAINWINDOW_H
