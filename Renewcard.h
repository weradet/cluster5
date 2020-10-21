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
private:
    Member user_member;  
public:
 
    void PrintRenewMenu();
    void Entercardcode(string cardcode);
    bool Findmember();
};
#endif
// Function