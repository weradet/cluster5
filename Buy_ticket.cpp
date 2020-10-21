#include"Buy_ticket.h"
Buy_ticket_controller :: Buy_ticket_controller(){
        Terminal = " ";
        Departure = " ";
        Cost = 0;
        Round = " ";
        Head  = new Path();
}
void Buy_ticket_controller :: Seach(){

}
void Buy_ticket_controller :: Departure_Staion(string Origin){
    
}
void Buy_ticket_controller :: Terminal_Staion(string destination){
    Head->read_file();
    Path *train = Head;
    while(train != NULL){
    if(destination == train->head->stationName()){
         cout << train->head->StationID();
         break;
    }
        train->head = train->head->link;
    }

}
void Buy_ticket_controller :: Chose_Round(){

}
double Buy_ticket_controller :: Calculate(){
return 1000;
}
void Buy_ticket_controller :: Payment(){

}
void Buy_ticket_controller :: Print_Ticket(){
    cout<<"ORIGIN : "<<"" <<endl;
    cout<<"DESTINATION  : "<<"" <<endl;
    cout<<"DEPARTURE DATE : "<<"" <<endl;
    cout<<"ROUND : "<<"" <<endl;
    cout<<"PRICE : "<<"" <<endl;
}

