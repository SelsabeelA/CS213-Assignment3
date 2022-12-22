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
    cout << vec << endl;
    cout << "String vector's size: " << vec.Size() << endl;
    vec.erase(vec.begin());
    cout << "size after erasing first element" << vec.Size() << endl;
    cout << vec;

    SNVector<int> intvec(4);
    intvec.push_back(40);
    intvec.push_back(32);
    intvec.push_back(22);
    intvec.push_back(53);
    cout << intvec << endl;
    cout << "Integer vector's size: " << intvec.Size() << endl;
    intvec.erase(intvec.begin());
    cout << "size after erasing first element" << intvec.Size() << endl;
    cout << intvec;

    double dbl_array[4] = {22.22,23.22,22.3,0.2};
    SNVector<double> dbl_vec(dbl_array, 4);
    cout << "Double vector's size: " << dbl_vec.Size() << endl;
    dbl_vec.clear();
    cout << "Double vector's size: " << dbl_vec.Size() << endl;
    dbl_vec.resize();
    dbl_vec.push_back(33.3);
    cout << "Double vector's size: " << dbl_vec.Size() << endl;
    dbl_vec.erase(dbl_vec.begin());
    return 0;
}
