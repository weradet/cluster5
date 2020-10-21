#ifndef VIEWCYCLETIMES_H
#define VIEWCYCLETIMES_H
#include"include.h"
#include"Path.h"
#include"station.h"
class ViewCycleTimes{
    private :
        Station my_station;
        Path my_path;

    public :
        Path *head;

        ViewCycleTimes();
        void ChooseDepatureStation(string name);
        void ChooseTeminalStation(string name);

};
#endif