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


	//TODO: доделать меню
        //  исправить костыль
        //  сделать стек на основе списка
	/*	while(1) {
			try {
		       char buf[50];
		       string str_in;
		       cout << "Введите выражение" << endl;
                cin >> buf;                          //get the input string
			   if(buf[0] == '0') break;
		       str_in = buf;
               Opz ppn;
		       ppn.convert(str_in);
		       cout << '\n' << ppn.getOutputStr() << '\n' << endl;
		       cout<<ppn.calculate(ppn.getOutputStr())<<endl;

			}
			catch(string exc) {
		       cout << exc << '\n' << endl;
			}
		}
		*/

    List<int> lst;

    lst.push(1);
    lst.push(11);
    lst.push(15);

    for (int i=0; i<lst.getSize(); i++){
        cout<< lst[i]<<endl;
    }

    cout<<"TOP:"<<lst.top()<<endl;

    lst.pop();
    for (int i=0; i<lst.getSize(); i++){
        cout<< lst[i]<<endl;
    }
    return 0;
}

