#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <windows.h>
#include <thread>

// �������̨���ڴ�С����ɫ
const int CONSOLE_WIDTH = 80;
const int CONSOLE_HEIGHT = 25;
const int TEXT_COLOR = 12; // ��ɫ

// ���ù��λ�ú���
void setCursorPosition(int x, int y) {
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// ���һ�зָ���
void printLine() {
    std::cout << std::string(CONSOLE_WIDTH, '-') << std::endl;
}

int main() {
    // ���ÿ���̨������ɫ
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, TEXT_COLOR);

    // ���ÿ���̨���ڴ�С
    SMALL_RECT srctWindow = { 0, 0, CONSOLE_WIDTH - 1, CONSOLE_HEIGHT - 1 };
    SetConsoleWindowInfo(handle, TRUE, &srctWindow);

    // ����
    system("cls");

    while (true) {
        // ��ȡ��ǰʱ��
        auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

        // ���ʱ��
        setCursorPosition(0, 0);
        std::cout << "Current time: " << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S") << std::endl;

        // ����ָ���
        printLine();

        // �ӳ�1��
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
