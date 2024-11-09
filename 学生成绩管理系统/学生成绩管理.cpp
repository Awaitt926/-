#include <iostream>
#include <string>
using namespace std;

const int MAX_NUM_STUDENTS = 50;

struct Student {
    string name;
    int id;
    double grade;
};

// ��ʾ�˵�
void showMenu() {
    cout << "----------------------------------" << endl;
    cout << "  1. ��ʾ����ѧ����Ϣ" << endl;
    cout << "  2. ���ѧ����Ϣ" << endl;
    cout << "  3. �޸�ѧ����Ϣ" << endl;
    cout << "  4. ɾ��ѧ����Ϣ" << endl;
    cout << "  5. ����ѧ����Ϣ" << endl;
    cout << "  6. ����ƽ���ɼ�" << endl;
    cout << "  0. �˳�" << endl;
    cout << "----------------------------------" << endl;
    cout << "��ѡ��������������֣���";
}

// ��ʾ����ѧ����Ϣ
void showAllStudents(Student students[], int num_students) {
    cout << "ѧ����Ϣ���£�" << endl;
    for (int i = 0; i < num_students; i++) {
        cout << "������" << students[i].name << endl;
        cout << "ѧ�ţ�" << students[i].id << endl;
        cout << "�ɼ���" << students[i].grade << endl;
        cout << "-----------------------" << endl;
    }
}

// ���ѧ����Ϣ
void addStudent(Student students[], int& num_students) {
    if (num_students >= MAX_NUM_STUDENTS) {
        cout << "ѧ�������Ѵ����ޣ��޷�����µ�ѧ����Ϣ��" << endl;
        return;
    }
    cout << "������ѧ��������";
    getline(cin, students[num_students].name);
    cout << "������ѧ��ѧ�ţ�";
    cin >> students[num_students].id;
    cout << "������ѧ���ɼ���";
    cin >> students[num_students].grade;
    cin.ignore(); // ����cin�������еĻ��з�
    num_students++;
    cout << "���ѧ����Ϣ�ɹ���" << endl;
}

// �޸�ѧ����Ϣ
void modifyStudent(Student students[], int num_students) {
    int id;
    cout << "��������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�";
    cin >> id;
    bool found = false;
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            found = true;
            cout << "�������޸ĺ��ѧ�����������س����޸ģ���";
            getline(cin, students[i].name);
            cout << "�������޸ĺ��ѧ���ɼ������س����޸ģ���";
            string input;
            getline(cin, input);
            if (!input.empty()) {
                students[i].grade = stod(input);
            }
            cout << "�޸�ѧ����Ϣ�ɹ���" << endl;
            break;
        }
    }
    if (!found) {
        cout << "û���ҵ���ѧ�Ŷ�Ӧ��ѧ����Ϣ��" << endl;
    }
}

// ɾ��ѧ����Ϣ
void deleteStudent(Student students[], int& num_students) {
    int id;
    cout << "��������Ҫɾ����Ϣ��ѧ��ѧ�ţ�";
    cin >> id;
        bool found = false;
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            found = true;
            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_students--;
            cout << "ɾ��ѧ����Ϣ�ɹ���" << endl;
            break;
        }
    }
    if (!found) {
        cout << "û���ҵ���ѧ�Ŷ�Ӧ��ѧ����Ϣ��" << endl;
    }
}

// ����ѧ����Ϣ
void searchStudent(Student students[], int num_students) {
    int id;
    cout << "��������Ҫ������Ϣ��ѧ��ѧ�ţ�";
    cin >> id;
    bool found = false;
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == id) {
            found = true;
            cout << "ѧ����Ϣ���£�" << endl;
            cout << "������" << students[i].name << endl;
            cout << "ѧ�ţ�" << students[i].id << endl;
            cout << "�ɼ���" << students[i].grade << endl;
            break;
        }
    }
    if (!found) {
        cout << "û���ҵ���ѧ�Ŷ�Ӧ��ѧ����Ϣ��" << endl;
    }
}

// ����ƽ���ɼ�
void calculateAverageGrade(Student students[], int num_students) {
    double sum = 0;
    for (int i = 0; i < num_students; i++) {
        sum += students[i].grade;
    }
    double average = num_students > 0 ? sum / num_students : 0;
    cout << "ѧ��ƽ���ɼ�Ϊ��" << average << endl;
}

int main() {
    Student students[MAX_NUM_STUDENTS];
    int num_students = 0;
    while (true) {
        showMenu();
        int choice;
        cin >> choice;
        cin.ignore(); // ����cin�������еĻ��з�
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
            cout << "ллʹ�ã��ټ���" << endl;
            return 0;
        default:
            cout << "����Ĳ�������ȷ�����������룡" << endl;
            break;
        }
    }
}