#pragma once

#include <iostream>
#include <string>
using namespace std;

// 计算器基类声明
class Calculator {
public:
    double add(double a, double b);     // 加法
    double subtract(double a, double b); // 减法
    double multiply(double a, double b); // 乘法
    double divide(double a, double b);   // 除法
};

// 计算器基类实现
double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b == 0) {
        cout << "错误：除数不能为零！" << endl;
        return 0; // 简单处理，实际项目可抛异常
    }
    return a / b;
}

