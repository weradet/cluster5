#ifndef BUY_MEMMER_H
#define BUY_MEMMER_H
#include"include.h"
#include"ViewCycleTimes.h"
#include"Path.h"
#include"domainclass.h"
#include"Round.h"
class Buy_Member_controller{
    public:
        double change;
        ViewCycleTime * view; 
        ViewCycleTime * isview;
        Path *Head;
       // Round *round;
      //  Member *mem;
         Member *head;
         Member *tail;

        Buy_Member_controller();
        void SeachDeparture();
        void SeachTerminal(string Departure);
        Round* ShowTime_Buyticket(string name);
        void Calculate();
        double Payment(string password);
        void Print_Ticket(string retime);
        void Print_Ticket_Customer(string retime);
        void View(); 
        bool checkmember(string password);
        void Loaddata();
        void SetMemberIndata(string firstname,string lastname,string tel,string password,string expire,string money);
        void clear();
        bool CheckPayment(string password);
        void savedata();
      //  void member();
};
#endif