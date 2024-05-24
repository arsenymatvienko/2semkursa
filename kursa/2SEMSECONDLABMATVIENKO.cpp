#include <iostream>
#include <windows.h>
#include <conio.h>
#include <chrono>
using namespace std;
using namespace chrono;

struct List {
    int data;
    List* head;
    List* tail;
};

List* createList(int length) {
    List* curr = 0,
        * next = 0;
    for (int i = 1; i <= length; ++i)
    {
        curr = new List;
        curr->tail = next;
        if (next)
            next->head = curr;
        next = curr;
    }
    curr->head = 0;
    return curr;
}

List* createListWithDinamicLength() {
    List* curr = 0;
    List* next = 0;
    int data;

    cout << "Введите элементы списка (для завершения введите любой символ):" << endl;

    while (cin >> data) {
        List* newNode = new List;
        newNode->data = data;
        newNode->tail = nullptr;

        if (curr == nullptr) {
            curr = newNode;
            next = newNode;
        }
        else {
            next->tail = newNode;
            next = newNode;
        }

    }
    cin.clear();
    cin.ignore(10000, '\n');
    return curr;
}

int countListLength(const List* arr) {
    int count = 0;
    const List* current = arr;
    while (current) {
        count++;
        current = current->tail;
    }
    return count;
}

List* findItemByIndex(List* arr, int index) {
    List* curr = arr;
    int counter = 0;

    if (index >= countListLength(arr))
        cout << "не найден.";
    //return nullptr;
    while (curr) {
        if (counter == index) return curr;
        curr = curr->tail;
        counter++;
    }
    return nullptr;
}

int findValueByIndex(List* arr, int index) {
    List* curr = arr;
    int currentIndex = 0;
    while (curr) {
        if (currentIndex == index) {
            return curr->data;
        }
        curr = curr->tail;
        currentIndex++;
    }
    return -1;
}

int findIndexByValue(List* arr, int value) {
    List* curr = arr;
    int index = 0;
    while (curr) {
        if (curr->data == value) {
            return index;
        }
        curr = curr->tail;
        index++;
    }
    return -1;
}

void fillListByRandomNumbers(int length) {
    List* list = createList(length);
    List* curr = list;
    while (curr) {
        curr->data = -99 + rand() % (99 - (-99) + 1);
        curr = curr->tail;
    }
}

void showList(List*& arr) {
    if (arr == 0) {
        cout << "пусто" << endl;
        return;
    }
    else {
        List* curr = arr;
        while (curr) {
            cout << curr->data << " ";
            curr = curr->tail;
        }
    }
    cout << endl << endl;
}

List* insertItem(List*& beg, int index, int data)
{
    List* item = new List;
    item->data = data;
    //index -= 1;
    if (index == 0 || beg == 0) {
        beg->head = item;
        item->head = nullptr;
        item->tail = beg;
        beg = item;
        return item;
    }

    List* prevItem = beg;
    index -= 1;
    while (prevItem->tail && (index--)) {
        prevItem = prevItem->tail;
    }

    item->head = prevItem;
    if (prevItem->tail) prevItem->tail->head = item;
    item->tail = prevItem->tail;
    prevItem->tail = item;
    return item;
}

void delItemByIndex(List*& beg, int index) {
    if (index >= countListLength(beg))
    {
        cout << "Элемент не найден" << endl;
        return;
    }
    List* item;
    if (!index) {
        item = beg->tail;
        delete beg;
        beg = item;
        beg->head = nullptr;
        return;
    }
    item = findItemByIndex(beg, index - 1);
    List* dItem = item->tail;
    item->tail = dItem->tail;
    item->tail->head = item;
    delete dItem;
}

void delItem(List*& beg, int value) {
    int index = findIndexByValue(beg, value);
    if (index >= countListLength(beg))
    {
        cout << "Элемент не найден" << endl;
        return;
    }
    List* item;
    if (!index) {
        item = beg->tail;
        delete beg;
        beg = item;
        beg->head = nullptr;
        return;
    }
    item = findItemByIndex(beg, index - 1);
    List* dItem = item->tail;
    item->tail = dItem->tail;
    item->tail->head = item;
    delete dItem;
}

