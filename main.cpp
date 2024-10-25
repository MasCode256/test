#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <clocale> // ��� setlocale

using namespace std;


class q00 {
	public:
		char lang = 0;
		
		void printLn(vector<string> outv) {
			if(lang < outv.size()) {
				cout << outv[lang] << endl;
			}
		}
		
		void set_lang(char index, string lang) {
			setlocale(LC_ALL, lang.c_str()); // ��� Windows
			lang = index;
		}
} out;


void set_color(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

int main() {
    std::cout << "This string was printed." << std::endl;

    Sleep(2000);
    set_color(12);

    system("cls");
    
    out.set_lang(1, "Russian_Russia.1251");
    out.printLn(std::vector<string>{"Hello, world!", "������, ���!"});

	set_color(7);
    return 0;
}


/*0 � ������
1 � �����
2 � �������
3 � �������
4 � �������
5 � ���������
6 � ������
7 � �����
8 � �����
9 � ������-�����
10 � ������-�������
11 � ������-�������
12 � ������-�������
13 � ������-���������
14 � ������-������
15 � ����-�����*/
