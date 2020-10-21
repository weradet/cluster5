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
                
}//void showMenu

void TopupCardController::CheckMember(string Pass_Card){

}//voidCheck

void TopupCardController::ShowMemberInformation(){

}//show InforMember

void TopupCardController::TopupMoney(double money,string password){
                 Member *customer = list_member->getmember(password);
                 if(customer!=NULL){
                      customer->Topupmoney(money);
                      ShowRemainingAmount(password);
                 }else{
                    cout << "Error Information!!" << endl;
                  }
}//void topupMoney

void TopupCardController::ShowRemainingAmount(string password){
    Member *customer = list_member->getmember(password);
    if(customer!=NULL){
        cout << "Remaining Amount : " << customer->getMoney();
        cout << "\n=====================================================" << endl;   
    }else{
        cout << "Error Information!!" << endl;
    }
}//void showamoung
 