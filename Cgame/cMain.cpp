#include <stdio.h>
#include <Windows.h>

#define ENEMY_COUNT 10

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
}Player, Enemy;

void SetColor(int color);
void SetPosition(int x, int y);
void HideCursor();

Player* player = nullptr;
Enemy* enemies[ENEMY_COUNT] = {};


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

    for (int i = 0; i < ENEMY_COUNT; i++)
    {
        enemies[i] = (Enemy*)malloc(sizeof(Enemy));
        enemies[i]->x = rand() % 35;
        enemies[i]->y = rand() % 35;
        enemies[i]->color = RED;
        enemies[i]->shape = "б▄";

    }
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

    for (int i = 0; i < ENEMY_COUNT; i++)
    {
        SetPosition(enemies[i]->x, enemies[i]->y);
        SetColor(enemies[i]->color);
        printf(enemies[i]->shape);
    }
}

void Clear()
{
    if (player != nullptr)
    {
        free(player);
        player = nullptr;
    }

    for (int i = 0; i < ENEMY_COUNT; i++)
    {
        free(enemies[i]);
        enemies[i] = nullptr;
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
