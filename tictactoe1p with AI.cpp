#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

void draw_board(string board){
    system("cls");
    cout <<"Tic Tac Toe v2.0\n";
    cout <<"Player vs CPU\n";
    for(int i=1;i<board.length();i++){
        if(i%3==1) cout <<"\n";
        cout <<board[i]<<" ";
    }
    cout <<"\n\n";
}

int cpuPick(string board){
    int ret=0; //return value picked
    int count=0;
    int win_square[8][3]={ {1,2,3},
                            {4,5,6},
                            {7,8,9},
                            {1,4,7},
                            {2,5,8},
                            {3,6,9},
                            {1,5,9},
                            {3,5,7}};

    if(board[5]=='5') return 5;//get square 5 when available

    //AI calculated own row
    for(int i=0;i<8;i++){
        count=0;
        for(int j=0;j<3;j++){
            if(board[win_square[i][j]]=='O') count++;
            else ret=win_square[i][j];
        }
        if(count>1 and board[ret]!='X') return ret;
        else ret=-1;
    }

    //AI calculated human row
    if(ret==-1){
        for(int i=0;i<8;i++){
            count=0;
            for(int j=0;j<3;j++){
                if(board[win_square[i][j]]=='X') count++;
                else ret=win_square[i][j];
            }
            if(count>1 and board[ret]!='O') return ret;
            else ret=-1;
        }
    }
    if(ret==-1){ //means randomly search available square
        while(true){
            ret=rand()%9+1;
            if(board[ret]=='X' or board[ret]=='O') continue;
            else break;
        }
    }
    return ret;
}

void random_first(char &player){
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

int check_win(string board){
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

int main(){
    string board = "0123456789";//board as a string
    char player;//default human is X, cpu is O
    bool win=false;//default win flag
    int choice;//number chosen by both player and cpu
    int play=9;//loop is unlimited but valid input is limited to 9
    srand(time(0));

    cout <<"Tic Tac Toe v2.0\n";
    //random who play first
    random_first(player);

    while(play>=0)
    {
        //draw the board
        draw_board(board);

        //game ends if there's a winner
        if(win) {
            if(player=='X') cout<<"You LOSE";
            else cout<<"You WIN";
            break;
        }
        //game ends if ends in draw
        if(play==0) {cout<<"DRAW!";break;}


        if(player=='X'){ //player input manually
            cout << "Player picked...";
            cin >> choice;
            //validating human input
            if(choice<1 or choice >9){ //error input 1-9
                cout <<"chose 1-9"; Sleep(2000); continue;
            }
            if(board[choice] == 'X' or board[choice] == 'O'){ //error square already picked
                cout<<"square already picked"; Sleep(2000); continue;
            }
        }
        else{ //CPU random input
            cout << "CPU picked ";
            Sleep(2000);
            choice=cpuPick(board);
            cout <<choice;
            Sleep(2000);
        }

        //updating square
        board[choice] = player;//marking O-X
        play--;//while stops at play 0
        (player=='X')? player='O':player='X';//switch player turn


        //checking if any occur
        win=check_win(board);
    }

}

