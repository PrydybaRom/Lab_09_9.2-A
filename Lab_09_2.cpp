#include <iostream>
#include <Windows.h>

using namespace std;

enum Spec { ME, MF, FI, KN };
const char* specStrings[] = { "ME", "MF", "FI", "KN" };

struct Student {
    string prizv;
    int kurs;
    Spec spec;
    int physoc;
    int mathoc;
    int infroc;
};

void inputStudentData(Student& student) {
    cout << "�������: ";
    cin >> student.prizv;

    cout << "����: ";
    cin >> student.kurs;

    cout << "������������ ( ME, MF, FI, KN ): ";
    string specValue;
    cin >> specValue;

    if (specValue == "ME") student.spec = ME;
    else if (specValue == "MF") student.spec = MF;
    else if (specValue == "FI") student.spec = FI;
    else if (specValue == "KN") student.spec = KN;
    else {
        cout << "����������� �������� ��� ������������. �������� ������" << endl;
        return;
    }

    cout << "Գ����: ";
    cin >> student.physoc;

    cout << "����������: ";
    cin >> student.mathoc;

    cout << "�����������: ";
    cin >> student.infroc;
    cout << endl;
}

void fullInfo(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        cout << "������ ���������� ��� �������� " << i + 1 << ":" << endl;
        inputStudentData(students[i]);
    }
}

void printTable(const Student students[], int numStudents) {
    cout << "������ ��������:" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "|  �  |     �������    | ���� |  ������������  |  Գ����  | ���������� | �����������  |" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < numStudents; ++i) {
        cout << "| " << i + 1 << "   | ";
        cout.width(15); cout << left << students[i].prizv << " | ";
        cout.width(4); cout << students[i].kurs << " | ";
        cout.width(15); cout << left << specStrings[students[i].spec] << " | ";
        cout.width(8); cout << left << students[i].physoc << " | ";
        cout.width(10); cout << left << students[i].mathoc << " | ";
        cout.width(12); cout << left << students[i].infroc << " |" << endl;
    }

    cout << "----------------------------------------------------------------------------------------" << endl;
}

// �������� 1

