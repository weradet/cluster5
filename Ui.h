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
#include"Buy_ticket.h"
#include"Buy_memer.h"
class UI{
    private:
        RenewController *Renew_obj;  
        RegisterController *Regis_obj;
        StationController *station_obj;
        TopupCardController topupcard;
        StationList *StationList_obj;
        ViewCycleTime *view;
        ViewCycleTime *isview;
        Buy_ticket_controller *Buy;
        Buy_Member_controller *BuyCustomer;
        
    public:
        UI();
        bool CheckID(string id);
        void remove();
        void readfile();
        bool CheckStatus(string name);
        void PrintCustomer();
        void PrintAdmin();
        void PrintFirstMenu();
        void ChooseFixMenu(string id,string menu);
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
        void ClearRenewdata();
        bool CheckmemberRenew(string password);

        void Addstation(string StationName,string StationID,int Cost,string Status);
        void AddStation_ontheway(int index,string StationID,string StationName,int Cost,string Status);
        bool checkStationID(string id);
        bool checkStationName(string name);
        void WriteStationfile();
        void show_station();
        int StationNumber();//คืนค่าจำนวนสถานี(return count)
        void WriteRoundfile();
        void ReadStationFile();
        void chang();

        //view
        void Show_Departure();
        void Show_Terminal(string departure);
        Round* Show_viewcycles(string name);
        bool Check(string ID_station);
        void Show_Cost();

        //Buyticket
        void BuyTicket_Departure();
        void BuyTicket_Terminal(string Terminal);
        bool Check_Station(string ID_station);
        void BuyTicket_Customer();
        Round* ShowTime_Buyticket(string name);
        void Buy_Calculate();
        void Buy_Shows(string retime);
        void Buy_Ticket_Calculate();
        void BuyTicket_Customer(string retime);
  // is = fluk
        //Buy ticket Member
         bool checkmemberBuy(string password);
         void LoaddataBuymember();
         void clearBuy();
        void isShow_Departure();
        void isShow_Terminal(string departure);
        Round* isShow_viewcycles(string name);
        bool isCheck(string ID_station);
         
        //Buyticket
        void isBuyTicket_Departure();
        void isBuyTicket_Terminal(string Terminal);
        bool isCheck_Station(string ID_station);
        void isBuyTicket_Customer();
        Round* isShowTime_Buyticket(string name);
        void isBuy_Calculate();
        void isBuy_Shows(string retime);
        void isBuy_Ticket_Calculate(string password);
        void isBuyTicket_Customer(string retime);
        void SavedataBuyMember();
        bool checkPayment(string password);
};
#endif