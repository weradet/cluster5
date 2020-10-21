#ifndef BUY_TICKET_H
#define BUY_TICKET_H
#include"include.h"
//#include"station.h"
#include"Path.h"
class Buy_ticket_controller{
    private:
        string Terminal;
        string Departure;
        int Cost;
        string Round;
    public:
       // Path line;
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
#endif