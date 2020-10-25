 #include "Renewcard.h"
RenewController::RenewController(){
  head = NULL;
  tail = NULL;
}
void RenewController::PrintRenewMenu(){
  cout << "\n" << right << setw(88) << "********************************************" << endl;
  cout << right << setw(88) << "*         1.Renew Member Card              *" << endl;
  cout << right << setw(88) << "*         2.Back To Menu Customer          *" << endl;
  cout << right << setw(88) << "********************************************" << endl;
  cout << right << setw(75) << "Please Input 1 Choice : ";
}
void RenewController::Findmember(string password){
  Member *cur = head;
  while(cur != NULL){
    if(cur->getPassword()==password){
      cout << right << setw(91) << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
      cout << right << setw(65) << "    Name Customer : " << cur->getFirstname() << " " << cur->getLastname() << endl;
      cur->member_card.renewcard();
      cout << right << setw(62) << "    New Expire : " << cur->getExpire() << endl;
      cout << right << setw(91) << "- - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
      break;
    }
    cur = cur->link;
  }
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
void RenewController::savedata(){
  Member *cur = head;
  ofstream file("member.txt",ios::out);
  if(file.is_open()){
    while (cur != NULL){
      file << cur->getFirstname() << ","<<cur->getLastname() << "," << cur->getTel() << "," 
           << cur->getPassword() << ","<< cur->getExpire() << "," << cur->getMoney() << endl;   
      cur = cur->link;
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
bool RenewController::CheckMember(string password){
         Member *cur = head;
         while(cur!=NULL){
              if(cur->getPassword()==password){
                   return true;
              }
              cur=cur->link;
         }
        return false;
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
    cout << right << setw(90) << "File Error!!" << endl;
  }
  data.close();
}