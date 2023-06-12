#include "action_functions.h"
#include "ui_random_functions.h"
#include <iostream>
#include <cctype>
#include <chrono>
#include <thread>
#include <random>
#include <array>


using namespace std;

void penalties(int maxPens){
    int player_pen = 0, opp_pen = 0;
    int action_choice;
    cout<<endl<<"What a tight game! Onto PENALTIES!"<<endl;
    for(int i = 0; i<maxPens; i++){
        
        cout<<endl<<"Penalty: "<<i+1<<"/5 completed"<<endl;
        while (true) {
            cout << "YOUR SHOT! Choose where youd like to shoot your penalty: " << endl
                 << "1. Left" << endl
                 << "2. Centre" << endl
                 << "3. Right" <<endl
                 << "Enter the index of the choice you would like to make: ";
    
            cin >> action_choice;

            if (action_choice == 1 || action_choice == 2 || action_choice == 3) {
                break;
            }

            cout << "Invalid choice, choose again" <<endl;
        }
        
        bool opp_shot_jump = penRandom();
        
        cout << "Press enter to shoot...";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        cout << endl;
        
        if(action_choice == opp_shot_jump){
            cout<<"Oh no! the opponent goalkeeper has blocked it!"<<endl<<endl
                <<"The score is "<<player_pen<<"-"<<opp_pen<<endl;
        }
        else{
            player_pen++;
            cout<<"Congratulations! You've buried it into the net!"<<endl<<endl
                <<"The score is "<<player_pen<<"-"<<opp_pen<<endl;
        }
        
        
        while (true) {
            cout << "THEIR SHOT! Choose where you'd like your goalkeeper to jump: " << endl
                 << "1. Left" << endl
                 << "2. Centre" << endl
                 << "3. Right" <<endl
                 << "Enter the index of the choice you would like to make: ";
    
            cin >> action_choice;

            if (action_choice == 1 || action_choice == 2 || action_choice == 3) {
                break;
            }

            cout << "Invalid choice, choose again" <<endl;
        }
        
        opp_shot_jump = penRandom();
        
        cout << "Press enter to jump...";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin.get();
        cout << endl;
        
        if(action_choice == opp_shot_jump){
            cout<<"Congratulations! Your goalkeeper has saved it!"<<endl<<endl
                <<"The score is "<<player_pen<<"-"<<opp_pen<<endl;
        }
        else{
            opp_pen++;
            cout<<"Oh no! They've slotted it in!"<<endl<<endl
                <<"The score is "<<player_pen<<"-"<<opp_pen<<endl;
        }
    }
    if(player_pen > opp_pen){
        cout<<"CONGRATULATIONS! It ended "<<player_pen<<"-"<<opp_pen<<". YOUVE WON THE GAME!!"<<endl;
    }
    else if(player_pen < opp_pen){
        cout<<"OH NO! It ended "<<player_pen<<"-"<<opp_pen<<". THE OPPONENT SLIPPED THROUGH!"<<endl;
    }
    else{
        cout<<"Its an incredibly tight game, still tied. Would you like to go to best of one? (Y/N): ";
        char choice;
        cin>>choice;
        if(choice == 'Y' || choice == 'y'){
            penalties(1);
        }
        else{
            cout<<endl<< "AND THATS THE FINAL WHISTLE!! What a tight game! The match has ended "<<player_pen<<"-"<<opp_pen<<" on penalties. Thank you for playing!";
        }
    }
}