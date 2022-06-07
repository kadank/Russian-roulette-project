#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h> 
#include <conio.h>

using namespace std;

char choice;

int chamber = rand() % 6 + 1;

int players;

void lived() {
    cout << "click..." << endl;
}

void ded() {
    cout << "BAM... Untortunately, you are dead!" << endl;
    players--;
    if (players == 1)
    {
        cout << " Aaaand we have a winner!";
        exit(0);
    }
}

bool trigger() {        //shoots

    if (chamber == 1)
    {
        ded();
        chamber = rand() % 6 + 1; //if got shot, roll the chamber and pass
        return true;
    }
    else
    {
        lived();
        chamber--;
        return false;             //if alive, go down by one and pass
    }   

}

void roll() {           //rolls the chamber and shoots

    cout << "and a spin..." << endl;
    chamber = rand() % 6 + 1;
    trigger();

}

void decision() {       //the player decides what to do
    bool err = false;
    cout << "what will you do?" << endl;
    do
    {
        choice = _getch();


        err = false;
        switch (choice)
        {
        case 'r':
            roll();
            break;
        case 's':
            trigger();
            break;
        default:
            cout << "wrong input" << endl;
            err = true;
        }
    } while (err == true);
}


int main()
{
    srand(time(NULL));
                                                                        //introduction to the game

    cout << "Welcome to the russian roulette!" << endl << "The rules are simple here - press S to shoot, or R to spin the chamber, you might get lucky with it" << endl << endl;
    cout << "Now choose the amount of players:" << endl;
    cin >> players;
    cout << "anytime you shoot, or spin, you pass the gun to the guy on the left" << endl << endl;

    for (int i=1;;) {       //main gameplay loop

        cout << endl << "Round " << i << endl << endl;
        i++;
        decision();
        cout << "the gun is being passed on..." << endl << endl;
    }


    
}





