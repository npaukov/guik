#pragma once

namespace guik {
class mstring {
public:
   void setString(const char*);
   void addToString(const char*);
   int getLength();

   void operator+=(const char* str);
   void operator+=(mstring& str);

    operator char*() const {
        return this->text;
    }

   mstring& operator=(const char* str);
   mstring& operator=(mstring& str);

   char* getString();

   mstring();
   mstring(char* str);
   ~mstring();
private:
   char* text;
};

}