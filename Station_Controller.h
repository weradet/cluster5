#ifndef STATION_CONTROLL_H
#define STATION_CONTROLL_H
#include "include.h"
#include "station.h"
#include "Status.h"
#include "StationList.h"
class StationController{
    private:
        Status obj_sta;
    public:
        bool CheckID(string id);
        void ShowStation(string id);
        void remove();
        void readfile();
        void ChooseFixMenu(string id,string menu);
        void ShowAllStation();
        void ShowFixMenuStation();
        bool CheckStatus(string name);
        void WriteFixFile();
};
#endif