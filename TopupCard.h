//62160157 Preechaya Choosrithong
#include"include.h"

class TopupCardController{
        private:
            Member UserMember;
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

            void TopupMoney(double money){

            }


};