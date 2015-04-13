#include "counter.h"
#include <QDebug>
Counter::Counter(QObject *parent) :
    QObject(parent)
{
    m_value=0;
}
void Counter::print()
{
    qDebug()<<m_value;
}
void Counter::setValue(int value)
{
    if(m_value==value)
        return;
    int old_value=m_value;
    m_value=value;
    emit ValueChanged(old_value,m_value);
}
void Counter::set(int temp)
{
     m_value=temp;
}
int Counter::value()
{
    return m_value;
}
