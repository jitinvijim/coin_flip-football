#include "action_functions.h"
#include "ui_random_functions.h"
#include <iostream>
#include <cctype>
#include <chrono>
#include <thread>
#include <random>
#include <array>


using namespace std;




void defending (int* score, bool& possession, double& opp_shot_acc, int& opp_consec_passes){
    
    cout<<"You are out of possession. You can only tackle/interecept!"<<endl;
    bool enemy_action = boolRandom();
    if(!enemy_action){
        cout<<"The opponent has chosen to pass."<<endl;
    }
    else{
        cout<<"The opponent decides to take a shot!"<<endl;
    }
    
    char choice = side_chooser();
    pressAnyKeyToContinue();
    
    if(enemy_action){
        bool coin = weighted_random(opp_shot_acc);
        if((!coin && choice == 'h') || (coin && choice == 't')){
            cout<<"Coin: "<<coin<<endl;
            cout<<endl<<endl<<"OH NO! THE OPPONENT HAS SCORED!"<<endl;
            score[1]++;
            opp_consec_passes = 0;
            opp_shot_acc = 0.25;
            possession = true;
            cout<<"The score is now "<<score[0]<<"-"<<score[1]<<endl;
            cout<<endl<<"Its time for Kick-off!"<<endl;
        }
        else{
            cout<<endl<<"Congratulations! Your keeper saved it!"<<endl;
            opp_consec_passes = 0;
            opp_shot_acc = 0.25;
            possession = true;
        }
        
    }
    else{
        bool coin = boolRandom();
        if((coin && choice == 'h') || (!coin && choice == 't')){
            if(opp_consec_passes < 4){
               cout<<endl<<"The enemy has successfully passed. They are now closer to goal!"<<endl;
                opp_consec_passes++;
                opp_shot_acc+=0.25; 
            }
        }
        else{
            cout<<endl<<"Congratulations! You have successfully interecepted! The ball is now in your possession. "<<endl;
            opp_shot_acc = 0.25;
            opp_consec_passes = 0;
            possession = true;
        }
    }
}