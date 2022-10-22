/*
Create an interactive program
    allows user to guess a number between 1-10 (default)
    have main menu of up to 3 choices
        1 - play game 
        2 - ability to change value limit but cannot go past MAX VALUE
            Note:
                must be able to back out of this side menu
        3 - quit
            thank user for the program ends

Create a new branch once program is completed
save_user_max_number
    remember the user's chosen max value for the next time the game starts (dynamic linking?)
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int userChoice;
int base_value = 10;
int max_value = 100;
int N = 10;

void settings() {

}

void playGame() {
    
}

void generator(int num) {

    int number = 0;
    char userInput[10];
    int userNum;

    srand(time(NULL));

    number = rand() % num;
    
    //if statements depending on the user guess and if correct or wrong
    do {
        printf("Guess a number between 1 and %d\n", num);
        gets(userInput);

        if(userInput[0] == 'q'){
            return;
        }
        userNum = atoi(userInput);
        if(userNum > base_value || userNum < 1) {
            printf("Please pick a number within the limits\n");
        } else if(userNum < number) {
            printf("Pick a higher value\n");
        } else if(userNum > number) {
            printf("Pick a lower value\n");
        } else {
            printf("Great Job! The number was %d\n", number);
        }
        if(userNum == number) {
            return;
        }
    } while (userNum != number);
    //Create an if statement regarding invalid guesses (going past max_value or base_value or letters/decimals)
}


int main() 
{
    int key;

    //print a main menu at start
    printf("///////////////////\n");

    printf("Please Choose: \n");
    printf("Press 1 to play a game \n");
    printf("Press 2 to change the max number \n");
    printf("Press 3 to quit\n");

    printf("///////////////////\n");


    //read information from console
    scanf("%d", &userChoice);
    if(userChoice == 1 || userChoice == 2) {
        key = 1;
    }

    //prompt menu with the 3 options
    //scanf provided to read input and if statement to display next part
    while(key = 1) {
        if(userChoice == 1) {
            //call method for game functions
            generator(N);
        } else if (userChoice == 2) {
            //allow user to change base_value
            settings();
        } else if (userChoice == 3) {
            printf("Thanks for Playing");
            return EXIT_SUCCESS;
        }

        printf("///////////////////\n");

        printf("Please Choose: \n");
        printf("Press 1 to play a game \n");
        printf("Press 2 to change the max number \n");
        printf("Press 3 to quit\n");

        printf("///////////////////\n");
        scanf("%d", &userChoice);
    }
    return EXIT_SUCCESS;
}


/*
Must create a branch that will save the user's input value

dynamic linking possible?
*/
