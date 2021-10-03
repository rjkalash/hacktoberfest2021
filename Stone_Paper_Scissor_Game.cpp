#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{

    int quit;
    cout<< "\n\n\t\t\t\t**********WELCOME TO STONE PAPER SCISSOR GAME****************\n\n\n";

    while(quit != -1)
    {
        srand(time(0));

        int userNum;
        int randomNum;

        cout<<"1.Rock"<<endl;
        cout<<"2.Paper"<<endl;
        cout<<"3.Scissors"<<endl;
        cout<<endl;

        cin>>userNum;
        cout<<endl;

        randomNum = (rand()%3)+1;

        if(userNum == -1)
        {
            return 0;
        }
        if(userNum == randomNum)
        {
            cout<<"Tie!"<<endl;
        }
        if((randomNum == 1 && userNum == 2)||
           (randomNum == 3 && userNum ==1) ||
           (randomNum == 2 && userNum == 3))
           {
               cout<<"You Win!"<<endl;
           }
           else
           {
               cout<<"You Lose!"<<endl;
           }
    }

    return 0;
}
