#pragma once
namespace guik {

class mstring {
public:
	mstring();
	mstring(const char* str);
	~mstring();

	const char* getString();

	void addToString(const char*);
	void setString(const char*);

    int getSize();

	void operator+=(const char* str);
	void operator+=(mstring& str);

	operator char*() const {
		return this->text;
	}

	mstring& operator=(const char* str);
	mstring& operator=(mstring& str);

	bool operator== (const mstring& t) const;
	bool operator== (const char* t) const;

protected:
	char* text;
};

}
