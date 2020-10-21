#ifndef STATION_H
#define STATION_H
#include"include.h"
class Station{
    private:
        string ID;
        string StationName;
        string StationStatus;
        int Cost;
    public:
        Station *link;
        Station *plink;
        Station(string sta_name,string id,string sta_stu,int cost);
        void NewCost(int cost);
        void NewStatus(string status);
        void NewName(string name);
        string StationID();
        string stationName();
        string stationStatus();
        int cost();

};

#endif