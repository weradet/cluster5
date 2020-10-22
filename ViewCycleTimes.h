#ifndef VIEWCYCLETIMES_H
#define VIEWCYCLETIMES_H
#include"include.h"
#include"Path.h"
#include"station.h"
#include"Round.h"
class ViewCycleTime{
    private :
        string DepartureStation;
        string TerminalStation;
        Station my_station;
        Path *head;
        Round *round;
    public :
        ViewCycleTime(void);
        void ChooseDepartureStation();
        void ChooseTerminalStation();
        void SearchRound();
};
#endif