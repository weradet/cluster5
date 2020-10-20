#ifndef PATH_H
#define PATH_H
#include "include.h"
#include "station.h"


class Path{
    private:

    public:
        Station *head;
        Station *tail;
        int count;
        void add_path(string id,string sta_name,string sta_stu,int cost){
            Station *New = new Station(id,sta_name,sta_stu,cost);
            if(head == NULL){
                head = New;
                tail = New;
                count++;
            }else{
                tail->plink = tail;
                tail = New;
                tail->link = head;
                head->plink = tail;
                count++;
            }
        }
        Path(){
            head = NULL;
            tail = NULL;
            count = 0;
        }
        void read_file(){
		string Id,Fac,Date,In,Out,filein;
        int Cost
			filein = "Station.txt";
			ifstream infile;
            stringstream ss()
			infile.open(filein.c_str(),std::ios::in);
				if(infile.fail()){
					return false;
				}else{
					while(getline(infile,filein)){
						name = filein.substr(0,filein.find(','));
						     filein.erase(0,filein.find(',')+1);
						id = filein.substr(0,filein.find(','));
						     filein.erase(0,filein.find(',')+1);
						cost = filein.substr(0,filein.find(','));
						     filein.erase(0,filein.find(',')+1);
						status = filein;
                        stringstream ss(cost);
                        ss >> Cost
					    
						add_path(name,id,Cost,status);
					}
					infile.close();
					}
					
        }

        void show(){
            linklist_station *a = head;
            for(int i=0;i<count;i++){
                //cout << a->station.StationID() << endl;
            }
        }

        void calculate_cost(string DepartureStation,string TerminalStation){
            

        }
};

#endif