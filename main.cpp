#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <clocale>

using namespace std;


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void clear_console() {
    system("cls");
}

void set_color(int textColor) {
    SetConsoleTextAttribute(hConsole, textColor);
}

size_t window_width() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    // Ширина окна консоли
    size_t width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void centralized_printLn(const string& str) {
    size_t width = window_width();
    size_t start_pos = (width > str.length()) ? (width / 2 - str.length() / 2) : 0;

    
    for(size_t i = 0; i < start_pos; i++) {
        cout << " ";
    }
    cout << str << endl;
}

void centralized_print(const string& str) {
    size_t width = window_width();
    size_t start_pos = (width > str.length()) ? (width / 2 - str.length() / 2) : 0;


    for(size_t i = 0; i < start_pos; i++) {
        cout << " ";
    }
    cout << str;
}


int main(int argc, char** argv) {
    clear_console();
    set_color(10);
    cout << "Window width: " << window_width() << endl;
    centralized_print("Hello, world!");

    set_color(7);
}