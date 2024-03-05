#include <iostream>
#include <string>

#include "templateArray.h"

int main()
{
	setlocale(LC_ALL, "ru");
	
	//�������� ������� int
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

	//�������� ������� ��� �������� �����
	TArray<std::string> strArray(2);
	strArray[0] = "Alesha";
	strArray[1] = "Masha";
	for (int i = 0; i < strArray.getLength(); i++)
	{
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;

	//��������� ����� �������
	strArray.resize(3);
	for (int i = 0; i < strArray.getLength(); i++)
	{
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;
	strArray[2] = "�����!";
	
	//���������� �������� �� �������
	strArray.insertBefore("Gena", 2);
	for (int i = 0; i < strArray.getLength(); i++)
	{
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;
	//����������� ���������
	std::cout << strArray.getLength() << std::endl;

	//������� �������, � ������ ������ ������
	strArray.remove(3);
	intArray.remove(4);
	intArray.remove(3);
	for (int i = 0; i < intArray.getLength(); i++)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	//���������� ������� ��������
	strArray.insertAtBeginning("Semen");
	//���������� ���������� ��������
	strArray.insertAtEnd("Jeniy");
	for (int i = 0; i < strArray.getLength(); i++)
	{
		std::cout << strArray[i] << " ";
	}
	std::cout << std::endl;
	//����������� ���������
	std::cout << strArray.getLength() << std::endl;

	return 0;
}