#include"include.h"
#include"station.h"
using namespace std;
class Buy_ticket_controller{
    private:
        string Terminal;
        string Departure;
        int Cost;
        string Round;
    public:
        Path *Head;
        Buy_ticket_controller();
        void Seach();
        void Departure_Staion(string Origin);
        void Terminal_Staion(string destination);
        void Chose_Round();
        double Calculate();
        void Payment();
        void Print_Ticket();
};
Buy_ticket_controller :: Buy_ticket_controller(){
        Terminal = " ";
        Departure = " ";
        Cost = 0;
        Round = " ";
        Head  = new Path();
        //Head->head = Head->head;


}
void Buy_ticket_controller :: Seach(){

}
void Buy_ticket_controller :: Departure_Staion(string Origin){
    Head->read_file();
    Head->add_path();
    Path * train = Head;
    while(train != NULL){
    if(Origin == train->StationName){
         cout << Head->head->StationID();
         break;
    }
        train = train->link;
    }
}
void Buy_ticket_controller :: Terminal_Staion(string destination){
    Head->read_file();
    Head->add_path();
    Path *train = Head;
    while(train != NULL){
    if(destination == train->StationName){
         cout << Head->head->StationID();
         break;
    }
        train = train->link;
    }

}
void Buy_ticket_controller :: Chose_Round(){

}
double Buy_ticket_controller :: Calculate(){

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

