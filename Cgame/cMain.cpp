#include <stdio.h>
#include <Windows.h>

enum Color
{
    //BLACK,
    BLUE = 1,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    YELLOW,
    LIGHT_GRAY,
    DARK_GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_MAGENTA,
    LIGHT_YELLOW,
    LIGHT_WHITE,
};

struct Obj
{
    int x;
    int y;
    Color color;
    const char* shape;
};

void SetColor(int color);
void SetPosition(int x, int y);
void HideCursor();



int main()
{
    Obj player;
    player.x = 10;
    player.y = 10;
    player.color = LIGHT_WHITE;
    player.shape = "бс";

    HideCursor();

    while (true)
    {
        system("cls");

        SetPosition(player.x, player.y);
        SetColor(player.color);
        printf(player.shape);

        Sleep(20);
    }

    return 0;
}


void SetColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void SetPosition(int x, int y)
{
    COORD pos{ x * 2, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void HideCursor()
{
    CONSOLE_CURSOR_INFO info;
    info.bVisible = false;
    info.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}