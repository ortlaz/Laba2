#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Opz.h"

template <class T>
class Stack {
    T* pstack; //������
    int istack; //���-�� ��������� � �����
	int size; //������������ ����������� �����

    friend class Opz; //����� �������������� ��������� � ���

    //������� �������� � ����
    void push(T x){
      if(istack < size) pstack[istack++] = x;
      else {
        std::cout<<"������������ �����!\n";
      }
    }
    //������� ������� � ������� �����
    T pop(){
        return (istack > 0)? pstack[--istack]: -1;
    }
    //������� ������� �������
    T top(){
	    return (istack > 0)? pstack[istack-1]: -1;
    }

  public:
	Stack(): size(50) {
		istack = 0;
		pstack = new T[size];
	}
    ~Stack() {if(pstack) delete[] pstack;}
};

#endif // STACK_H
