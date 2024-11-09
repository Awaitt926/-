#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <windows.h>
#include <thread>

// 定义控制台窗口大小和颜色
const int CONSOLE_WIDTH = 80;
const int CONSOLE_HEIGHT = 25;
const int TEXT_COLOR = 12; // 红色

// 设置光标位置函数
void setCursorPosition(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 输出一行分割线
void printLine() {
    std::cout << std::string(CONSOLE_WIDTH, '-') << std::endl;
}

int main() {
    // 设置控制台字体颜色
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, TEXT_COLOR);

    // 设置控制台窗口大小
    SMALL_RECT srctWindow = { 0, 0, CONSOLE_WIDTH - 1, CONSOLE_HEIGHT - 1 };
    SetConsoleWindowInfo(handle, TRUE, &srctWindow);

    // 清屏
    system("cls");

    while (true) {
        // 获取当前时间
        auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

        // 输出时间
        setCursorPosition(0, 0);
        std::cout << "Current time: " << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S") << std::endl;

        // 输出分割线
        printLine();

        // 延迟1秒
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
