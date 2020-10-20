#include "include.h"
#include "station.h"
class Path{
    private:

    public:
        linklist_station *head;
        linklist_station *tail;
        int count;
        void add_path(Station station){
            linklist_station *New = new linklist_station(Station station);
            if(head == NULL){
                head = New;
                tail = New;
                count++;
            }else{
                tail->plink = tail;
                tail = New;
                count++;
            }
        }
        void read_file(){
		string Id,Fac,Date,In,Out,filein;
        int Cost
			filein = "checking.dat";
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
					    
                        Station Station(name,id,Cost,status);
						add_path(Station);
					}
					infile.close();
					}
					return true;
        }
        void calculate_cost(string DepartureStation,string TerminalStation){
            

        }
};

class linklist_station{
    public:
        linklist_station *link;
        linklist_station *plink;
        Station station;
        string cost;
        linklist_station(Station station){
            this->station = station;
            link = NULL;
            plink = NULL;
        }
};