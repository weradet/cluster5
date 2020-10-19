#include"include.h"
class StationController{

    public:
        void printFixMenuStation(){
            cout << "------------------- Menu -------------------" << endl;
            cout << "1. Fix Station Name"       << endl;
            cout << "2. Maintenance Station"    << endl;
            cout << "3. Fix Cost Station"       << endl;
            cout << "--------------------------------------------" << endl;
        }
        void printShowAllStation(){
            cout << "------------------ Station -----------------" << endl;
            cout << "ID Station" << setw(10) << right << "Station Name" << setw(10) << right 
                 << "Status" << setw(10) << right << "Cost" << endl;
            
            cout << "--------------------------------------------" << endl;
        }
    
};
class Station{
    private:
        string ID,StationName,StationStatus;
        int Cost;
        Station *link;
    public:
        void printShowAllStation(){
            cout << "------------------ Station -----------------" << endl;
            cout << "ID Station" << setw(10) << right << "Station Name" << setw(10) << right 
                 << "Status" << setw(10) << right << "Cost" << endl;
            
            cout << "--------------------------------------------" << endl;
        }
        string StationID(){
            return ID;
        }
        string stationName(){
            return StationName;
        }
        string stationStatus(){
            return StationStatus;
        }
        int cost(){
            return Cost;
        }
        void Maintenance(){

        }
        void FixCostStation(){
            
        }
};