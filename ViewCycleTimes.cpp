#include"ViewCycleTimes.h"
        ViewCycleTime::ViewCycleTime(){
            head = new Path;
            head->read_file();
            first = NULL;
            last = NULL;
            count = 0;
            //round->Readfile();
        }

        void ViewCycleTime::ChooseDepartureStation(){
            Path *a = head;
                HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
                for(int i=0;i<a->count;i++){
                    if(a->head->stationStatus() != "close"){
                        
                        SetConsoleTextAttribute(color,5);
                        cout <<"ID DepartureStation: ";
                        SetConsoleTextAttribute(color,6);
                        cout << a->head->StationID();
                        SetConsoleTextAttribute(color,5);
                        cout << " Station Name: " ;
                        SetConsoleTextAttribute(color,6);
                        cout <<a->head->stationName() <<endl;
                        
                    }
                    a->head = a->head->link;
                }
                SetConsoleTextAttribute(color,7);
                cout << "Enter ID DepartureStation: ";
                SetConsoleTextAttribute(color,14);
                cin >> DepartureStation;
                SetConsoleTextAttribute(color,7);
        }

        void ViewCycleTime::ChooseTerminalStation(){
            Path *a = head;
                while(a->head != NULL){
                    if(a->head->StationID()== DepartureStation){
                        break;
                    }
                    a->head=a->head->link;
                }
                DepartureStation = a->head->stationName();
                a->head=a->head->link;
                HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
                for(int i=0;i<a->count-1;i++){
                    if(a->head->stationStatus() != "close"){
                        
                        SetConsoleTextAttribute(color,5);
                        cout <<"ID TerminalStation: ";
                        SetConsoleTextAttribute(color,6);
                        cout << a->head->StationID();
                        SetConsoleTextAttribute(color,5);
                        cout << " Station Name: " ;
                        SetConsoleTextAttribute(color,6);
                        cout <<a->head->stationName() <<endl;
                        
                    }
                    a->head = a->head->link;
                }
                SetConsoleTextAttribute(color,7);
                cout << "Enter ID TerminalStation: ";
                SetConsoleTextAttribute(color,14);
                cin >> TerminalStation;
                a = head;
                while(a->head != NULL){
                    if(a->head->StationID()== TerminalStation){
                        TerminalStation = a->head->stationName();
                        break;
                    }
                    a->head=a->head->link;
                }
        }
        void ViewCycleTime::Add(string name){
            Round *New = new Round(name); 
                if(first == NULL){
                    first = New;
                    last = New;
                }else{
                    last->link = New;
                    New->plink = last;
                    last = New; 
                }
                count++;
                string filein,Name,out;
                ifstream file("Round.txt",ios::in);
                if(file.is_open()){
                    while(getline(file,filein)){
                        Name = filein.substr(0,filein.find(','));
						     filein.erase(0,filein.find(',')+1); 
                             if(Name == name){
                                while(filein != "-"){
                                    out = filein.substr(0,filein.find(','));
                                    filein.erase(0,filein.find(',')+1);
                                    //cout << out << endl;
                                        New->add_time(out);
                                        //cout << out << endl;
                                }
                                //cout << "qwe" <<endl;
                             }
                    }
                file.close();
                }
        }
        void ViewCycleTime::SearchRound(){
                string filein,name,out;
                //TimeOut *takeoff;
                ifstream file("Round.txt",ios::in);
                if(file.is_open()){
                    while(getline(file,filein)){
                        
                        name = filein.substr(0,filein.find(','));
						    filein.erase(0,filein.length());
                           // cout << name << endl;
                            Add(name); 
 
                    }
                file.close();
                }
        }
        void ViewCycleTime::show(){
             Round *ro = first;
             string we;
            // cout << ro->Name << endl;
                while(ro != NULL){
                    if(ro->Name == DepartureStation){
                        cout << ro->Name << endl;
                        while(ro->first != NULL){
                            
                                cout << ro->first->TO <<endl;
                                ro->first = ro->first->link;
                        }
                    }
                    ro = ro->link;
                }

                cin >> we;     
        }
        //asd
