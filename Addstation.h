#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
class station_Data{
	public:
		string StationName,StationID,Status,Cost;
        int index;
		Station_Data *link;
		Station_Data *plink;
		Station_Data(int index,string Sid,string name,string stat,string c){
			StationName = name;
            StationID = Sid;
            Status = stat;
            Cost = c;
			link = NULL;
			plink = NULL;
		}
};
class stationList{
    private:
        Station_Data *head;
        Station_Data *tail;
        int count;
    public:
        string StationName,StationID,Status;
        int Cost;
        int countList(){
            int num = 0;
            Station_Data *temp = head;
            while(temp!=NULL){
                temp = temp->link;
                num++;
            }
            return num;
        }
        void AddOntheWay(string StationID,string StationName,string Status,string Cost){
			Station_Data *n = new Station_Data(StationID,StationName,Status,Cost);
			Station_Data *temp = head;
            int index;
            //stringstream ss;  
            //ss << StationID;  
            //ss >> index;  
			if(index > count){
				cout << "cannot add" << endl;
			}else if(index == 1){				
				n->link = head;
				head->plink = n;
				head = n;
				count++;
			}else{
				int i=2;
				while(temp!=NULL){
					if(index == i){
						n->plink = temp;
						n->link = temp->link;
						temp->link->plink = n;
						temp->link = n;
					}
					temp = temp->link;
					i++;
				}
				count++;
			}				
		}
        void AddStation(){
            string Cost;
                cout << "Station ID: ";
                cin >> StationID;
                    while(StationID.length() != 5){
                        cout << "!!! Warring !!!\n";
                        cout << "Station ID Not equal to 5 ";
                        cin >> StationID;
                    }
                cout << "StationName: ";
                cin >> StationName;
                cout << "Station Status: ";
                cin >> Status;
                cout << "Station cost: ";
                cin >> Cost;
                ofstream Stationfile;
                Stationfile.open("Station.txt",std::ios::app);
                Stationfile << StationID <<","<< StationName << "," << Status  << "," << Cost << endl;
                Stationfile.close(); 
                //add(StationID,StationName,Status,Cost);
            }
        void AddStation_Ontheway(){
            string Stationid,index,Cost;
                cout <<"Please Enter station id (index) : ";
                cin >>index;
                cout << "Station ID: ";
                cin >> Stationid;
                    while(Stationid.length() != 5){
                        cout << "!!! Warring !!!\n";
                        cout << "Station ID Not equal to 5 ";
                        cin >> Stationid;
                    }
                cout << "StationName: ";
                cin >> StationName;
                cout << "Station Status: ";
                cin >> Status;
                cout << "Station cost: ";
                cin >> Cost;
                ofstream Stationfile;
                Stationfile.open("Station.txt",std::ios::app);
                Stationfile << Stationid <<","<< StationName << "," << Status  << "," << Cost << endl;
                Stationfile.close(); 
                AddOntheWay(Stationid,StationName,Status,Cost);
        }    
};
    /*
int main(){
    Station *st = new Station;
    int addstationChoice,menu;
	string Departure,Destination,On_theWay;
    Addstation:cout <<"======== Add station ======== "<<endl;
	cout <<"1.Add destination"<<endl;
	cout <<"2.Add Departure station,Add station on the way"<<endl;
	cout <<"3.Exit "<<endl;
	cout <<"Enter ==> ";
	cin >>addstationChoice;
	switch(addstationChoice){
		case 1:
			cout <<"1.Add Destination station"<<endl;
            st->AddStation();
			cout <<"Add Destination station complete."<<endl;
			goto Addstation;
			break;		
		case 2:
            cout <<"Enter ==> ";
	        cin >>menu;
            switch(menu){
            case 1:
            cout <<"1.Add station on the way"<<endl;
            st->AddStation_Ontheway();
			cout <<"Add Station on the way station complete."<<endl;
			goto Addstation;
		    break;
            case 2:
            cout <<"2.Add Departure station"<<endl;
            st->AddStation_Ontheway();
            cout <<"Add Departure station complete."<<endl;
            goto Addstation;
		    break;   
            }
		case 3:
			cout <<"Exit"<<endl;
			goto EXIT;
			break;
	}
    EXIT:cout <<"================="<<endl; 
    return 0;
}
*/