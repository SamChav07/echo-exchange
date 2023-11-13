#include <iostream>

void gotoxy(int x, int y)
{
    std::cout << "\033[" << y << ";" << x << "H";
}