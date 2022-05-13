#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <random>
#include <iostream>
#include <string>

/*
int outlier()
{
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::uniform_int_distribution die{ 20, 50 };

    return die(mersenne);
}
*/

/*
int clicks()
{
    int cps{};
    if (cps == 0) {
        std::cout << "Please choose your CPS: ";
        std::cin >> cps;
        return cps;
    }
    else {
        return cps;
    }
}
*/

int randomisation()
{
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::uniform_int_distribution die{ 2, 4 };

    return die(mersenne);
}
int randomisation2()
{
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::uniform_int_distribution die{ 2, 4 };

    return die(mersenne);
}
int randomisation3()
{
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::uniform_int_distribution die{ 19, 30 };
    if (die(mersenne) == 30)
    {
        int a = rand() % 50 + 30;
        Sleep(a);
    }

    return die(mersenne);
}

void down()
{
    POINT p;
    GetCursorPos(&p);
    SendMessage(GetForegroundWindow(), WM_LBUTTONDOWN, MK_LBUTTON,
        MAKELPARAM(p.x, p.y));
}

void up()
{
    POINT p;
    GetCursorPos(&p);
    SendMessage(GetForegroundWindow(), WM_LBUTTONUP, MK_LBUTTON,
        MAKELPARAM(p.x, p.y));
}

void clicker()
{
    Sleep(randomisation() + randomisation2() * 4);
    down();
    Sleep(randomisation() + randomisation2() * 4);
    up();
}

int main()
{
    while (true)
    {
        if (GetAsyncKeyState(VK_LSHIFT) & 0x8000)
        {
            Sleep(20);
            continue;
        }
        else if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
        {
            clicker();
        }
    }
}