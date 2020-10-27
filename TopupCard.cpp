#include"TopupCard.h"
TopupCardController::TopupCardController(){
    //list_member=new ListMember;
    head = NULL;
    tail = NULL;
    //Loaddata();
}
void TopupCardController::ShowMenuTopupCard(){
    system("cls");
    cout << endl;
    cout << right << setw(80) << "================== TOPUP =================="<< endl;
    cout << right << setw(80) << "|  1. Topup                               |" << endl;
    cout << right << setw(80) << "|  2. Show balance                        |" << endl;
    cout << right << setw(80) << "|  3. Back to menu                        |" << endl;
    cout << right << setw(80) << "==========================================="<< endl;
    cout << right << setw(65) << "Please Enter Choice: ";
                
}//void showMenu

Member* TopupCardController::CheckMember(string Pass_Card){
    Member *cur = head;
         while(cur!=NULL){
             if(cur->getPassword()==Pass_Card){
                  return cur;
             }
             cur = cur->link;
         }
         return NULL;
}//voidCheck

void TopupCardController::ShowMemberInformation(Member *cur){
    cout << cur->getFirstname() << " " << cur->getLastname() ;
}//show InforMember

void TopupCardController::TopupMoney(double money,string password){
    Member *cur = head;
    while(cur!=NULL){
      if(cur->getPassword()==password){
           if(cur->member_card.CheckMoneyCard(money)){
              cout << endl;
              cout << "\t\t\t\t\t*********************************\n" << endl;
              cout << "\t\t\t\t\t  !!!! Card limit exceeded !!!!\n" << endl;
              cout << "\t\t\t\t\t*********************************" << endl;
           }else{
              cur->Topupmoney(money);
              ShowRemainingAmount(cur);
           }
        //savedata();
        break; 
      }
         cur = cur->link;
    }
}//void topupMoney

void TopupCardController::ShowRemainingAmount(Member *cur){
    cout << right << setw(80) << "============= Remaining amount ============" << endl;
    cout << right << setw(42) << "|    ";
    ShowMemberInformation(cur);
    cout << setw(28) << right  << "|" << endl;
    cout << right << setw(61) << "|    Remaining Amount : " << cur->getMoney() << " " << "Bath\t       |\n";
    cout << right << setw(80) << "===========================================" << endl;  
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
        
void TopupCardController::clear(){
    Member *temp = head;
      while(head!=NULL){
        temp = head;
        head = head->link;
      delete temp;
      }
}