#include"ViewCycleTimes.h"
        ViewCycleTimes::ViewCycleTimes(){
            head = new Path;
            head->read_file();
        }

        void ViewCycleTimes::ChooseDepatureStation(string name){
            Path *a = head;
            Path *b = head;
                while(a->head != NULL){
                    if(a->head->stationName()== name){
                        break;
                    }
                    a->head=a->head->link;
                }
                while(b->head != a->head->plink){
                    cout << b->head->StationID() << endl;
                }
        }

        void ViewCycleTimes::ChooseTeminalStation(string name){

        }
