//
// Created by Selsabeel on 2022-12-09.
//
#include "A3_Task2_20210714_20210423.h"

int main(){
    SNVector<string> vec(1);
    vec.push_back((string) "Hello");
    vec.push_back((string) "Neehaw");
    vec.push_back((string) "Bonjour");
    vec.push_back((string) "Guten Tag");
    vec.push_back((string) "Salam Alykum");
    vec.push_back((string) "Hola");
    cout << vec;

    cout << endl << endl;
    SNVector<string> vec2;
    vec2 = vec;

    cout << vec2;
}