 #include "Renewcard.h"

   RenewController::RenewController(){
    head = NULL;
    tail = NULL;
   }

   void RenewController::PrintRenewMenu(){
        //print interface ewnew card menu
        system("cls");
        cout << "\t\t*********** Renew Card **********" << endl;
        cout << "\t\t*\t1.Renew Card\t\t*" << endl;
        cout << "\t\t*\t2. Back \t\t*" << endl;
        cout << "\t\t*********************************" << endl;
    }
   void RenewController::Findmember(string password){
          Member *cur = head;
          while(cur != NULL){
             if(cur->getPassword()==password){
                //return cur;
                   cout << cur->getFirstname() << " " << cur->getLastname() << endl;
                  // cur->getmembercard().GenerateExpire();
                    cur->member_card.renewcard();
                   cout << "NEW EXPIRE : " << cur->getExpire() << endl;
                   break;
             }
              cur = cur->link;
          }
          //return NULL;
    }
    void RenewController::SetMemberIndata(string firstname,string lastname,string tel,string password,string expire,string money){
             Member *new_member = new Member(firstname,lastname,tel,password,expire,money);
                 if(head == NULL){
                    head = new_member;
                    tail = new_member; 
                  }else{
                   tail->link = new_member;
                   tail = new_member;
                }  
        }

   void RenewController:: savedata(){
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
  
  void RenewController::clear(){
    Member *temp = head;
      while(head!=NULL){
        temp = head;
        head = head->link;
      delete temp;
      }
    }
   void RenewController::Loaddata(){
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