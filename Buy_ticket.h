#include<iostream>
using namespace std;
class Buy_ticket_controller{
    private:
        string terminal;
        string departure;
        int cost;
        string round;
    public:
        void Seach();
        void Departure_Staion();
        void Terminal_Staion();
        void Chose_Round();
        void Calculate();
        void Payment();
        void Print_Ticket();
};

