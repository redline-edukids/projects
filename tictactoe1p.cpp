#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

void drawBoard(string board){
    system("cls");
    cout <<"Tic-Tac-Toe 1P\n";
    cout <<"Player vs CPU\n";
    for(int i=1;i<board.length();i++){
        if(i%3==1) cout <<"\n";
        cout <<board[i]<<" ";
    }
    cout <<"\n\n";
}
bool checkWin(string board){
    bool win=0;
    if (board[1] == board[2] && board[2] == board[3]) {win=1; }
    else if (board[4] == board[5] && board[5] == board[6]) {win=1; }
    else if (board[7] == board[8] && board[8] == board[9]) {win=1; }
    else if (board[1] == board[4] && board[4] == board[7]) {win=1; }
    else if (board[2] == board[5] && board[5] == board[8]) {win=1; }
    else if (board[3] == board[6] && board[6] == board[9]) {win=1; }
    else if (board[1] == board[5] && board[5] == board[9]) {win=1; }
    else if (board[3] == board[5] && board[5] == board[7]) {win=1; }
    return win;
}
void randomFirst(char &player){
    system("cls");
    cout <<"Tic-Tac-Toe 1P\n";
    for(int i=0;i<rand()%2+15;i++){
        if(i%2==0){
            cout<<"\rPlayer";player='X';
        }
        else{
            cout<<"\r   CPU";player='O';
        }
        Sleep(i*50);
    }
    Sleep(1500);
    cout<<" first";
    Sleep(2000);
}

int main(){
    srand(time(0));
    string board = "0123456789";
    char player;//default is player X, cpu O
    bool win=0;//win flag
    int choice;//choice of which square to pick
    int play=9;//play will limit the while loop to 9 valid choice

    //random first play
    randomFirst(player);

    while(play>=0)
    {
        //draw board
        drawBoard(board);

        //declare if anyone win
        if(win) {
            if(player=='X') cout<<"Player LOSE";
            else cout<<"Player WIN";
            break;
        }
        //declare if ends draw
        if(play==0) {cout<<"DRAW!";break;}

        //player input
        if(player=='X'){
            cout << "Player's turn ";
            cin >> choice;
            //validating input
            if(choice<1 or choice >9){//errmessage input not 1-9
                cout <<"enter 1-9"; system("pause>0"); continue;
            }
            if(board[choice] == 'X' || board[choice] == 'O'){//errmessage already picked
                cout<<"square already picked"; system("pause>0"); continue;
            }
        }
        //CPU random input
        else{
            cout << "CPU's turn...";Sleep(2000);
            if(board[5]!='X' and board[5]!='O') choice=5;//get square 5 if available
            else{
                while(true){
                    choice=rand()%9+1;
                    if(board[choice]=='X' or board[choice]=='O') continue;
                    else break;
                }
            }
            cout << "pick "<<choice;Sleep(2000);
        }

        //updating board
        board[choice] = player;//marking O-X

        //while stops at play 0
        play--;

        //switch turn between player & cpu
        if(player=='X'){
            player='O';
        }
        else{
            player='X';
        }

        //checking any win
        win=checkWin(board);
    }

}

