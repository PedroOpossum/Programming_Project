
#ifndef HOST_H
#define HOST_H

#define MAX_TOURNAMENTS 10

struct Game_Tournament {
    float Pool_Prize;
    int Num_Of_People;
    char Place[500], Time[10], Date[15];
    char Rule_Selection[500];
    char VideoGame[500];
};

extern struct Game_Tournament gt[MAX_TOURNAMENTS]; 

#endif