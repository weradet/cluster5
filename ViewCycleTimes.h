#ifndef VIEWCYCLETIMES_H
#define VIEWCYCLETIMES_H
#include"include.h"
#include"Path.h"
#include"station.h"
class ViewCycleTime{
    private :
        Station my_station;
        Path my_path;
        Path *head;
    public :
        ViewCycleTime(void);
        void ChooseDepatureStation(string name);
        void ChooseTeminalStation(string name);

};
#endif