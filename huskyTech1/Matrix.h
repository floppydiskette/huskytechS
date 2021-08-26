#pragma once

//mr anderson
template <typename T>
class Matrix
{
public:
	Matrix(int x, int y);
	~Matrix();

	void set(T addition, int x, int y);

	T get(int x, int y);

	int getSizeX();
	int getSizeY();

private:
	T* arr;

	int sizeX;
	int sizeY;

	void explode();

};

/*
arr = new T
*/

template<typename T>
inline Matrix<T>::Matrix(int x, int y)
{
	arr = new T[x * y];
	sizeX = x;
	sizeY = y;
}

template<typename T>
inline Matrix<T>::~Matrix()
{
	explode();
}

template<typename T>
inline void Matrix<T>::set(T addition, int x, int y)
{
	arr[x * sizeY + y] = addition;
}


template<typename T>
inline T Matrix<T>::get(int x, int y)
{
	return arr[x * sizeY + y];
}

template<typename T>
inline int Matrix<T>::getSizeX()
{
	return sizeX;
}

template<typename T>
inline int Matrix<T>::getSizeY()
{
	return sizeY;
}

template<typename T>
inline void Matrix<T>::explode()
{
	delete arr;
}
