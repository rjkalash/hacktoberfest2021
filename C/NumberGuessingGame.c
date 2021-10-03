#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number,  guess, nguesses=1;
  //Generate random number between 1-100 and store it in a number variable
    srand(time(0));
    number = rand()%100+1;
    //printf("the number is %d\n" , number);

    do
    {
        //Let the user to guess number between 1-100
        printf("guess the number between 1 to 100\n");
        scanf("%d", &guess);
        //Check if the number entered by user is higher or lower or correct 
        if(guess>number)
        {
            printf("lower number please!!\n");
        }
        else if(guess<number)
        {
            printf("higher number please!!\n");
        }
        else
        {
          //printing number of guess used by the user to guess the right number  
          printf("you guess it in %d attempts\n\a", nguesses);
        }
        nguesses++;
    }
    while(guess!=number);

    getch();
}
