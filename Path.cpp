#include"Path.h"
        Path::Path(){       
            head = NULL;
            tail = NULL;
            count = 0;
        }
        void Path::add_path(string id,string sta_name,string sta_stu,int cost){
            Station *New = new Station(id,sta_name,sta_stu,cost);
            if(head == NULL){
                head = New;
                tail = New;
                tail->link = head;
                head->plink = tail;
                count++;
            }else{
                tail->link = New;	
				New->plink = tail;
				tail = New;
                tail->link = head;
                count++;
            }
        }
        void Path::read_file(){
            string id,name,cost,status,filein;
            int Cost;
                filein = "Station.txt";
                ifstream infile;
                stringstream ss();
                infile.open(filein.c_str(),std::ios::in);
                        while(getline(infile,filein)){
                            name = filein.substr(0,filein.find(','));
                                filein.erase(0,filein.find(',')+1);
                            id = filein.substr(0,filein.find(','));
                                filein.erase(0,filein.find(',')+1);
                            cost = filein.substr(0,filein.find(','));
                                filein.erase(0,filein.find(',')+1);
                            status = filein;
                            stringstream ss(cost);
                            ss >> Cost;
                            add_path(name,id,status,Cost);
                        }
                        infile.close();			
        }
        void Path::show(){
            Station *a = head;
            while(a != NULL){
                cout << a->StationID() << a->stationName() << a->stationStatus() << a->cost() << endl;
                a = a->link;
            }
        }

        void Path::calculate_cost(string DepartureStation,string TerminalStation){
            
        }