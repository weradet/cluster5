#include"StationList.h"
		StationList::StationList(){
			head = NULL;
			tail = NULL;
			count = 0;
		}
		StationList::~StationList(){
			for(int i=1;i<count;i++){
				Node_Addstation *tmp = head;
				head = head->link;
				delete tmp;
				tmp = NULL;
			}
			head = NULL;
			tail = NULL;
		}
		void StationList::Addstation(string StationID,string StationName,string Status,string Cost){
			Node_Addstation *n = new Node_Addstation(StationID,StationName,Status,Cost);
			if(head == NULL){
				head = n;
				tail = head;
				count++;
			}else{
				tail->link = n;
				n->plink = tail;	
				tail = n;
				count++;
			}		
		}
		void StationList::AddStation_ontheway(int index,string StationID,string StationName,string Status,string Cost){
			Node_Addstation *newnode = new Node_Addstation(StationID,StationName,Status,Cost);
			Node_Addstation *temp = head;
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
			Node_Addstation *temp = head;
			while(temp !=NULL){
				if(temp->StationID == id){
					return true;
					break;
				}
				temp = temp->link;
			}
            return false;
		}
		bool StationList::checkStationName(string name){
			Node_Addstation *temp = head;
			while(temp !=NULL){
				if(temp->StationName == name){
					return true;
					break;
				}
				temp = temp->link;
			}
            return true;
		}
		void StationList::show_station(){
			Node_Addstation *temp = head;
			int i = 1;
			while(temp != NULL){
				cout << "Station" << i << ": = " << temp->StationID << temp->StationName << temp->Status << temp->Cost << endl;
				temp = temp->link;
				i++;
			}		
		}
		void StationList::WriteStationfile(){
			string line3;
			Node_Addstation *temp = head;
			ofstream myFile3("Station.txt",ios::app);
        	if(myFile3.is_open()){ 
        	while(temp!=NULL){
				myFile3 << temp->StationID <<","<< temp->StationName << "," << temp->Status  << "," << temp->Cost << endl;
				temp = temp->link;
   			}
		}

		}
		int StationList::StationNumber(){
            return count;
        }