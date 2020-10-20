#include"include.h"
class Node_Addstation{
	public:
		string StationName,StationID,Status,Cost;
		Node_Addstation *link;
		Node_Addstation *plink;
		Node_Addstation(string Sid,string name,string stat,string c){
			 StationID = Sid;
			StationName = name;
            Status = stat;
            Cost = c;
			link = NULL;
			plink = NULL;
		}
};
class StationList{
	private:		
		Node_Addstation *head;
		Node_Addstation *tail;
		int count;
	public:
		StationList(){
			head = NULL;
			tail = NULL;
			count = 0;
		}
		~StationList(){
			for(int i=1;i<count;i++){
				Node_Addstation *tmp = head;
				head = head->link;
				delete tmp;
				tmp = NULL;
			}
			head = NULL;
			tail = NULL;
		}
		void add(string StationID,string StationName,string Status,string Cost){
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
		void add(int index,string StationID,string StationName,string Status,string Cost){
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
		bool checkStationID(string id){
			Node_Addstation *temp = head;
			while(temp !=NULL){
				if(temp->StationID == id){
					return true;
					break;
				}
				temp = temp->link;
			}
		}
		bool checkStationName(string name){
			Node_Addstation *temp = head;
			while(temp !=NULL){
				if(temp->StationName == name){
					return true;
					break;
				}
				temp = temp->link;
			}
		}
		void show(){
			Node_Addstation *temp = head;
			int i = 1;
			while(temp != NULL){
				cout << "List " << i << ": = " << temp->StationID << temp->StationName << temp->Status << temp->Cost << endl;
				temp = temp->link;
				i++;
			}		
		}
		void writefile(){
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
		int size(){
            return count;
        }
};
/*int main(){
	StationList *stList = new StationList;
	char choice;
	string StationName,StationID,Status,Cost;
    do{
Addstation:cout <<"1.Add destination"<<endl;
		cout <<"2.Add Departure station,Add station on the way"<<endl;
		cout <<"3.show "<<endl;
		cout <<"4.Exit "<<endl;
		cout <<"Enter ==> ";
        cin >> choice;
        if(choice == '1'){
            //string Cost;
                cout << "Station ID: ";
                cin >> StationID;
                    while(StationID.length() != 5){
                        cout << "!!! Warning !!!\n";
                        cout << "Station ID Not equal to 5 ";
                        cin >> StationID;
                    }
                cout << "StationName: ";
                cin >> StationName;
				if(stList->checkStationID(StationID)==true && stList->checkStationName(StationName)==true){
					cout << "The station already exists!!!" << endl;
				}
                cout << "Station Status: ";
                cin >> Status;
                cout << "Station cost: ";
                cin >> Cost;
            stList->add(StationID,StationName,Status,Cost);
        }
        else if(choice == '2'){
            int index, data;
            int size = stList->size();

            if(size == 0){
                cout << "cannot add station" << endl;
            }
            else{
               string Cost;
                cout << "Station ID: ";
                cin >> StationID;
                    while(StationID.length() != 5){
                        cout << "!!! Warning !!!\n";
                        cout << "Station ID Not equal to 5 ";
                        cin >> StationID;
                    }
                cout << "StationName: ";
                cin >> StationName;
				if(stList->checkStationID(StationID)==true && stList->checkStationName(StationName)==true){
					cout << "The station already exists!!!" << endl;
				}
                cout << "Station Status: ";
                cin >> Status;
                cout << "Station cost: ";
                cin >> Cost;
                if(size == 1){
                    cout << "input position (1): ";
                    cin >> index;
                    if(index > size || index < 1){
                       cout << "cannot add station" << endl;
                    }
                    else{
                        stList->add(index,StationID,StationName,Status,Cost);
                    }
                }
                else{
                    cout << "choose position station(1 - " << size << "): ";
                    cin >> index;

                    
                    if(index > size || index < 1){
                    	cout << "cannot add station" << endl;
					}
					else{
						stList->add(index,StationID,StationName,Status,Cost);
					}
                }
            }
        }

    	else if(choice == '3'){
		stList->show();
    	stList->writefile();

}
        //system("cls");
    }while(choice != '4');
	//goto Addstation;
	return 0;
}*/
