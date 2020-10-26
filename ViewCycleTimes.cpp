#include"ViewCycleTimes.h"
        ViewCycleTime::ViewCycleTime(){
            head = new Path;
            head->read_file();
            first = NULL;
            last = NULL;
            count = 0;
            H = NULL;
            //round->Readfile();
        }

        void ViewCycleTime::ChooseDepartureStation(){
            head->remove();
            head->read_file();
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
                    H = first;
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
                void ViewCycleTime::remove(){
            Round *ro = first;
            TimeOut *temp;
            while(first != NULL){
                while(first->first != NULL){
                    temp = first->first;
                    first->first = first->first->link;
                    delete temp;
                }
                ro = first;
                first = first->link;
                delete ro; 
            }
            count=0;
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
                        break;
                    }
                    ro = ro->link;
                }
                Times(); 
        }


         string ViewCycleTime::Times(){
             remove();
             SearchRound();
            int hour,min;
            time_t now = time(0);
            tm *ltm = localtime(&now);
                    hour = ltm->tm_hour;
                    min = ltm->tm_min;
            int hr=0,Min=0,Recount=0;
            string timehour,timemin,Time;
            
            Round *ro = first;
                    while(ro->Name != DepartureStation){
                        ro = ro->link;
                    }
                     if(ro->Name == DepartureStation){
                       cout << ro->Name << endl; 
                        ro->head = ro->first;
                        while(ro->first != NULL){
                       stringstream ss,yy;
                            timehour = ro->first->TO.substr(0,2);
                            ss<<timehour;
                            ss>>hr;
                            timemin  = ro->first->TO.substr(ro->first->TO.find('.')+1,2);
                            yy<<timemin;
                            yy>>Min;
                            if(hr<hour){
                                    ro->first = ro->first->link;
                           }else if(hr==hour){
                                    if(min>Min){
                                        ro->first = ro->first->link;

                                    }
                                    else if(min<=Min){
                                        cout<<ro->first->TO<<endl;
                                        ro->first = ro->first->link;
                                    
                                    }
                           }else {
                               cout<<ro->first->TO<<endl;
                               ro->first = ro->first->link;
                            
                           }
                          Recount++; 
                        }   
                        }else{
                            cout << "Error" <<endl;
                        }

               //remove();
               //SearchRound();
               Round * Rounds = H;
                string retime;
                //int re;
               // int i=0;
               //getline(cin,retime);
                retimes:
                //cin.ignore(); 
                 ro->first = ro->head;
                cin.ignore();
                cin.clear();
               // cout<<"Please Write Back (Y/N) : "<<endl;
                cin >> retime;
               // re=0;
              // cout << "head: " <<ro->head->TO <<endl;
               
                
                while(ro->first != NULL){
                    //cout << "Check : " <<ro->first->TO <<endl;
                    if(retime == ro->first->TO){
                        goto correct;
                    }else{
                        ro->first = ro->first->link;
                    }

                }

               // cout<<"Please Write Back (Y/N) : "<<endl;
                   if(retime == "Y"||retime =="y"){
                        return "Y";
                    }
                goto retimes;
                correct:
                while( Rounds ->Name != DepartureStation){
                         Rounds = Rounds ->link;
                 }
                         int i = 0;
                        // cout << Rounds->count<<endl;
                            while(Rounds->first != NULL){
                                if( retime == Rounds ->first->TO){
                                    cout<<" Correct "<<endl;
                                    cout<<" Time : " << Rounds ->first->TO<<endl;
                                    Sleep(1000);
                                    break;
                                }
                                Rounds ->first = Rounds ->first->link;
                                i++;
                            }

                 Sleep(1500);
                 return retime;
            
        }
        int ViewCycleTime :: Calculate(){
          cout<<head->calculate_cost(DepartureStation,TerminalStation);
          Sleep(1500);
          return head->calculate_cost(DepartureStation,TerminalStation);

        }
