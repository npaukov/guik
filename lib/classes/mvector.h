#pragma once

#include "../functions/functions.h"

namespace guik {

template <class T>
class mvector
{
public:
    mvector(unsigned int size);
	mvector();
    int getSize();
	int getAllSize();

    T& operator [](unsigned int i);
	T& getElement(unsigned int i) {
		return this->data[i];
	};
	
	void push(T);

    ~mvector(void);
protected:
	unsigned int size;
	unsigned int lastIndex;
    T* data;
};

template <class  T> 
mvector<T>::mvector(unsigned int Size) {
    this->size = Size;
	this->lastIndex = Size-1;
    data = new T[Size];
}

template <class  T> 
mvector<T>::mvector() {
    this->size = 0;
	this->lastIndex = 0;
    data = 0;
}

template <class  T> 
mvector<T>::~mvector(void) {
    delete [] data;
}

template <class  T>
int mvector<T>::getSize(void) {
	if (size != 0) return lastIndex+1;
	return 0;
}

template <class  T>
int mvector<T>::getAllSize(void) {
    return size;
}

template <class  T>
T& mvector<T>::operator[](unsigned int i){
	//if (i > size-1) return NULL;
    return data[i];
}

template <class T>
void mvector<T>::push(T val){
	if (size == 0 || lastIndex == size-1) {
		int tempSize = size;

		T* temp = new T[tempSize];

		int i = 0;
		for (i=0;i<tempSize;i++) {
			temp[i] = data[i];
		}

		size = size + 5;
		data = new T[size];

		for (i=0;i<tempSize;i++) {
			data[i] = temp[i];
		}

		lastIndex = tempSize;
		data[lastIndex] = val;
	}
	else {
		lastIndex++;
		data[lastIndex] = val;
	}

	//std::cout << "Last index = " << lastIndex << std::endl;

	//return data[lastIndex];
}

}
