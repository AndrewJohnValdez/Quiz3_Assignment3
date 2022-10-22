#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int userChoice;
int base_value = 10;
int max_value = 100;
FILE * fPtr;

void settings() {
    int choice;
    int userInput;
    int done = -1;
    
    //while loop to keep the cycle continuing
    do {
        printf("Please set your desired max value: (Limit: 100)\n");
        scanf("%d", &userInput);

        //if statement to check if the inputs are valid or not
        if(userInput > 1 && userInput < max_value) {
            done = 0;
        } else {
            printf("Invalid input\n");
        }
    } while(done == -1);

    printf("New max value set \n");
    base_value = userInput;

    fPtr = fopen("user_value.txt", "w+");
    fprintf(fPtr, "%d", base_value);
    fclose(fPtr);
    return;
}

void generator(int num) {

    int number;
    char userInput[100];
    int userNum;

    srand(time(NULL));

    number = (rand() % num) + 1;

    gets(userInput);
    
    //if statements depending on the user guess and if correct or wrong
    do {
        printf("Guess a number between 1 and %d\n", num);
        gets(userInput);

        if(userInput[0] == 'q'){
            return;
        }
        userNum = atoi(userInput);
        if(userNum > base_value || userNum < 1) {
            //checks for invalid guesses 
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
}


int main() 
{
    int key;
    char fileVal[100];

    fPtr = fopen("user_value.txt", "r+");
    if(fPtr == NULL) {
        fPtr = fopen("user_value.txt", "w+");
        fprintf(fPtr, "%d", 10); //base value if file is new 
    } else {
        fgets(fileVal, 100, (FILE*)fPtr);
        base_value = atoi(fileVal);
    }
    fclose(fPtr);

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
            generator(base_value);
        } else if (userChoice == 2) {
            //allow user to change base_value
            settings();
        } else if (userChoice == 3) {
            printf("Thanks for Playing\n");
            fclose(fPtr);
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
