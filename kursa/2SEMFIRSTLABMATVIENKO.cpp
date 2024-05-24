#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

struct Profile
{
	string surname;
	string name;
	string patronymic;
	string sex;
	int group;
	int number;
	int grades[8];
	float averageScore;
};

struct Teacher
{
	string surnameTeacher;
	string nameTeacher;
	string patronymicTeacher;
	char sex;
	int age;
	string academicDegree;
	string subject;
	string email;
	struct 
	{
		int group1;
		int group2;
		int group3;
		int group4;
		int group5;
	} groupTeaching;
};

void creatingRecord(Profile &student)
{
	cout << "Введите фамилию студента: ";
	cin >> student.surname;
	cout << "Введите имя студента: ";
	cin >> student.name;
	cout << "Введите отчество студента: ";
	cin >> student.patronymic;
	cout << "Введите пол студента (М / Ж): ";
	cin >> student.sex;
	while (student.sex != "М" or student.sex != "Ж" or student.sex != "м" or student.sex != "ж")
	{
		if (student.sex == "М" or student.sex == "Ж" or student.sex == "м" or student.sex == "ж")
			break;
		cout << "Доступно два пола, введите одно из предлженного (М / Ж): ";
		cin >> student.sex;
	}
	cout << "Введите номер группы студента: ";
	cin >> student.group;
	cout << "Введите номер студента в списке группы: ";
	cin >> student.number;
	cout << "Введите оценки студента за прошедшую сессию (всего 3 экзамена и 5 дифференцированных зачетов): " << endl;
	bool validGrade = false;
	for (int i = 0; i < 8; i += 1)
	{
		bool validGrade = false;
		while (!validGrade)
		{
			cout << "Введите оценку " << i + 1 << ": ";
			cin >> student.grades[i];
			if (student.grades[i] >= 3 and student.grades[i] <= 5)
			{
					validGrade = true;
			}
			else
			{
				cout << "Введите оценку 3, 4 или 5." << endl;
			}
		}
	}
	int temp = 0;
	for (int i = 0; i < 8; i++)
	{
		if (student.grades[i] == 2)
			temp++;
	}
	if (temp > 0)
	{
		cout << "У студента есть неуд и он должен быть отчислен." << endl;
	}
	else
	{
		cout << "Нажмите любую кнопку для продолжения." << endl;
	}
}

void printData(Profile& student)
{
	cout << "Текущая информация о студенте:" << endl;
	cout << "1) Фамилия: " << student.surname << endl;
	cout << "2) Имя: " << student.name << endl;
	cout << "3) Отчество: " << student.patronymic << endl;
	cout << "4) Пол: " << student.sex << endl;
	cout << "5) Номер группы: " << student.group << endl;
	cout << "6) Номер в списке группы: " << student.number << endl;
	cout << "7) Оценки за прошедшую сессию: ";
	for (int i = 0; i < 8; i++)
	{
		cout << student.grades[i] << " ";
	}
	cout << endl;
}

void printTeacherData(Teacher& teacher)
{
	cout << "Текущая информация о преподавателе:" << endl;
	cout << "1) Фамилия: " << teacher.surnameTeacher << endl;
	cout << "2) Имя: " << teacher.nameTeacher << endl;
	cout << "3) Отчество: " << teacher.patronymicTeacher << endl;
	cout << "4) Пол: " << teacher.sex << endl;
	cout << "5) Возраст: " << teacher.age << endl;
	cout << "6) Ученая степень: " << teacher.academicDegree << endl;
	cout << "7) Наименование дисциплины: " << teacher.subject << endl;
	cout << "8) Почта: " << teacher.email << endl;
	cout << "9) Группы преподавателя: ";
	if (teacher.groupTeaching.group1 != 0) {
		cout << teacher.groupTeaching.group1 << " ";
	}
	if (teacher.groupTeaching.group2 != 0) {
		cout << teacher.groupTeaching.group2 << " ";
	}
	if (teacher.groupTeaching.group3 != 0) {
		cout << teacher.groupTeaching.group3 << " ";
	}
	if (teacher.groupTeaching.group4 != 0) {
		cout << teacher.groupTeaching.group4 << " ";
	}
	if (teacher.groupTeaching.group5 != 0) {
		cout << teacher.groupTeaching.group5;
	}
	cout << endl;
}

