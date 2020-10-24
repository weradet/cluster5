#include"Status.h"
string Status::SortStation(Station *ptemp){
    Station *temp = tail;
    string id,name,status;
    int cost;
    while(temp != NULL){
        if(ptemp->StationID().compare(temp->StationID()) == 1){
            id = temp->StationID();
            name = temp->stationName();
            status = temp->stationStatus();
            cost = temp->cost();
            temp->NewID(ptemp->StationID());
            temp->NewName(ptemp->stationName());
            temp->NewStatus(ptemp->stationStatus());
            temp->NewCost(ptemp->cost());
            ptemp->NewID(id);
            ptemp->NewName(name);
            ptemp->NewStatus(status);
            ptemp->NewCost(cost);
        }if(ptemp->StationID().compare(temp->StationID()) == 0){
            break;
        }
        temp = temp->plink;
    }
    return ptemp->StationID();
}
void Status::ShowAllStation(){
            Station *temp = head;
            //int i;
            cout << "**************** Station ****************" << endl;
            cout << setw(7) << left << "ID."  << setw(18) << left << "Station Name" << setw(8) << right << "Status" << setw(8) << right<< "Cost"<< endl;
            cout << "*****************************************" << endl;
            while(temp != NULL){
                if(SortStation(temp) == temp->StationID()){
                    cout << left << setw(7) << temp->StationID();
                    cout << left << setw(20) << temp->stationName();
                    cout << left << setw(10) << temp->stationStatus();
                    cout << temp->cost() << endl;
                }
                temp = temp->link;
                if(temp == head){
                 	break;
				}   
            }
            cout << "*****************************************" << endl;
}
bool Status::CheckID(string id){
    Station *temp = head;
    while(temp != NULL){
        if(temp->StationID() == id){
            return false;
        }
        temp = temp->link;
        if(temp == head){
                 	break;
		}
    }
    return true;
}
void Status::showStation(string id){
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
            }            cout << "*****************************************" << endl;
}
 void Status::ChooseFixMenu(string id,string menu){
                if(menu == "1"){
                    int cost;
                    cout << "Enter New Station Cost : ";
                    cin >> cost;
                    FixCostStation(id,cost);
                    cout << "******** Fix Station Cost Complete *******" << endl;
                }                 
                if(menu == "2"){
                    Maintenance(id);
                    cout << "******** Maintenance Station Complete *******" << endl;
                }
                if(menu == "3"){
                    string name;
                    cout << "Enter New Station Name : ";
                    cin >> name;
                    NewStationName(id,name);
                    cout << "******** Fix Station Name Complete *******" << endl;
                }      
                 showStation(id);    
        }
void Status::FixCostStation(string id,int cost){
            Station *temp = head;
          //  int ptemp;
            while(temp != NULL){
                if(id == temp->StationID()){
                    temp->NewCost(cost);
                    break;
                }
                temp = temp->link;
            }
        }
void Status::Maintenance(string id){
            Station *temp = head;
            for(int i=0;i<count+1;i++){
                if(id == temp->StationID()){
                    if(temp->stationStatus() == "open"){
                        temp->NewStatus("close");
                        break;
                    }else if(temp->stationStatus() == "close"){
                        temp->NewStatus("open");
                        break;
                    }
                }
                temp = temp->link;
            }
        }
void Status::NewStationName(string id,string name){
           Station *temp = head;
            while(temp != NULL){
                if(id == temp->StationID()){
                    temp->NewName(name);
                    break;
                }
                temp = temp->link;
            } 
        }
bool Status::CheckStatus(string name){
            Station *temp = head;
            while(temp != NULL){
                if(name == temp->stationName()){
                    if(temp->stationStatus() == "close"){
                        return true;
                    }else{
                        return false;
                    }
                }
                temp = temp->link;
            }
            return true;
}
void Status::WriteFixFile(){
			Station *temp = head;
			ofstream myFile3("Station.txt",ios::out);
        	if(myFile3.is_open()){ 
        	while(temp!=NULL){
				myFile3  << temp->stationName() <<","<< temp->StationID() << "," << temp->cost()  << ","  << temp->stationStatus() << endl;
				temp = temp->link;
				if(temp == head){
                	break;
				}
   			}		   
		}
        myFile3.close();
}
