#ifndef REGISTER_H
#define REGISTER_H
#include "include.h"
#include"domainclass.h"
class RegisterController{
    public:
        Member UserMember;
        MemberCard PassMember;
       // ListMember *list_member;
        Member *head;
        Member *tail;
        //Member *cur;
        RegisterController(); 
        ~RegisterController();
        void SetMemberInformation(string f,string l,string t,string pw);
        void SetMemberIndata(string firstname,string lastname,string tel,string password,string expire,string money);
        void ShowUserInformation(string name,string pass);
        void ShowExpireCard(string name,string pass);
        void Showallmember();
        void InputMoneyCard(double numMoney,string password);
        void ShowRemainingAmount(Member *cur);
        void savedata();
        void Loaddata();
};
#endif