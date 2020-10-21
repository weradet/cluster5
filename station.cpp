#include"station.h"
        Station::Station(string sta_name,string id,string sta_stu,int cost){
            ID = id;
            StationName = sta_name;
            StationStatus = sta_stu;
            Cost = cost;
            link = NULL;
            plink = NULL;
        }
        void Station::NewCost(int cost){
            Cost = cost;
        }
        void Station::NewStatus(string status){
            StationStatus = status;
        }
        void Station::NewName(string name){
            StationName = name;
        }
        string Station::StationID(){
            return ID;
        }
        string Station::stationName(){
            return StationName;
        }
        string Station::stationStatus(){
            return StationStatus;
        }
        int Station::cost(){
            return Cost;
        }
