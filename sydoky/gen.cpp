#include "gen.h"

#include "counter.h"
#include <QDebug>
void Pushbut::setValue()
{
    emit ValueChanged(m_value);
}
void Pushbut::set(int temp)
{
     m_value=temp;
}
int Pushbut::value()
{
    return m_value;
}

