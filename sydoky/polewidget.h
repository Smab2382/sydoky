#ifndef POLEWIDGET_H
#define POLEWIDGET_H
#include "counter.h"
#include <QWidget>

class poleWidget : public QWidget
{
    Q_OBJECT
public:
    explicit poleWidget(QWidget *parent = 0);
    int n;
    Counter p[9][9];
    void in(int i,int j,int z){p[i][j].set(z);}
    int out(int i,int j){return p[i][j].value();}\
    void g(int slognost);
    void setn(int t);
    bool check();
    void pr();
signals:

public slots:
 void checkw();
};

#endif // POLEWIDGET_H
