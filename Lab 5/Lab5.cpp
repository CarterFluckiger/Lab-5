/*
 Carter Fluckiger
 C++ Fall 2019
 Due:  October 24, 2019
 Lab: I wrote a number-guessing game in which the computer selects a random
 number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
 the end of each game, users should be told whether they won or lost, and then be asked
 whether they want to play again. When the user quits, the program should output the
 total number of wins and losses. To make the game more interesting, the program
 should vary the wording of the messages that it outputs for winning, for losing, and for
 asking for another game. Create 10 different messages for each of these cases, and use
 random numbers to choose among them. This application should use at least one Do-
 While loop and at least one Switch statement. Write your C++ code using good style and
 documenting comments. You should use functions in your code as well. Your source
 code file should be called Lab5.cpp.
 */
#include <iostream>
#include <time.h>
#include <cassert>
using namespace std;
 int userinput;
void switchwin();
void askswitch();
void switchlose();
void urmom(int&userinputurmom,int&randomnumber);

int main()
{
    
    int playagain;
    int win=0;
    int loss=0;
    srand((unsigned int) time(NULL));
    // output to screen random number between 1 and 10
    bool play= true;
do
{
    // Seed random number
    int randomnumber = rand()% 101;

    for (int game=1;game<=20;game++)
    {
        cout<<randomnumber;
    cout<<"Guess a the random number that is between 0 and 100: ";
    cin>>userinput;

        if(!cin)
              {
                  cout<<"Invalid Input"<<endl;
                  return 3;
              }

    if(randomnumber == userinput)
  {
      switchwin();
      //switch(switchrandomnumber)
             //The question needs to change not the enter 1 to play
      askswitch();
       cout<<endl<<"Enter 1 to play again"<<endl<<"Enter 2 to end the game and display your score"<<endl;
       cin>> playagain;
       switch (playagain)
       {
           case 1: play=true;
               break;
           case 2: play = false;
               break;
           default:cout<<"Invalid input"<<endl;
           return 2;
       }
      win++;
      break;
  }
        if(randomnumber != userinput && userinput<=100 && userinput>=0)
        {
        switchlose();
        }
        if(userinput>100 || userinput<0)
        {
            cout<<"This input is not between 0 and 100"<<endl;
        }
  if(game>=20)
  {
      //switch(switchrandomnumber)
          //The question needs to change not the enter 1 to play
      askswitch();
    cout<<endl<<"Enter 1 to play again"<<endl<<"Enter 2 to end the game and display your score"<<endl;
    cin>> playagain;
    switch (playagain)
    {
        case 1: play=true;
            break;
        case 2: play = false;
            break;
        default: cout<<"Invalid input"<<endl;
            return 1;
    }
      loss++;
  }
    }
}while (play);
    
    cout<<"Wins:"<<win<<endl<<"Losses:"<<loss<<endl;
    return 0;
}

void switchwin()
{
    srand((unsigned int) time(NULL));
switch(rand()% 10+1)
    {
    case 1: cout<<"You're a winner"<<endl;
        
        break;
    case 2: cout<<"Technically that is the correct answer"<<endl;
        break;
    case 3: cout<<"Wow, you can guess a number. Good job "<<endl;
        break;
    case 4: cout<<"That was the answer we were looking"<<endl;
        break;
    case 5: cout<<"Unfortunatly you guessed correctly"<<endl;
        break;
    case 6: cout<<"You really used your whole brain to get that one correct"<<endl;
        break;
    case 7: cout<<"7win"<<endl;
        break;
    case 8: cout<<"8win"<<endl;
        break;
    case 9: cout<<"9win"<<endl;
        break;
    case 10:cout<<"10win"<<endl;
        break;
        //10 statements for correct answers
        //Can I put the asking statement to playagain after every correct answer?
    }
}

void askswitch()
{
       srand((unsigned int) time(NULL));
    switch(rand()% 10+1)
    {
        case 1:cout<<"So do you think you want to play?"<<endl;
            break;
        case 2:cout<<"Would you like to play again?"<<endl;
             break;
        case 3:cout<<"I bet you won't play again?"<<endl;
             break;
        case 4:cout<<"If you would like to play again?"<<endl;
             break;
        case 5:cout<<"Hey, do you want to play again?"<<endl;
            break;
        case 6:cout<<"You're not very good do you want to play again?"<<endl;
            break;
        case 7:cout<<"You are very bad at this game. . . please quit. . . play again?"<<endl;
             break;
        case 8:cout<<"Please play again so you lose. Play?"<<endl;
             break;
        case 9:cout<<"Play again?"<<endl;
             break;
        case 10:cout<<"You're trash, would you like to play again?"<<endl;
             break;
    }
}
void switchlose()
{

    cout<<endl;
    switch(rand()% 10+1)
    {
        case 1: cout<<"Why are you so stupid?"<<endl;
            break;
        case 2: cout<<"I'm not going to lie that wasn't even close"<<endl;
            break;
        case 3: cout<<"Wait . . . you're a math teacher? Hysterical"<<endl;
            break;
        case 4: cout<<"Are you even trying?"<<endl;
            break;
        case 5: cout<<"You're kind of an idiot and that the nice way of putting it"<<endl;
            break;
        case 6: cout<<"Wow,  wrong again:("<<endl;
            break;
        case 7: cout<<"Not what we were looking for there"<<endl;
            break;
        case 8: cout<<"INCORRECTTTTTTTT"<<endl;
            break;
        case 9: cout<<"And that is another wrong answer"<<endl;
            break;
        case 10:cout<<"Worst guessing I've ever seen"<<endl;
        
        


}
}

