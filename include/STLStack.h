#ifndef STLSTACK_H
#define STLSTACK_H

#include <string>
#include <stdlib.h>


using namespace std;

class STLStack {
    char current;                   //������� ������
	string inputStr, outputStr;     //������� � �������� ������
    int indInpStr;                  //������ ������� ������� ������

    char nextChar();            //��������� ������ ������
	bool isDigit(char c);
    int priorOp(char c);        //��������� ��������

  public:
    void convert(string);       //�������������� � ���
    string getOutputStr();      //�������� ������
    int calculate(string str_in);
};



#endif // STLSTACK_H
