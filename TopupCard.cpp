#include"TopupCard.h"
TopupCardController::TopupCardController(){
             //list_member=new ListMember;
             head = NULL;
             tail = NULL;
             Loaddata();
}
void TopupCardController::ShowMenuTopupCard(){
   
            cout << "=============== TOPUP ==============="<< endl;
            cout << "1. Topup" << endl;
            cout << "2. Show balance" << endl;
            cout << "3. Back to menu" << endl;
            cout << "====================================="<< endl;
            cout << "" << endl;
                
}//void showMenu

void TopupCardController::CheckMember(string Pass_Card){

}//voidCheck

void TopupCardController::ShowMemberInformation(){

}//show InforMember

void TopupCardController::TopupMoney(double money,string password){
    Member *cur = head;
    while(cur!=NULL){
        if(cur->getPassword()==password){
            cur->Topupmoney(money);
            ShowRemainingAmount(password);
            savedata();
             break; 
        }
         cur = cur->link;
    }
}//void topupMoney

void TopupCardController::ShowRemainingAmount(string password){
      Member *cur = head;
    while(cur!=NULL){
        if(cur->getPassword()==password){
             cout << "Remaining Amount : " << cur->getMoney();
             cout << "\n=====================================================" << endl;  
             break; 
        }
         cur = cur->link;
    }
}//void showamoung

void TopupCardController::SetMemberIndata(string firstname,string lastname,string tel,string password,string expire,string money){
             Member *new_member = new Member(firstname,lastname,tel,password,expire,money);
                 if(head == NULL){
                    head = new_member;
                    tail = new_member; 
                  }else{
                   tail->link = new_member;
                   tail = new_member;
                }  
        }

void TopupCardController:: savedata(){
          Member *cur = head;
          ofstream file("member.txt",ios::out);
          if(file.is_open()){
            while (cur!=NULL){ 
              file<< cur->getFirstname() <<","<<cur->getLastname()<< "," << cur->getTel() << "," 
              << cur->getPassword() << ","<< cur->getExpire() << "," << cur->getMoney()<< endl;   
              cur=cur->link;
            }//while
          }//if
        }
 
void TopupCardController::Loaddata(){
          string line,firstname,lastname,tel,password,expire,money;
          ifstream data("member.txt",ios::in);
          if(data.is_open()){
            while(getline(data,line)){ 
              firstname = line.substr(0,line.find(','));
                          line.erase(0,line.find(',')+1); 
              lastname = line.substr(0,line.find(','));
                         line.erase(0,line.find(',')+1); 
              tel = line.substr(0,line.find(','));
                    line.erase(0,line.find(',')+1); 
              password = line.substr(0,line.find(','));
                         line.erase(0,line.find(',')+1); 
              expire = line.substr(0,line.find(','));
                       line.erase(0,line.find(',')+1); 
              money = line.substr(0,line.find(','));
                      line.erase(0,line.find(',')+1); 
            SetMemberIndata(firstname,lastname,tel,password,expire,money);
            }//while
          }else{
            cout << "File Error!!" << endl;
          }
          data.close();
        }