void changeItems(List*& arr, int firstItem, int secondItem)
{
    /*if (!findItemByIndex(arr, firstItem) || !findItemByIndex(arr, secondItem))
    {
        cout << "Элементы не найдены" << endl;
        return;
    }*/
    //int firstIndex = checkForNumber(arr, firstItem);
    int firstIndex = firstItem;

    //if (firstIndex == -1) return;
    //int secondIndex = checkForNumber(arr, secondItem);
    int secondIndex = secondItem;

    //if (secondIndex == -1) return;

    if (firstIndex == secondIndex) return;
    //firstIndex--;
    //secondIndex--;
    List* leftItem1 = findItemByIndex(arr, firstIndex - 1);
    List* item1 = findItemByIndex(arr, firstIndex);
    List* rightItem1 = findItemByIndex(arr, firstIndex + 1);
    List* leftItem2 = findItemByIndex(arr, secondIndex - 1);
    List* item2 = findItemByIndex(arr, secondIndex);
    List* rightItem2 = findItemByIndex(arr, secondIndex + 1);
    List* tail1 = item1->tail;
    List* head1 = item1->head;
    List* tail2 = item2->tail;
    List* head2 = item2->head;

    if (abs(secondIndex - firstIndex) == 1) // стоят рядом
    {
        item1->head = item2;
        item2->tail = item1;
        if (leftItem1) leftItem1->tail = item2;
        if (rightItem2) rightItem2->head = item1;
        item1->tail = rightItem2;
        item2->head = leftItem1;
    }
    else
    {
        item1->head = leftItem2;
        item2->head = leftItem1;
        item1->tail = rightItem2;
        item2->tail = rightItem1;
        if (leftItem1) leftItem1->tail = item2;
        if (rightItem1) rightItem1->head = item2;
        if (leftItem2) leftItem2->tail = item1;
        if (rightItem2) rightItem2->head = item1;
    }
    if (firstIndex == 0) arr = item2;
    if (secondIndex == 0) arr = item1;
    List* curr = arr;
    while (curr != nullptr)
    {
        cout << curr->data << ' ';
        curr = curr->tail;
    }
}

List* IDZ(List* arr, int minus) {
    if (arr == 0) {
        cout << "Список пустой. " << endl;
        return NULL;
    }
    else {
        List* curr = arr;
        while (curr) {
            if (curr->data % 2 == 0) {
                curr->data -= minus;
                curr = curr->tail;
            }
            else {
                curr = curr->tail;
            }
        }
    }
}

List* IDZ2(List* arr, int multiply) {
    if (arr == 0) {
        cout << "Список пустой. " << endl;
        return NULL;
    }
    else {
        List* curr = arr;
        while (curr) {
            if (curr->data % 2 == 0) {
                curr->data *= multiply;
                curr = curr->tail;
            }
            else {
                curr = curr->tail;
            }
        }
    }
}

