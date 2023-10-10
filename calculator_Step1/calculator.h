#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

class calculator
{
private:
    long long power(long long a, int b);

public:
    calculator();
    QString calculate(bool flag, QString firstStr, QString secondStr);
};

#endif // CALCULATOR_H
