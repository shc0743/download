#include<iostream>
#include<string>
#include<stdio.h>
#include<windows.h>
#include <sstream>
#include<fstream>
#include<conio.h>
#include "fn.h"
using namespace std;
inline void cls() {
    system("cls");
}

void scan() {
    system("cls");
    ostringstream oss;
    /*/ oss.str() 
    ifstream inFile("settings/openasnew", ios::in);
    char c[7]; string ra; ra = "";
    //判断文件是否正常打开
    if (inFile) {
        //从 in.txt 文件中读取一行字符串，最多不超过 39(40-1) 个
        inFile.getline(c, 6);
        if (c == "true") ra = "start ";
    }
    inFile.close();*/
    oss << "start " << "waster " << endl << "exit";
    system(oss.str().c_str());
    system("cls");
    std::cout << "扫描完成,3秒后返回主页..." << endl << "exit";
    //Sleep(3000);
}

void scan(string path) {
    system("cls");
    ostringstream oss;
    oss << "start " << "waster " << path << endl << "exit";
    system(oss.str().c_str());
    system("cls");
    std::cout << "扫描完成,3秒后返回主页..." << endl << "exit";
    //Sleep(3000);
}

int scan(string ResType, string saveto) {
    //system("cls");
    if (ResType != "save") return 1;
    ostringstream oss;
    oss << "xcopy waster.log " << saveto << endl;
    // oss.str() 
    system(oss.str().c_str());
    system("cls");
    std::cout << "操作已完成,3秒后返回主页..." << endl;
    Sleep(3000);
    return 0;
}

int scan(int method, bool ttt, bool fff) {
    char c[10000];
    ifstream log("waster.log", ios::in);
    while (log.getline(c, 9999)) {
        //文件名=char c
        string fn;
        fn = c;
        /*
        if (fn.find("dll", 1) && ttt) continue;
        if (fn.find("sys", 1) && ttt) continue;
        if (fn.find("lib", 1) && ttt) continue;
        if (fn.find("bin", 1) && ttt) continue;
        if (fn.find("windows", 1) && ttt) continue;
        */
        if (fn.find("template", 1)!=string::npos && ttt) continue; 
        if (fn.find("dll", 1)!=string::npos && ttt) continue; 
        if (fn.find("sys", 1)!=string::npos && ttt) continue; 
        if (fn.find("lib", 1)!=string::npos && ttt) continue;
        if (fn.find("bin", 1)!=string::npos && ttt) continue;
        ifstream inFile(c, ios::in | ios::binary); //二进制读方式打开
        if (!inFile) {
            inFile.close();
            continue;
        }
        inFile.close();
        ostringstream oss; ostringstream oss2;
        if (method == 1) {
            std::cout << "\n" << c << " ,是否删除? [Y,N]";
            char s = _getche();
            if (s == 'y' || s == 'Y') {
                oss << "del /f /s /q \"" << c << "\"";
                oss2 << "rd /s /q \"" << c << "\"";
                system(oss.str().c_str());
                system(oss2.str().c_str());
                std::cout << "命令行: " << endl << oss.str() << endl << oss2.str() << endl;
                continue;
            }
            if(s=='n'||s=='N') continue;
            std::cout << "输入错误!" << endl;
        }
        if (method == 2) {
            oss << "del /f /s /q \"" << c << "\"";
            oss2 << "rd /s /q \"" << c << "\"";
            system(oss.str().c_str());
            system(oss2.str().c_str());
            std::cout << "命令行: " << endl << oss.str() << endl << oss2.str() << endl;
            continue;
        }
        if (method == 3) {
            system("mkdir %SYSTEMDRIVE%\\Trush\\ 2>nul");
            oss << "move /Y \"" << c << "\" %SYSTEMDRIVE%\\Trush\\";
            std::cout << "命令行: " << endl << oss.str() << endl << "处理的文件:" << c << endl;
            system(oss.str().c_str());
            continue;
        }
    }
    log.close();
    std::cout << "清除完成,3秒后返回主页..." << endl;
    Sleep(3000);
    return 0;
}

