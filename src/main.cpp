#include <iostream>
#include <string>

#include "templateArray.h"

int main()
{
	setlocale(LC_ALL, "ru");
	
	//создание объекта int
	TArray<int> intArray(3);
	intArray[0] = 1;
	intArray[1] = 2;
	intArray[2] = 3;
	for (int i = 0; i < intArray.getLength(); i++)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	intArray.resize(5);
	for (int i = 0; i < intArray.getLength(); i++)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	//создание объекта для хранения строк
	TArray<std::string> strArray(2);
	strArray[0] = "Alesha";
	strArray[1] = "Masha";
	for (int i = 0; i < strArray.getLength(); i++)
	{
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;

	//изменение длины массива
	strArray.resize(3);
	for (int i = 0; i < strArray.getLength(); i++)
	{
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;
	strArray[2] = "Пусто!";
	
	//добовление элемента по индексу
	strArray.insertBefore("Gena", 2);
	for (int i = 0; i < strArray.getLength(); i++)
	{
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;
	//колличество элементов
	std::cout << strArray.getLength() << std::endl;

	//удалить элемент, в данном случае пустой
	strArray.remove(3);
	intArray.remove(4);
	intArray.remove(3);
	for (int i = 0; i < intArray.getLength(); i++)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	//добовление первого элемента
	strArray.insertAtBeginning("Semen");
	//добовление последнего элемента
	strArray.insertAtEnd("Jeniy");
	for (int i = 0; i < strArray.getLength(); i++)
	{
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;
	//колличество элементов
	std::cout << strArray.getLength() << std::endl;

	return 0;
}