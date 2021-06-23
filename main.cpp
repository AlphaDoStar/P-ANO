#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

void setCursor(int bVisible) {
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = bVisible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int key_in(void) {
    int key;

    if (kbhit()) {
        key = getch();
        return key;
    }

    return 0;
}

void out_sound(int key) {
    char path[128];

    sprintf(path, "%s%d%s", "sound\\sound", key, ".wav");
    PlaySoundA(path, NULL, SND_FILENAME | SND_ASYNC);
}

int main(void) {
    int key;

    system("title P-ANO");
    system("mode con cols=36 lines=12");
    system("color 0f");
    setCursor(0);

    printf("\n\n      _______________________\n");
    printf("     | | | | | | | | | | | | |\n");
    printf("     | |_| |_| | |_| |_| |_| |\n");
    printf("     | 1| 2 |3 | 4| 5 | 6 |7 |\n");
    printf("     |__|___|__|__|___|___|__|\n\n");
    printf("     [Silent] SPACE\n");
    printf("     [Exit] 0");

    while (true) {
        key = key_in();

        if (key > 48 && key < 57) {
            out_sound(key - 48);
        }

        if (key == 32) {
            PlaySound(NULL, 0, 0);
        }

        if (key == 48) {
            system("cls");
            printf("\n\n\n\n\n     < Project C/C++ #1 P-ANO >");
            getch();
            break;
        }
    }

    return 0;
}