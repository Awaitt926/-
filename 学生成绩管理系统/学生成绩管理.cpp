#include <iostream>
#include <string>
using namespace std;

const int MAX_NUM_STUDENTS = 50;

struct Student {
    string name;
    int id;
    double grade;
};

// 显示菜单
void showMenu() {
    cout << "----------------------------------" << endl;
    cout << "  1. 显示所有学生信息" << endl;
    cout << "  2. 添加学生信息" << endl;
    cout << "  3. 修改学生信息" << endl;
    cout << "  4. 删除学生信息" << endl;
    cout << "  5. 查找学生信息" << endl;
    cout << "  6. 计算平均成绩" << endl;
    cout << "  0. 退出" << endl;
    cout << "----------------------------------" << endl;
    cout << "请选择操作（输入数字）：";
}

// 显示所有学生信息
void showAllStudents(Student students[], int num_students) {
    cout << "学生信息如下：" << endl;
    for (int i = 0; i < num_students; i++) {
        cout << "姓名：" << students[i].name << endl;
        cout << "学号：" << students[i].id << endl;
        cout << "成绩：" << students[i].grade << endl;
        cout << "-----------------------" << endl;
    }
}

// 添加学生信息
void addStudent(Student students[], int& num_students) {
    if (num_students >= MAX_NUM_STUDENTS) {
        cout << "学生人数已达上限，无法添加新的学生信息！" << endl;
        return;
    }
    cout << "请输入学生姓名：";
    getline(cin, students[num_students].name);
    cout << "请输入学生学号：";
    cin >> students[num_students].id;
    cout << "请输入学生成绩：";
    cin >> students[num_students].grade;
    cin.ignore(); // 忽略cin输入流中的换行符
    num_students++;
    cout << "添加学生信息成功！" << endl;
}

// 修改学生信息
void modifyStudent(Student students[], int num_students) {
    int id;
    cout << "请输入需要修改信息的学生学号：";
    cin >> id;
    bool found = false;
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            found = true;
            cout << "请输入修改后的学生姓名（按回车不修改）：";
            getline(cin, students[i].name);
            cout << "请输入修改后的学生成绩（按回车不修改）：";
            string input;
            getline(cin, input);
            if (!input.empty()) {
                students[i].grade = stod(input);
            }
            cout << "修改学生信息成功！" << endl;
            break;
        }
    }
    if (!found) {
        cout << "没有找到该学号对应的学生信息！" << endl;
    }
}

// 删除学生信息
void deleteStudent(Student students[], int& num_students) {
    int id;
    cout << "请输入需要删除信息的学生学号：";
    cin >> id;
        bool found = false;
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            found = true;
            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_students--;
            cout << "删除学生信息成功！" << endl;
            break;
        }
    }
    if (!found) {
        cout << "没有找到该学号对应的学生信息！" << endl;
    }
}

// 查找学生信息
void searchStudent(Student students[], int num_students) {
    int id;
    cout << "请输入需要查找信息的学生学号：";
    cin >> id;
    bool found = false;
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            found = true;
            cout << "学生信息如下：" << endl;
            cout << "姓名：" << students[i].name << endl;
            cout << "学号：" << students[i].id << endl;
            cout << "成绩：" << students[i].grade << endl;
            break;
        }
    }
    if (!found) {
        cout << "没有找到该学号对应的学生信息！" << endl;
    }
}

// 计算平均成绩
void calculateAverageGrade(Student students[], int num_students) {
    double sum = 0;
    for (int i = 0; i < num_students; i++) {
        sum += students[i].grade;
    }
    double average = num_students > 0 ? sum / num_students : 0;
    cout << "学生平均成绩为：" << average << endl;
}

int main() {
    Student students[MAX_NUM_STUDENTS];
    int num_students = 0;
    while (true) {
        showMenu();
        int choice;
        cin >> choice;
        cin.ignore(); // 忽略cin输入流中的换行符
        switch (choice) {
        case 1:
            showAllStudents(students, num_students);
            break;
        case 2:
            addStudent(students, num_students);
            break;
        case 3:
            modifyStudent(students, num_students);
            break;
        case 4:
            deleteStudent(students, num_students);
            break;
        case 5:
            searchStudent(students, num_students);
            break;
        case 6:
            calculateAverageGrade(students, num_students);
            break;
        case 0:
            cout << "谢谢使用，再见！" << endl;
            return 0;
        default:
            cout << "输入的操作不正确，请重新输入！" << endl;
            break;
        }
    }
}