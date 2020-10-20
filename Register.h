// 62160085 Natsuda Kuhasak //
// 62160334 Mattaneeya Phosrisuk //
#include "include.h"
class RegisterController{
    private:
         Member UserMember;
    public:
        RegisterController(string f,string l,string t,string id){
           UserMember.Setmember(f,l,t);
        }
        ~RegisterController(){
        }//destructer
        void SetMemberInformation(string f,string l,string t){
             //  UserMember
             UserMember.Setmember(f,l,t);
        }
        string SetMemberCard(){
            
        }
        void MemberCardInformation(){

        }
        void EnterMoney(){

        }
        void TopupMoney(){

        }
        void SaveMoneyInformation(){

        }
};