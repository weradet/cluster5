// 62160085 Natsuda Kuhasak //
// 62160334 Mattaneeya Phosrisuk //
#include "include.h"
class RegisterController{
    private:
        string Firstname;
        string Lastname;
        string Tel;
    public:
        Register(string f,string l,string t){
            Firstname = f;
            Lastname = l;
            Tel = t;
        }
        ~Register(){
        }//destructer
        void AddMember(){
            
        }
        void SetMemberInformation(string f,string l,string t){
            Firstname = f;
            Lastname = l;
            Tel = t;
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