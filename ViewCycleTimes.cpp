#include"ViewCycleTimes.h"
        ViewCycleTime::ViewCycleTime(){
            head = new Path;
            head->read_file();
        }
        void ViewCycleTime::ChooseDepartureStation(){
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
                SetConsoleTextAttribute(color,7);
                cout << "Enter ID TerminalStation: ";
                SetConsoleTextAttribute(color,14);
                cin >> DepartureStation;
                SetConsoleTextAttribute(color,7);
        }

        void ViewCycleTime::ChooseTerminalStation(){
            Path *a = head;
                while(a->head != NULL){
                    if(a->head->StationID()== DepartureStation){
                        break;
                    }
                    a->head=a->head->link;
                }
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
                SetConsoleTextAttribute(color,7);
                cout << "Enter ID TerminalStation: ";
                SetConsoleTextAttribute(color,14);
                cin >> TerminalStation;
        }
