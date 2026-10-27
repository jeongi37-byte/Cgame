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

typedef struct Obj
{
    int x;
    int y;
    Color color;
    const char* shape;
}Player;

void SetColor(int color);
void SetPosition(int x, int y);
void HideCursor();

Player* player = nullptr;

void Init();
void Update();
void Clear();

int main()
{
    Init();

    HideCursor();

    while (true)
    {
        system("cls");

        Update();

        Sleep(20);
    }

    Clear();
    
    return 0;
}


void Init()
{

    player = (Player*)malloc(sizeof(Player));
    player->x = 10;
    player->y = 10;
    player->color = LIGHT_WHITE;
    player->shape = "бс";
}

void Update()
{
    if (GetAsyncKeyState(VK_LEFT))
    {
        player->x--;
    }

    if (GetAsyncKeyState(VK_RIGHT))
    {
        player->x++;
    }
    if (GetAsyncKeyState(VK_UP))
    {
        player->y--;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        player->y++;
    }

    SetPosition(player->x, player->y);
    SetColor(player->color);
    printf(player->shape);
}

void Clear()
{
    if (player != nullptr)
    {
        free(player);
        player = nullptr;
    }
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
