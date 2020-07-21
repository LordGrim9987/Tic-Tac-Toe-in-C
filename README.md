# Tic-Tac-Toe-in-C
First major C project. Created solely by myself. A Tic-Tac-Toe CMD game that can be played by two players. 
Function Explanations:
1.	main():
It’s the main function of the program and is used to run the game by first calling the ‘menu’ function to open the menu screen of the game, and when one game has been completed, it prompts the user if he/she wants to play again. If yes, then it calls the ‘reinitialize’ function before running the do-while loop again. 
2.	menu():
It’s the first function that is called by main. Its purpose is to open the menu of the game and ask the player to choose his/her marker(X/O), and assign the marker to the player and start the game. There is also the option for exiting the game in the menu. It uses the ‘switch()’ case to ask for the player options.
3.	display_board():
This function is used to display the game-board where the game is played in a 3X3 format like that of a keypad mobile. This is achieved by using bars and dashes along with the ‘printf’ function and the ‘game_board’ array.

4.	place_marker1(ch1):
It’s a function that asks for the player input for the position that the first player wants to put his/her marker on by taking the first player’s marker as argument. It also checks if the desired position is free or not by using the ‘space_check’ function before placing the marker in that position.
5.	place_marker2(ch2):
It’s a function that asks for the player input for the position that the second player wants to put his/her marker on by taking the second player’s marker as argument. It also checks if the desired position is free or not by using the ‘space_check’ function before placing the marker in that position.
6.	win_check(mark,player[]):
It’s a function to check if a player has won or not by taking the player-marker and the player-identity(both char) as arguments, and returns 1 if the player has won the game in any way, else 0. The function uses several if-else statements to check the conditions.
7.	space_check(p):
This function is used to check if a position is free or not by taking the position(game-board index) as argument and returns 1 if the desired position is free, else 0.
8.	fullboard_space_check():
This function is used to check if there is any free space in the game-board or not with the help of the ‘space_check’ function, and returns 1 if there is any free space in the game-board, else it returns 0. It uses a for loop to iterate through each of the indexes of the ‘game_board’ array and checks for free spaces at every index using the ‘space_check’ function.
9.	initialize():
This function is used to reinitialize the game-board and set all the positions to blank-space if the user wants to play again after the completion of the first game. It uses a for loop to iterate through all the elements of the ‘game_board’ array and sets every element to blank space.
10.	 start_game():
It’s the most important function of the Tic-Tac-Toe program since it is this function that runs the game by utilising the various functions previously defined. It first defines a variable called ‘game_on’ and then runs a while loop with the condition being ‘game_on’ being true. The function uses several if-else, break and continue statements along with some library as-well-as the user-defined functions to run the game.

