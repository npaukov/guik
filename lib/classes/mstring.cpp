#include "mstring.h"
#include "string.h"
#include "../functions/functions.h"

const char* guik::mstring::getString() {
   return text;
}

guik::mstring::mstring() {
	text = 0;
	//guik::debug("String Init\n");
	this->setString("");
}

guik::mstring::mstring(const char* str) {
	text = 0;
	//guik::debug("String -> char Init\n");
	this->setString(str);
}

void guik::mstring::setString(const char* txt) {
	//guik::debug("String -> setString\n");

	if (text) {
		delete[] text;
		text = 0;
	}

	text = new char[strlen(txt)+1];

	strcpy(text, txt);

	//guik::debug("String -> endSetString\n");
}

void guik::mstring::operator+=(const char* str) {
   this->addToString(str);
}

void guik::mstring::operator+=(mstring& str) {
   this->addToString(str.getString());
}

guik::mstring& guik::mstring::operator=(const char* str) {
   this->setString(str);
   return *this;
}

guik::mstring& guik::mstring::operator=(mstring& str) {
   this->setString(str.getString());
   return *this;
}

bool guik::mstring::operator== (const guik::mstring& t) const {
	return (strcmp(text, t.text) == 0);
}

bool guik::mstring::operator== (const char* t) const {
	return (strcmp(text, t) == 0);
}

int guik::mstring::getSize() {
    return strlen(text);
}

void guik::mstring::addToString(const char* txt) {
   // Определяем длину новой строки
   int len = strlen(text)+strlen(txt)+1;

   // Копируем существующую строку во временный массив
   char* temp = new char[len];
   strcpy(temp, text);
   // Создаём новую строку
   text = new char[len];

   // Соединяем старую строку с новой
   strcpy(text, temp);
   strcat(text, txt);

   // Удаляём временную строку
   delete[] temp;
}

guik::mstring::~mstring() {
	if (text) {
		delete[] text;
		text = 0;
	}
}
