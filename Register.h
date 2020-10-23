#ifndef REGISTER_H
#define REGISTER_H
#include "include.h"
#include "domainclass.h"
class RegisterController{
    public:
        Member UserMember;
        MemberCard PassMember;
        Member *head;
        Member *tail;
        RegisterController(); 
        ~RegisterController();
        void SetMemberInformation(string firstname,string lastname,string tel,string password);
        void ShowUserInformation(string firstname,string password);
        void ShowExpireCard(string firstname,string password);
        void SetMemberInData(string firstname,string lastname,string tel,string password,string expire,string money);
        void InputMoneyCard(double money,string password);
        void LoadData();
        void SaveData();
        void ShowRemainingAmount(Member *cur);
        void ShowMember();   
        void clear();     
};
#endif