
/*
 Author1: Selsabeel Asim Ali Elbagir
 ID1: 20210714
 Author2:
 ID2:
 Section: S11
 Assignment: 3
 Course: CS213
 Date created: 7th December, 2022
Purpose: Create our own version of STL's vectors.
 */





#ifndef ASSIGNMENT3_A3_TASK2_20210714_20210423_H
#define ASSIGNMENT3_A3_TASK2_20210714_20210423_H
#include<iostream>
#include<bits/stdc++.h>
#include <iterator>
using namespace std;

template <typename T>
class SNVector { // Selsabeel

private:
    T* data;
    int size;
    int capacity;
public:
    class MyIterator : public std::iterator<std::input_iterator_tag, T>
    {
        T* it_data;
    public:
        MyIterator(T* data){
            it_data = data;
        }
        ~MyIterator(){
        delete[] it_data;
        }
        MyIterator(const MyIterator& m_data){
            it_data = m_data.it_data;
        }
        MyIterator& operator++(){
            it_data++;
            return *this;
        }
        int& operator*(){
            return *it_data;
        }
        bool operator==(const MyIterator& rhs) const {
            return it_data==rhs.it_data;
        }
        bool operator!=(const MyIterator& rhs) const {
            return it_data!=rhs.it_data;}
    };
    MyIterator begin(){ //Selsabeel
        return MyIterator(data);
    }
    void erase(MyIterator item){ // Selsabeel
        T* new_data = new T[capacity];
        int count;
        for(int i=0;i<size;i++){
            if(MyIterator(data) == item){
                count = i;
            }
        }
        for(int i=0;i<count;i++){
            new_data[i] = data[i];
        }
        size = size-1;
        for(int i = count;i<size;i++){
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }

    SNVector(int cap = 2){ // Selsabeel
        capacity = cap;
        size = 0;
        data = new T[capacity];
    }
    SNVector(T* array, int n)	// Selsabeel
    {
        data = new T[n];
        for (int i = 0; i < n; i++) {
            data[i] = array[i];
        }
        size = n;
    }
    ~SNVector(){
        delete[] data;
    }
    SNVector& operator=(const SNVector&& other){ // Selsabeel
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
        return data;
    }
    else{
        cout << "Cannot delete self" << endl;
    }
    }


    SNVector(SNVector&& other) // Selsabeel move constructor
    {
        data = other.data;
        other.data = nullptr;
    }
    int push_back(T item) // Selsabeel
    {
        size+=1;
        resize();
        data[size-1] = item;
        return size;
    }
    void clear()     // Delete all vector content Selsabeel
    {
        for(int i =0;i<size;i++){
            data[i] = NULL;
        }
        size = 0;
    }

    bool operator==(const SNVector<T>& rhs) // Selsabeel
    {
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
    int Size() const     //  Selsabeel
    {
        const int const_size = size;
        return const_size;
    }
    int resize()         // Selsabeel
    {
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
    //                   (Selsabeel)
    friend std::ostream& operator<< (std::ostream& out, const SNVector<T>& v){
        for (int i = 0; i < v.Size(); i++) {
            out << v.data[i] << " ";
        }
        return out;
    }
};
#endif //ASSIGNMENT3_A3_TASK2_20210714_20210423_H


