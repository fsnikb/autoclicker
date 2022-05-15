#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include <random>
#include <iostream>
#include <string>
#include <cstdlib>

int outlier(void)
{
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::uniform_int_distribution die{ 150, 200 };
    if (die(mersenne) == 200)
    {
        Sleep(die(mersenne));
    }

    return die(mersenne);
}

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
    std::uniform_int_distribution die{25, 31 };

    return die(mersenne);
}

/*
int randomisation2()
{
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::uniform_int_distribution die{ 5, 7 };

    return die(mersenne);
}
*/
/*
int randomisation3()
{
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::uniform_int_distribution die{ 5, 7 };


    return die(mersenne);
}
*/

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
    outlier();
    Sleep(randomisation());
    down();
    Sleep(randomisation());
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