/*
Author: Selsabeel Asim Ali Elbagir
 ID: 20210714
 Section: S11
 Assignment: 3
 Course: CS213
 Date created: 7th December, 2022
Purpose:
 */

/*
 Template – Set. Abdullah Mohamed uses a C++ version that does not support STL and he needs a set
class for his programming job. Help him by writing a template-based class that implements a set of
items. A set is a collection of items in which no item occurs more than once. Internally, you may
represent the set using the data structure of your choice (for example, list, vector, arrays, etc.). However,
the class should externally support the following functions:
 Add a new item to the set. If the item is already in the set then nothing happens.
 Remove an item from the set.
 Return the number of items in the set.
 Determine if an item is a member of the set.
 Return a pointer to a dynamically created array containing each item in the set. The caller of this
function is responsible for de-allocating the memory.
Test your class by creating different sets of different data types (for example, strings, integers, or other
classes). If you add objects to your set, then you may need to overload the == and != operators for the
object’s class so your template-based set class can properly determine membership.*/

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
        dynamic_data[1] = 0;
    }
    ~Set(){
        delete[] dynamic_data;
    }
    void Push_back(T item);
    void Remove(T item);
    bool isMember(T item);
    int Size();
};


template<typename T>
void Set<T>::Push_back(T item) {
    const T value = item;
    if (find(data.begin(), data.end(), value) == data.end()) {
        data.push_back(value);
        size+=1;
        T* temp[size];
        temp = move(dynamic_data);
    }
}

template<typename T>
void Set<T>::Remove(T item) {
    const T value = item;
    if (find(data.begin(), data.end(), value) != data.end()) {
        data.std::remove(find(data.begin(), data.end(), value));
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
    example.Push_back(3);

}