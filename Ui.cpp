#include "Ui.h"
UI::UI(){
    Renew_obj = new RenewController;
    Regis_obj = new RegisterController;
    station_obj = new StationController;
    StationList_obj = new StationList;
    view = new ViewCycleTime;
}
void UI::PrintCustomer(){
    cout << "\n" << right << setw(80) << "********************************************" << endl;
    cout << right << setw(80) << "*  1. Find Cycle Time                      *" << endl; 
    cout << right << setw(80) << "*  2. Buy Train Ticket                     *" << endl;
    cout << right << setw(80) << "*  3. Topup The Card                       *" << endl;
    cout << right << setw(80) << "*  4. Back To Menu                         *" << endl;
    cout << right << setw(80) << "********************************************" << endl;
    cout << right << setw(70) << "Please Choose 1 Choice (1-4) : ";
}//Print Menu For Customer
void UI::PrintAdmin(){
    cout << "\n" << right << setw(80) << "********************************************" << endl;
    cout << right << setw(80) << "*  1. Find Cycle Time                      *" << endl; 
    cout << right << setw(80) << "*  2. Buy Train Ticket                     *" << endl;
    cout << right << setw(80) << "*  3. Register Member                      *" << endl;
    cout << right << setw(80) << "*  4. Renew Member Card                    *" << endl;
    cout << right << setw(80) << "*  5. Add Station                          *" << endl;
    cout << right << setw(80) << "*  6. Fix Station                          *" << endl;
    cout << right << setw(80) << "*  7. Back To Menu                         *" << endl;
    cout << right << setw(80) << "********************************************" << endl;
    cout << right << setw(70) << "Please Choose 1 Choice (1-7) : ";
}//Print Menu For Admin
void UI::PrintFirstMenu(){
    cout << "\n" << right << setw(80) << "************* Personal *************" << endl;
    cout << right << setw(80) << "*  1.CUSTOMER                      *" << endl;
    cout << right << setw(80) << "*  2.ADMIN                         *" << endl;
    cout << right << setw(80) << "*  3.EXIT THE PROGRAM              *" << endl;
    cout << right << setw(80) << "************************************" << endl;
    cout << right << setw(75) << "Please Choose 1 Choice (1-3) : ";
}//Print Main Menu
bool UI::CheckID(string id){
    return  station_obj->CheckID(id); 
}
void UI::WriteFixFile(){
    station_obj->WriteFixFile();
}
void UI::remove(){
    station_obj->remove();
}
void UI::readfile(){
    station_obj->readfile();
}
bool UI::CheckStatus(string name){
    return station_obj->CheckStatus(name);      
}
void UI::ChooseFixMenu(string id,string menu){
    station_obj->ChooseFixMenu(id,menu);
}
void UI::ShowFixMenuStation(){
    station_obj->ShowFixMenuStation();
}
void UI::ShowAllStation(){
    station_obj->ShowAllStation();
}
void UI::ShowStaiton(string id){
    station_obj->ShowStation(id);
}
/* Usecase Register */
void UI::InputPersonalInformation(string firstname,string lastname,string tel,string password){
    Regis_obj->SetMemberInformation(firstname,lastname,tel,password);   
}
void UI::ShowInformation(string firstname,string password){
    Regis_obj->ShowUserInformation(firstname,password);
}
void UI::ShowExprirationDate(string firstname,string password){
    Regis_obj->ShowExpireCard(firstname,password);
}
void UI::InputMoneyCard(double money,string password){
    Regis_obj->InputMoneyCard(money,password);
}
void UI::ShowRemainingAmount(string password){
    Regis_obj->ShowRemainingAmount(password);
}
void UI::LoadFile(){
    Regis_obj->LoadData();
}
void UI::SaveFile(){
    Regis_obj->SaveData();
}
void UI::ShowMember(){
    Regis_obj->ShowMember();
}
void UI::ClearRegister(){
   Regis_obj->clear();
}


/* Usecase Topup Card */
void UI::ShowMenu(){
    topupcard.ShowMenuTopupCard();
}
bool UI::checkmember(string pass){
    Member *member = topupcard.CheckMember(pass);
    if(member!=NULL){
        return true;
    }
    return false;
}
void UI::InputMoney(double money,string pass){
    topupcard.TopupMoney(money,pass);
}
void UI::Showmoney(string password){
    Member *member = topupcard.CheckMember(password);
    topupcard.ShowRemainingAmount(member);
}
void UI::loadtopupfile(){
    topupcard.Loaddata();
}
void UI::savetopupfile(){
    topupcard.savedata();
}
void UI::Clear(){
    topupcard.clear();
}


/*Usecase Renew Card */
void UI::showmenuRenewCard(){
    Renew_obj->PrintRenewMenu();
} 
void UI::EnterCardcode(string password){
    Renew_obj->Findmember(password);   
}
void UI::loaddataRenew(){
    Renew_obj->Loaddata();
}
void UI::SaveDataRenew(){
    Renew_obj->savedata();
}
void UI::ClearRenewdata(){
    Renew_obj->clear();
}


/* Usecase Add Station */

void UI::Addstation(string StationName,string StationID,int Cost,string Status){
    StationList_obj->Addstation(StationID,StationName,Cost,Status);
}
void UI::AddStation_ontheway(int index,string StationID,string StationName,int Cost,string Status){
    StationList_obj->AddStation_ontheway(index,StationID,StationName,Cost,Status);
}
bool UI::checkStationID(string id){
    return StationList_obj->checkStationID(id);
}
bool UI::checkStationName(string name){
    return StationList_obj->checkStationName(name);
}
void UI::WriteStationfile(){
    StationList_obj->WriteStationfile();
}
void UI::show_station(){
    StationList_obj->show_station();
}
int UI::StationNumber(){
    return StationList_obj->StationNumber();
}
void UI::WriteRoundfile(){
    StationList_obj->WriteRoundfile();
}

void UI::View(){
    view->ChooseDepartureStation();
    view->ChooseTerminalStation();
}