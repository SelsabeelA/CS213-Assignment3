/*
Author: Selsabeel Asim Ali Elbagir
 ID: 20210714
 Section: S11
 Assignment: 3
 Course: CS213
 Date created: 7th December, 2022
Purpose: I made my own class which acts very similar to STL's set.
 */

#include <iostream>
#include <vector>
#include<algorithm>
#include<utility>
using namespace std;


template <typename T>
class Set{
private:
    vector<T> data;
    T* dynamic_data;
    int size;
public:
    Set(){
        size = 0;
    }
    void Push_back(T item);
    void Remove(T item);
    bool isMember(T item);
    T* returnPointer();
    int Size();
};


template<typename T>
void Set<T>::Push_back(T item) {
    const T value = item;
    if (find(data.begin(), data.end(), value) == data.end()) {
        data.push_back(value);
        size+=1;

    }
}
template<typename T>
T* Set<T>::returnPointer() {
    dynamic_data = new T[size];
    for (int i = 0; i < size; i++) {
        dynamic_data[i] = data[i];
    }
    return dynamic_data;
}


template<typename T>
void Set<T>::Remove(T item) {
    const T value = item;
    if (find(data.begin(), data.end(), value) != data.end()) {
        std::remove(data.begin(), data.end(), value);
        size-=1;
    }
}

template<typename T>
bool Set<T>::isMember(T item) {
    if(find(data.begin(), data.end(), item)!= data.end()){
        return true;
    }
    else return false;
}

template<typename T>
int Set<T>::Size(){
    return size;
}


int main(){
    Set<int> example;
    example.Push_back(3);
    cout << "Is 3 a member? " << example.isMember(3) << endl;
    cout << "Size = " << example.Size() << endl;
    example.Push_back(3);
    cout << "Size = " << example.Size() << endl;
    example.Remove(3);
    cout << "Size = " << example.Size() << endl;
    cout << "------------------\n";
    Set<string> example2;
    example2.Push_back("hello");
    example2.Push_back("hello");
    cout << "Value of what pointer points to = " << *example2.returnPointer() << endl;
    cout << "Is 'hello' a member? " << example2.isMember("hello") << endl;
    cout << "Size = " << example2.Size() << endl;
    example2.Push_back("world!");
    cout << "Size after pushing back world = " << example2.Size() << endl;
    example2.Remove("hello");
    cout << "Size after removing hello = " << example2.Size() << endl;

    return 0;
}
