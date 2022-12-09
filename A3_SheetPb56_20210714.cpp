
/*
Author: Selsabeel Asim Ali Elbagir
 ID: 20210714
 Section: S11
 Assignment: 3
 Course: CS213
 Date created: 7th December, 2022
Purpose:
 */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool isBadPosition();
int FindGoodMove();

class Board{
private:
    char board[5][5];
public:
    Board(){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                board[i][j]='0';
                }
            }
            board[0][0] = 'X'; board[0][4] = 'X'; board[4][0] = 'X'; board[4][4] = 'X';
            board[0][1] = 'V'; board[0][2] = 'V'; board[0][3] = 'V';
            board[1][0] = '>'; board[2][0] = '>'; board[3][0] = '>';
    }
    bool validMove(int x, int y, bool player){
        if(player == 0 ){
            if(board[x][y] == '0' && board[x-1][y] == 'V'){
                return true;
            }
            if(board[x][y] == '0' && board[x-1][y] == '>' && board[x-2][y] == 'V' ){
                return true;
            }
        }
        if(player == 1){
            if(board[x][y] == '0' && board[x][y-1] == '>'){
                return true;
            }
            if(board[x][y] == '0' && board[x][y-1] == 'V' && board[x][y-2] == '>' ){
                return true;
            }
        }
        else return false;
    }
    bool validMovesLeft(bool player){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(validMove(i,j,player)){
                    return true;
                }
            }
        }
        return false;
    }
    bool skipTurn(bool player){
        if(player ==0){
            for(int i=1;i<4;i++){
                for(int j=1;j<4;j++){
                    if(board[i][j] == '>' && board[i-1][j] == '>'){
                        return true;
                    }
                }
            }
        }
        if(player==1){
            for(int i=1;i<4;i++){
                for(int j=1;j<4;j++){
                    if(board[i][j] == 'V' && board[i][j-1] == 'V'){
                        return true;
                    }
                }
            }
        }
        else return false;
    }
    void updateBoard(int x, int y, bool player){
        if(validMove(x, y, player)){
            if(player == 0){
                if(board[x-1][y] != '>'){
                    board[x][y] = 'V';
                    board[x-1][y] = '0';
                }
                else{
                    board[x][y] = 'V';
                    board[x-2][y] = '0';
                }
            }
            if (player == 1){
                if(board[x][y-1] != 'V'){
                    board[x][y] = '>';
                    board[x][y-1] = '0';
                }
                else{
                    board[x][y] = '>';
                    board[x][y-2] = '0';
                }
            }
        }
        else{
            cout << "\nERROR! Invalid move\n";
        }
        cout << endl;
        printBoard();
    }

    void printBoard(){
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void playGame(){
        int x, y;
        bool player = 1;
        bool isGameOver = false;
        while(!isGameOver){
            cout << "Player " << player << " enter your move: ";
            cin >> x >> y;
            if(skipTurn(player)){
                cout << "Player " << player << " has two enemy rockets in front of it, so it cannot move. Skipping turn.\n";
                player = !player;
                continue;
            }
            if(validMovesLeft(player)){
                updateBoard(x,y, player);
            }
            if(!validMovesLeft(player)){
                isGameOver = true;
                cout << "Player " << player << " has no valid moves left. Game Over!\n";
            }
            if(board[4][1] == board[4][2] == board[4][3] == 'V'){
                isGameOver = true;
                cout << "Player " << 0 << " wins!\n";
            }
            if(board[1][4] == board[2][4] == board[3][4] == '>'){
                isGameOver = true;
                cout << "Player " << 1 << " wins!\n";
            }
            player = !player;
        }
    }
};
int main(){

    Board b1;
    b1.printBoard();
    b1.playGame();
    return 0;
}