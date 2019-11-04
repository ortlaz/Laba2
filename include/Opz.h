#ifndef OPZ_H
#define OPZ_H
#include <string>
#include <stdlib.h>

using namespace std;

class Opz {
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


#endif // OPZ_H
