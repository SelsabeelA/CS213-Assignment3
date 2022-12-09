
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
#include<iterator>
using namespace std;


template <typename T>
class SNVector {
private:
    T* data;
    int size;
    int capacity;
public:
    SNVector(int cap = 2){
        capacity = cap;
        size = 0;
        data = new T[capacity];
    }
    SNVector(T*, int n)	;	// Initialize by n items from array Selsabeel
    ~SNVector()		;		// Delete allocated memory Selsabeel
    SNVector &operator=(const SNVector&&); // Move assignment Selsabeel
    int push_back(T); // Add item to end of vec & return # of items Selsabeel
    // Increase capacity of needed
    // Throw exception if invalid iter

    //void erase(iterator);        // Remove item at iterator Selsabeel

    // iterator 1 <= iterator 2 otherwise do nothing
// Throw exception if any iterator outside range
    void clear();     // Delete all vector content Selsabeel
    bool operator==(const SNVector<T>&); // Return true if == Selsabeel
    int Size() const;     // Return current size of vec  Selsabeel
    int resize();         // Relocate to bigger space Selsabeel
    // Friends
    friend ostream& operator << (ostream& out, SNVector<T>); //Selsabeel
};
#endif //ASSIGNMENT3_A3_TASK2_20210714_20210423_H
