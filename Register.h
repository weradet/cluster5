// 62160085 Natsuda Kuhasak //
// 62160334 Mattaneeya Phosrisuk //
#include "include.h"
class RegisterController{
    private:
         Member UserMember;
         ListMember *list_member;
    public:
        RegisterController(){
            list_member = new ListMember;
        } 
        RegisterController(string f,string l,string t,string pass){
           UserMember.Setmember(f,l,t,pass);
        }
        ~RegisterController(){
        }//destructer
        void SetMemberInformation(string f,string l,string t,string pwc){
             //  UserMember
             UserMember.Setmember(f,l,t,pwc);  
             list_member->Addmember(UserMember);
             //list_member->
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