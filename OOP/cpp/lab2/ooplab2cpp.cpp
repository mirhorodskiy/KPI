#include <iostream>
#include <vector>
#include <set>
using namespace std;

class MyString {
public:
	MyString(const char* string) {
		length = strlen(string);
		this->string = new char[length + 1];
		memcpy(this->string, string, length + 1);
	}
	int getStringLength() {
		return length;
	}

	char* getString() {
		return string;
	}

	void deleteFirstSpace() {
		if (string[0] == ' ') {
			char* tmp = new char[length];
			for (int i = 0; i < length; i++)
				tmp[i] = string[i + 1];
			delete[] string;
			string = new char[length];
			string = tmp;
			length--;
		}
	}

	void deleteLastSpace() {
		if (string[length - 1] == ' ') {
			string[length - 1] = '\0';
			length--;
		}
	}

	int findCoupleSpaces() {
		for (int i = 0; i < length - 1; i++)
			if (string[i] == ' ' && string[i + 1] == ' ')
				return i;
		return -1;
	}

	void deleteCoupleSpaces() {
		while (findCoupleSpaces() != -1) {
			int pos = findCoupleSpaces();
			int t = 0;
			char* tmp = new char[length];
			for (int i = 0; i < length; i++) {
				if (i == pos)
					t++;
				tmp[i] = string[i + t];
			}
			delete[] string;
			string = new char[length];
			string = tmp;
			length--;
		}
	}

	int countConsonants() {
		int count = 0;
		set <char> consonants = { 'q','w','r','t','p', 's', 'd', 'f', 'g', 'h', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
		for (int i = 0; i < length; i++)
			if (consonants.find(string[i]) != consonants.end())
				count++;
		return count;
	}

private:
	char* string;
	int length;
};

class Text {
public:
	void addStr(MyString str) {
		text.push_back(str);
	}

	void printText() {
		for (int i = 0; i < text.size(); i++)
			cout << text[i].getString() << endl;
	}

	void deleteStr(MyString str) {
		for (int i = 0; i < text.size(); i++) {
			if (strcmp(text[i].getString(), str.getString()) == 0) {
				text.erase(text.begin() + i);
				break;
			}
		}
	}
	void deleteFirstSpaces() {
		for (int i = 0; i < text.size(); i++)
			text[i].deleteFirstSpace();
	}

	void deleteLastSpaces() {
		for (int i = 0; i < text.size(); i++)
			text[i].deleteLastSpace();
	}

	void deleteSpaces() {
		for (int i = 0; i < text.size(); i++)
			text[i].deleteCoupleSpaces();
	}

	int persentOfConsonants() {
		int countConsonants = 0;
		int all = 0;
		for (int i = 0; i < text.size(); i++) {
			countConsonants += text[i].countConsonants();
			all += text[i].getStringLength();
		}
		return countConsonants*100/all;
	}

	int getTheShortestLength() {
		int shortestLength = text[0].getStringLength();
		for (int i = 1; i < text.size(); i++)
			if (text[i].getStringLength < shortestLength)
				shortestLength = text[i].getStringLength();
		return shortestLength;
	}
private:
	vector <MyString> text;
};

int main()
{
	MyString str1("Second    text line");
	Text text1;
	text1.addStr(" First text line ");
	text1.addStr(str1);
	text1.addStr(" Third text line");

	text1.printText();
	cout << "=======================================\n";
	cout << "Percent of consonants letters in text: " << text1.persentOfConsonants() << "%\n";
	text1.deleteFirstSpaces();
	cout << "Spaces on the start were deleted\n";
	text1.deleteLastSpaces();
	cout << "Spaces in the end were deleted\n";
	text1.printText();
	cout << "=======================================\n";
	text1.deleteSpaces();
	cout << "Repetitive spaces were deleted\n";
	text1.printText();
	cout << "=======================================\n";
	cout <<"Percent of consonants letters in text: "<< text1.persentOfConsonants()<<"%\n";
}