int main2()
{
    setlocale(LC_ALL, "RU");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(0));

    List* list = nullptr;

    int choose = 0;
    while (choose != -1)
    {
        cin.clear();
        cin.sync();
        cout << "Выберите действия:" << endl << endl
            << "1. Сформировать двусвязный список размерности N и определить скорость создания." << endl << endl
            << "2. Вставить, удалить, поменять местами или получить элемент двусвязного списка. (Удаление и получение элемента по индексу и по значению)." << endl << endl
            << "3. Вывести список на экран. " << endl << endl
            << "4. Выполнить ИДЗ №9 (уменьшить четные элементы на заданное пользователем число и умножить на произвольное от 1 до 5)." << endl << endl
            << "5. Выход. " << endl << endl;

        cout << "Выбор: ";
        int input;
        cin >> input;
        cout << endl;

        if (cin.fail()) {
            cout << "Неправильный ввод, нажмите любую клавишу для продолжения." << endl << endl;
            _getch();
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> startFirst, endFirst, startSecond, endSecond;
        nanoseconds resultFirst;
        nanoseconds resultSecond;

        switch (input)
        {

        case 1: {

            cout << "1) Ввести количество элементов в списке, который будет автоматически заполняться случайными числами (0 до 99);" << endl << endl
                << "2) Ввести в консоль элементы списка, N определяется автоматически по количеству введенных элементов;" << endl << endl;
            cout << "(1 / 2): ";
            int inputFirstTask;

            cin >> inputFirstTask;
            cout << endl;
            if (cin.fail()) {
                cout << "Неправильный ввод, нажмите любую клавишу для продолжения. " << endl << endl;
                _getch();
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            if (inputFirstTask == 1) {
                cout << "Введите количество элементов: ";
                int listLength;
                cin >> listLength;
                if (listLength == 0) {
                    cout << "Итоговый список: пусто" << endl << endl;
                    break;
                }
                if (cin.fail()) {
                    cout << "Неправильный ввод, нажмите любую клавишу для продолжения. " << endl << endl;
                    _getch();
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }

                startFirst = steady_clock::now();
                list = createList(listLength);
                List* curr = list;
                cout << "Итоговый список: ";
                while (curr) {
                    curr->data = -99 + rand() % (99 - (-99) + 1);
                    cout << curr->data << " ";
                    curr = curr->tail;
                }
                endFirst = steady_clock::now();
                resultFirst = duration_cast<nanoseconds>(endFirst - startFirst);
                cout << endl << "Время, затраченное на создание двусвязного списка в (1) случае, составило " << resultFirst.count() << " наносекунд." << endl;
                cout << endl << "Нажмите любую клавишу для продолжения." << endl << endl;
                break;
            }
            if (inputFirstTask == 2) {
                startSecond = steady_clock::now();
                list = createListWithDinamicLength();
                endSecond = steady_clock::now();
                resultSecond = duration_cast<nanoseconds>(endSecond - startSecond);
                cout << "Итоговый список: ";
                if (countListLength(list) > 0) {
                    List* curr = list;
                    while (curr) {
                        cout << curr->data << " ";
                        curr = curr->tail;
                    }
                }
                else {
                    cout << "пусто.";
                }
                cout << endl << "Время, затраченное на создание двусвязного списка в (2) случае, составило " << resultSecond.count() << " наносекунд." << endl;
                cout << endl << endl;
                break;
            }
            break;
        }

        case 2: {
            List* curr = list;
            cout << "Исходный список: ";
            showList(list);
            cout << "1) Вставить элемент в список;" << endl << endl
                << "2) Удалить элемент из списка (по индексу / значению);" << endl << endl
                << "3) Поменять местами элементы списка;" << endl << endl
                << "4) Получить элемент списка (по индексу / значению);" << endl << endl;
            cout << "Ваш выбор (1 / 2 / 3 / 4): ";
            int inputSecondTask;
            cin >> inputSecondTask;

            if (cin.fail()) {
                cout << endl << "Неправильный ввод, нажмите любую клавишу для продолжения. " << endl << endl;
                _getch();
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            if (inputSecondTask == 1) {

                cout << endl << "Введите числовое значение элемента, который нужно вставить в список: ";
                int item;
                cin >> item;

                if (cin.fail()) {
                    cout << endl << "Неправильный ввод, нажмите любую клавишу для продолжения. " << endl << endl;
                    _getch();
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }

                cout << "Введите индекс элемента в списке: ";
                int indexInsert;
                cin >> indexInsert;

                if (cin.fail()) {
                    cout << endl << "Неправильный ввод, нажмите любую клавишу для продолжения. " << endl << endl;
                    _getch();
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }

                insertItem(list, indexInsert, item);
                //curr = list;
                cout << endl;
                cout << "Итоговый список: ";
                showList(list);
            }

            if (inputSecondTask == 2) {
                cout << endl << "1) Удалить элемент по индексу;" << endl << endl
                    << "2) Удалить элемент по значению;" << endl << endl;
                int inputSecondTask2;
                cin >> inputSecondTask2;

                if (cin.fail()) {
                    cout << endl << "Неправильный ввод, нажмите любую клавишу для продолжения. " << endl << endl;
                    _getch();
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }

                if (inputSecondTask2 == 1) {
                    cout << "Введите индекс элемента, который нужно удалить из списка: ";
                    int indexForDelete;
                    cin >> indexForDelete;

                    if (cin.fail()) {
                        cout << endl << "Неправильный ввод, нажмите любую клавишу для продолжения. " << endl << endl;
                        _getch();
                        cin.clear();
                        cin.ignore(10000, '\n');
                        continue;
                    }

                    delItemByIndex(list, indexForDelete);
                    cout << endl;
                    cout << "Итоговый список: ";
                    showList(list);

                }

                if (inputSecondTask2 == 2) {
                    cout << "Введите значение элемента, который нужно удалить из списка: ";
                    int itemForDelete;
                    cin >> itemForDelete;

                    if (cin.fail()) {
                        cout << endl << "Неправильный ввод, нажмите любую клавишу для продолжения. " << endl << endl;
                        _getch();
                        cin.clear();
                        cin.ignore(10000, '\n');
                        continue;
                    }

                    delItem(list, itemForDelete);
                    cout << endl;
                    cout << "Итоговый список: ";
                    showList(list);

                }

            }

            if (inputSecondTask == 3) {
                cout << "Введите индекс первого числа: ";
                int indexChangeFirst;
                cin >> indexChangeFirst;

                if (cin.fail()) {
                    cout << endl << "Неправильный ввод, нажмите любую клавишу для продолжения. " << endl << endl;
                    _getch();
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }

                cout << "Введите индекс второго числа: ";
                int indexChangeSecond;
                cin >> indexChangeSecond;

                if (cin.fail()) {
                    cout << endl << "Неправильный ввод, нажмите любую клавишу для продолжения. " << endl << endl;
                    _getch();
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }

                changeItems(list, indexChangeFirst, indexChangeSecond);
                cout << endl;
                cout << "Итоговый список: ";
                showList(list);
            }

            if (inputSecondTask == 4) {
                cout << "1) Найти элемент по индексу" << endl;
                cout << "2) Найти элемент по значению" << endl;
                int inputSecondTask4;
                cin >> inputSecondTask4;

                if (cin.fail()) {
                    cout << endl << "Неправильный ввод, нажмите любую клавишу для продолжения. " << endl << endl;
                    _getch();
                    cin.clear();
                    cin.ignore(10000, '\n');
                    continue;
                }

                if (inputSecondTask4 == 1) {
                    cout << "Введите индекс элемента: ";
                    int index4;
                    cin >> index4;
                    if (findValueByIndex(list, index4) == -1) {
                        cout << "не найден." << endl;
                    }
                    else {
                        cout << "Элемент с индексом " << index4 << ": " << findValueByIndex(list, index4);
                    }
                }
                if (inputSecondTask4 == 2) {
                    cout << "Введите значение элемента: ";
                    int value4;
                    cin >> value4;
                    if (findIndexByValue(list, value4) == -1) {
                        cout << "не найден." << endl;
                    }
                    else {
                        cout << "Элемент со значением " << value4 << " имеет индекс: " << findIndexByValue(list, value4);
                    }
                }
            }

            break;
        }

        case 3: {
            cout << "-----------------------------------------" << endl << endl;
            showList(list);
            cout << "-----------------------------------------" << endl << endl;
            break;
        }

        case 4: {
            cout << "Введите число на которое уменьшить все четные элементы: ";
            cout << endl;
            int numberMinus;
            cin >> numberMinus;

            if (cin.fail()) {
                cout << endl << "Неправильный ввод, нажмите любую клавишу для продолжения. " << endl << endl;
                _getch();
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            IDZ(list, numberMinus);
            cout << "Итоговый список с уменьшенными четными числами: ";
            showList(list);
            int numberMultiply = 1 + rand() % 5;
            IDZ2(list, numberMultiply);
            cout << "Итоговый список с умноженными четными числами на " << numberMultiply << ": ";
            showList(list);
            break;
        }

        case 5: {
            choose = -1;
            break;
        }

        default: {
            cout << "Неправильный ввод, нажмите любую клавишу для продолжения. " << endl << endl;
            _getch();
            break;
        }
        }
        _getch();
    }
    return 0;
}