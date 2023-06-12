#ifndef ACTION_FUNCTIONS_H
#define ACTION_FUNCTIONS_H

void attacking (int* score, bool& possession, double& shot_acc, int& consec_passes);
void defending (int* score, bool& possession, double& opp_shot_acc, int& opp_consec_passes);
int* match(int turn_count, bool possession, int* score, int maxTurns);
void penalties(int maxPens);

#endif
