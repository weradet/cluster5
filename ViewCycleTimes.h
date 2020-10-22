#ifndef VIEWCYCLETIMES_H
#define VIEWCYCLETIMES_H
#include"include.h"
#include"Path.h"
#include"station.h"
class ViewCycleTime{
    private :
        string DepartureStation;
        string TerminalStation;
        Station my_station;
        Path *head;
    public :
        ViewCycleTime(void);
        void ChooseDepartureStation();
        void ChooseTerminalStation();

};
#endif