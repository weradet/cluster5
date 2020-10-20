#include"include.h"
#include"AddStation.h"
#include"Path.h"
class StationController{
    private:

    public:
        void ShowFixMenuStation(){
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
        Station *plink;
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
        string GetStationID(){
            return ID;
        }
        string GetstationName(){
            return StationName;
        }
        string GetstationStatus(){
            return StationStatus;
        }
        int Getcost(){
            return Cost;
        }
};
class Status :public Path{
    public:
        void ShowAllStation(){
            Station *temp = head;
            int i;
            cout << "------------------ Station -----------------" << endl;
            cout << "ID Station" << setw(10) << right << "Station Name" << setw(10) << right 
                 << "Status" << setw(10) << right << "Cost" << endl;
            while(temp != NULL){
                cout << left << setw(10) << i;
                cout << left << setw(10) << temp->GetStationID();
                cout << left << setw(10) << temp->GetstationName();
                cout << left << setw(10) << temp->GetstationStatus();
                cout << left << setw(10) << temp->Getcost() << endl;
            }
            cout << "--------------------------------------------" << endl;
        }
        void ShowStation(string id){
            Station *temp = head;
            cout << "------------------ Detail Station -----------------" << endl;
            while(temp != NULL){
                if(id == temp->ID){
                   cout << "Station ID : " << temp->GetStationID() << endl;
                   cout << "Station Name : " << temp->GetstationName() << endl;
                   cout << "Station Status : " << temp->GetstationStatus() << endl;
                   cout << "Station Cost : " << temp->Getcost() << endl; 
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
                    if(temp->StationStatus == "Open"){
                        temp->NewStatus("Close");
                    }else if(temp->StationStatus == "Close"){
                        temp->NewStatus("Open");
                    }
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