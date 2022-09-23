#include <stdio.h>
#include <iostream>
#include <fstream> // библиотека дл€ работы с записью и выводом из файлов с++
#include <stdlib.h>
#include <time.h>

std::string numbers = { "0123456789" };
std::string symbols = { "!@$%^&*?#_-+" };
std::string hightRegistr = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
std::string lowRegistr = { "abcdefghijklmnopqrstuvwxyz" };
std::string password;

int randomazing(int min, int max)
{
  return min + rand() % (max - min + 1);
}

char choiceElement(int rowSelection)
{
	int point;
	char element = 0;

	switch (rowSelection) {
	case 1:
		point = randomazing(0, 8);
		element = numbers[point];
		break;
	case 2: 
		point = randomazing(0, 11);
		element = symbols[point];
		break;
	case 3:
		point = randomazing(0, 25);
		element = hightRegistr[point];
		break;
	case 4:
		point = randomazing(0, 25);
		element = lowRegistr[point];
		break;
	}
	return element;
}

int main()
{
	srand(time(NULL));

	std::ofstream file("password.txt", std::ios::app); // std::ios::app ¬вод в файл подр€д
	std::string password;
	std::string name;

	int count = 0;
	int rowSelection;

	std::cout << "Which site do we create a password for?: ";
	std::cin >> name;
	std::cout << "How many elements should the password contain?: ";
	std::cin >> count;
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Incorrect input. Please, try again: \b\b\b";
		std::cin >> count;

	}

	for (int i = 0; i < count; i++)
	{
		rowSelection = randomazing(1, 4);
		password.push_back(choiceElement(rowSelection)); // push_back - добавить элемент в конец строки 
	}

	file.write("Site: ", 6);
	file.write(name.c_str(), name.size());
	file.write("\n", 1);
	file.write("Your password: ", 15);
	file.write(password.c_str(), password.size()); // file.write() - запись в файл, password.c_str() - возвращает массив символов, password.size() - возвращает количество символов
	file.write("\n", 1); // ,1 - количество символов(байт)
	file.write("\n", 1);
	file.close();

	std::cout << "Your password: " << password;

	return 0;
}