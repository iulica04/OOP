#pragma once
template <typename T>
int compare_ints(const T& x, const T& y)
{
	if (x == y)
		return 0;
	else
		if (x < y)
			return -1;
	else
		if (x > y)
			return 1;
}

template <typename T>
class Vector
{
private:
	int size;
	T *element;
public:
	Vector() : element(nullptr), size(0){}
	~Vector() { delete[] element; }

	Vector(const Vector& other);
	Vector(Vector&& other);

	Vector& operator=(const Vector& other)
	{
		if (this != &other)
		{
			delete[] element;
			size = other.size;
			element = new T[size];
			for (int i = 0; i < size; i++)
				element[i] = other.element[i];
		}
		return *this;
	}
	Vector& operator=(Vector&& other)
	{
		if (this != &other)
		{
			delete[] element;
			element = other.element;
			size = other.size;
			other.element = nullptr;
			other.size = 0;
		}
		return *this;
	}


	T& operator[](int index);

	void insert(int index, const T& element);
	void remove(int index);
	void print() const;
	void sort(int (*compare_inst)(const T& a, const T& b));

};


