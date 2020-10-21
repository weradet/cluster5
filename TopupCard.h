//62160157 Preechaya Choosrithong
#ifndef TOPUPCARD_H
#define TOPUPCARD_H
#include"include.h"
#include"domainclass.h"
class TopupCardController{
        private:
            Member UserMember;
            ListMember *list_member;
        public:
        TopupCardController();
        void ShowMenuTopupCard();
        void CheckMember(string Pass_Card);
        void ShowMemberInformation();
        void TopupMoney(double money,string password);
        void ShowRemainingAmount(string password);
 
};
 #endif           