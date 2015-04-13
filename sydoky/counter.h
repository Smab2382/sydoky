#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>

class Counter : public QObject
{
    Q_OBJECT

    int m_value;
public:
    explicit Counter(QObject *parent = 0);
    void set(int temp);
    int value();
signals:
    void ValueChanged(int old_value,int new_value);
public slots:
    void setValue(int value);
    void print();

};

#endif // COUNTER_H
