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
    system("title ����������� V1.0");
    bool isinst = getInstallStatus();
    while (1) {
        cout << "����������� V1.0 " ;
        if(isinst) cout << "������" << endl;
        if(!isinst) cout << "������" << endl;
        cout << "                   For Windows" << endl;
        cout << "=================================================" << endl;
        cout << "��ѡ����Ҫ���еĲ���" << endl;
        cout << "0. �˳�" << endl;
        cout << "1. ����ϵͳ��ɨ�����" << endl;
        cout << "2. �����Զ���ɨ�����" << endl;
        if(!isinst) cout << "����: ����ɨ�������Ҫ������װ������������װ������ : ,Ȼ������ :install ��" << endl;
        cout << "3. �������н��" << endl;
        cout << "4. �������н��������" << endl;
        cout << "5. ˢ��" << endl;
        cout << "6. �Թ���Ա������´�" << endl;
        cout << "7. ����" << endl;
        cout << "8. ��һҳ" << endl;
        cout << "9. ��һҳ" << endl;
        cout << ":. �߼�����" << endl;
        cout << "��ѡ��: ";
        char s = _getche();
        //system("cls");
        cout << "\n==================================================" << endl;
        if (s == '0') return 0;
        if (s == '1') scan();
        if (s == '2') {
            string u;
            cout << "������Ҫɨ���Ŀ¼: ";
            cin >> u;
            scan(u);
        }
        if (s == '3') {
            string u;
            cout << "���浽? ";
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
            //cout << "����,����������" << endl;
            //cout << "2��󷵻���ҳ..." << endl;
            //Sleep(2000);
            system("cls");
        }
        continue;
    };
    return 0;
}