int searchStudent(string surname, Profile student[], const int length)
{
	for (int i = 0; i < length; i++)
	{
		if (student[i].surname == surname)
		{
			return i;
		}
	}
	return -1;
}

void editProfile(Profile& student)
{
	cout << "----------------------------------------------" << endl;
	bool flagSuccess = true;
	printData(student);
	cout << "Что вы хотите изменить (введите цифру)? ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Введите новую фамилию: ";
		cin >> student.surname;
		break;
	case 2:
		cout << "Введите новое имя: ";
		cin >> student.name;
		break;
	case 3:
		cout << "Введите новое отчество: ";
		cin >> student.patronymic;
		break;
	case 4:
		cout << "Введите новый пол: ";
		cin >> student.sex;
		break;
	case 5:
		cout << "Введите новую группу: ";
		cin >> student.group;
		break;
	case 6:
		cout << "Введите новый номер студента в группе: ";
		cin >> student.number;
		break;
	case 7:
		cout << "Введите новые оценки: ";
		for (int i = 0; i < 8; i++)
		{
			cin >> student.grades[i];
		}
		break;
	default:
		cout << "Некорректный ввод." << endl;
		flagSuccess = false;
		break;
	}
	if (flagSuccess)
	{
		cout << "Изменения внесены." << endl;
	}
	cout << "----------------------------------------------" << endl;
}

template <size_t N> float calculateAverageScore(int(&scores)[N])
{
	float averageScore = 0.0;
	for (int i = 0; i < N; i++)
	{
		averageScore += scores[i];
	}
	return averageScore / N;
}

