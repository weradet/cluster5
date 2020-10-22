#ifndef DOMAINCLASS_H
#define DOMAINCLASS_H
#include"include.h"
class MemberCard{
      private:
        string Password,DayExpire;
        double Money;
      public:
        MemberCard();
        void PasswordCard(string pass);    
        string getPassword();
        string getDayExpire();
        void GenerateExpire();
        double getMoney();
        void TopupMoney(double money);
        void InputMoneyCard(double numMoney,string password);
        void setMoney(double money);
        void PayTicket(double money);
        void setDateExpire(string dayexpire); 
};

class Member{
      //class member 
      private:
        string Firstname,Lastname,Tel;
        MemberCard member_card; 
        /*data is name of member lastname 
        Telephone number 
        Thai Id Card */ 
      public: 
        Member *link;
        Member();
        Member(string firstname,string lastname,string tel,string password,string expire,string money);
        void setMember(string firstname,string lastname,string tel,string password);
        string getFirstname();
        string getLastname();
        string getTel();
        string getPassword();
        string getExpire();
        double getMoney();
        MemberCard getmembercard();
        void Topupmoney(double money);
};
#endif