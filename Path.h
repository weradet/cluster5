#include "include.h"
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
class Path{
    private:

    public:
        linklist_station *head;
        linklist_station *tail;
        void add_path(string name){
            linklist_station *New = new linklist_station(name);
            if(head == NULL){
                
            }else{

            }
        }
};