#include"Station_Controller.h"    
        bool StationController::CheckID(string id){
            return obj_sta.CheckID(id);
        }
        void StationController::remove(){
            obj_sta.remove();
        }
        void StationController::readfile(){
            obj_sta.read_file();
           // obj_stalist.read_file();
        }
        void StationController::WriteFixFile(){
            obj_sta.WriteFixFile();
        }
        bool StationController::CheckStatus(string name){
           return obj_sta.CheckStatus(name);
        }
        void StationController::ChooseFixMenu(string id,string menu){
            obj_sta.ChooseFixMenu(id,menu);
        }
         void StationController::ShowAllStation(){
            obj_sta.ShowAllStation();
        } 
        void StationController::ShowStation(string id){
            obj_sta.showStation(id);
        }
        void StationController::ShowFixMenuStation(){
            cout << right << setw(81) << "----------------- Menu -------------------" << endl;
            cout << right << setw(62) << "1. Fix Station Cost"       << endl;
            cout << right << setw(65) << "2. Maintenance Station"    << endl;
            cout << right << setw(62) << "3. Fix Station Name"       << endl;
            cout << right << setw(81) << "------------------------------------------" << endl;
        }