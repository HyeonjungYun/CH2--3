#ifndef _SIMLPLE_VECTOR_H_
#define _SIMLPLE_VECTOR_H_

#include <algorithm>

using namespace std;

template<typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;
public:
	void resize(int newCapacity);
	SimpleVector() : data(new T[10]), currentSize(0), currentCapacity(10) {}
	SimpleVector(int capacity) : data(new T[capacity]), currentSize(0), currentCapacity(capacity) {}
	~SimpleVector() { if(data) delete[] data; }
	void push_back(const T& t);
	void pop_back();
	void sortData();
	T& operator[](int index) { return data[index]; }
	int size() { return currentSize; }
	int capacity() { return currentCapacity; }
};

template<typename T>
void SimpleVector<T>::resize(int newCapacity) {
	if (newCapacity > currentCapacity) {
		T* temp = new T[newCapacity];

		for (int i = 0; i < currentSize; i++)
			temp[i] = data[i];

		currentCapacity = newCapacity;

		delete[] data;
		data = temp;
	}
}

template<typename T>
void SimpleVector<T>::push_back(const T& t) {
	if (currentSize > currentCapacity) {
		T* temp = new T[currentCapacity + 5];

		for (int i = 0; i < currentSize; i++)
			temp[i] = data[i];

		currentCapacity = currentCapacity + 5;

		delete[] data;
		data = temp;
	}

	data[currentSize] = t;
	currentSize++;
}

template<typename T>
void SimpleVector<T>::pop_back() {
	if (currentSize > 0)
		currentSize--;
}

template<typename T>
void SimpleVector<T>::sortData() {
	sort(data, data + currentSize);
}

#endif