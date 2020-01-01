#include <windows.h>
#include <iostream>
#include "Opz.h"
#include "Stack.h"
#include "List.h"
#include "STLStack.h"

using namespace std;

int main(){

    SetConsoleCP(866);
	SetConsoleOutputCP(866);

    int var;

    while (var){
        system("cls");
        //������� 4
        cout<<"����:\n1.���� �� ������ ������\n2.���� �� ������ �������\n3.���� STL\n0.�����\n";
        cout<<"�������� �����:";
        cin>>var;

        switch(var){
            //������� 2
            case 1:{
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
			case 2:{
			    //������� 1
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
			case 3:{
			    //������� 3
			    char buf2[50];
                string strin_g;
                cout << "������� ���������" << endl;
                cin >> buf2;                          //get the input string
                if(buf2[0] == '0') break;
                strin_g = buf2;

                STLStack ppn;
                ppn.convert(strin_g);
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
            break;
            }
        }
    }

    return 0;
}

