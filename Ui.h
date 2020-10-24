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
#include "node_Addstation.h"
//#include"Buy_ticket.h"
class UI{
    private:
        RenewController *Renew_obj;  
        RegisterController *Regis_obj;
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
        void WriteFixFile();
        
        
        void InputPersonalInformation(string firstname,string lastname,string tel,string password);
        void ShowInformation(string firstname,string password);
        void ShowExprirationDate(string firstname,string password);
        void InputMoneyCard(double money,string password);
        void ShowRemainingAmount(string password);
        void LoadFile();
        void SaveFile();
        void ShowMember();
        void ClearRegister();


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

        void Addstation(string StationName,string StationID,int Cost,string Status);
        void AddStation_ontheway(int index,string StationID,string StationName,int Cost,string Status);
        bool checkStationID(string id);
        bool checkStationName(string name);
        void WriteStationfile();
        void show_station();
        int StationNumber();//คืนค่าจำนวนสถานี(return count)
        void WriteRoundfile();

        void View();
};
#endif