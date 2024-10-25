#include <windows.h>
#include <iostream>
#include <string>
using namespace std;


int main() {
    const string str = "Hello, world!";
    for (size_t i = 0; i < str.length(); i++)
    {
        cout << str[i];
        Sleep(100);
    }
}