//
// Created by Selsabeel on 2022-12-07.
//
#include "A3_Task2_20210714_20210423.h"

template<typename T>
SNVector<T>::SNVector(T *array, int n) {
    data = new T[n];
    for (int i = 0; i < n; i++) {
        data[i] = array[i];
    }
    size = n;
}

template<typename T>
SNVector<T>::~SNVector() {
    delete[] data;
}

template<typename T>
SNVector<T> &SNVector<T>::operator=(const SNVector<T> && other) {
    // PLEASE NOTE THIS IS NOT MY CODE
    // THIS IS LECTURE CODE
    // PLEASE REMEMBER TO CHANGE
    if(this != &other){
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for(int i = 0; i < other.size; i++){
            data[i] = other.data[i];
        }
    }
    else{
        cout << "Cannot delete self" << endl;
    }


}

template<typename T>
int SNVector<T>::push_back(T item) {
    size+=1;
    resize();
    data[size-1] = item;
    return size;
}

/*
template<typename T>
void SNVector<T>::erase(std::_Bit_const_iterator::iterator<random_access_iterator_tag, bool> my_iterator) {
    T* new_data = new T[capacity];
    for(auto i;i<my_iterator;){
        new_data[i] = data[i]
    }
    for(auto i = my_iterator;){
        new_data[i] = data[i];
    }
}*/

template<typename T>
void SNVector<T>::clear() {
    for(int i =0;i<size;i++){
        data[i] = NULL;
    }
    size = 0;
}
template<typename T>
bool SNVector<T>::operator==(const SNVector<T> &rhs) {
    if(size != rhs.size){
        return false;
    }
    for(int i=0;i<size;i++){
        if(data[i] != rhs.data[i]){
            return false;
        }
    }
    return true;
}


template<typename T>
int SNVector<T>::Size() const {
    const int const_size = size;
    return const_size;
}

template<typename T>
int SNVector<T>::resize() {
    int new_capacity = capacity * 2;
    T* new_data = new T[new_capacity];
    for (int i = 0; i < size; i++) {
        new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
    return capacity;
}

// Friends
template<typename T>
ostream& operator << (ostream& out, SNVector<T> v) {
    for (int i = 0; i < v.Size(); i++) {
        out << v[i] << " ";
    }
    return out;
}