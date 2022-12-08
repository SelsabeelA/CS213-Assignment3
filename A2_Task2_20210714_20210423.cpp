//
// Created by Selsabeel on 2022-12-07.
//
#include<iostream>
using namespace std;


template <typename T>
class SNVector {
private:
    T* data;
public:
// Constructors and Big 4
//The copy constructor
//The assignment operator
//The move constructor
//The destructor
    SNVector (int);	// Initialize by specific capacity Nada
// No content is added, size = 0
// Assign a default size value
    SNVector (T*, int  n )	;	// Initialize by n items from array Selsabeel
    SNVector (const SNVector&)	;// Initialize with a copy Nada
    ~SNVector()		;		// Delete allocated memory Selsabeel
    //move constructor here selsabeel
    SNVector &operator=(const SNVector&);  // Copy assignment Nada
    SNVector &operator=(const SNVector&&); // Move assignment Selsabeel

// Access operations
    T& operator[](int); // Access item by reference Nada
    // Throw an exception if out of range

// Modifying operations
    int push_back(T); // Add item to end of vec & return # of items Selsabeel
    // Increase capacity of needed
    T pop_back();   // Remove and return last element in vec Nada
    void erase(iterator);        // Remove item at iterator Selsabeel

    // Throw exception if invalid iter
    void erase(iterator1, iterator2);// Remove items between Nada
// iterator 1 <= iterator 2 otherwise do nothing
// Throw exception if any iterator outside range
    void clear();     // Delete all vector content Selsabeel
    void insert(iterator, T);       // Insert item at iterator Nada
    // Throw exception if invalid

// Iterators 		// Supports *, + and ++ operations at least
// Can use: typedef T* iterator
    // Or u can use std::iterator so you can
// apply STL algorithms on XYVector
    iterator begin();	// Return an iterator (T*) Selsabeel
    iterator end();	// Return an iterator (T*) Nada

// Comparison operations
    bool operator==(const SNVector<T>&); // Return true if == Selsabeel
    bool operator< (const SNVector<T>&); // Compares item by item Nada
    // Return true if first different item in this is < in other

// Capacity operations
    int size() const;     // Return current size of vec  Selsabeel
    int capacity() const; // Return size of current allocated array Nada
    int resize();         // Relocate to bigger space Selsabeel
    bool empty();         // Return true if size is 0 Nada

// Friends
    friend ostream& operator << (ostream& out, SNvector<T>); //Selsabeel
};
