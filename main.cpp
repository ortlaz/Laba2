#include <windows.h>
#include <iostream>
#include "Opz.h"
#include "Stack.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

		while(1) {
			try {
		       char buf[50];
		       string str_in;
		       cout << "¬ведите выражение" << endl;
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


    return 0;
}

