/* Create By Weradet Nopsombun 62160110 
   Use Case - Renew Card
    *** Add class MemberList
*/ 
#ifndef RENEWCARD_H
#define RENEWCARD_H
#include"include.h"
#include"domainclass.h"
//Class
class RenewController{
    //Contro Usecase Renew Card
    //Member user_member;  
public:
    Member *head;
    Member *tail;
    
    void PrintRenewMenu();
    void Entercardcode(string cardcode);
    bool Findmember();
};
#endif
// Function