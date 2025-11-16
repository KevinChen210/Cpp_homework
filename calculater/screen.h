// comculater.h: 标准系统包含文件的包含文件
// 或项目特定的包含文件。

#pragma once

#include <iostream>
#include <string>
using namespace std;


// 计算器界面类声明
class CalculatorUI {
private:
    Calculator calc; // 组合Calculator对象
public:
    void run(); // 运行界面
};

// 计算器界面类实现
void CalculatorUI::run() {
    char choice;
    do {
        double num1, num2;
        char op;

        cout << "=======================" << endl;
        cout << "     简 单 计 算 器     " << endl;
        cout << "=======================" << endl;

        // 输入第一个数
        cout << "请输入第一个数字: ";
        if (!(cin >> num1)) {
            cout << "错误：输入的不是数字！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // 输入运算符
        cout << "请输入运算符 (+, -, *, /): ";
        cin >> op;

        // 输入第二个数
        cout << "请输入第二个数字: ";
        if (!(cin >> num2)) {
            cout << "错误：输入的不是数字！" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        // 计算并输出结果
        double result;
        bool validOp = true;

        switch (op) {
        case '+':
            result = calc.add(num1, num2);
            break;
        case '-':
            result = calc.subtract(num1, num2);
            break;
        case '*':
            result = calc.multiply(num1, num2);
            break;
        case '/':
            if (num2 == 0) {
                cout << "错误：除数不能为零！" << endl;
                validOp = false;
                break;
            }
            result = calc.divide(num1, num2);
            break;
        default:
            cout << "错误：无效的运算符！" << endl;
            validOp = false;
            break;
        }

        if (validOp) {
            cout << "结果: " << num1 << " " << op << " " << num2 << " = " << result << endl;
        }

        // 询问是否继续
        cout << "\n是否继续计算？(y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "计算器已退出，谢谢使用！" << endl;
}
