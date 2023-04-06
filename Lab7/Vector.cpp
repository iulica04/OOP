#include "Vector.h"
#include<iostream>


template<typename T>
Vector<T>::Vector(const Vector& other)
{
	size = other.size;
	element = new T[size];
	for (int i = 0; i < size; i++)
		element[i] = other.element[i];
}

template<typename T>
Vector<T>::Vector(Vector&& other)
{
	element = other.element;
	size = other.size;
	other.element = nullptr;
	other.size = 0;
}


template<typename T>
T& Vector<T>::operator[](int index)
{
	return element[index];
}

template<typename T>
void Vector<T>::insert(int index, const T& value)
{
	if (index >= 0 && index <= size)
	{
		if (index <= size)
		{
			for (int i = size - 1; i >= index; i--)
				element[i + 1] = element[i];
			element[index] = value;
			size++;
		}
	}
	
}

template<typename T>
 void Vector<T>::remove(int index)
{
	 if (index <= size)
	 {
		 for (int i = index; i < size - 1; i++)
			 element[i] = element[i + 1];
		 size--;
	 }

}

 template<typename T>
 void Vector<T>::print() const
 {
	 for (int i = 0; i < size; i++)
		 std::cout << element[i] << " ";
	 std::cout << std::endl;
 }

 template<typename T>
 void Vector<T>::sort(int(*compare_inst)(const T& a, const T& b))
 {
	 for(int i=0; i<size-1; i++)
		 for(int j=i+1; j<size; j++)
			 if (compare_inst(element[i], element[j]) == 1)
			 {
				 T aux = element[i];
				 element[i] = element[j];
				 element[j] = aux;
			 }
 }

