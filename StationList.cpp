#include"StationList.h"
		void StationList::Addstation(string StationID,string StationName,string Status,int Cost){
			Path::add_path(StationID,StationName,Status,Cost);	
		}
		void StationList::AddStation_ontheway(int index,string StationID,string StationName,string Status,int Cost){
			Station *newnode = new Station(StationID,StationName,Status,Cost);
			Station *temp = head;
			if(index > count){
				cout << "Overflow" << endl;
			}else if(index == 1){				
				newnode->link = head;
				head->plink = newnode;
				head = newnode;
				count++;
			}else{
				int i=2;
				while(temp!=NULL){
					if(index == i){
						newnode->plink = temp;
						newnode->link = temp->link;
						temp->link->plink = newnode;
						temp->link = newnode;
					}
					temp = temp->link;
					i++;
				}
				count++;
			}				
		}
		bool StationList::checkStationID(string id){
			Station *temp = head;
			while(temp !=NULL){
				if(temp->StationID() == id){
					return true;
					break;
				}
				temp = temp->link;
			}
            return false;
		}
		bool StationList::checkStationName(string name){
			Station *temp = head;
			while(temp !=NULL){
				if(temp->stationName() == name){
					return true;
					break;
				}
				temp = temp->link;
			}
            return true;
		}
		void StationList::show_station(){
			Station *temp = head;
			int i = 1;
			while(temp != NULL){
				cout << "Station" << i << ": = " << temp->StationID() << temp->stationName() << temp->stationStatus() << temp->cost() << endl;
				temp = temp->link;
				i++;
			}		
		}
		void StationList::WriteStationfile(){
			string line3;
			Station *temp = head;
			ofstream myFile3("Station.txt",ios::app);
        	if(myFile3.is_open()){ 
        	while(temp!=NULL){
				myFile3  << temp->stationName() <<","<< temp->StationID() << "," << temp->cost()  << ","  << temp->stationStatus() << endl;
				temp = temp->link;
				if(temp == head){
                	break;
				}
   			}
			   
		}

		}
		int StationList::StationNumber(){
            return count;
        }