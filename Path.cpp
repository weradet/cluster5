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
        void Path::remove(){
            int num = count;
            Station *temp = head;
            //Station *ptemp = tail;
            for(int i=0; i<num;i++){
                temp = head;
                if(count != 0){
                    head = temp->link;
                    delete temp;
                    tail->link = head;
                    head->plink = tail;
                    count--; 
                }else if(count == 1){
                    head = NULL;
                    tail = NULL;
                    delete temp;
                    count--;
                }
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
                            status = filein.substr(0,filein.find(','));
                                filein.erase(0,filein.find(','));
                            stringstream ss(cost);
                            ss >> Cost;
                            add_path(name,id,status,Cost);
                        }
                        infile.close();			
        }

        double Path::calculate_cost(string DepartureStation,string TerminalStation){
            Station *temp = head;
                for(int i = 0; i<count ;i++){
                    if(DepartureStation == temp->stationName()){
                        break;
                    }
                    temp = temp->link;
                }
                double sum = 0;
                for(int i=0;i<count;i++){
                    if(TerminalStation == temp->stationName()){
                        break;
                    }else{
                        sum += temp->cost();
                        temp = temp->link;
                    }
                }
                return sum;
        }