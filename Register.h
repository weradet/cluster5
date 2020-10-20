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
        ~RegisterController(){
        }//destructer
        void SetMemberInformation(string f,string l,string t,string pwc){
             //  UserMember
             UserMember.Setmember(f,l,t,pwc);  
             list_member->Addmember(UserMember);          
        }
        void ShowuserInformation(string name){
             Member *customer = list_member->searchMember(name);
             if(customer!=NULL){
                 cout << "====Customer Information===" << endl;
                 cout << "Name: "     <<customer->getname() << endl;
                 cout << "LastName: " <<customer->getlastname() << endl;
                 cout << "Tel.: " <<customer->gettel() <<" "<< endl;
             }else{
                 cout << "Error Information" << endl;
             }
             
        }
        void showExpireCard(string name){
             Member *customer = list_member->searchMember(name);
             if(customer!=NULL){
                 cout << "ExpireCard : " << customer->getExpire();   
             }else{
                 cout << "Error Information" << endl;
             }
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