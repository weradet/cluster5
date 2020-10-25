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
    public :
        Round *first;
        Round *last;
        Round *H;
        int count;
        ViewCycleTime(void);
        void ChooseDepartureStation();
        void ChooseTerminalStation();
        void SearchRound();
        void Add(string N);
        string Times();
        void show();
        void remove();
};
#endif