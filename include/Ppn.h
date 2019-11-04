#ifndef PPN_H
#define PPN_H
#include <string>
#include <stdlib.h>


using namespace std;

class Ppn {
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



#endif // PPN_H
