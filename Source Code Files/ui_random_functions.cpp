#include "ui_random_functions.h"
#include <iostream>
#include <random>

using namespace std;

bool boolRandom(){
    random_device rd;     // Only used once to initialise (seed) engine
    mt19937 gen(rd());    // Random-number engine used (Mersenne-Twister in this case)
    uniform_int_distribution<> dis(0,1);
    
    return dis(gen) == 1;
}

bool weighted_random(double shot_acc){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    
    return dis(gen) < shot_acc;
}

int penRandom(){
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1,3);
    
    return uni(rng);
}

char side_chooser(){
    char choice;
    cout<<"Choose your side (H for heads, T for tails): ";
    cin>> choice;
    if( choice == 'H' || choice == 'h'){
        cout<<"You chose heads!"<<endl;
    }
    else if( choice == 'T' || choice == 't'){
        cout<<"You chose tails!"<<endl;
    }
    else{
        cout<<"Invalid input, please try again!:"<<endl<<endl;
        side_chooser();
    }
    
    return tolower(choice);
    
}

void pressAnyKeyToContinue() {
    cout << "Press enter to toss the coin...";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

void instructions(){
    cout<<endl<<"\033[4mINSTRUCTIONS\033[0m"<<endl;
    cout<<"This is a text based football game, where you toss a coin to decide the success of your actions."<<endl
        <<"There are 15 turns in normal time. The game begins with a coin toss for kick off."<<endl<<endl
        <<"I. Kick-Off"<<endl
        <<"1. Choose a side of the coin."<<endl
        <<"2. Toss the coin to see who kicks off."<<endl<<endl
        <<"II. In Possession"<<endl
        <<"1. Choose whether you would like to pass or shoot."<<endl
        <<"2. If you complete the pass, you will be closer to goal, and you can take an easier shot."<<endl
        <<"3. If your pass gets intercepted, you will lose possession and have to defend."<<endl<<endl
        <<"III. Out of Possession"<<endl
        <<"1. When out of possession, you will only be able to intercept passes/block shots."<<endl
        <<"2. If you do either, you will gain possession and can go into a counter-attack."<<endl
        <<"3. If you don't, the enemy can pass to take an easier shot, or take a shot at goal."<<endl<<endl
        <<"IV. Extra-Time and Penalties"<<endl
        <<"1. If normal time ends in a draw, you will have a choice to go into extra-time and penalties."<<endl
        <<"2. There are 7 turns in extra-time"<<endl
        <<"3. If extra-time also ends in a draw, you can go into penalties."<<endl
        <<"4. There are 5 penalties for each team."<<endl
        <<"5. You will begin the penalties with a shot"<<endl
        <<"6. You can choose 1 of 3 places you could both shoot your penalty and dive to save the opposition penalty: Left, Center and Right."<<endl
        <<"7. If the game hasnt been decided on one round of penalties, you can go into best of one."<<endl<<endl
        <<"Last but not least, have fun! :)"<<endl<<endl;
    cout << "Press enter to play...";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.get();
}

