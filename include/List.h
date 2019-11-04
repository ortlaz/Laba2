#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Ppn.h"

template<typename T>
class List
{
    friend class Ppn;

    public:
        List();
        ~List();

        void push(T data);
        int getSize() {return Size;}
        void removeAt(int index);

        T top() {return (tail)? tail->data : -1;}

        T& operator[](const int index);
        void pop();

    private:
        template<typename U>
        class Node{
        public:
            Node *next;
            U data;
            Node(U data=U(), Node *next = 0){
                this->data = data;
                this->next = next;
            }

        };
        int Size;
        Node<T> *head;
        Node<T> *tail;

};

template<typename T>
List<T>::List()
{
    Size = 0;
    head = 0;
}

template<typename T>
List<T>::~List()
{
    Node<T>* cur = head;
    while(cur){
        cur = head->next;
        delete head;
        head = cur;
    }
}

template<typename T>
void List<T>::push(T data){

     Node<T> *cur = new Node<T>(data);

    if(head == 0){
        head = cur;
    }else{
        tail->next = cur;
    }
    tail = cur;
    Size++;
}

template<typename T>
 T& List<T>::operator[](const int index){
    int cnt = 0;

    Node<T> *cur = this->head;

    while (cur){
        if(cnt == index){
            return cur->data;
        }
        cur = cur->next;
        cnt++;
    }
}

template<typename T>
void List<T>::removeAt(int index){

    if (index == 0){
        Node<T> *temp = head;
        head = head->next;
        tail=head;
        delete temp;
        Size--;
	}
	else
	{
        Node<T> *previous = this->head;

        for(int i = 0; i<index - 1; i++){
            previous = previous->next;
        }

        Node<T> *toDel = previous->next;
        tail = previous;
        previous->next = toDel->next;
        delete toDel;
        toDel=nullptr;
        Size--;
	}
}

 template<typename T>
void List<T>::pop(){
    removeAt(Size-1);
}

#endif // LIST_H
