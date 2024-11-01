#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <clocale>

using namespace std;


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void clear_console() {
    system("cls");
    return;
}

void set_color(int textColor) {
    SetConsoleTextAttribute(hConsole, textColor);
    return;
}

void set_background(int bgColor, int textColor = 0) {
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
    return;
}

size_t window_width() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

void centralized_printLn(const string& str, size_t width = window_width()) {
    size_t start_pos = (width > str.length()) ? (width / 2 - str.length() / 2) : 0;

    
    for(size_t i = 0; i < start_pos; i++) {
        cout << " ";
    }
    cout << str << endl;
    return;
}

void centralized_print(const string& str, size_t width = window_width()) {
    size_t start_pos = (width > str.length()) ? (width / 2 - str.length() / 2) : 0;


    for(size_t i = 0; i < start_pos; i++) {
        cout << " ";
    }
    cout << str;
    return;
}

void print_line(char c, size_t width = window_width()) {
    for(size_t i = 0; i < width; i++) {
        cout << c;
    }
    return;
}

void endl(size_t count = 1) {
    for (size_t i = 0; i < count; i++)
    {
        cout << endl;
    }
    
    return;
}


int main(int argc, char** argv) {
    clear_console();
    set_color(10);

    size_t width = window_width();
    cout << "Window width: " << width << endl;

    Sleep(100);

    const size_t fake_load_str_len = 60;
    for (size_t i = 0; i < fake_load_str_len; i++)
    {
        clear_console();

        print_line('_', width);
        endl(3);

        string load_str = "["; 
        for (size_t j = 0; j < fake_load_str_len; j++)
        {
            if(j <= i) {
                load_str += "#";
            } else {
                load_str += ".";
            }
        }
        
        load_str += "]";


        centralized_printLn("Fake loading process...", width);
        centralized_printLn(load_str, width);

        //Sleep(1);
    }
    

    centralized_print("#vivatC++", window_width());
    endl(2); print_line('-', width);
    endl(2);

    set_color(7);
}