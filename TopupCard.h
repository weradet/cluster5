//62160157 Preechaya Choosrithong
#ifndef TOPUPCARD_H
#define TOPUPCARD_H
#include"include.h"
#include"domainclass.h"
class TopupCardController{
     public:
            //Member UserMember;
           // ListMember *list_member;
           Member *head;
           Member *tail;
        public:
        TopupCardController();
        void ShowMenuTopupCard();
        Member* CheckMember(string Pass_Card);
        void ShowMemberInformation(Member *cur);
        void TopupMoney(double money,string password);
        void ShowRemainingAmount(Member *cur);
        void Loaddata();
        void savedata();
        void SetMemberIndata(string firstname,string lastname,string tel,string password,string expire,string money);
 
};
 #endif           