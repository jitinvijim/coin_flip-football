#include "action_functions.h"
#include "ui_random_functions.h"
#include <iostream>
#include <cctype>
#include <chrono>
#include <thread>
#include <random>
#include <array>

using namespace std;

int* match(int turn_count, bool possession, int* score, int maxTurns) {
    
    int consec_passes = 0, opp_consec_passes = 0;
    double shot_acc = 0.25, opp_shot_acc = 0.25;
    while(turn_count<maxTurns)
    {
        cout<<"-----------------------------------------------------------------------------------------------------------------";
        cout<<endl<<"Turn "<<turn_count+1<<"/"<<maxTurns<<endl
            <<"Score"<<score[0]<<"-"<<score[1]<<endl<<endl;
            
        
        if(possession){
            attacking(score, possession, shot_acc, consec_passes);
        }
        else{
            defending(score,possession, opp_shot_acc, opp_consec_passes);
        }
        turn_count++;
    }
    
    return score;
}