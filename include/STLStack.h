#ifndef STLSTACK_H
#define STLSTACK_H

#include <string>
#include <stdlib.h>


using namespace std;

class STLStack {
    char current;                   //текущий символ
	string inputStr, outputStr;     //входная и выходная строки
    int indInpStr;                  //индекс символа входной строки

    char nextChar();            //следующий символ строки
	bool isDigit(char c);
    int priorOp(char c);        //приоритет операций

  public:
    void convert(string);       //преобразование в ОПЗ
    string getOutputStr();      //выходная строка
    int calculate(string str_in);
};



#endif // STLSTACK_H
