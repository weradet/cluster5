#ifndef STATUS_H
#define STATUS_H
#include"include.h"
#include"Path.h"
class Status :public Path{
    public:
        void ShowAllStation();
        void showStation(string id);
        void ChooseFixMenu(string id,int menu);
        void FixCostStation(string id,int cost);
        void Maintenance(string id);
        void NewStationName(string id,string name);
};
#endif
