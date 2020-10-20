#include "include.h"
<<<<<<< Updated upstream
class linklist_station{
    public:
        linklist_station *link;
        linklist_station *plink;
        string station_name;
        linklist_station(string name){
            station_name = name;
            link = NULL;
            plink = NULL;
        }
};
=======
#include "station.h"
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======
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
>>>>>>> Stashed changes
};