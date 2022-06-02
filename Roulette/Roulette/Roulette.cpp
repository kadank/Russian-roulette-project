#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h> 
#include <conio.h>

using namespace std;

char choice;

int chamber = rand() % 6 + 1;

void ded() {
    cout << "you are dead lol" << endl;
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
        chamber--;
        return false;             //if alive, go down by one and pass
    }   

}

void roll() {           //rolls the chamber and shoots

    chamber = rand() % 6 + 1;
    trigger();

}

void decision() {
    bool err = false;
    do
    {
        cout << chamber << endl;
        choice = _getch();

        cout << choice << endl;

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
    
    

    for (;;) {
        
        decision();
       



    }


    
}





