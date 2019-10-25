/*
 Carter Fluckiger
 C++ Fall 2019
 Due:  October 24, 2019
 Lab: I wrote a number-guessing game in which the computer selects a random
 number in the range of 0 to 100, and users get a maximum of 20 attempts to guess it. At
 the end of each game, users are told whether they won or lost, and then be asked
 whether they want to play again. When the user quits, the program should outputs the
 total number of wins and losses. To make the game more fun there are varying messages.
 */
// These are the libraries need iostream because it is everything, time.h for the random number generater
#include <iostream>
#include <time.h>
//using standard namespace
using namespace std;
//void switchwin is for the switch statement containing the possible statements output when the correct number is guessed
void switchwin();
//void askswitch is used for the switch statement used to ask if the user would like to play again
void askswitch();
// void switchlose is the void used for the switch statements that can be output when the wrong answer is guessed
void switchlose();
//int askplay is the function that has the inputs for if the user wants to quit or continue
int askplay(bool&play_,int&playagain);
//This is the main
int main()
{
    // int userinput is for what the play inputs while guessing the number
    int userinput;
    // int playagain is used for when the user decides to continue or quit the game
    int playagain;
    // int win and loss are used to calculate the wins and losses of the user
    int win=0;
    int loss=0;
    //This statement is used for the random number statement
    srand((unsigned int) time(NULL));
    //bool play is used in the do while loop and is how the loop stops or goes through another iteration
    bool play= true;
//This do while loop is used to continue the game or quit the game if the user chooses which they want
do
{
    // Seed random number for the number to be guessed
    int randomnumber = rand()% 101;
    //This for statement is used to loop the asking of a guess 20 times so the user can have that many guesses
    for (int game=1;game<=20;game++)
    {
        //This if statement is used to get rid of bad userinputs and gracefully exits the program
        if(!cin)
        {
            cout<<"Invalid Input"<<endl;
            return 3;
        }
        // This cout and cin asks and recieves the userinputs respectfully
    cout<<"Guess a the random number that is between 0 and 100: ";
    cin>>userinput;
       //This if statment is used for if the userinput is equal to the random number that is generated
    if(randomnumber == userinput)
  {
      //This a void function used for the switch statements for if the user wins the game
      switchwin();
      //This void function for the switch statements asing if the player wants to play again
      askswitch();
      
      // This is an int function that contains a cout that has the options for if the player wants to play again
      // It also has the switch that lets the user decide whether they want to play
      askplay(play,playagain);
      //This is an if statement that gracefully ends the program if the user inputs a bad input while selecting if
      //they want to play again
      if(!playagain || playagain>2||playagain<1)
           {
               return 4;
           }
      //This win++ statement adds a 1 to the variable win to calculate the total wins
      win++;
      break;
  }
        //This is an if statement that is used when the input is not equal to the randomnumber
        if(randomnumber != userinput && userinput<=100 && userinput>=0)
        {
        //This void statement is switch statement for losing messages displayed when the guess is incorrect
        switchlose();
        }
        //This if statement is for if the userinput is not within the stated perameters stated above
        if(userinput>100 || userinput<0)
        {
            cout<<"This input is not between 0 and 100"<<endl;
        }
    //This is an if statement for if the user guess 20 times and does not guess the correct answer
  if(game>=20)
  {
      //This void function for the switch statements asing if the player wants to play again
      askswitch();
      
      // This is an int function that contains a cout that has the options for if the player wants to play again
      // It also has the switch that lets the user decide whether they want to play
      askplay(play,playagain);
      
      //This an if statement to gracefully ends the program if the input is out of parameters when asking if the user wants to
      //playy again
      if(!playagain || playagain>2||playagain<1)
      {
          return 4;
      }
      //This loss++ is for calculating the losses for the end of the program
      loss++;
  }
    }
    // This is the end of the do while stated above where the bool variable play is asigned true or falsed based of if
    // the player wants to play again.  If the player wants to play again they select the option that makes play true
    // and it loops until they don't want to play again and choose the false option
}while (play);
    // This cout outputs the wins and losses when game is over
    cout<<"Wins:"<<win<<endl<<"Losses:"<<loss<<endl;
    return 0;
}
//This is a void statement that has the switch statements for winning the game
void switchwin()
{
    //seed for random number for the switch statement
    srand((unsigned int) time(NULL));
switch(rand()% 10+1)
    {
    //These are the cases that contain the win statements and a break statement to get out of switch statement
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
    case 7: cout<<"That is the correct guess"<<endl;
        break;
    case 8: cout<<"I hope you don't think that correct answer was skillfull"<<endl;
        break;
    case 9: cout<<"Wow, that took a lot of effort congratulations"<<endl;
        break;
    case 10:cout<<"That is the correct nummber.  Good for your self esteem"<<endl;
        break;
    }
}
//This is the void statment for the switch statements that ask if the player wants to play again
void askswitch()
{
    //seed for random number for the switch statement
       srand((unsigned int) time(NULL));
    switch(rand()% 10+1)
    {
        //These are the cases that contain the do you want to play again statements and a break statement to get out of switch
        //statement
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
//void statment for the switch statments for losing the game
void switchlose()
{
    cout<<endl;
    //seed for random number
    switch(rand()% 10+1)
    {
        //Theses are the cases for the statements that are output when the user loses and the break statements that get
        // it out of the switch statement
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
//This is the int function that is used as the options for when the user selects the if they want to play again or not
int askplay(bool&play_,int&playagain_)
{
    //cout promting the user to select 1 or 2 for whether they want to play again
cout<<endl<<"Enter 1 to play again"<<endl<<"Enter 2 to end the game and display your score"<<endl;
    //cin the selection of the user
      cin>> playagain_;
    //switch statement for using the player input to either continue the game or quit by assigning the bool play_ true or false
    // making the do while stop or continue accordingly
      switch (playagain_)
      {
            // The case statements and breaks to continue the program
          case 1: play_=true;
              break;
          case 2: play_ = false;
              break;
        //default used for if the user inputs an inproper input
        default:cout<<"Invalid input"<<endl;
                return 2;
           
      }
    return 0;
}
