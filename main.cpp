#include <iostream>
#include <fstream>
#include <set>
#include <unordered_set>
#include<algorithm>
using namespace std;

unordered_set<string> FileWords;

unordered_set<string> GetFromFile(string Filename){
    fstream file;
    file.open(Filename , ios::in);
    string temp;
    while(!file.eof()){
        getline(file , temp);
        FileWords.insert(temp);
    }

  return FileWords;

}


void checkWord(string message ){
    string first;
    string rest;
    bool check = false;
    string old;
    unsigned int j= message.size();
    if(message.size()!=0) {
        for (int i = 0; i < message.size(); i++) {
            first = message.substr(0, i + 1);
            rest = message.substr(i + 1, message.size() - (i + 1));
            unordered_set <string>:: const_iterator itr;
            itr = FileWords.find(first);
            j--;

            if (itr != FileWords.end()) {
                cout << first << " ";
                check = true;
                old = first;
                message.erase(0, i + 1);
                break;
            }



        }
        checkWord(message);
        if(!check){
            for(int k = 0; k<message.size() ; k++){
                string temp;


                string forBacktrack = old+temp;
                temp = forBacktrack.substr(0,k+2);
                unordered_set <string>:: const_iterator itr;
                itr = FileWords.find(forBacktrack);
                if(itr != FileWords.end()){
                    cout<<forBacktrack<<endl;
                }

            }


        }
    }







    }











/*class PutSpace{
private :
    vector <string> FileWords;
string Message ;

public:
    long long i =0;
    int j=1;
    void setMessage(string message){
        Message = message;

    }
    void takeFromFile(string Filename){
        ifstream file ;
        file.open(Filename , ios:: in );
        string temp;
        while(getline(file , temp )){
         // size_t pos=  temp.find((Message.substr(0 , j)));
         // if (pos!= string::npos){
         FileWords.push_back(temp);

          }
cout<<FileWords[4]<<endl;



        file.close();
    }


    bool isInFile(const string& subMessage){


        if (subMessage== FileWords[i]){
            cout<<"true";

            return true;

        }
        else{
            i++;
           // cout<<"in else in isinfile";
            isInFile(subMessage);

        }
        if ( i >= FileWords.size()){
            cout<<"false";
            return false;
        }





    }
    //check if the first char is a word
    // if it's a word, return true and store it somewhere
    //if not , check if the first and second char are a word

    string constructSubStr(){
        cout<<"unknown here"<<endl;

        string mySubstr = Message.substr(0, j);
        if (isInFile(mySubstr)){
            cout<<"\n is it here\n";


            return mySubstr;
        }
        else{
            j++;

            cout<<"true";
            constructSubStr();

        }
    }

    vector<string> constructPossibleMessage(){

        vector<string> constructedMessage;
        if(j == Message.size()){

            constructedMessage.push_back(constructSubStr());
            cout<<Message.size();

            return constructedMessage;
        }
        else if (j<Message.size()){
            cout<<"here"<<j;

            constructedMessage.push_back(constructSubStr());
            constructedMessage.push_back(" ");
            constructPossibleMessage();
        }

    }
};

*/

int main(){

    GetFromFile("dictionary.txt");


   checkWord("army" );
\
  /*  unordered_set<string> :: iterator itr;
    for (itr = FileWords.begin(); itr != FileWords.end(); itr++)
        cout << (*itr) << endl;*/


}