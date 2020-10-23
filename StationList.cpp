#include"StationList.h"
//#include "include.h"
//#include"node_Addstation.h"
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
		void StationList::Addstation(string StationName,string StationID,int Cost,string Status){
			Node_Addstation *n = new Node_Addstation(StationName,StationID,Cost,Status);
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
		void StationList::AddStation_ontheway(int index,string StationName,string StationID,int Cost,string Status){
			Node_Addstation *newnode = new Node_Addstation(StationName,StationID,Cost,Status);
			Node_Addstation *temp = head;
			if(index > count){
				cout << "cannot add" << endl;
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
		void StationList::ReadStationFile(){
			string line;
			string StationName,StationID,Status;
			string C;
			ifstream myFile("Station.txt", ios::in);
				if(myFile.is_open()){ 
					while(getline(myFile,line)){
						StationName = line.substr(0,line.find(','));
							line.erase(0,line.find(',')+1);	
						StationID = line.substr(0,line.find(','));
							line.erase(0,line.find(',')+1);
						Status = line.substr(0,line.find(','));
							line.erase(0,line.find(',')+1);
						C = line.substr(0,line.find(','));
							line.erase(0,line.find(',')+1);
						stringstream COST(C);
						int Cost = 0;
						COST >> Cost;
						Addstation(StationName,StationID,Cost,Status);
					}
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
				cout << "Station" << i << ": = " << temp->StationID << temp->StationName << temp->Cost << temp->Status << endl;
				temp = temp->link;
				i++;
			}		
		}
		void StationList::WriteStationfile(){
			Node_Addstation *temp = head;
			ofstream myFile3("Station.txt",ios::out);
        	if(myFile3.is_open()){ 
				while(temp!=NULL){
					myFile3  << temp->StationName <<","<< temp->StationID << "," << temp->Cost  << ","  << temp->Status <<"," << endl;
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