#include <stdio.h>
#include<stdlib.h>  //for 'system("cls")' and 'exit()' functions
#include<string.h>  //for 'strcmp' and 'strcpy' functions

/*
**Console-based tic-tac-toe game for Windows created by Ranit Barman(CSE-43/19; ASTU-190710007043) as C-Programming project.**
**Started coding on 01/07/2020.**
**Ended coding on 04/07/2020.**
*/

void menu();
void place_marker1(char);
void place_marker2(char);
void start_game();
void display_board();
int win_check(char, char[]);
int space_check(int);
int fullboard_space_check();
void initialize();

char game_board[10]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};  //initializing the game board
char player1_marker,player2_marker; //variables that hold the markers(X,O) for the two players

void main()
{

    char chc;
    do
    {
        system("cls");  //to clear the screen
        fflush(stdin);  //to clear the input buffer
        fflush(stdout); //to clear the output buffer
        menu();
        printf("\nDo you want to play again(Y/y)?: ");
        scanf(" %c",&chc);
        initialize();   //to re-initialize the board if the player wants to play again
    }while(chc=='Y' || chc=='y'); //to ask if the players want to play again


}

void menu() //the menu screen of the game
{
    int choice;
    //system("cls");
    puts("Welcome to Tic-Tac-Toe");
    puts("This game will be played between two players");
    printf("\n----------MENU----------\n");
    puts("Player 1, choose your marker:");
    puts("1. Play as X");
    puts("2. Play as O");
    puts("3. Exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            player1_marker='X'; player2_marker='O';
            start_game();
            break;
        case 2:
            player1_marker='O'; player2_marker='X';
            start_game();
            break;
        case 3:
            exit(1);
        default:
            menu();
    }
}

void display_board()    //to format the game board and display it
{
    system("cls");
    puts("\nGame Board:");
    printf("\n %c | %c | %c ",game_board[1],game_board[2],game_board[3]);
    printf("\n-----------");
    printf("\n %c | %c | %c ",game_board[4],game_board[5],game_board[6]);
    printf("\n-----------");
    printf("\n %c | %c | %c \n",game_board[7],game_board[8],game_board[9]);
}

void place_marker1(char ch1)    //to ask the player-1 for input and placing the player's marker on that position
{
    int pos1;
    printf("\nPlayer-1, place your marker on a desired position(1-9): ");
    scanf("%d",&pos1);
    if(space_check(pos1))
        game_board[pos1]=ch1;
}

void place_marker2(char ch2)    //to ask the player-2 for input and placing the player's marker on that position
{
    int pos2;
    printf("\nPlayer-2, place your marker on a desired position(1-9): ");
    scanf("%d",&pos2);
    if(space_check(pos2))
        game_board[pos2]=ch2;
}

int win_check(char mark, char player[10])   /*to check if the player currently holding the control of the game has won or not
                                             *returns 1 if the player has won in any of the three ways(horizontal, vertical or diagpnal)
                                             *returns 0 is the player hasn't won*/
{
    if (game_board[1] == game_board[2] && game_board[2] == game_board[3] && game_board[3]== mark)   //horizontal check
        {
            printf("\n%s has won!!",player);
            return 1;
        }

    else if (game_board[4] == game_board[5] && game_board[5] == game_board[6] && game_board[6] == mark) //horizontal check
        {
            printf("\n%s has won!!",player);
            return 1;
        }

    else if (game_board[7] == game_board[8] && game_board[8] == game_board[9] && game_board[9] == mark) //horizontal check
        {
            printf("\n%s has won!!",player);
            return 1;
        }

    else if (game_board[1] == game_board[4] && game_board[4] == game_board[7] && game_board[7] == mark) //vertical check
        {
            printf("\n%s has won!!",player);
            return 1;
        }

    else if (game_board[2] == game_board[5] && game_board[5] == game_board[8] && game_board[8] == mark) //vertical check
        {
            printf("\n%s has won!!",player);
            return 1;
        }

    else if (game_board[3] == game_board[6] && game_board[6] == game_board[9] && game_board[9] == mark) //vertical check
        {
            printf("\n%s has won!!",player);
            return 1;
        }

    else if (game_board[1] == game_board[5] && game_board[5] == game_board[9] && game_board[9] == mark) //diagonal check
        {
            printf("\n%s has won!!",player);
            return 1;
        }

    else if (game_board[3] == game_board[5] && game_board[5] == game_board[7] && game_board[7] == mark) //diagonal check
        {
            printf("\n%s has won!!",player);
            return 1;
        }
    else
        return 0;
}


int space_check(int p)  /*to check if a position is free or not
                         *returns 1 if it's free, otherwise it returns 0*/
{
    if(game_board[p]==' ')
        return 1;
    else
        return 0;
}

int fullboard_space_check() /*to check if there's any free space in the game board or not
                             *returns 1 if there's, otherwise it returns 0*/
{
    int i;
    for(i=1;i<10;i++)
    {
        if(space_check(i))
            return 1 ;
    }
    return 0;
}

void initialize()   //function to re-initialize the board to blank values
{
    int i;
    for(i=1;i<10;i++)
        game_board[i]=' ';
}

void start_game()   //the main function of the game; the function that runs the game
{
    int game_on=1;
    while(game_on)
    {
        char player[10]="Player-1"; //code section for player-1
        if(!strcmp(player,"Player-1"))
        {
            place_marker1(player1_marker);
            display_board();
            if(!win_check(player1_marker,player))
            {
                strcpy(player,"Player-2");  //transfers the control to player-2
                if(fullboard_space_check())
                {
                    place_marker2(player2_marker);
                    display_board();
                    if(win_check(player2_marker,player))
                        break;
                    else
                        continue;
                }
                else
                {
                    puts("\nThe game is a draw!!");
                    game_on=0;
                    break;
                }
            }
            else
            {
                game_on=0;
                break;
            }
        }
        else
            {
                place_marker2(player2_marker);  //code section for player-2
                display_board();
                if(!win_check(player2_marker,player))
                {
                    strcpy(player,"Player-1");  //transfers the control to player-1
                    if(fullboard_space_check())
                    {
                        place_marker1(player1_marker);
                        display_board();
                        if(win_check(player1_marker,player))
                            break;
                        else
                            continue;
                    }
                }
            }
    }

}


