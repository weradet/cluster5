// 62160085 Natsuda Kuhasak //
// 62160334 Mattaneeya Phosrisuk //
#include "include.h"
#include"domainclass.h"

class RegisterController{
    protected:
         Member UserMember;
         MemberCard PassMember;
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
            // list_member->savedata();       
        }
        void ShowUserInformation(string name){
             Member *customer = list_member->searchMember(name);
             if(customer != NULL){
                system ("cls");
                cout << "================ Customer Information ===============" << endl;
                cout << "Firstname : " << customer->getFirstname() << endl;
                cout << "Lastname : " << customer->getLastname() << endl;
                cout << "Tel. : " << customer->getTel() << endl;
                cout << "pass : " << customer->getPassword() << endl;
             }else{
                cout << "Error Information!!" << endl;
             }
             
        }
        void ShowExpireCard(string name){
             Member *customer = list_member->searchMember(name);
             //list_member->printlist();
             if(customer!=NULL){
                cout << "ExpireCard : " << customer->getExpire();  
             }else{
                cout << "Error Information!!" << endl;
             }
        } 
};


class TopupCardController{
        private:
            Member UserMember;
            ListMember *list_member;
        public:
               TopupCardController(){
                 list_member = new ListMember;
                } 
            void ShowMenuTopupCard(){
                int chioceMenu;
                do{
                    cout << "=============== TOPUP ==============="<< endl;
                    cout << "1. Topup" << endl;
                    cout << "2. Show balance" << endl;
                    cout << "3. Back to menu" << endl;
                    cout << "====================================="<< endl;
                    cout << "" << endl;
                }while(chioceMenu!=3);
                
            }

            void CheckMember(string Pass_Card){
                
                
            }

            void ShowMemberInformation(){

            }

            void TopupMoney(double money,string password){
                 Member *customer = list_member->getmember(password);
                 //cout <<"2 "<< password << endl;
                 //list_member->printlist();
                 list_member->Loaddata();
                 if(customer!=NULL){
                      customer->Topupmoney(money);
                      ShowRemainingAmount(password);
                      list_member->Loaddata();
                 }else{
                    cout << "Error" << endl;
                  }
            }
        void ShowRemainingAmount(string password){
            Member *customer = list_member->getmember(password);
            if(customer!=NULL){
                cout << "Remaining Amount : " << customer->getMoney();
                cout << "\n=====================================================" << endl;   
            }else{
                cout << "Error Information!!" << endl;
            }
        }
 
};