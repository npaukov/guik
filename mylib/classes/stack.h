#pragma once

namespace guik {

template <typename T>
class Stack
{
private:
    T *stackPtr;                      // ��������� �� ����
    const int size;                   // ������������ ���������� ��������� � �����
    int top;                          // ����� �������� �������� �����
public:
    Stack(int = 30);                  // �� ��������� ������ ����� ����� 10 ���������
    Stack(const Stack<T> &);          // ����������� �����������
    ~Stack();                         // ����������
 
    inline void push(const T & );     // ��������� ������� � ������� �����
    inline T pop();                   // ������� ������� �� ������� ����� � ������� ���
    inline void printStack();         // ����� ����� �� �����
    inline const T &Peek(int ) const; // n-� ������� �� ������� �����
    inline int getStackSize() const;  // �������� ������ �����
    inline T *getPtr() const;         // �������� ��������� �� ����
    inline int getTop() const;        // �������� ����� �������� �������� � �����
};

}