#include"Station_Controller.h"        
        void StationController::ChooseFixMenu(string id,int menu){
             obj_sta.ChooseFixMenu(id,menu);
        }
         void StationController::ShowAllStation(){
            obj_sta.ShowAllStation();
        } 
        void StationController::ShowFixMenuStation(){
            cout << "------------------- Menu -------------------" << endl;
            cout << "1. Fix Station Cost"       << endl;
            cout << "2. Maintenance Station"    << endl;
            cout << "3. Fix Station Name"       << endl;
            cout << "--------------------------------------------" << endl;
        }