#include "Massive.h"
#include <iostream>
#include <errno.h>
#include <cstring>

Massive::Massive()
{
    max_elem =1;
    last =0;
    data = new int[max_elem];
}
Massive::Massive(int n)
{
    max_elem =n;
    last =0;
    data = new int[max_elem];
}

Massive::~Massive()
{
    delete [] data;
}

int Massive::pop(){
    if(last){
        --last;
        return data[last-1];
    }else return -1;
}
void Massive::push(int value){
    if (last < max_elem)
        data[last++] = value;
    else{
        //если места не достаточно, увеличиваем стек в 2 раза
        int *new_data = new int[max_elem*2];
        memcpy(new_data, data, max_elem*sizeof(int));
        max_elem *=2;

        delete[] data;
        data = new_data;
        data[last++] = value;
    }
}
int Massive::size(){
    return last;
}
bool Massive::empty(){
    return !last;
}


