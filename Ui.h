#ifndef UI_H
#define UI_H
#include "include.h"
#include "station.h"
#include "Station_Controller.h"
#include "Path.h"
#include "Status.h"
#include "Register.h"
#include "Renewcard.h"
#include "TopupCard.h"
#include "StationList.h"
#include "ViewCycleTimes.h"
//#include"Buy_ticket.h"
class UI{
    /*
    class UI 
    any ui in the project
    */
    private:
    RenewController *Renew_obj;  
    RegisterController *Regis_obj;
    //Buy_ticket_controller *a;
    StationController *station_obj;
    TopupCardController topupcard;
    StationList *StationList_obj;
    ViewCycleTime *view;
    public:
        UI();
        void readfile();
        bool CheckStatus(string name);
        void PrintCustomer();
        void PrintAdmin();
        void PrintFirstMenu();
        void ChooseFixMenu(string id,int menu);
        void ShowFixMenuStation();
        void ShowAllStation();
        void ShowStaiton(string id);
        
        
        void InputPersonalInformation(string firstname,string lastname,string tel,string password);
        void ShowInformation(string firstname,string password);
        void ShowExprirationDate(string firstname,string password);
        void InputMoneyCard(double money,string password);
        void LoadFile();
        void SaveFile();
        void ShowMember();


        void ShowMenu();
        bool checkmember(string password);
        void InputMoney(double money,string pass);
        void Showmoney(string password);
        void loadtopupfile();
        void savetopupfile(); 
        void Clear();
        

        void showmenuRenewCard();
        void EnterCardcode(string password);
        void loaddataRenew();
        void SaveDataRenew();
        void ConfirmRenew();
        void ClearRenewdata();

        void Addstation(string StationID,string StationName,string Status,int Cost);
        void AddStation_ontheway(int index,string StationID,string StationName,string Status,int Cost);
        bool checkStationID(string id);
        bool checkStationName(string name);
        void WriteStationfile();
        void show_station();
        int StationNumber();//คืนค่าจำนวนสถานี(return count)

        void View();
};
#endif