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
        Member(string firstname,string lastname,string tel,string password);
        void setMember(string firstname,string lastname,string tel,string password);
        string getFirstname();
         string getLastname();
         string getTel();
        string getPassword();
        string getExpire();
        double getMoney();
        void Topupmoney(double money);
};

class ListMember{
//Linked list Member 
      private:
        Member *head;
        Member *tail;
      public:
        ListMember();
        ~ListMember();
        void Printlist();
        void Addmember(Member newmember);
        void Addmember(string firstname,string lastname,string tel,string password,string expire,string money);
        Member *searchMember(string name);
        Member *getMember(string password_card);
        void savedata();
        void Loaddata(); 
      
};
