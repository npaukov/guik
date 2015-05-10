#include "../common.h"
#include "number.h"

template <typename T>
guik::Number<T>::Number() {

}

template <typename T>
guik::Number<T>::~Number() {

}

template <typename T>
void guik::Number<T>::init() {
	Control::init();
}

template <typename T>
void guik::Number<T>::destroy() {
	Control::destroy();
}

template <typename T>
void guik::Number<T>::draw(bool relative) {
	// Рисование налписи
    if (this->visible) {
        bool valueIsPointer = false;
        int nBase = 0;

        T arg1 = ( valueIsPointer ? 1 : 0 ) |
            ( (nBase) << 8 ) |
            ( ( 5 & 0x1F ) << 16 );
        T arg2 = ( this->x << 16 ) | this->y;

        __asm__ __volatile__(
        "int $0x40"
        ::"a"(47),
          "b"(arg1),
          "c"(this->number),
          "d"(arg2),
          "S"(this->textColor));
    }
	// Рисование дочерних элементов
	Control::draw(relative);
}

template <typename T>
T guik::Number<T>::getNumber() {
    return this->number;
}

template <typename T>
void guik::Number<T>::setNumber(T number) {
    this->number = number;
}
