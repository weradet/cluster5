#ifndef STATION_CONTROLL_H
#define STATION_CONTROLL_H
#include "include.h"
#include "station.h"
#include "Status.h"
#include "StationList.h"
class StationController{
    private:
        StationList obj_stalist;
        Status obj_sta;
    public:
        void ShowStation(string id);
        void readfile();
        void ChooseFixMenu(string id,int menu);
        void ShowAllStation();
        void ShowFixMenuStation();
        bool CheckStatus(string name);
        void WriteFixFile();
};
#endif