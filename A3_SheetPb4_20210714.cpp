//
// Created by Selsabeel on 2022-12-05.
//
/*
Author: Selsabeel Asim Ali Elbagir
 ID: 20210714
 Section: S11
 Assignment: 3
 Course: CS213
 Date created: 5th December, 2022
Purpose: Create a recursive algorithm that prints all the possible permutations of red, green, and yellow traffic lights.
 */


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void trafficLightsPermutations(int n){
    static string word = "";
    if(n==1){
        word+="R";
        cout<<word;
        word = word.substr(0, word.size()-1);
        cout << endl;
        word+="G";
        cout<<word;
        word = word.substr(0, word.size()-1);
        cout << endl;
        word+="Y";
        cout<<word;
        word = word.substr(0, word.size()-1);
        cout << endl;


    }
    else{
        word+="R";
        trafficLightsPermutations(n-1);
        word = word.substr(0, word.size()-1);
        cout << endl;
        word+="G";
        trafficLightsPermutations(n-1);
        word = word.substr(0, word.size()-1);
        cout << endl;
        word+="Y";
        trafficLightsPermutations(n-1);
        word = word.substr(0, word.size()-1);
        cout << endl;

    }
}


int main(){
    int n;
    cout << "PLease enter how many intersections you've passed by: ";
    cin >> n;
    cout << endl;
    trafficLightsPermutations(n);
}