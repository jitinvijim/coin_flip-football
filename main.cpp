#include <iostream>
#include <cctype>
#include <chrono>
#include <thread>
#include <random>
#include <array>
#include "action_functions.h"
#include "ui_random_functions.h"

using namespace std;

int main() {
    
    char choice;
    cout<<"WELCOME TO COIN FLIP FOOTBALL!"<<endl<<endl;
    while (true) {
        cout << "Before we play, would you like to see the instructions? (Y/N): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            instructions();
            break;
        } else if (choice == 'n' || choice == 'N') {
            break;
        } else {
            cout << "Invalid input. Please try again." <<endl<<endl;
        }
    }
    cout<<endl<<"Kick-off!"<<endl;
    
    choice = side_chooser();
    pressAnyKeyToContinue();
    bool coin = boolRandom();
    
    bool kickoff;
    if(coin){
        kickoff = (choice == 'h') ? true : false;
        cout<<"Result of coin flip: Heads"<<endl;
    }
    else{
        kickoff = (choice == 't') ? true : false;
        cout<<"Result of coin flip: Tails"<<endl;
    }
    int* score = new int[2]{0, 0};
    
    score = match(0, kickoff, score, 15);
    
    if(score[0] == score[1]){
        cout<<endl<<"The match has ended level. Would you like to continue to extra time?(Y/N): ";
        cin>>choice;
        if(choice == 'y' || choice == 'Y'){
            cout<<endl<<"Extra Time Kick Off!"<<endl;
            char choice = side_chooser();
            pressAnyKeyToContinue();
            bool coin = boolRandom();
    
            if(coin){
                kickoff = (choice == 'h') ? true : false;
                cout<<"Result of coin flip: Heads"<<endl;
            }
            else{
                kickoff = (choice == 't') ? true : false;
                cout<<"Result of coin flip: Tails"<<endl;
            }
            score = match(0, kickoff, score, 7);
            if(score[0]==score[1]){
                cout<<"It's a tight game. Would you like to go to penalties? (Y/N): ";
                cin>>choice;
                if(choice == 'y' || choice == 'Y'){
                    penalties(5);
                }
            }
            else
            {
                cout<<endl<< "AND THATS THE FINAL WHISTLE!! What a tight game! The match has ended "<<score[0]<<"-"<<score[1]<<". Thank you for playing!";
            }
        }
        else{
            cout<<endl<< "AND THATS THE FINAL WHISTLE!! The match has ended "<<score[0]<<"-"<<score[1]<<". Thank you for playing!";
        }
    }
    else{
        cout<<endl<< "AND THATS THE FINAL WHISTLE!!";
        if(score[0]>score[1]){
            cout<<"The match has ended "<<score[0]<<"-"<<score[1]<<". YOU'VE WON!! Thank you for playing!";
        }
        else{
            cout<<"The match has ended "<<score[0]<<"-"<<score[1]<<". YOU'VE LOST!! Thank you for playing!";
        }
        
    }
            
    return 0;
}



