#include "gen.h"

#include "counter.h"
#include <QDebug>
Counter1::Counter1(QObject *parent) :
    QObject(parent)
{
    m_value=0;
}
void Counter1::print()
{
    qDebug()<<m_value;
}
void Counter1::setValue(int value)
{
    if(m_value==value)
        return;
    int old_value=m_value;
    m_value=value;
    emit ValueChanged(old_value,m_value);
}
void Counter1::set(int temp)
{
     v_value=temp;
}
int Counter1::value()
{
    return m_value;
}

