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
    //�ж��ļ��Ƿ�������
    if (inFile) {
        //�� in.txt �ļ��ж�ȡһ���ַ�������಻���� 39(40-1) ��
        inFile.getline(c, 6);
        if (c == "true") ra = "start ";
    }
    inFile.close();*/
    oss << "start " << "waster " << endl << "exit";
    system(oss.str().c_str());
    system("cls");
    std::cout << "ɨ�����,3��󷵻���ҳ..." << endl << "exit";
    //Sleep(3000);
}

void scan(string path) {
    system("cls");
    ostringstream oss;
    oss << "start " << "waster " << path << endl << "exit";
    system(oss.str().c_str());
    system("cls");
    std::cout << "ɨ�����,3��󷵻���ҳ..." << endl << "exit";
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
    std::cout << "���������,3��󷵻���ҳ..." << endl;
    Sleep(3000);
    return 0;
}

int scan(int method, bool ttt, bool fff) {
    char c[10000];
    ifstream log("waster.log", ios::in);
    while (log.getline(c, 9999)) {
        //�ļ���=char c
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
        ifstream inFile(c, ios::in | ios::binary); //�����ƶ���ʽ��
        if (!inFile) {
            inFile.close();
            continue;
        }
        inFile.close();
        ostringstream oss; ostringstream oss2;
        if (method == 1) {
            std::cout << "\n" << c << " ,�Ƿ�ɾ��? [Y,N]";
            char s = _getche();
            if (s == 'y' || s == 'Y') {
                oss << "del /f /s /q \"" << c << "\"";
                oss2 << "rd /s /q \"" << c << "\"";
                system(oss.str().c_str());
                system(oss2.str().c_str());
                std::cout << "������: " << endl << oss.str() << endl << oss2.str() << endl;
                continue;
            }
            if(s=='n'||s=='N') continue;
            std::cout << "�������!" << endl;
        }
        if (method == 2) {
            oss << "del /f /s /q \"" << c << "\"";
            oss2 << "rd /s /q \"" << c << "\"";
            system(oss.str().c_str());
            system(oss2.str().c_str());
            std::cout << "������: " << endl << oss.str() << endl << oss2.str() << endl;
            continue;
        }
        if (method == 3) {
            system("mkdir %SYSTEMDRIVE%\\Trush\\ 2>nul");
            oss << "move /Y \"" << c << "\" %SYSTEMDRIVE%\\Trush\\";
            std::cout << "������: " << endl << oss.str() << endl << "������ļ�:" << c << endl;
            system(oss.str().c_str());
            continue;
        }
    }
    log.close();
    std::cout << "������,3��󷵻���ҳ..." << endl;
    Sleep(3000);
    return 0;
}

int scan(bool isOption) {
    system("cls");
    if (!isOption) return 1;
    std::cout << "�ѷ��ֵ������ļ�:" << endl;
    system("type waster.log");
    std::cout << endl << "========" << endl << "��ʾ:����ʹ�ù���Ա��ݽ������" << endl << "�Ƿ�����? [Y/N]";
    char s = _getche();
    if (s == 'n' || s == 'N') {
        std::cout << "���������,3��󷵻���ҳ..." << endl;
        Sleep(3000);
        return 0;
    }
    if (s == 'y' || s == 'Y') {
        std::cout << "��ѡ������ʽ\n1.��Ҫȷ��\n2.ֱ��ɾ��\n3.�ƶ���%SYSTEMDRIVE%\\Trush\\\n��ѡ��: ";
        char us = _getche();
        //system("CLS");
        if (us != '1' && us != '2' && us != '3') {
            std::cout << "\n�������,3��󷵻���ҳ..." << endl;
            Sleep(3000);
            return 1;
        }
        std::cout << endl;
        if (us == '1') scan(1, true, true);
        if (us == '2') scan(2, true, true);
        if (us == '3') scan(3, true, true);
        std::cout << "���������,3��󷵻���ҳ..." << endl;
        Sleep(3000);
        return 0;
    }
    return 0;
}

