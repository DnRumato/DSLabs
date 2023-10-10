#include "calculator.h"

calculator::calculator(){}

long long calculator::power(long long a, int b)
{
    if(b == 0) return 1;
    for(int i = 0; i < a; ++i) a*=a;
    return a;
}


QString calculator::calculate(bool flag, QString firstStr, QString secondStr)
{
    long long firstNum, secondNum, resultNum;
    int firstIndex, secondIndex, dotIndex;
    QString resultStr;

    firstIndex = firstStr.indexOf(".");
    if(firstIndex == -1) firstIndex = firstStr.indexOf(",");
    if(firstIndex != 0 && firstIndex != -1) firstNum = firstStr.leftRef(firstIndex).toLongLong() + firstStr.rightRef(firstStr.size() - firstIndex).toLongLong();
    else firstNum = firstStr.toLongLong();

    secondIndex = secondStr.indexOf(".");
    if(secondIndex == -1) secondIndex = secondStr.indexOf(",");
    if(secondIndex != 0 && secondIndex != -1) secondNum = secondStr.leftRef(secondIndex).toLongLong() + secondStr.rightRef(secondStr.size() - secondIndex).toLongLong();
    else secondNum = secondStr.toLongLong();

    dotIndex = std::max(firstIndex, secondIndex);
    if(dotIndex != 0 && dotIndex != -1){
       firstNum *= power(10, dotIndex);
       secondNum *= power(10, dotIndex);
    }

    if(flag) resultNum = firstNum + secondNum;
    else resultNum = firstNum - secondNum;

    resultStr = QString::number(resultNum);
    if(dotIndex != 0 && dotIndex != -1){
       resultStr.insert(dotIndex, ",");
    }
    return resultStr;
}


