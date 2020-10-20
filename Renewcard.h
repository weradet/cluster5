/* Create By Weradet Nopsombun 62160110 
   Use Case - Renew Card
    *** Add class MemberList
*/ 
#include"include.h"
//Class
class RenewController{
    //Contro Usecase Renew Card
private:
    Member user_member;  
public:
 
    void PrintRenewMenu(){
        //print interface ewnew card menu
        cout << "****Renew Card****" << endl;
        cout << "1.Renew Card" << endl;
        cout << "2. Back " << endl;
    }
    void Entercardcode(string cardcode){

    }
    bool Findmember(){
       return true; 
    }
};

// Function