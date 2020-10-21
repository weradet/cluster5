#include"TopupCard.h"
void TopupCardController::ShowMenuTopupCard(){
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
            void TopupCardController::CheckMember(string Pass_Card){
                
                
            }

            void TopupCardController::ShowMemberInformation(){

            }

            void TopupCardController::TopupMoney(double money,string password){
                 Member *customer = list_member->getMember(password);
                 if(customer!=NULL){
                      customer->Topupmoney(money);
                      ShowRemainingAmount(password);
                 }else{
                    cout << "Error Information!!" << endl;
                  }
            }
        void TopupCardController::ShowRemainingAmount(string password){
            Member *customer = list_member->getMember(password);
            if(customer!=NULL){
                cout << "Remaining Amount : " << customer->getMoney();
                cout << "\n=====================================================" << endl;   
            }else{
                cout << "Error Information!!" << endl;
            }
        }
 