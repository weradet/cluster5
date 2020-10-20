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
        void SetMemberInformation(string f,string l,string t,string pw){
             //  UserMember
             UserMember.Setmember(f,l,t,pw);  
             list_member->Addmember(UserMember);          
        }
        void ShowUserInformation(string name){
             Member *customer = list_member->searchMember(name);
             if(customer != NULL){
                system ("cls");
                cout << "================ Customer Information ===============" << endl;
                cout << "Firstname : " << customer->getFirstname() << endl;
                cout << "Lastname : " << customer->getLastname() << endl;
                cout << "Tel. : " << customer->getTel() << endl;
             }else{
                cout << "Error Information!!" << endl;
             }
             
        }
        void ShowExpireCard(string name){
             Member *customer = list_member->searchMember(name);
             if(customer!=NULL){
                cout << "ExpireCard : " << customer->getExpire();
                cout << "\n===================================================" << endl;   
             }else{
                cout << "Error Information!!" << endl;
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