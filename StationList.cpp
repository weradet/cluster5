#include"StationList.h"
//#include "include.h"
//#include"node_Addstation.h"
		StationList::StationList(){
			head = NULL;
			tail = NULL;
			count = 0;
			ReadStationFile();
			cycle  =new ViewCycleTime;
			cycle->SearchRound();
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
				tail = n;
				count++;
			}else{
				tail->link = n;
				//n->plink = tail;	
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
				//head->plink = newnode;
				head = newnode;
				count++;
			}else{
				int i=2;
				while(temp!=NULL){
					if(index == i){
						//newnode->plink = temp;
						newnode->link = temp->link;
						//temp->link->plink = newnode;
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
						C = line.substr(0,line.find(','));
							line.erase(0,line.find(',')+1);
						Status = line.substr(0,line.find(','));
							line.erase(0,line.find(',')+1);
						stringstream COST(C);
						int Cost = 0;
						COST >> Cost;
						Addstation(StationName,StationID,Cost,Status);
					}
				}
				myFile.close();
		}
		bool StationList::checkStationID(string id){
			//cout << id << endl;
			Node_Addstation *temp = head;
			while(temp !=NULL){
				//cout << temp->StationID << endl;
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
            return false;
		}
		void StationList::show_station(){
			Node_Addstation *temp = head;
			int i = 1;
			while(temp != NULL){  
				cout << "Station" << i << ": = " << temp->StationID << " "<< temp->StationName << temp->Cost << temp->Status << endl;
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
				}
				myFile3.close();  
			}
		}
		int StationList::StationNumber(){
            return count;
        }
		void StationList::remove(){
			//ReadStationFile();
			while(head!=NULL){
				Node_Addstation *tmp = head;
				head = head->link;
				delete tmp;
				tmp = NULL;
				count--;
			}
			count = 0;
		}
		void StationList::WriteRoundfile(){
			remove();
			ReadStationFile();
			int co = StationNumber();
			ViewCycleTime *view = cycle;
			view->remove();
			view->SearchRound();
			Node_Addstation *temp = head;
			ViewCycleTime *V = view;

			int i=1;
			while(temp!=NULL){
				if(V->first->Name != temp->StationName){
					break;
				}
				i++;
				if(V->first->link != NULL){
					V->first = V->first->link;
				}
					temp = temp->link;
			}
			Round *New = new Round(temp->StationName);
			if(i==1){
					V->first->plink = New;
					New->link = V->first;
					V->first = New;
					V->H = V->first;
			}else if(i>1){
				if(V->count+1 == i){
					V->first->link = New;
					New->plink = V->first;
					V->first = New;
				}else if(i != 1){
					New->link = V->first;
					New->plink = V->first->plink;
					V->first->plink->link = New; 
					V->first->plink = New;	
				}
			}
		view->first = view->H;

			int hour = 6 ,min=0,sum = 0,sum1 = 0,h=0,m=0;
			 string T,t;
			ofstream myFile3("Round.txt",ios::out);
        	if(myFile3.is_open()){ 
				while(view->first!=NULL){
					h = hour;
					m = min;
					sum = 0;
					sum1 = 0; 
					myFile3 << view->first->Name <<",";

					while(h < 24){
						sum = 0;
						sum1 = 0; 
						stringstream ss,yy;
							ss<<h;
							ss>>T;
							if(T.length()==1){
								T = "0"+T;
							}
							yy<<m;
							yy>>t;
							if(t.length()==1){
								t = "0"+t;
							}
							myFile3 << T <<"."<< t << ","; 
							sum1 = 10*co;
							while(sum1 >= 60){
								sum++;
								sum1 -= 60;
							}
							h += sum;
							m += sum1;

							while(m>=60){
								h++;
								m -=60;
							}		
					}//while
						min = min+10;
						if(min >= 60){
							hour++;
							min = 0;
						}
					myFile3 << "-" <<endl;
					view->first = view->first->link;
				}//while
				
			}
			myFile3.close();
			//cout << "com\n";
		}