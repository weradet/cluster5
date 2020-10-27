#ifndef BUY_TICKET_H
#define BUY_TICKET_H
#include"include.h"
#include"ViewCycleTimes.h"
#include"Path.h"
#include"domainclass.h"
#include"Round.h"
class Buy_ticket_controller{
    public:
        double change;
        ViewCycleTime * view; 
        Path *Head;
       // Round *round;
      //  Member *mem;

        Buy_ticket_controller();

        void SeachDeparture();
        void SeachTerminal(string Departure);
        Round* ShowTime_Buyticket(string name);
        void Calculate();
        double Payment();
        void Print_Ticket(string retime);
        void Print_Ticket_Customer(string retime);
        void View(); 
      //  void member();
};
#endif