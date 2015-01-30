#pragma once

namespace guik {

template <typename T>
class Stack
{
private:
    T *stackPtr;                      // указатель на стек
    const int size;                   // максимальное количество элементов в стеке
    int top;                          // номер текущиго элемента стека
public:
    Stack(int = 30);                  // по умолчанию размер стека равен 10 элементам
    Stack(const Stack<T> &);          // конструктор копирования
    ~Stack();                         // деструктор
 
    inline void push(const T & );     // поместить элемент в вершину стека
    inline T pop();                   // удалить элемент из вершины стека и вернуть его
    inline void printStack();         // вывод стека на экран
    inline const T &Peek(int ) const; // n-й элемент от вершины стека
    inline int getStackSize() const;  // получить размер стека
    inline T *getPtr() const;         // получить указатель на стек
    inline int getTop() const;        // получить номер текущего элемента в стеке
};

}