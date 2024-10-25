#include <windows.h>
#include <iostream>
#include <string>
using namespace std;


int main() {
    const string str = "Hello, world!"; string current = "";

    for (size_t i = 0; i < str.length(); i++)
    {
        for (int j = 0; j < 256; j++)
        {
            if (j == str[i])
            {
                current += char(j);
                cout << current;

                break;
            }
            else {
                cout << current << char(j);
            }

            cout << endl;
            Sleep(1);
        }
    }
}