int scan(bool isOption) {
    system("cls");
    if (!isOption) return 1;
    std::cout << "已发现的垃圾文件:" << endl;
    system("type waster.log");
    std::cout << endl << "========" << endl << "提示:建议使用管理员身份进行清除" << endl << "是否清理? [Y/N]";
    char s = _getche();
    if (s == 'n' || s == 'N') {
        std::cout << "操作已完成,3秒后返回主页..." << endl;
        Sleep(3000);
        return 0;
    }
    if (s == 'y' || s == 'Y') {
        std::cout << "请选择清理方式\n1.需要确认\n2.直接删除\n3.移动至%SYSTEMDRIVE%\\Trush\\\n请选择: ";
        char us = _getche();
        //system("CLS");
        if (us != '1' && us != '2' && us != '3') {
            std::cout << "\n输入错误,3秒后返回主页..." << endl;
            Sleep(3000);
            return 1;
        }
        std::cout << endl;
        if (us == '1') scan(1, true, true);
        if (us == '2') scan(2, true, true);
        if (us == '3') scan(3, true, true);
        std::cout << "操作已完成,3秒后返回主页..." << endl;
        Sleep(3000);
        return 0;
    }
    return 0;
}

void ScanSettings(char id) {
    cls();
    switch (id) {
        /*case '1':{
            std::cout << "是否始终在新窗口打开文件扫描器?\n0:true\n1:false\nYour select:";
            char s = _getche();
            if (s == '1') {
                system("cd settings&echo true > openasnew");
            break;
            }
            if (s == '0') {
                system("cd settings&echo false > openasnew");
            break;
            }
            std::cout << "错误,3秒后返回...";
            std::cout << "\n错误详情=>输入不合适";
            Sleep(3000);
            return;
        }*/
    default: {
        std::cout << "错误,3秒后返回...";
        Sleep(3000);
        return;
    }
    };
    std::cout << "\n成功,2秒后返回..." << endl;
    Sleep(2000);
    return;
}
void ScanSettings() {
    system("mkdir settings");
    while (1) {
        cls();
        std::cout <<
            "设                                             置" << endl <<
            "=================================================" << endl <<
            "0. 返回" << endl <<
            /*"1. 始终在新窗口打开文件扫描器" <<*/ endl;//<<;
        char s = _getche();
        if (s == '0') return;
        ScanSettings(s);
    }
}