// ����
void bubbleSortByCourse(Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; ++i) {
        for (int j = 0; j < numStudents - i - 1; ++j) {
            if (students[j].kurs > students[j + 1].kurs) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// ���ֲ���Ͳ���
void bubbleSortBySpecialty(Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; ++i) {
        for (int j = 0; j < numStudents - i - 1; ++j) {
            if (specStrings[students[j].spec][0] > specStrings[students[j + 1].spec][0]) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
            else if (specStrings[students[j].spec][0] == specStrings[students[j + 1].spec][0] &&
                specStrings[students[j].spec][1] > specStrings[students[j + 1].spec][1]) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// �в�����
void bubbleSortLastName(Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; ++i) {
        for (int j = 0; j < numStudents - i - 1; ++j) {
            if (students[j].prizv < students[j + 1].prizv) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
//=======================================================================





// �������� 2

// ������� ��� ��������� ���� �������� ��� ����������

bool compareStudentsForIndex(const Student& a, const Student& b) {
    if (a.kurs != b.kurs)
        return a.kurs > b.kurs;
    else if (a.spec != b.spec)
        return a.spec < b.spec;
    else
        return a.prizv > b.prizv;
}

// ������� ��� ��������� ���� ������� ��������
bool compareIndex(const int& a, const int& b, const Student* students) {
    return compareStudentsForIndex(students[a], students[b]);
}

// ������� ��� ����� ���� �������� ������
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// ��������� ��������� ���������� ���������� ��� �������
void bubbleSortForIndex(int* arr, int n, const Student* students) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareIndex(arr[j], arr[j + 1], students)) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ������� ��� �������� ���������� ������
void buildIndex(const Student* students, int numStudents, int* index) {
    for (int i = 0; i < numStudents; ++i) {
        index[i] = i;
    }

    bubbleSortForIndex(index, numStudents, students);
}

// ������� ������ ������������� ������ ��������
void printSortedTable(const Student* students, int numStudents, const int* index) {
    cout << "�������� 2:" << endl;
    cout << "³���������� �������:" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "|  �  |     �������    | ���� |  ������������  |  Գ����  | ���������� | �����������  |" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < numStudents; ++i) {
        int currentIndex = index[i];
        cout << "| " << i + 1 << "   | ";
        cout.width(15); cout << left << students[currentIndex].prizv << " | ";
        cout.width(4); cout << students[currentIndex].kurs << " | ";
        cout.width(15); cout << left << specStrings[students[currentIndex].spec] << " | ";
        cout.width(8); cout << left << students[currentIndex].physoc << " | ";
        cout.width(10); cout << left << students[currentIndex].mathoc << " | ";
        cout.width(12); cout << left << students[currentIndex].infroc << " |" << endl;
    }

    cout << "----------------------------------------------------------------------------------------" << endl;
}
//===================================================================================


// �������� 3
// �������� ����� �������� �� ��������, ������ �� ������������

void inputSearchStudent(Student& searchStudent) {
    cout << "����� �������, ���� � ������������ ��� ������:" << endl;
    cout << "�������: ";
    cin >> searchStudent.prizv;
    cout << "����: ";
    cin >> searchStudent.kurs;
    cout << "������������ ( ME, MF, FI, KN ): ";
    string specValue;
    cin >> specValue;

    if (specValue == "ME") searchStudent.spec = ME;
    else if (specValue == "MF") searchStudent.spec = MF;
    else if (specValue == "FI") searchStudent.spec = FI;
    else if (specValue == "KN") searchStudent.spec = KN;
    else {
        cout << "����������� �������� ��� ������������." << endl;
        searchStudent.spec = ME;
    }
}

// �������� ����� �������� �� ��������, ������ �� ������������
bool binarySearchStudent(const Student* students, int left, int right, const Student& searchStudent) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (students[mid].prizv == searchStudent.prizv && students[mid].kurs == searchStudent.kurs &&
            students[mid].spec == searchStudent.spec) {
            return true;
        }
        else if (students[mid].prizv < searchStudent.prizv ||
            (students[mid].prizv == searchStudent.prizv && students[mid].kurs < searchStudent.kurs) ||
            (students[mid].prizv == searchStudent.prizv && students[mid].kurs == searchStudent.kurs &&
                students[mid].spec < searchStudent.spec)) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false;
}





int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int numStudents;
    cout << "����� ������� ��������: ";
    cin >> numStudents;

    Student* students = new Student[numStudents];

    fullInfo(students, numStudents);

    cout << endl;
    printTable(students, numStudents);

    // ������ ������� �������
    int sortingOption;

    do {
        cout << "������ ������� ����������:" << endl;
        cout << "1) �� ������� �����" << endl;
        cout << "2) �� ������ ������������" << endl;
        cout << "3) �� �������� (� ���������� �� ���������� �������)" << endl;
        cout << "4) ����������" << endl;

        cout << "��� ����: ";
        cin >> sortingOption;

        switch (sortingOption) {
        case 1:
            bubbleSortByCourse(students, numStudents);
            break;
        case 2:
            bubbleSortBySpecialty(students, numStudents);
            break;
        case 3:
            bubbleSortLastName(students, numStudents);
            break;
        }

        if (sortingOption >= 1 && sortingOption <= 3) {
            cout << endl;
            printTable(students, numStudents);
        }
        else if (sortingOption != 4) {
            cout << "������������ ����. ��������� �� ���." << endl;
        }

    } while (sortingOption != 4);

    // ������ ������� ��������
    int* index = new int[numStudents];
    buildIndex(students, numStudents, index);

    cout << endl;
    // ���� ����������� ������� �� ��������� ������ index
    printSortedTable(students, numStudents, index);


    // ������ ������� ��������
    Student searchStudent;
    inputSearchStudent(searchStudent);

    if (binarySearchStudent(students, 0, numStudents - 1, searchStudent)) {
        cout << "������� �� ��������� ����������� ���������." << endl;
    }
    else {
        cout << "������� �� ��������� ����������� �� ���������." << endl;
    }

    delete[] students;
    delete[] index;

    return 0;
}
