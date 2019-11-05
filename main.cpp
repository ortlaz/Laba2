#include <windows.h>
#include <iostream>
#include "Opz.h"
#include "Stack.h"
#include "List.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    int var;

    while (var){
        system("cls");
        cout<<"����:\n1.���� �� ������ �������.\n2.���� �� ������ ������\n0.�����\n";
        cout<<"�������� �����:";
        cin>>var;

        switch(var){
            case 1:{
                char buf[50];
                string str_in;
                cout << "������� ���������" << endl;
                cin >> buf;                          //get the input string
                if(buf[0] == '0') break;
                str_in = buf;

                Opz ppn;
                ppn.convert(str_in);
                cout << "�������� ������� ������:" << ppn.getOutputStr()<< endl;
                cout<<"���������:"<<ppn.calculate(ppn.getOutputStr())<<endl;
                system("pause");
                break;
			}
			case 2:{
                char buf1[50];
                string strin;
                cout << "������� ���������" << endl;
                cin >> buf1;                          //get the input string
                if(buf1[0] == '0') break;
                strin = buf1;

                Ppn ppn;
                ppn.convert(strin);
                cout << "�������� ������� ������:" << ppn.getOutputStr()<< endl;
                cout<<"���������:"<<ppn.calculate(ppn.getOutputStr())<<endl;
                system("pause");
			    break;
			}
			case 0:{
                exit(0);
                system("pause");
                break;
			}
            default:{
            cout<<"�������� ����� �� ������!\n";
            system("pause");
            }
        }
    }

    return 0;
}

