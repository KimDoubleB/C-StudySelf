#include "String.h"
String::String() {
	len = 0;
	str = NULL;
}
String::String(const char * s) {
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}
String::String(const String& s) {
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}
String::~String() {
	if (str != NULL)
		delete[] str;
}
String& String::operator=(const String& s) {
	if (str != NULL)
		delete[] str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);

	return *this;
}
String& String::operator+=(const String& s) {
	len += (s.len - 1);
	char* temp = new char[len];
	strcpy(temp, str);
	strcat(temp, s.str);

	if (str != NULL)
		delete[] str;
	str = temp;
	return *this;
}
bool String::operator==(const String& s) {
	return (strcmp(str, s.str) == 0) ? true : false;
}
String String::operator+(const String& s) {
	char* temp = new char[len + s.len - 1];
	strcpy(temp, str);
	strcat(temp, s.str);

	String tempStr(temp);
	delete[] temp;
	return tempStr;
}

ostream& operator<< (ostream& os, const String& s) {
	os << s.str;
	return os;
}
istream& operator>> (istream& os, String& s) {
	char temp[NAME_LENGTH];
	// A name including spacing words.
	cin.get();
	os.getline(temp, NAME_LENGTH); // getline allows up to spacing words.
	
	s = String(temp);
	return os;
}