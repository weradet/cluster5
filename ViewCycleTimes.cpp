#include"ViewCycleTimes.h"
        ViewCycleTime::ViewCycleTime(){
            head = new Path;
            head->read_file();
            first = NULL;
            last = NULL;
            count = 0;
            H = NULL;
            Ttime = "";
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
        }
        bool ViewCycleTime::Check(string name){
            Path *a = head;
            int i=0;
          //  cout << a->count <<endl;
                while(a->head != NULL){
                    if(a->head->StationID()== name){
                        
                        return true;
                    }
                   
                    if(i > a->count){
                        return false;
                    }
                    i++;
                    a->head=a->head->link;
                    
                }
                return true;
        }
        void ViewCycleTime::ChooseTerminalStation(string terminal){

            Path *a = head;
                while(a->head != NULL){
                    if(a->head->StationID()== terminal){
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
               // Times(); 
        }


         Round* ViewCycleTime::Times(string name){
               Path *a = head;
                while(a->head != NULL){
                    if(a->head->StationID()== name){
                      
                        break;
                    }
                    a->head=a->head->link;
                }
                TerminalStation = a->head->stationName();
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
            return ro;
            
        }

        int ViewCycleTime :: Calculate(){
          //cout<<head->calculate_cost(DepartureStation,TerminalStation);
          //Sleep(1500);
          return head->calculate_cost(DepartureStation,TerminalStation);

        }
        void ViewCycleTime :: ShowView(){
            cout<<"Cost : "<<head->calculate_cost(DepartureStation,TerminalStation)<<endl;
            Sleep(1500);
        }
