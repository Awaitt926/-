#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <thread>


using namespace std;
using namespace chrono;

int main() {
    while (true) {
        // ��ȡ��ǰʱ��
        auto now = system_clock::now();
        time_t t = system_clock::to_time_t(now);
        tm local;
        localtime_s(&local, &t);

        // ��ʾ��ǰʱ��
        cout << "\r" << put_time(&local, "%T") << flush;

        // �ȴ� 1 ��
        this_thread::sleep_for(seconds(1));
    }

    return 0;
}
