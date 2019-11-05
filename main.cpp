#include <windows.h>
#include <iostream>
#include "Opz.h"
#include "Stack.h"
#include "List.h"
#include "STLStack.h"

using namespace std;

int main(){

    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    int var;

    while (var){
        system("cls");
        cout<<"Меню:\n1.Стек на основе списка\n2.Стек на основе массива\n3.Стек STL\n0.Выход\n";
        cout<<"Выберите опцию:";
        cin>>var;

        switch(var){
            case 1:{
               char buf1[50];
                string strin;
                cout << "Введите выражение" << endl;
                cin >> buf1;                          //get the input string
                if(buf1[0] == '0') break;
                strin = buf1;

                Ppn ppn;
                ppn.convert(strin);
                cout << "Обратная польска запись:" << ppn.getOutputStr()<< endl;
                cout<<"Результат:"<<ppn.calculate(ppn.getOutputStr())<<endl;
                system("pause");
			    break;
			}
			case 2:{
			     char buf[50];
                string str_in;
                cout << "Введите выражение" << endl;
                cin >> buf;                          //get the input string
                if(buf[0] == '0') break;
                str_in = buf;

                Opz ppn;
                ppn.convert(str_in);
                cout << "Обратная польска запись:" << ppn.getOutputStr()<< endl;
                cout<<"Результат:"<<ppn.calculate(ppn.getOutputStr())<<endl;
                system("pause");
                break;

			}
			case 3:{
			    char buf2[50];
                string strin_g;
                cout << "Введите выражение" << endl;
                cin >> buf2;                          //get the input string
                if(buf2[0] == '0') break;
                strin_g = buf2;

                STLStack ppn;
                ppn.convert(strin_g);
                cout << "Обратная польска запись:" << ppn.getOutputStr()<< endl;
                cout<<"Результат:"<<ppn.calculate(ppn.getOutputStr())<<endl;
                system("pause");
                break;
			}
			case 0:{
                exit(0);
                system("pause");
                break;
			}
            default:{
            cout<<"Выберите опцию из списка!\n";
            system("pause");
            break;
            }
        }
    }

    return 0;
}

