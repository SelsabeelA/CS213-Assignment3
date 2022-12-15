
/*
Author: Selsabeel Asim Ali Elbagir
 ID: 20210714
 Section: S11
 Assignment: 3
 Course: CS213
 Date created: 7th December, 2022
Purpose: A program that converts the date from month/day format to alphabetic month/day.
 Contains two exception classes, MonthError and DayError.
 */

#include <iostream>
#include<bits/stdc++.h>
using namespace std;


class MonthError{
private:
    std::string my_msg;
public:
    MonthError(const std::string& msg): my_msg(msg){};
    string get_msg(){
        return my_msg;
    }
};


class DayError{
private:
    std::string my_msg;
public:
    DayError(const std::string& msg): my_msg(msg){};
    string get_msg(){
        return my_msg;
    }
};

string FixDate(int month,int day){
    try{
        string word = "";
        switch(month){
            case(1):{
                word+="January";
                break;
            }
            case(2):{
                word+="February";
                break;
            }
            case(3):{
                word+="March";
                break;
            }
            case(4):{
                word+="April";
                break;
            }
            case(5):{
                word+="May";
                break;
            }
            case(6):{
                word+="June";
                break;
            }
            case(7):{
                word+="July";
                break;
            }
            case(8):{
                word+="August";
                break;
            }
            case(9):{
                word+="September";
                break;
            }
            case(10):{
                word+="October";
                break;
            }
            case(11):{
                word+="November";
                break;
            }
            case(12):{
                word+="December";
                break;
            }

        }
        if(month<1 || month>12){
            throw MonthError("Month does not exist. ");
        }
        if(day>31 || day<1){
            throw DayError("Day cannot be greater than 1 or 31.");
        }
        else if(day>30 && (month==4 || month==6 || month==9 || month==11)){
            throw DayError("Some months end on the 30th.. ");
        }
        else if(day>29 && month==2){
            throw DayError("February ends on the 29th.");
        }
        string result = word + " " + to_string(day);
        cout << result << endl;
        return result;
    }
    catch(MonthError& error){
        cout << error.get_msg() << endl;
    }
    catch(DayError& error){
        cout << error.get_msg() << endl;
    }
}

int main(){
    while(true){
        // this code will run until it has to throw an exception
        string word;
        cout << "\nPlease enter the date in month/day format!:";
        cin >> word;
        int slash_position = word.find('/');
        int month = stoi(word.substr(0,slash_position) );
        int day = stoi(word.substr(slash_position+1,word.size()) );
        FixDate(month, day);
    }

}
