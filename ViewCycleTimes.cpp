#include"ViewCycleTimes.h"

        void ViewCycleTime::ChooseDepatureStation(string name){
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

        void ViewCycleTime::ChooseTeminalStation(string name){

        }
