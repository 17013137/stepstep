#include <iostream>
#include<string.h>
#include<algorithm>

class Mystring {
	char* str_con;
	int str_len;
	int memory_capacity;

	public :
		Mystring(char c);
		Mystring(const char* str);
		Mystring(const Mystring& str);
		~Mystring();

		int length() const;
		int capacity() const;
		void reserve(int size);
		void print() const;
		void println() const;

		Mystring& assign(const Mystring& str);
		Mystring& assign(const char *str);
		Mystring& insert(int loc, Mystring& str);
		Mystring& insert(int loc, char c);
		Mystring& insert(int loc, const char* str);
		Mystring& erase(int loc, int num);

		int find(int find_from, const Mystring& str) const;
		int find(int find_from, const char* str) const;
		int find(int find_from, char c) const;

		int compare(const Mystring& str) const;
};

int Mystring::compare(const Mystring& str) const {
	for (int i = 0; i < std::min(str_len, str.str_len); i++) {
		if (str_con[i] > str.str_con[i]) {
			return 1;
		}
		else if (str_con[i] < str.str_con[i]) {
			return -1;
		}
	}
	if (str_len > str.str_len) {
		return -1;
	}
	else if (str_len < str.str_len) {
		return 1;
	}
	else return 0;
}

int Mystring::find(int find_from, const Mystring& str) const {
	if (str.str_len == 0)
		return -1;
	int i, j;
	for (i = find_from; i < str_len - str.str_len; i++) {
		for (j = 0; j < str.str_len; j++) {
			if (str.str_con[j] != str_con[i + j])
				break;
		}
		if (str.str_len == j)
			return i;
	}

	return -1;
}

Mystring& Mystring::erase(int loc, int num) {
	
	for (int i = loc + num; i < str_len; i++) {
		str_con[i - num] = str_con[i];
	}
	str_len -= num;
	return *this;
}

int Mystring::find(int find_from, const char* str) const {
	Mystring temp(str);
	return find(find_from, temp);
}

int Mystring::find(int find_from, char c) const {
	Mystring temp(c);
	return find(find_from, temp);
}

Mystring& Mystring::insert(int loc, Mystring& str) {
	if (loc < 0 || loc > str_len) return *this;

	if (str_len + str.str_len > memory_capacity) {
		memory_capacity = str_len + str.str_len;

		char* prev_str_con = str_con; //내용을 옮기는 작업임. 
		str_con = new char[memory_capacity]; //새로 배열선언할때 내용이 초기화되나?? (그러니까 위에 내용을 옮기는 작업을 한거인듯.)
		int i;
		for (i = 0; i < loc; i++) {
			str_con[i] = prev_str_con[i];
		}

		for (int j = 0; j < str.str_len; j++) {
			str_con[i + j] = str.str_con[j];
		}

		for (; i < str_len; i++) {
			str_con[i + str.str_len] = prev_str_con[i];
		}

		delete[] prev_str_con;

		str_len = memory_capacity;
		return *this;
	}
		for (int i = str_len - 1; i >= loc; i--) {// 배열 안 숫자 카운팅용
			str_con[i + str.str_len] = str_con[i]; // 글자 밀어내기
		}
		for (int i = 0; i < str.str_len; i++) {	//배열 안 숫자 카운팅
			str_con[i + loc] = str.str_con[i];	//loc는 위치순서임.
		}

		str_len += str.str_len;

		return *this;
}
Mystring& Mystring::insert(int loc, char c) {
	Mystring temp(c);

	return insert(loc, temp);
}
Mystring& Mystring::insert(int loc, const char* str) {
	Mystring temp(str);
	return insert(loc, temp);
}

int Mystring::capacity() const{
	return memory_capacity;
}

void Mystring::reserve(int size) {
	if (size > memory_capacity) {
		char* prev_string_content = str_con;
		str_con = new char[size];
		memory_capacity = size;

		for (int i = 0; i != str_len; i++) {
			str_con[i] = prev_string_content[i];
		}

		delete[] prev_string_content;
	}
}
Mystring::Mystring(char c) {
	str_con = new char[1];
	str_con[0] = c;
	str_len = 1;
}
Mystring::Mystring(const char *str) {
	int len = 0;
	for (int i = 0; ; i++) {
		if (str[i] == '\0') {
			len = i;
			break;
		}
	}
	str_con = new char[len];
	str_len = len;

	for (int i = 0; i < len; i++) {
		str_con[i] = str[i];
	}
}
Mystring::Mystring(const Mystring& str) {
	str_len = str.str_len;
	str_con = new char[str_len];
	for (int i = 0; i < str_len; i++) {
		str_con[i] = str.str_con[i];
	}
}
Mystring::~Mystring() {
	delete[] str_con;
}
int Mystring::length() const{
	return str_len;
}
void Mystring::print() const {
	for (int i = 0; i < str_len; i++) {
		std::cout << str_con[i];
	}
}
void Mystring::println() const {
	for (int i = 0; i < str_len; i++) {
		std::cout << str_con[i];
	}
	std::cout << std::endl;
}
Mystring& Mystring::assign(const Mystring& str) {
	if (str.str_len > str_len) {
		delete[] str_con;

		str_con = new char[str.str_len];
	}
	str_len = str.str_len;
	for (int i = 0; i != str_len; i++) {
		str_con[i] = str.str_con[i];
	}

	return *this;
}
Mystring& Mystring::assign(const char *str) {
	int length = strlen(str);
	if (length > str_len) {
		delete[] str_con;

		str_con = new char[length];
	}
	for (int i = 0; i != length; i++) {
		str_con[i] = str[i];
	}
	str_len = length;

	return *this;
}

int main() {
	Mystring str1("very very very long string");
	Mystring str2(" much ");
	str1.reserve(30);

	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;
	str1.println();

	str1.insert(4, str2);
	str1.println();
	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.length() << std::endl;

	str1.erase(4, 6);
	str1.println();

	std::cout << "Location of first<long> in the string : " << str1.find(0, "long") << std::endl;


}
