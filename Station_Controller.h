#ifndef STATION_CONTROLL_H
#define STATION_CONTROLL_H
#include "include.h"
#include "station.h"
#include "Path.h"
class StationController{
    private:
        Status obj_sta;
    public:
        void ChooseFixMenu(string id,int menu);
        void ShowAllStation();
        void ShowFixMenuStation();
};
#endif