//62160157 Preechaya Choosrithong
#include"include.h"
#include"domainclass.h"
class TopupCardController{
        private:
            Member UserMember;
            ListMember *list_member;
        public:

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
                 if(customer!=NULL){
                      customer->Topupmoney(money);
                      ShowRemainingAmount(password);
                 }else{
                    cout << "Error Information!!" << endl;
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