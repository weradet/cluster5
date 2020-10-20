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
};
class Station{
    private:
        string ID,StationName,StationStatus;
        int Cost;
    public:
        Station *link;
        Station(string id,string sta_name,string sta_stu,int cost){
            ID = id;
            StationName = sta_name;
            StationStatus = sta_stu;
            Cost = cost;
            link = NULL;
        }
        void NewCost(int cost){
            Cost = cost;
        }
        void NewStatus(string status){
            StationStatus = status;
        }
        void NewName(string name){
            StationName = name;
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
};
class Status :protected Add{
    public:
        void printShowAllStation(){
            Station *temp = head;
            int i;
            cout << "------------------ Station -----------------" << endl;
            cout << "ID Station" << setw(10) << right << "Station Name" << setw(10) << right 
                 << "Status" << setw(10) << right << "Cost" << endl;
            while(temp != NULL){
                cout << left << setw(10) << i;
                cout << left << setw(10) << temp->StationID();
                cout << left << setw(10) << temp->stationName();
                cout << left << setw(10) << temp->stationStatus();
                cout << left << setw(10) << temp->cost() << endl;
            }
            cout << "--------------------------------------------" << endl;
        }
        void printStation(string id){
            Station *temp = head;
            cout << "------------------ Detail Station -----------------" << endl;
            while(temp != NULL){
                if(id == temp->ID){
                   cout << "Station ID : " << temp->ID << endl;
                   cout << "Station Name : " << temp->StationName << endl;
                   cout << "Station Status : " << temp->StationStatus << endl;
                   cout << "Station Cost : " << temp->Cost << endl; 
                }
               temp = temp->link;
            }
            cout << "--------------------------------------------" << endl;
        }
        void FixCostStation(string id,int cost){
            Station *temp = head;
            int ptemp;
            while(temp != NULL){
                if(id == temp->ID){
                    temp->NewCost(cost);
                    break;
                }
                temp = temp->link;
            }
        }
        void Maintenence(srting id){
            Station *temp = head;
            while(temp != NULL){
                if(id == temp->ID){
                    temp->NewStatus("Close");
                    break;
                }
                temp = temp->link;
            }
        }
        void NewStationName(string id,string name){
           Station *temp = head;
            while(temp != NULL){
                if(id == temp->ID){
                    temp->Newname(name);
                    break;
                }
                temp = temp->link;
            } 
        }

};