int main1()
{
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//int length;
	//cout << "Введите количество студентов для заполнения: ";
	//cin >> length;
	//Profile* students = new Profile[length];
	
	const int length = 30;
	struct Profile students[length];
	int choose = 0;
	int studentIndex = 0;
	while (choose != -1)
	{
		cout << "Введите 1 для создания новой записи студента." << endl;
		cout << "Введите 2 для изменения данных студента." << endl;
		cout << "Введите 3 для вывода всех данных о студентах." << endl;
		cout << "Введите 4 для вывода всех данных о студентах определенной группы." << endl;
		cout << "Введите 5 для вывода топа студентов по их средним значениям." << endl;
		cout << "Введите 6 для вывода количества студентов мужского и женского пола." << endl;
		cout << "Введие 7 для вывода данных о студентах, которые не получают стипендию; учатся только на «хорошо» и «отлично»; учатся только на «отлично»." << endl;
		cout << "Введите 8 для вывода данных о студентах, имеющих определенный номер в списке." << endl;
		cout << "Введите 9 для вывода информации о преподавателях текущего семестра." << endl;
		int vvod;
		cin >> vvod;
		switch (vvod)
		{
		case 1:
		{
			creatingRecord(students[studentIndex]);
			studentIndex++;
			break;
		}
		case 2:
		{
			cout << "Введите фамилию студента, данные которого нужно изменить: " << endl;
			string surnameInput;
			cin >> surnameInput;
			int index = searchStudent(surnameInput, students, length);
			if (index != -1)
			{
				editProfile(students[index]);
			}
			else
			{
				cout << "Студент не найден." << endl;
			}
			break;
		}
		case 3:
		{
			for (int i = 0; i < length + 1; i++)
			{
				printData(students[i]);
				if (i == studentIndex - 1)
				{
					cout << "Данные о студентах выведены." << endl;
					break;
				}
			}
			break;
		}
		case 4:
		{
			cout << "Введите номер группы, чтобы вывести информацию о студентах этой группы: " << endl;
			int groupInput;
			cin >> groupInput;
			for (int i = 0; i < length + 1; i++)
			{
				if (students[i].group == groupInput)
				{
					printData(students[i]);
				}
				else
				{
					cout << "Студенты такой группы не найдены." << endl;
					break;
				}
			}
			break;
		}
		case 5:
		{
			for (int i = 0; i < length; i++)
			{
				cout << calculateAverageScore(students[i].grades) << " - средний балл студента " << students[i].name << ";\n";
				if (i == studentIndex - 1)
				{
					break;
				}
			}
			//float* arr = new float[length];
			float arr[length];
			for (int i = 0; i < length; i++)
			{
				arr[i] = calculateAverageScore(students[i].grades);
			}
			float swap = 0;
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < length - 1; j++)
				{
					if (arr[j] > arr[j + 1])
					{
						swap = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = swap;
					}
				}
			}
			cout << "Топ самых успешных студентов с наивысшим по рейтингу средним баллом за прошедшую сессию." << endl;
			int k = 0;
			for (int i = length - 1; i >= 0; i--)
			{
				if (arr[i] > 0)
				{
					cout << arr[i] << " ";
					k++;
				}
				if (k == 3)
				{
					break;
				}
			}
			break;
		}
		case 6:
		{
			int maleCount = 0;
			int femaleCount = 0;
			for (int i = 0; i < length; i++)
			{
				if (students[i].sex == "Ж" || students[i].sex == "ж")
				{
					femaleCount++;
				}
				else if (students[i].sex == "М" || students[i].sex == "м")
				{
					maleCount++;
				}
				/*else
				{
					cout << "Ошибка: Некорректный символ для обозначения пола" << endl;
				}*/
			}
			cout << "В группе " << femaleCount << " студентов женского пола" << endl;
			cout << "В группе " << maleCount << " студентов мужского пола" << endl;
			break;
		}
		case 7:
		{
			cout << "\nСтуденты, которые не получают стипендию (есть тройки):" << endl;
			for (int i = 0; i < length; i++) {
				bool haveThree = false;
				int count = 0;
				for (int j = 0; j < 8; j++) {
					if (students[i].grades[j] == 3) {
						haveThree = true;
						count++;
					}
					else if (students[i].grades[j] == 4 or students[i].grades[j] == 5) {
						count++;
					}
				}
				if (haveThree == true and count == 8) {
					printData(students[i]);
				}
			}
			cout << "\nСтуденты, которые учатся только на 4 и 5:" << endl;
			for (int i = 0; i < length; i++) {
				bool withoutThree = false;
				int count = 0;
				for (int j = 0; j < 8; j++) {
					if (students[i].grades[j] == 4 or students[i].grades[j] == 5) {
						withoutThree = true;
						count++;
					}
					else if (students[i].grades[j] != 3) {
						count++;
					}
				}
				if (withoutThree == true and count == 8) {
					printData(students[i]);
				}
			}
			cout << "\nСтуденты, которые учатся только на 5:" << endl;
			for (int i = 0; i < length; i++) {
				bool onlyFive = true;
				for (int j = 0; j < 8; j++) {
					if (students[i].grades[j] == 4 || students[i].grades[j] == 3) {
						onlyFive = false;
						break;
					}
					else if (students[i].grades[j] != 5) {
						onlyFive = false;
						break;
					}
				}
				if (onlyFive == true) {
					printData(students[i]);
				}
			}
			break;
		}
		case 8:
		{
			cout << "Введите номер студента, чтобы вывести информацию о нём: " << endl;
			int k;
			cin >> k;
			for (int i = 0; i < length + 1; i++)
			{
				if (students[i].number == k)
				{
					printData(students[i]);
				}
				else
				{
					cout << "Студента с таким номером нет." << endl;
				}
			}
			break;
		}
		case 9:
		{
			const int length = 7;
			struct Teacher teachers[length];
			//struct Teacher Glushenko = { "Глущенко", "Артем", "Геннадьевич", 'М', 24, "Доктор наук (лучший преподаватель СПБГТУ ЛЭТИ)", "Программирование", "art26@gmail.com", {3372, 3373} };
			//struct Teacher Cehanovski = { "Цехановский", "Владислав", "Владимирович", 'М', 56, "Доктор наук", "Информационные технологии", "vvcehanovsky@mail.ru", {3372, 3373, 3374, 3375, 3395} };
			//struct Teacher Hryashev = { "Хрящев", "Сергей", "Михайлович", 'М', 70, "Доктор наук", "Математический анализ", "hryashev@mail.ru", {3372, 3373} };
			//struct Teacher Krym = { "Крым", "Виктор", "Револьтович", 'М', 50, "Кандидат наук", "Алгебра и Геометрия", "krym@mail.ru", {3372, 3373} };
			//struct Teacher Kostyrev = { "Костырев", "Игорь", "Иванович", 'М', 43, "Кандидат наук", "Алгебра и Геометрия", "kostalgem@mail.ru", {3372, 3373, 3374, 3375, 3395} };
			//struct Teacher Sinev = { "Синев", "Валерий", "Евгеньевич", 'М', 44, "Кандидат наук", "Программирование", "sinev@mail.ru", {3372, 3373, 3374, 3375, 3395} };
			//struct Teacher Titov = { "Титов", "Леонид", "Алексеевич", 'М', 63, "Кандидат наук", "Физика", "titovvv@mail.ru", {3372, 3373} };
			struct Teacher teacherData[length] = {
		{ "Глущенко", "Артем", "Геннадьевич", 'М', 24, "Доктор наук (лучший преподаватель СПБГЭТУ ЛЭТИ)", "Программирование", "art26@gmail.com", {3372, 3373} },
		{ "Цехановский", "Владислав", "Владимирович", 'М', 56, "Доктор наук", "Информационные технологии", "vvcehanovsky@mail.ru", {3372, 3373, 3374, 3375, 3395} },
		{ "Хрящев", "Сергей", "Михайлович", 'М', 70, "Доктор наук", "Математический анализ", "hryashev@mail.ru", {3372, 3373} },
		{ "Крым", "Виктор", "Револьтович", 'М', 50, "Кандидат наук", "Алгебра и Геометрия", "krym@mail.ru", {3372, 3373} },
		{ "Костырев", "Игорь", "Иванович", 'М', 43, "Кандидат наук", "Алгебра и Геометрия", "kostalgem@mail.ru", {3372, 3373, 3374, 3375, 3395} },
		{ "Синев", "Валерий", "Евгеньевич", 'М', 44, "Кандидат наук", "Программирование", "sinev@mail.ru", {3372, 3373, 3374, 3375, 3395} },
		{ "Титов", "Леонид", "Алексеевич", 'М', 63, "Кандидат наук", "Физика", "titovvv@mail.ru", {3372, 3373} }
			};
			for (int i = 0; i < length; i++)
			{
				teachers[i] = teacherData[i];
			}
			cout << "Выберите по какому признаку вывести информацию о преподавателе:" << endl;
			cout << "1) По фамилии;" << endl;
			cout << "2) По номеру группы;" << endl;
			cout << "3) По наименованию дисциплины;" << endl;
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				cout << "Введите фамилию преподавателя:" << endl;
				string teacherSurname;
				cin >> teacherSurname;
				bool foundTeacher = false;
				for (int i = 0; i < length + 1; i++)
				{
					if (teachers[i].surnameTeacher == teacherSurname)
					{
						printTeacherData(teachers[i]);
						foundTeacher = true;
					}
				}
				if (!foundTeacher)  
				{
					cout << "Такого преподавателя не существует." << endl;
				}
				break;
			}
			case 2:
			{
				cout << "Введите номер группы, у которой ведет занятия преподаватель:" << endl;
				int teacherGroupNumber;
				cin >> teacherGroupNumber;
				bool foundTeacher = false;
				for (int i = 0; i < length + 1; i++)
				{
					if (teachers[i].groupTeaching.group1 == teacherGroupNumber || teachers[i].groupTeaching.group2 == teacherGroupNumber || teachers[i].groupTeaching.group3 == teacherGroupNumber || teachers[i].groupTeaching.group4 == teacherGroupNumber || teachers[i].groupTeaching.group5 == teacherGroupNumber)
					{
						printTeacherData(teachers[i]);
						foundTeacher = true;
					}
				}
				if (!foundTeacher)
				{
					cout << "Такого преподавателя не существует." << endl;
				}
				break;
			}
			case 3:
			{
				cout << "Введите наименование дисциплины:" << endl;
				string subjectInput;
				cin >> subjectInput;
				bool foundTeacher = false;
				for (int i = 0; i < length + 1; i++)
				{
					if (teachers[i].subject == subjectInput)
					{
						printTeacherData(teachers[i]);
						foundTeacher = true;
					}
				}
				if (!foundTeacher)
				{
					cout << "Такого преподавателя не существует." << endl;
				}
				break;
			}
			default:
			{
				cout << "Неверный ввод, нажмите любую клавишу для продолжения." << endl;
				_getch();
				break;
			}
			}
			break;
		}
		default:
		{
			cout << "Неверный ввод, нажмите любую клавишу для продолжения." << endl;
			_getch();
			break;
		}
		}
		if (studentIndex == length + 1)
		{
			cout << "Места для студентов закончились, запись студентов пойдет сначала.";
			studentIndex = 0;
			
		}
		_getch();
	}
	delete[] students;
	return 0;
}
