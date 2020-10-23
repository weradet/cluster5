#include"domainclass.h"
        MemberCard::MemberCard(){
          Money = 0;
        }
        void MemberCard::PasswordCard(string pass){
          Password = pass; 
        }    
        string MemberCard::getPassword(){
          return Password;
        }
        string MemberCard::getDayExpire(){
          return DayExpire;
        }
        void MemberCard::GenerateExpire(){
          time_t now = time(0);
          tm *ltm = localtime(&now);
          stringstream ss;
          ss <<  1901+ltm->tm_year << "-" << 1+ltm->tm_mon << "-" << ltm->tm_mday;
          string date = ss.str();
          DayExpire = date;
        }
        void MemberCard::renewcard(){
          //DayExpire = dayexpire;
          time_t now = time(0);
          tm *ltm = localtime(&now);
          stringstream ss;
          ss <<  1901+ltm->tm_year << "-" << 1+ltm->tm_mon << "-" << ltm->tm_mday;
          string date = ss.str();
          cout << "Date :" << date << endl;
          setDateExpire(date);
        }
        double MemberCard::getMoney(){
          return Money;
        }
        void MemberCard::TopupMoney(double money){
          Money += money;
        }
        void MemberCard::setMoney(double money){
          Money = money;
        }
        void MemberCard::PayTicket(double money){
          Money -= money;
        }
        void MemberCard::setDateExpire(string dayexpire){
          //cout << "In" << endl;
          DayExpire = dayexpire;
        }
        bool MemberCard::CheckMoneyCard(double money){
             double customer_money = Money+money;
                    if(customer_money > 10000){
                      return true;
                    }
        }
     
     
        Member::Member(){
        link = NULL;
        }
        Member::Member(string firstname,string lastname,string tel,string password,string expire,string money){
          Firstname = firstname;
          Lastname = lastname;
          Tel = tel;
          member_card.PasswordCard(password);
          stringstream ss;
          ss << money;
          double Money;
          ss >> Money;
          member_card.setDateExpire(expire);
          member_card.setMoney(Money);
          link = NULL;
        }
        void Member::setMember(string firstname,string lastname,string tel,string password){
          Firstname = firstname;
          Lastname = lastname;
          Tel = tel;
          member_card.PasswordCard(password);
          member_card.GenerateExpire();
        }
        string Member::getFirstname(){
          return Firstname;
        }
         string Member::getLastname(){
          return Lastname;
        }
         string Member::getTel(){
          return Tel;
        }
        string Member::getPassword(){
          return member_card.getPassword();
        }
        string Member::getExpire(){
          return member_card.getDayExpire();
        }
        double Member::getMoney(){
          return member_card.getMoney();
        }
        void Member::Topupmoney(double money){
          member_card.TopupMoney(money);
        }
        MemberCard Member::getmembercard(){
          return member_card;
        }
