#include <iostream>
using namespace std;

void printInfo(int age) {
    cout << "Age: " << age << endl;
}

void printInfo(string name) {
    cout << "Name: " << name << endl;
}

void printInfo(string name, int age) {
    cout << "Name: " << name << ", Age: " << age << endl;
}

void printInfo(string name, int age, double height) {
    cout << "Name: " << name << ", Age: " << age << ", Height: " << height << endl;
}

int main() {
    int age, option;
    string name;
    double height;
    cin >> age >> name >> height;

    cout << "Choose an option (1-4):" << endl;
    cout << "1. Print age" << endl;
    cout << "2. Print name" << endl;
    cout << "3. Print name and age" << endl;
    cout << "4. Print name, age, and height" << endl;
    cout << "0. Exit" << endl;
    while (option != 0) {
        cin >> option;
        switch (option) {
            case 1:
                printInfo(age);
                break;
            case 2:
                printInfo(name);
                break;
            case 3:
                printInfo(name, age);
                break;
            case 4:
                printInfo(name, age, height);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option" << endl;
        }
    }
    return 0;
}