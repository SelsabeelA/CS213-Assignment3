
/*
Author: Selsabeel Asim Ali Elbagir
 ID: 20210714
 Section: S11
 Assignment: 3
 Course: CS213
 Date created: 7th December, 2022
Purpose:
 */
/*Exceptions. Ihab Ashraf is trying to write a program that converts dates from numerical month/day
format to alphabetic month/day (for example, 1/31 or 01/31 corresponds to January 31). You will define
two exception classes, one called MonthError and another called DayError. If the user enters
anything other than a legal month number (integers from 1 to 12), then your program will throw and
catch a MonthError. Similarly, if the user enters anything other than a valid day number (integers
from 1 to either 29, 30, or 31, depending on the month), then your program will throw and catch a
DayError. To keep things simple, always allow 29 days for February.*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

string FixDate(int month,int day){
    string word = "";
    switch(month){
        case(1):
            word+="January";
        case(2):
            word+="February";
        case(3):
            word+="March";
        case(4):
            word+="April";
        case(5):
            word+="May";
        case(6):
            word+="June";
        case(7):
            word+="July";
        case(8):
            word+="August";
        case(9):
            word+="September";
        case(10):
            word+="October";
        case(11):
            word+="November";
        case(12):
            word+="December";
        default:
            throw ;
    }
    if(day>31 || day<1){
        throw "DayError";
    }
    else if(day>30 && (month==4 || month==6 || month==9 || month==11)){
        throw "DayError";
    }
    else if(day>29 && month==2){
        throw "DayError";
    }
    string result = word + " " + to_string(day);
    cout << result;
    return result;
}
int main(){

}
