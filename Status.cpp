#include"Status.h"
void Status::ShowAllStation(){
            remove();
            read_file();
            Station *temp = head;
            cout << right << setw(81) << "**************** Station *****************" << endl;
            cout << setw(40) << left << " " << setw(7) << left << "ID."  << setw(18) << left << "Station Name" << setw(8) << right << "Status" << setw(8) << right<< "Cost"<< endl;
            cout << right << setw(81) << "******************************************" << endl;
            while(temp != NULL){
                    cout << setw(40) << left << " " << left << setw(7) << temp->StationID();
                    cout << left << setw(20) << temp->stationName();
                    cout << left << setw(10) << temp->stationStatus();
                    cout << temp->cost() << endl;
                temp = temp->link;
                if(temp == head){
                 	break;
				}   
            }
            cout << right << setw(81) << "******************************************" << endl;
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
    cout << right << setw(81) << "************* Detail Station *************" << endl;
    while(temp != NULL){
        if(id == temp->StationID()){
            cout << right << setw(60) << "Station ID : " << temp->StationID() << endl;
            cout << right << setw(62) << "Station Name : " << temp->stationName() << endl;
            cout << right << setw(64) << "Station Status : " << temp->stationStatus() << endl;
            cout << right << setw(62) << "Station Cost : " << temp->cost() << endl; 
        }
        temp = temp->link;
        if(temp == head){
            break;
		}
    }   
    cout << right << setw(81) << "******************************************" << endl;
}
 void Status::ChooseFixMenu(string id,string menu){
                if(menu == "1"){
                    stringstream ss;
                    string fix;
                    int cost;
            ch_cost:cout << "Enter New Station Cost : ";
                        try{ 
                            cin >> cost; //User input
                         if(!cin){
                              throw cost;
                         }
                        }catch(int x){  
                            cin.clear(); 
                            cin.ignore(100, '\n');
                            goto ch_cost; 
                        }  
                    FixCostStation(id,cost);
                    cout << right << setw(83) << "********** Fix Station Cost Complete *********" << endl;
                }                 
                if(menu == "2"){
                    Maintenance(id);
                    cout << right << setw(83) << "********* Maintenance Station Complete *******" << endl;
                }
                if(menu == "3"){
                    string name;
            ch_name:cout << "Enter New Station Name : ";
                    cin.ignore();
                    getline(cin,name);
                    if(name <= "A"){
                        goto ch_name;
                    }
                    NewStationName(id,name);
                    cout << right << setw(83) << "********** Fix Station Cost Complete *********" << endl;
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
