#include "string.h"

#include "../functions/string.h"

namespace guik {

mstring::mstring() : text(NULL) {

}

mstring::mstring(char* str) {
   this->setString(str);
}

void mstring::setString(const char* txt) {
   text = new char[gstrlen(txt)+1];
   gstrcpy(text, txt);
}

void mstring::operator+=(const char* str) {
   this->addToString(str);
}

void mstring::operator+=(mstring& str) {
   this->addToString(str.getString());
}

mstring& mstring::operator=(const char* str) {
   this->setString(str);
   return *this;
}

mstring& mstring::operator=(mstring& str) {
   this->setString(str.getString());
   return *this;
}

void mstring::addToString(const char* txt) {
   // Определяем длину новой строки
   int len = gstrlen(text)+gstrlen(txt)+1;

   // Копируем существующую строку во временный массив
   char* temp = new char[len];
   gstrcpy(temp, text);
   // Создаём новую строку
   text = new char[len];

   // Соединяем старую строку с новой
   gstrcpy(text, temp);
   gstrcat(text, txt);

   // Удаляём временную строку
   delete[] temp;
}

char* mstring::getString() {
   return text;
}

int mstring::getLength() {
	return gstrlen(text);
}

mstring::~mstring() {
   delete[] text;
}

}