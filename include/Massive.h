#ifndef MASSIVE_H
#define MASSIVE_H
#include <cstdlib>


class Massive
{
        std::size_t last; //���-�� ��������� � �����
        int *data; //������
        std::size_t max_elem; //������������ ������ �����

    public:

        int pop(void); //���������� � ������� ��������� �������
        void push(int);// ������� ��������
        int size(void);//���������� ������ �����
        bool empty(void);//�������� �� �������


        Massive();
        Massive(int);
        virtual ~Massive();

    private:
        Massive(const Massive&) = delete; //������ ������������ �����
};

#endif // MASSIVE_H
