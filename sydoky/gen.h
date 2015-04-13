#ifndef GEN_H
#define GEN_H

#include <QObject>

class Counter1 : public QObject
{
    Q_OBJECT

    int m_value;
    int v_value;
public:
    explicit Counter1(QObject *parent = 0);
    int value();
signals:
    void ValueChanged(int old_value,int new_value);
public slots:
    void set(int temp);
    void setValue(int value);
    void print();

};
#endif // GEN_H
