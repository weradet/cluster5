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
        Station(string sta_name,string id,string sta_stu,int cost){
            ID = id;
            StationName = sta_name;
            StationStatus = sta_stu;
            Cost = cost;
            link = NULL;
            plink = NULL;
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

class Status :public Path{
    public:
        void ShowAllStation(){
            read_file();
            Station *temp = head;
            cout << "**************** Station ****************" << endl;
            cout << setw(7) << left << "NO."  << setw(18) << left << "Station Name" << setw(8) << right << "Status" << setw(8) << right<< "Cost"<< endl;
            cout << "*****************************************" << endl;
            while(temp != NULL){
                cout << left << setw(7) << temp->StationID();
                cout << left << setw(20) << temp->stationName();
                cout << left << setw(10) << temp->stationStatus();
                cout << temp->cost() << endl;
                temp = temp->link;
                if(temp == head){
                	break;
				}
            }
            cout << "*****************************************" << endl;
        }
        void showStation(string id){
            Station *temp = head;
            cout << "**************** Detail Station ****************" << endl;
            while(temp != NULL){
                if(id == temp->StationID()){
                   cout << "Station ID : " << temp->StationID() << endl;
                   cout << "Station Name : " << temp->stationName() << endl;
                   cout << "Station Status : " << temp->stationStatus() << endl;
                   cout << "Station Cost : " << temp->cost() << endl; 
                }
               temp = temp->link;
               if(temp == head){
                	break;
				}
            }
            cout << "*****************************************" << endl;
        }
        void ChooseFixMenu(string id,int menu){
            showStation(id);
                if(menu == 1){
                    int cost;
                    cout << "Enter New Station Cost : ";
                    cin >> cost;
                    FixCostStation(id,cost);
                    cout << "******** Fix Station Cost Complete *******" << endl;
                }else if(menu == 2){
                    Maintenence(id);
                    cout << "******** Maintenance Station Complete *******" << endl;
                }else if(menu == 3){
                    string name;
                    cout << "Enter New Station Name : ";
                    cin >> name;
                    NewStationName(id,name);
                    cout << "******** Fix Station Name Complete *******" << endl;
                }
        }
        void FixCostStation(string id,int cost){
            Station *temp = head;
            int ptemp;
            while(temp != NULL){
                if(id == temp->StationID()){
                    temp->NewCost(cost);
                    break;
                }
                temp = temp->link;
            }
        }
        void Maintenence(string id){
            Station *temp = head;
            while(temp != NULL){
                if(id == temp->StationID()){
                    if(temp->stationStatus() == "open"){
                        temp->NewStatus("close");
                    }else if(temp->stationStatus() == "close"){
                        temp->NewStatus("open");
                    }
                    break;
                }
                temp = temp->link;
            }
        }
        void NewStationName(string id,string name){
           Station *temp = head;
            while(temp != NULL){
                if(id == temp->StationID()){
                    temp->NewName(name);
                    break;
                }
                temp = temp->link;
            } 
        }

};
class StationController{
    private:
        Status obj_sta;
    public:
        void ChooseFixMenu(string id,int menu){
             obj_sta.ChooseFixMenu(id,menu);
        }
        void ShowAllStation(){
            obj_sta.ShowAllStation();
        } 
        void ShowFixMenuStation(){
            cout << "------------------- Menu -------------------" << endl;
            cout << "1. Fix Station Cost"       << endl;
            cout << "2. Maintenance Station"    << endl;
            cout << "3. Fix Station Name"       << endl;
            cout << "--------------------------------------------" << endl;
        }
};