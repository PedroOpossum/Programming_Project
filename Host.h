
#ifndef HOST_H
#define HOST_H

#define MAX_TOURNAMENTS 10

struct Game_Tournament {
    char Rule_Selection[100];
    char VideoGame[500];  
    char Place[500], Time[10], Date[15];
    float Pool_Prize;
    int NumOfPeople;
    int totalNumOfPeople;
};


extern struct Game_Tournament gt[MAX_TOURNAMENTS]; 
extern int current_tournament;
extern void Main_Menu();


#endif


