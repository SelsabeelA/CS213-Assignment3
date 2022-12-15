#include<iostream>
using namespace std;
#include "A3_Task2_20210714_20210423.h"

int main(){
    SNVector<string> vec(1);
    vec.push_back((string) "Hello");
    vec.push_back((string) "Neehaw");
    vec.push_back((string) "Bonjour");
    vec.push_back((string) "Guten Tag");
    vec.push_back((string) "Salam Alykum");
    vec.push_back((string) "Hola");
    cout << vec.Size() << endl;

    SNVector<int> intvec(4);
    intvec.push_back(4);
    intvec.push_back(3);
    intvec.push_back(2);
    intvec.push_back(5);
    intvec.begin()++;
    cout << intvec.Size();
    intvec.erase(intvec.begin());
    cout << intvec.Size();
    cout << endl;
    cout << intvec;

    return 0;
}