int HighFunction(int page)
{
    using namespace std;
    cls();
    while(1){
        if(page==1){
            std::cout << "垃圾清理程序 V1.0 For Windows" << endl;
            std::cout << "=================================================" << endl;
            std::cout << "高级功能 - 第1/1页" << endl;
            std::cout << ":c 清除扫描结果" << endl;
            std::cout << ":cls 清除屏幕" << endl;
            std::cout << ":fd 强力删除(删除所有已发现的垃圾文件)" << endl;
            std::cout << ":fs 强力扫描(加入类型: old chk log gid)" << endl;
            //std::cout << ":h 查看帮助" << endl;
            if(!getInstallStatus()) std::cout << ":install 进行完整安装" << endl;
            std::cout << ":q 退出" << endl;
            std::cout << ":r 返回" << endl;
            if(getInstallStatus()) std::cout << ":uninstall 卸载完整安装(不卸载基本安装)" << endl;
            //std::cout << "4. 分析运行结果并操作" << endl;
            std::cout << "(提示: 高级功能区分大小写,并且需要输入冒号)\n";
            std::cout << "请选择: ";
            string s;
            cin >> s;
            //system("cls");
            std::cout << "\n==================================================" << endl;
            if (s == ":q") exit(0);
            if (s == ":r") return 0;
            if (s == ":c") {
                system("del /f /s /q waster.log");
                std::cout << "\n成功,2秒后返回..." << endl;
                Sleep(2000);
                return 0;
            }
            if (s == ":cls") { 
                cls();
                continue;
            }
            if (s == ":fd") {
                scan(2, false, true);
                return 0;
            }
            if (s == ":fs") {
                system("cls");
                ostringstream oss;
                string path;
                cout << "输入扫描目录:";
                cin >> path;
                oss << "start " << "waster \"" << path << "\" --searchall" << endl << "exit";
                system(oss.str().c_str());
                system("cls");
                std::cout << "扫描完成,3秒后返回主页..." << endl;
                //Sleep(3000);
                return 0;
            }
            //install
            if (s == ":install"&&!getInstallStatus()) {
                cls(); cout << "完整安装 垃圾清理程序 V1.0 For Windows\n========\n";
                cout << "当前进度: 安装waster.bat...\n";
                ofstream mainbatfile("waster.bat", ios::out); //以文本模式打开备写
                mainbatfile << "@echo off\n";
                mainbatfile << "    if '%1'=='' ("<<endl;
                mainbatfile << "        set a=%SYSTEMDRIVE%"<<endl; 
                mainbatfile << "        ) else ("<<endl;
                mainbatfile << "            set a=%1"<<endl;
                mainbatfile << "        )"<<endl;
                mainbatfile << "    if '%2'=='--seachall' ("<<endl;
                mainbatfile << "    set \"sfhyold= old log gid chk\""<<endl;
                mainbatfile << "        )"<<endl;
                mainbatfile << "        echo ========"<<endl;
                mainbatfile << "        echo 垃圾文件扫描器"<<endl;
                mainbatfile << "        echo ========"<<endl;
                mainbatfile << "        echo."<<endl;
                mainbatfile << "        echo 扫描中......"<<endl;
                mainbatfile << "        echo."<<endl;
                mainbatfile << "        echo 请等待执行结束...扫描目录: %a%, 输出文件名 : waster.log"<<endl;
                mainbatfile << "        dir %a% / s / b | findstr \"tmp temp%sfhyold%\" > %~dp0\\waster.log"<<endl;
                mainbatfile << "        echo 扫描结束"<<endl;
                mainbatfile.close();
                cls(); cout << "完整安装 垃圾清理程序 V1.0 For Windows\n========\n";
                cout << "当前进度: 创建安装数据...\n";
                ofstream mainregedfile("install.ed", ios::out); //以文本模式打开备写
                mainregedfile << "true";
                mainregedfile.close();
                cls(); cout << "完整安装 垃圾清理程序 V1.0 For Windows\n========\n";
                cout << "当前进度: 完成...\n";
                std::cout << "操作成功,5秒后自动重启程序..." << endl;
                Sleep(5000);
                ostringstream oss;
                oss << "start " << __argv[0];
                system(oss.str().c_str());
                exit(0);
            }
            //uninstall
            if (s == ":uninstall"&&getInstallStatus()) {
                string a;
                cout << "确定吗? [Y/N]";
                cin >> a;
                if (a == "n" || a == "N") return 3;
                cls(); cout << "卸载完整安装 垃圾清理程序 V1.0 For Windows\n========\n";
                system("del /f /s /q waster.bat");
                system("del /f /s /q install.ed"); 
                std::cout << "操作成功,5秒后退出程序..." << endl;
                Sleep(5000);
                exit(0);
            }
            std::cout << "错误,请重新输入...\n";
            //return 1;
        } //if
    } //while-loop
//default
            std::cout << "Error\n";
            Sleep(2000);
            return 1;
}

bool getInstallStatus()
{
    ifstream srcFile("install.ed", ios::in); //以文本模式打开in.txt备读
    string ss;
    if (srcFile) srcFile >> ss;
    if (!srcFile || ss != "true") { //打开失
        return false;
    }
    return true;
}
