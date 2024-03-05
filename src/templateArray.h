#pragma once

#include <iostream>
#include <cassert>
#include <typeinfo>
//#include <algorithm>

template <typename T>
class TArray
{
private:
	int m_length;
	T* m_data;

public:
	//Constructor
	TArray() { m_length = 0; m_data = nullptr; }

	TArray(int length)
	{
		assert(length >= 0);
		m_data = new T[length];
		m_length = length;
	}

	//Destructor
	~TArray()
	{
		delete[] m_data; 
		std::cout << "Destructor worked!" << std::endl; 
	}

	//��������
	void erase()
	{
		delete[] m_data;
		// ����������� �������� nullptr ��� m_data, ����� �� ������ �� �������� ������� ���������!
		m_data = nullptr;
		m_length = 0;
	}

	//Operator
	T& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	TArray& operator=(const TArray& arr);

	// ����� ������� ������ �������� ������������� ���������, ��� �� ������� �� ���� ��������� �������
	int getLength() { return m_length; }

	//��������� ����� ������� � ����������� ������(changing the length of an array while saving data)
	void resize(int newLength);

	//��������� ����� ������� � ������� ������(changing array length with data loss)
	void reallocate(int newLength) //����������������
	{
		//�������� ������� � ��������� ��� ����� � 0
		erase();
		if (newLength <= 0)
			return;
		m_data = new T[newLength]{};
		m_length = newLength;
	}

	// ��������(insert)
	void insertBefore(const T& value, int index);
	//������� 1 ��������(insert)
	void insertAtBeginning(const T& value) { insertBefore(value, 0); }
	//������� ���������� ��������(insert)
	void insertAtEnd(const T& value) { insertBefore(value, m_length); }

	//�������� ��������(deleting an element)
	void remove(int index);
};

template<typename T>
inline TArray<T>& TArray<T>::operator=(const TArray& arr)
{
	//�������� �� ����������� �� �� � ���� ������
	if (&arr == this)
		return *this;
	reallocate(arr.getLength());
	for (int i = 0; i < m_length; i++)
	{
		m_dat[i] = arr.m_data[i];
	}
	return *this;
}

template<typename T>
inline void TArray<T>::resize(int newLength)
{
	//�� ������
	if (newLength == m_length)
		return;
	//����� � 0
	if (newLength <= 0)
	{
		erase();
		return;
	}
	//�������� ������ ������� ��������������� �����(creating a new array of the appropriate length)
	T* data = new T[newLength]{}; //T* data{ new T[newLength] ()}; //������ ���������

	//if (m_length > 0)
	//{
	//	int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
	//	std::copy_n(m_data, elementsToCopy, data); // copy the elements
	//}

	if (m_length > 0)
	{
		if (newLength > m_length)
		{
			for (int i = 0; i < m_length; i++)
			{
				data[i] = m_data[i];
			}			
		}
		if (newLength < m_length)
		{
			for (int i = 0; i < newLength; i++)
			{
				data[i] = m_data[i];
			}
		}
	}
	delete[] m_data;//������� ������ ������
	m_data = data;//��������� �� ����� ������(point to a new array)
	m_length = newLength;//������������ ����� �����(set new length)
}

template<typename T>
inline void TArray<T>::insertBefore(const T& value, int index)
{
	assert(index >= 0 && index <= m_length);
	//�������� ������ ������� �� ���� ������� ������(creating a new array with one more element)
	T* data = new T[m_length + 1]{};
	//�������� �������� �� �������(copy elements to index)
	for (int  i = 0; i < index; i++)
	{
		data[i] = m_data[i];
	}
	//��������� ��������(insert value)
	data[index] = value;
	//�������� �������� ����� �������(copy the elements after the index)
	for (int i = index + 1; i < m_length + 1; i++)
	{
		data[i] = m_data[i - 1];
	}
	delete[] m_data;
	m_data = data;
	++m_length;
}

template<typename T>
inline void TArray<T>::remove(int index)
{
	//�������� �������� �������(checking index value)
	assert(index >= 0 && index < m_length);
	//���� � ������� 1 �������, ������ ������ �������(if there is 1 element in the array, make the array null)
	if (m_length == 1)
	{
		erase();
		return;
	}
	//�������� ������ ������� �� 1 ������� ������ �������(creating a new array with 1 element less than the old one)
	T* data = new T[m_length - 1](); //T* data{ new T[m_length -1]() };
	//����������� ��� �������� �� �������(copy all of the elements up to the index)
	for (int i = 0; i < index; i++)
	{
		data[i] = m_data[i];
	}
	//���������� ��� �������� ����� ���������� ��������(copy all of the values after the removed element)
	for (int i = index; i < m_length -1; i++)
	{
		data[i] = m_data[i + 1];
	}
	//delete old array
	delete[] m_data;
	m_data = data;
	--m_length;
}

