#ifndef BUY_TICKET_H
#define BUY_TICKET_H
#include"include.h"
#include"ViewCycleTimes.h"
#include"Path.h"
class Buy_ticket_controller{
    public:
        string Terminal;
        string Departure;
        int Cost;
        string Round;
        Path *Head;
        Buy_ticket_controller();
        void Seach();
        double Calculate();
        void Payment();
        void Print_Ticket();
        void View(); 
};
#endif