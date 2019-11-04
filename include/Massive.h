#ifndef MASSIVE_H
#define MASSIVE_H
#include <cstdlib>


class Massive
{
        std::size_t last; //кол-во элементов в стеке
        int *data; //массив
        std::size_t max_elem; //максимальный размер стека

    public:

        int pop(void); //возвращает и удаляет последний элемент
        void push(int);// вставка элемента
        int size(void);//возвращает размер стека
        bool empty(void);//проверка на пустоту


        Massive();
        Massive(int);
        virtual ~Massive();

    private:
        Massive(const Massive&) = delete; //запрет конструктора копии
};

#endif // MASSIVE_H
