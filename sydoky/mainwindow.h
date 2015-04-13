#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QAction>
#include <QMenu>
#include <QComboBox>
class poleWidget;

namespace Ui {
class MainWindow;
}
class  MainWindow  : public QMainWindow//QWidget
{
    Q_OBJECT

public:
     MainWindow();
     int n;
private:
     int complexity;

        Ui::MainWindow *ui;
         QComboBox *forwardBtn[9][9];
    poleWidget *segBtn;
     QAction   *newAct, *exitAct;
     QMenu *fileMenu ;
    signals:
public slots:
     void newpol();
      void setcomplexity(int t);
       void setn(int t);
       void newfunc();
};
#endif // MAINWINDOW_H
