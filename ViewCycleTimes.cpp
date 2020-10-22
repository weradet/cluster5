#include"ViewCycleTimes.h"
        ViewCycleTime::ViewCycleTime(){
            head = new Path;
            head->read_file();
        }
        void ViewCycleTime::ChooseDepartureStation(string name){
            Path *a = head;
         //   Path *b = head;
                while(a->head != NULL){
                    if(a->head->stationName()== name){
                        break;
                    }
                    a->head=a->head->link;
                }
                a->head=a->head->link;
                for(int i=0;i<a->count-1;i++){
                    if(a->head->stationStatus() != "close"){
                        cout << a->head->StationID()<<endl;
                    }
                    a->head = a->head->link;
                }
        }

        void ViewCycleTime::ChooseTerminalStation(string name){

        }
