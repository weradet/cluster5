#include"node_Addstation.h"

		Node_Addstation::Node_Addstation(string Sid,string name,string stat,string c){
			 StationID = Sid;
			StationName = name;
            Status = stat;
            Cost = c;
			link = NULL;
			plink = NULL;
		}

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
            stList->addStation(StationID,StationName,Status,Cost);
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
						stList->AddStation(index,StationID,StationName,Status,Cost);
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
