#include <iostream>

#include <QCoreApplication>
#include <QDebug>

#include <compare_functions.h>



enum ActualValueStatus {
    EQUAL,
    SMALL_DEVIATION,
    HUGE_DEVIATION
};

ActualValueStatus calcAVStatus(double changeVal, double actualVal) {
    ActualValueStatus state = ActualValueStatus::EQUAL;
    double high = 1.15;
    double low = 0.85;

    if (isApproximatelyEqual(changeVal, actualVal)) {
        state = ActualValueStatus::EQUAL;
    }
    else if (isDefinitelyLessThan(changeVal*low, actualVal) && isDefinitelyGreaterThan(changeVal*high,actualVal)) {
        state = ActualValueStatus::SMALL_DEVIATION;
    }
    else if (isDefinitelyGreaterThan(changeVal*low, actualVal) || isDefinitelyLessThan(changeVal*high, actualVal)) {
        state = ActualValueStatus::HUGE_DEVIATION;
    }
    return state;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    double v = 45;
    qDebug() << static_cast<int>(calcAVStatus(v, v)); //0
    qDebug() << static_cast<int>(calcAVStatus(v, v*1.1));//1
    qDebug() << static_cast<int>(calcAVStatus(v, v*0.95));//1
    qDebug() << static_cast<int>(calcAVStatus(v, v*1.2)); //2
    qDebug() << static_cast<int>(calcAVStatus(v, v*0.8))<< endl; //2
    v = 45.4;
    qDebug() << static_cast<int>(calcAVStatus(v, v));
    qDebug() << static_cast<int>(calcAVStatus(v, v*1.1));
    qDebug() << static_cast<int>(calcAVStatus(v, v*0.95));
    qDebug() << static_cast<int>(calcAVStatus(v, v*1.2));
    qDebug() << static_cast<int>(calcAVStatus(v, v*0.8))<< endl;
    v = 45.04;
    qDebug() << static_cast<int>(calcAVStatus(v, v));
    qDebug() << static_cast<int>(calcAVStatus(v, v*1.1));
    qDebug() << static_cast<int>(calcAVStatus(v, v*0.95));
    qDebug() << static_cast<int>(calcAVStatus(v, v*1.2));
    qDebug() << static_cast<int>(calcAVStatus(v, v*0.8))<< endl;
    v = 45.004;
    qDebug() << static_cast<int>(calcAVStatus(v, v));
    qDebug() << static_cast<int>(calcAVStatus(v, v*1.1));
    qDebug() << static_cast<int>(calcAVStatus(v, v*0.95));
    qDebug() << static_cast<int>(calcAVStatus(v, v*1.2));
    qDebug() << static_cast<int>(calcAVStatus(v, v*0.8)) << endl;
    v = 45.004;
    qDebug() << static_cast<int>(calcAVStatus(v*0.00005, v*0.00005)); //0
    qDebug() << static_cast<int>(calcAVStatus(v*1.15, v*1.15*1.2)); //2
    qDebug() << static_cast<int>(calcAVStatus(v*1.15, v*1.15*0.99)); //1

    return a.exec();
}
