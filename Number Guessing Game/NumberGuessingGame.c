#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int number, guess, attempts = 0;
    srand(time(NULL));
    number = rand() % 100 + 1; // Random number between 1 and 100

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100. Can you guess it?\n");
    printf("Enter your guess: ");
    scanf("%d", &guess);
    while (guess != number) {
        attempts++;
        if(guess < number){
            printf("Too Low, try again: ");
            scanf("%d", &guess);
        } else if (guess > number){
            printf("Too High, try again: ");
            scanf("%d", &guess);
        }
    }
    if(guess == number){
        printf("Congratulations, the number was %d and you did it in %d attempts.", number, attempts);
    }
    return 0;
}