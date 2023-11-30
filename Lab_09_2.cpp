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
    cout << "Прізвище: ";
    cin >> student.prizv;

    cout << "Курс: ";
    cin >> student.kurs;

    cout << "Спеціальність ( ME, MF, FI, KN ): ";
    string specValue;
    cin >> specValue;

    if (specValue == "ME") student.spec = ME;
    else if (specValue == "MF") student.spec = MF;
    else if (specValue == "FI") student.spec = FI;
    else if (specValue == "KN") student.spec = KN;
    else {
        cout << "Неправильне значення для спеціальності. Повторіть спробу" << endl;
        return;
    }

    cout << "Фізика: ";
    cin >> student.physoc;

    cout << "Математика: ";
    cin >> student.mathoc;

    cout << "Інформатика: ";
    cin >> student.infroc;
    cout << endl;
}

void fullInfo(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        cout << "Введіть інформацію про студента " << i + 1 << ":" << endl;
        inputStudentData(students[i]);
    }
}

void printTable(const Student students[], int numStudents) {
    cout << "Список студентів:" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "|  №  |     Прізвище    | Курс |  Спеціальність  |  Фізика  | Математика | Інформатика  |" << endl;
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

// ЗАВДАННЯ 1

// КУРС
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

// СПЕЦІАЛЬНІСТЬ
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

// ПРІЗВИЩЕ
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





// ЗАВДАННЯ 2

// Функція для порівняння двох студентів для сортування

bool compareStudentsForIndex(const Student& a, const Student& b) {
    if (a.kurs != b.kurs)
        return a.kurs > b.kurs;
    else if (a.spec != b.spec)
        return a.spec < b.spec;
    else
        return a.prizv > b.prizv;
}

// Функція для порівняння двох індексів студентів
bool compareIndex(const int& a, const int& b, const Student* students) {
    return compareStudentsForIndex(students[a], students[b]);
}

// Функція для обміну двох елементів масиву
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Реалізація алгоритму сортування бульбашкою для індексів
void bubbleSortForIndex(int* arr, int n, const Student* students) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compareIndex(arr[j], arr[j + 1], students)) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функція для побудови індексного масиву
void buildIndex(const Student* students, int numStudents, int* index) {
    for (int i = 0; i < numStudents; ++i) {
        index[i] = i;
    }

    bubbleSortForIndex(index, numStudents, students);
}

// Функція виводу відсортованого списку студентів
void printSortedTable(const Student* students, int numStudents, const int* index) {
    cout << "ЗАВДАННЯ 2:" << endl;
    cout << "Відсортована таблиця:" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "|  №  |     Прізвище    | Курс |  Спеціальність  |  Фізика  | Математика | Інформатика  |" << endl;
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


// Звадання 3
// Бінарний пошук студента за прізвищем, курсом та спеціальністю

void inputSearchStudent(Student& searchStudent) {
    cout << "Введи прізвище, курс і спеціальність для пошуку:" << endl;
    cout << "Прізвище: ";
    cin >> searchStudent.prizv;
    cout << "Курс: ";
    cin >> searchStudent.kurs;
    cout << "Спеціальність ( ME, MF, FI, KN ): ";
    string specValue;
    cin >> specValue;

    if (specValue == "ME") searchStudent.spec = ME;
    else if (specValue == "MF") searchStudent.spec = MF;
    else if (specValue == "FI") searchStudent.spec = FI;
    else if (specValue == "KN") searchStudent.spec = KN;
    else {
        cout << "Неправильне значення для спеціальності." << endl;
        searchStudent.spec = ME;
    }
}

// Бінарний пошук студента за прізвищем, курсом та спеціальністю
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
    cout << "Введи кількість студентів: ";
    cin >> numStudents;

    Student* students = new Student[numStudents];

    fullInfo(students, numStudents);

    cout << endl;
    printTable(students, numStudents);

    // Виклик першого задання
    int sortingOption;

    do {
        cout << "Оберіть критерій сортування:" << endl;
        cout << "1) За номером курсу" << endl;
        cout << "2) За назвою спеціальності" << endl;
        cout << "3) За прізвищем (в зворотному до алфавітного порядку)" << endl;
        cout << "4) Продовжити" << endl;

        cout << "Ваш вибір: ";
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
            cout << "Неправильний вибір. Спробуйте ще раз." << endl;
        }

    } while (sortingOption != 4);

    // Виклик другого завдання
    int* index = new int[numStudents];
    buildIndex(students, numStudents, index);

    cout << endl;
    // Вивід відсортованої таблиці за допомогою масиву index
    printSortedTable(students, numStudents, index);


    // Виклик третьго завдання
    Student searchStudent;
    inputSearchStudent(searchStudent);

    if (binarySearchStudent(students, 0, numStudents - 1, searchStudent)) {
        cout << "Студент із вказаними параметрами знайдений." << endl;
    }
    else {
        cout << "Студент із вказаними параметрами не знайдений." << endl;
    }

    delete[] students;
    delete[] index;

    return 0;
}
