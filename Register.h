// 62160085 Natsuda Kuhasak //
// 62160334 Mattaneeya Phosrisuk //
#include "include.h"
#include"domainclass.h"
class RegisterController{
    public:
        Member UserMember;
        MemberCard PassMember;
        ListMember *list_member;
        RegisterController(); 
        ~RegisterController();
        void SetMemberInformation(string f,string l,string t,string pw);
        void ShowUserInformation(string name);
        void ShowExpireCard(string name);
        void TopupMoney(double money,string password);
        void ShowRemainingAmount(string password);
};

/*class TopupCardController{
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
 
};*/