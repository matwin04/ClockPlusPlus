#include <iostream>
#include <ctime>
#include "raylib.h"
using namespace std;

string getFormattedTime() {
    time_t now = time(nullptr);
    tm* local = localtime(&now);
    strftime(buffer,sizeof(buffer),"%H:%M:%S",local);
    return string(buffer);
}
int main() {

    const int screenW = 800;
    const int screenH = 600;
    InitWindow(screenW,screenH,"ClockPlusPlus");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {

        time_t now = time(nullptr);
        BeginDrawing();
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTextEx(timeStr.c_str)
        EndDrawing();
    }
    CloseWindow();
    time_t timestamp;
    time(&timestamp);
    cout << asctime(localtime(&timestamp));
    cout << "HELLO WORLD\n";
    return 0;
}