#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Opz.h"

template <class T>
class Stack {
    T* pstack; //массив
    int istack; //кол-во элементов в стеке
	int size; //максимальная вместимость стека

    friend class Opz; //класс преобразования выражения в ОПЗ

    //вставка элемента в стек
    void push(T x){
      if(istack < size) pstack[istack++] = x;
      else {
        std::cout<<"Переполнение стека!\n";
      }
    }
    //удалить элемент с вершины стека
    T pop(){
        return (istack > 0)? pstack[--istack]: -1;
    }
    //вернуть верхний элемент
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
