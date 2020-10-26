#ifndef BUY_TICKET_H
#define BUY_TICKET_H
#include"include.h"
#include"ViewCycleTimes.h"
#include"Path.h"
class Buy_ticket_controller{
    public:
        double change;
        ViewCycleTime * view; 
        Path *Head;
        Buy_ticket_controller();
        void Seach();
        double Calculate();
        double Payment();
        void Print_Ticket();
        void View(); 
};
#endif