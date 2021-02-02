#include<iostream>
#include<string>
#include<stdio.h>
#include<windows.h>
#include <sstream>
#include<fstream>
#include<conio.h>
#include "fn.h"
using namespace std;

int main(int argc, char* argv[]){
    system("title 垃圾清理程序 V1.0");
    bool isinst = getInstallStatus();
    while (1) {
        cout << "垃圾清理程序 V1.0 " ;
        if(isinst) cout << "完整版" << endl;
        if(!isinst) cout << "基本版" << endl;
        cout << "                   For Windows" << endl;
        cout << "=================================================" << endl;
        cout << "请选择您要进行的操作" << endl;
        cout << "0. 退出" << endl;
        cout << "1. 运行系统盘扫描程序" << endl;
        cout << "2. 运行自定义扫描程序" << endl;
        if(!isinst) cout << "警告: 运行扫描程序需要完整安装。进行完整安装请输入 : ,然后输入 :install 。" << endl;
        cout << "3. 保存运行结果" << endl;
        cout << "4. 分析运行结果并操作" << endl;
        cout << "5. 刷新" << endl;
        cout << "6. 以管理员身份重新打开" << endl;
        cout << "7. 设置" << endl;
        cout << "8. 上一页" << endl;
        cout << "9. 下一页" << endl;
        cout << ":. 高级功能" << endl;
        cout << "请选择: ";
        char s = _getche();
        //system("cls");
        cout << "\n==================================================" << endl;
        if (s == '0') return 0;
        if (s == '1') scan();
        if (s == '2') {
            string u;
            cout << "请输入要扫描的目录: ";
            cin >> u;
            scan(u);
        }
        if (s == '3') {
            string u;
            cout << "保存到? ";
            cin >> u;
            scan("save",u);
        }
        if (s == '4') {
            scan(true);
        }
        if (s == '5') {
            system("cls");
            continue; 
        }
        if (s == '6') {
            system("cls");
            ostringstream oss;
            oss << "powershell Start-Process -FilePath \"" << argv[0] << "\" -Verb runAs";
            system(oss.str().c_str());
            return 0;
        }
        if (s == '7') {
            ScanSettings();
            continue;
        }
        if (s == ':') {
            HighFunction(1);
            continue;
        }
            system("cls");
        if (s != '1' && s != '2' && s != '3' && s != '4' && s != '5' && s != '6') {
            //cout << "错误,请重新输入" << endl;
            //cout << "2秒后返回主页..." << endl;
            //Sleep(2000);
            system("cls");
        }
        continue;
    };
    return 0;
}

