#include"station.h"
        Station::Station(string sta_name,string id,string sta_stu,int cost){
            ID = id;
            Station_Name = sta_name;
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
            Station_Name = name;
        }
        void Station::NewID(string id){
            ID = id;
        }
        string Station::StationID(){
            return ID;
        }
        string Station::stationName(){
            return Station_Name;
        }
        string Station::stationStatus(){
            return StationStatus;
        }
        int Station::cost(){
            return Cost;
        }
    Station::Station(){

    }