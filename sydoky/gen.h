#ifndef GEN_H
#define GEN_H

#include <QObject>
#include <QPushButton>

class Pushbut : public QPushButton
{
    Q_OBJECT
    int m_value;
public:
    int value();
signals:
    void ValueChanged(int value);
public slots:
    void set(int temp);
    void setValue();

};
#endif // GEN_H
