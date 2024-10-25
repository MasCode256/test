#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
#include <clocale> // ƒл€ setlocale

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
			setlocale(LC_ALL, lang.c_str()); // ƒл€ Windows
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
    out.printLn(std::vector<string>{"Hello, world!", "ѕривет, мир!"});

	set_color(7);
    return 0;
}


/*0 Ч „ерный
1 Ч —иний
2 Ч «еленый
3 Ч √олубой
4 Ч  расный
5 Ч ѕурпурный
6 Ч ∆елтый
7 Ч Ѕелый
8 Ч —ерый
9 Ч —ветло-синий
10 Ч —ветло-зеленый
11 Ч —ветло-голубой
12 Ч —ветло-красный
13 Ч —ветло-пурпурный
14 Ч —ветло-желтый
15 Ч ярко-белый*/
