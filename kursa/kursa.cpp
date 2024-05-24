#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <chrono>
using namespace std;

int main() {
    int choice;
    cout << "Navigation:" << "\n"
        << "Laba 1" << "\n"
        << "Laba 2" << "\n"
        << "Laba 3" << "\n";


    while (true) {
        cin.clear();
        cin.sync();
        int workPoint;

        cout << "Select point: ";
        cin >> workPoint;

        switch (workPoint)
        {
        case 1: {
            system("2SEMFIRSTLABMATVIENKO.exe");
            break;
        }
        case 2: {
            system("2SEMSECONDLABMATVIENKO.exe");
            break;
        }
        case 3: {
            system("2SEMTHIRDLABMATVIENKO2.exe");
            break;
        }
        default: {
            cout << "\n" << "You did not enter a number in the range from 1 to 4";
            break;
        }
        }

        cin.clear();
        cin.sync();

        char stopFlag;
        cout << "\n" << "Continue the main program? (Y/N) ";
        cin >> stopFlag;

        if (stopFlag != 'Y' && stopFlag != 'y') {
            break;
        }
    }

    return 0;
}
