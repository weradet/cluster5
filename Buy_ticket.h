#include<iostream>
using namespace std;
class Buy_ticket_controller{
    private:
        string Terminal;
        string Departure;
        int Cost;
        string Round;
    public:
        Buy_ticket_controller();
        void Seach();
        void Departure_Staion();
        void Terminal_Staion();
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
}
void Buy_ticket_controller :: Seach(){

}
void Buy_ticket_controller :: Departure_Staion(){

}
void Buy_ticket_controller :: Terminal_Staion(){

}
void Buy_ticket_controller :: Chose_Round(){

}
double Buy_ticket_controller :: Calculate(){

}
void Buy_ticket_controller :: Payment(){

}
void Buy_ticket_controller :: Print_Ticket(){
    cout<<"ORIGIN : "<< <<endl;
    cout<<"DESTINATION  : "<< <<endl;
    cout<<"DEPARTURE DATE : "<< <<endl;
    cout<<"ROUND : "<< <<endl;
    cout<<"PRICE : "<< <<endl;
}

