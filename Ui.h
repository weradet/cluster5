#ifndef UI_H
#define UI_H
#include"include.h"
#include"station.h"
#include"Station_Controller.h"
#include"Path.h"
#include"Status.h"
#include"Register.h"
#include"Renewcard.h"
#include"TopupCard.h"
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
    TopupCardController *topupcard;
    public:
        UI();
        bool CheckStatus(string name);
        void PrintCustomer();
        void PrintAdmin();
        void PrintFirstMenu();
        void ChooseFixMenu(string id,int menu);
        void ShowFixMenuStation();
        void ShowAllStation();
        void InputPersonalInformation(string firstname,string lastname,string tel,string password);
        void ShowExprirationDate(string name);
        void ShowInformation(string name);
        void InputMoney(double money,string pass);
        void savefile();
        void loadfile();
};
#endif