void ScanSettings(char id) {
    cls();
    switch (id) {
        /*case '1':{
            std::cout << "�Ƿ�ʼ�����´��ڴ��ļ�ɨ����?\n0:true\n1:false\nYour select:";
            char s = _getche();
            if (s == '1') {
                system("cd settings&echo true > openasnew");
            break;
            }
            if (s == '0') {
                system("cd settings&echo false > openasnew");
            break;
            }
            std::cout << "����,3��󷵻�...";
            std::cout << "\n��������=>���벻����";
            Sleep(3000);
            return;
        }*/
    default: {
        std::cout << "����,3��󷵻�...";
        Sleep(3000);
        return;
    }
    };
    std::cout << "\n�ɹ�,2��󷵻�..." << endl;
    Sleep(2000);
    return;
}
void ScanSettings() {
    system("mkdir settings");
    while (1) {
        cls();
        std::cout <<
            "��                                             ��" << endl <<
            "=================================================" << endl <<
            "0. ����" << endl <<
            /*"1. ʼ�����´��ڴ��ļ�ɨ����" <<*/ endl;//<<;
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
            std::cout << "����������� V1.0 For Windows" << endl;
            std::cout << "=================================================" << endl;
            std::cout << "�߼����� - ��1/1ҳ" << endl;
            std::cout << ":c ���ɨ����" << endl;
            std::cout << ":cls �����Ļ" << endl;
            std::cout << ":fd ǿ��ɾ��(ɾ�������ѷ��ֵ������ļ�)" << endl;
            std::cout << ":fs ǿ��ɨ��(��������: old chk log gid)" << endl;
            //std::cout << ":h �鿴����" << endl;
            if(!getInstallStatus()) std::cout << ":install ����������װ" << endl;
            std::cout << ":q �˳�" << endl;
            std::cout << ":r ����" << endl;
            if(getInstallStatus()) std::cout << ":uninstall ж��������װ(��ж�ػ�����װ)" << endl;
            //std::cout << "4. �������н��������" << endl;
            std::cout << "(��ʾ: �߼��������ִ�Сд,������Ҫ����ð��)\n";
            std::cout << "��ѡ��: ";
            string s;
            cin >> s;
            //system("cls");
            std::cout << "\n==================================================" << endl;
            if (s == ":q") exit(0);
            if (s == ":r") return 0;
            if (s == ":c") {
                system("del /f /s /q waster.log");
                std::cout << "\n�ɹ�,2��󷵻�..." << endl;
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
                cout << "����ɨ��Ŀ¼:";
                cin >> path;
                oss << "start " << "waster \"" << path << "\" --searchall" << endl << "exit";
                system(oss.str().c_str());
                system("cls");
                std::cout << "ɨ�����,3��󷵻���ҳ..." << endl;
                //Sleep(3000);
                return 0;
            }
            //install
            if (s == ":install"&&!getInstallStatus()) {
                cls(); cout << "������װ ����������� V1.0 For Windows\n========\n";
                cout << "��ǰ����: ��װwaster.bat...\n";
                ofstream mainbatfile("waster.bat", ios::out); //���ı�ģʽ�򿪱�д
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
                mainbatfile << "        echo �����ļ�ɨ����"<<endl;
                mainbatfile << "        echo ========"<<endl;
                mainbatfile << "        echo."<<endl;
                mainbatfile << "        echo ɨ����......"<<endl;
                mainbatfile << "        echo."<<endl;
                mainbatfile << "        echo ��ȴ�ִ�н���...ɨ��Ŀ¼: %a%, ����ļ��� : waster.log"<<endl;
                mainbatfile << "        dir %a% / s / b | findstr \"tmp temp%sfhyold%\" > %~dp0\\waster.log"<<endl;
                mainbatfile << "        echo ɨ�����"<<endl;
                mainbatfile.close();
                cls(); cout << "������װ ����������� V1.0 For Windows\n========\n";
                cout << "��ǰ����: ������װ����...\n";
                ofstream mainregedfile("install.ed", ios::out); //���ı�ģʽ�򿪱�д
                mainregedfile << "true";
                mainregedfile.close();
                cls(); cout << "������װ ����������� V1.0 For Windows\n========\n";
                cout << "��ǰ����: ���...\n";
                std::cout << "�����ɹ�,5����Զ���������..." << endl;
                Sleep(5000);
                ostringstream oss;
                oss << "start " << __argv[0];
                system(oss.str().c_str());
                exit(0);
            }
            //uninstall
            if (s == ":uninstall"&&getInstallStatus()) {
                string a;
                cout << "ȷ����? [Y/N]";
                cin >> a;
                if (a == "n" || a == "N") return 3;
                cls(); cout << "ж��������װ ����������� V1.0 For Windows\n========\n";
                system("del /f /s /q waster.bat");
                system("del /f /s /q install.ed"); 
                std::cout << "�����ɹ�,5����˳�����..." << endl;
                Sleep(5000);
                exit(0);
            }
            std::cout << "����,����������...\n";
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
    ifstream srcFile("install.ed", ios::in); //���ı�ģʽ��in.txt����
    string ss;
    if (srcFile) srcFile >> ss;
    if (!srcFile || ss != "true") { //��ʧ
        return false;
    }
    return true;
}
