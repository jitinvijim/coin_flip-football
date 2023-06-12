#include "action_functions.h"
#include "ui_random_functions.h"
#include <iostream>
#include <cctype>
#include <chrono>
#include <thread>
#include <random>
#include <array>

using namespace std;

void attacking (int* score, bool& possession, double& shot_acc, int& consec_passes){
  
    int action_choice;
    while (true) {
    cout << "You have the ball! You can now choose among the following choices: " << endl
         << "1. Pass" << endl
         << "2. Shoot" << endl
         << "Enter the index of the choice you would like to make: ";

    cin >> action_choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout <<endl<<"Invalid choice. Please enter a valid choice." << endl;
    } else if (action_choice == 1 || action_choice == 2) {
        break;
    } else {
        cout <<endl<< "Invalid choice. Please enter a valid choice." << endl;
    }
}

    
    char choice = side_chooser();
    pressAnyKeyToContinue();
    
    if(action_choice == 2){
        bool coin = weighted_random(shot_acc);
        if((coin && choice == 'h') || (!coin && choice == 't')){
            cout<<endl<<endl<<"CONGRATULATIONS!! YOU HAVE SCORED!!"<<endl;
            score[0]++;
            cout<<"The score is now "<<score[0]<<"-"<<score[1]<<endl;
            cout<<endl<<"It's time for Kick-off!"<<endl;
        }
        else{
            cout<<endl<<"Oh no! Your shot has been blocked by their goalkeeper!"<<endl;
        }
        consec_passes = 0;
        shot_acc = 0.25;
        possession = false;
    }
    else{
        bool coin = boolRandom();
        if((coin && choice == 'h') || (!coin && choice == 't')){
            if(consec_passes < 4){
               cout<<endl<<"You have passed successfully! You are now closer to goal!"<<endl;
                consec_passes++;
                shot_acc+=0.25; 
            }
        }
        else{
            cout<<endl<<"Oh no! Your pass has been intercepted!"<<endl;
            shot_acc = 0.25;
            consec_passes = 0;
            possession = false;
        }
    }
}