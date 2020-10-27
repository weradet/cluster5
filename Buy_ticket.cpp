#include"Buy_ticket.h"
Buy_ticket_controller :: Buy_ticket_controller(){
        Head  = new Path;
        view = new ViewCycleTime;
        view->SearchRound();
       // mem = new Member;
}
void Buy_ticket_controller :: SeachDeparture(){
    view->ChooseDepartureStation();
}
void Buy_ticket_controller::SeachTerminal(string Departure){
    view->ChooseTerminalStation(Departure);
}
Round* Buy_ticket_controller ::ShowTime_Buyticket(string name){
    return view->Times(name);
}
void Buy_ticket_controller :: Calculate(){
    view->ShowView();
}
double Buy_ticket_controller :: Payment(){
    double money;
    double Change = 0;
    do{
    //cout<<endl;
    //cout<<view->Calculate()<<endl;
    cout<<"Please Input Money : ";
    cin>>money;
    if(money<view->Calculate()){
        cout<<"!! Not Enough Money !! "<<endl;
    }
    else if(money > view->Calculate()){
       Change = money - view->Calculate();
       change = Change;
    }
    else if(money == view->Calculate()){
        change = 0;   
    }
    }while(money<view->Calculate());
    return change;
}
void Date(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout<<"DEPARTURE DATE : "<<1900 + ltm->tm_year<<":"<<1 + ltm->tm_mon<<":"<<ltm->tm_mday<<endl;
}
void Buy_ticket_controller :: Print_Ticket(string retime){
    cout<<"========================================="<<endl;
    cout<<"ORIGIN : "<<view->DepartureStation <<endl;
    cout<<"DESTINATION  : "<<view->TerminalStation <<endl;
    Date();
    cout<<"ROUND : "<<retime <<endl;
    cout<<"PRICE : "<<view->Calculate() <<endl;
    cout<<"CHANGE : "<< change <<endl;
    cout<<"========================================="<<endl;
    Sleep(1500);
}
void Buy_ticket_controller :: Print_Ticket_Customer(string retime){
    cout<<"========================================="<<endl;
    cout<<"ORIGIN : "<<view->DepartureStation <<endl;
    cout<<"DESTINATION  : "<<view->TerminalStation <<endl;
    Date();
    cout<<"ROUND : "<<retime <<endl;
    cout<<"PRICE : "<<view->Calculate() <<endl;
   // cout<<"CHANGE : "<< change <<endl;
    cout<<"========================================="<<endl;
    Sleep(1500);
}




