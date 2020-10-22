#include"Register.h"
  RegisterController::RegisterController(){
    head = NULL;
    tail = NULL;
  }
  RegisterController::~RegisterController(){
  }//destructer
  void RegisterController::SetMemberInformation(string f,string l,string t,string pw){
    Member *new_member = new Member;
    new_member->setMember(f,l,t,pw);  
    if(head == NULL){
      head = new_member;
      tail = new_member; 
    }else{
      tail->link = new_member;
      tail = new_member;
    }       
  }
  void RegisterController::ShowUserInformation(string firstname,string password){
    Member *customer = head;
    while(customer != NULL){
      if(customer->getFirstname() == firstname && customer->getPassword() == password){
        system ("cls");
        cout << "============== Customer Information ==============" << endl;
        cout << "Name Customer : " << customer->getFirstname() << " " << customer->getLastname() << endl;
        cout << "Tel. : " << customer->getTel() << endl;
      }
      customer = customer->link;
    }
  }//Show User Information
  void RegisterController::ShowExpireCard(string firstname,string password){
    Member *customer = head;
    while(customer != NULL){
      if(customer->getFirstname()==firstname && customer->getPassword()==password){
        cout << "ExpireCard : " << customer->getExpire() << endl;     
      }
      customer = customer->link;
    }
  }//Show exp. Card
  void RegisterController::SetMemberInData(string firstname,string lastname,string tel,string password,string expire,string money){
    Member *new_member = new Member(firstname,lastname,tel,password,expire,money);
    if(head == NULL){
      head = new_member;
      tail = new_member; 
    }else{
      tail->link = new_member;
      tail = new_member;
    }  
  }
  void RegisterController::InputMoneyCard(double numMoney,string password){
    Member *cur = head;
    while(cur != NULL){
      if(cur->getPassword() == password){
        cur->Topupmoney(numMoney);
        ShowRemainingAmount(cur);
        break; 
      }
      cur = cur->link;
    }//while
  }//Input Money Card
  void RegisterController::LoadData(){
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
        SetMemberInData(firstname,lastname,tel,password,expire,money);
      }//while
    }else{
      cout << "File Error!!" << endl;
    }
      data.close();
  }
  void RegisterController::SaveData(){
    Member *cur = head;
    ofstream file("member.txt",ios::app);
    if(file.is_open()){
      while(cur != NULL){ 
        file << cur->getFirstname() << "," << cur->getLastname() << "," << cur->getTel() << "," 
            << cur->getPassword() << "," << cur->getExpire() << "," << cur->getMoney() << endl;   
        cur = cur->link;
      }//while
    }
  }
  void RegisterController::ShowRemainingAmount(Member *cur){
    cout << "Remaining Amount : " << cur->getMoney();
    cout << "\n=====================================================" << endl;  
  }//Show Remaining Amount
  void RegisterController::ShowMember(){
    Member *cur = head;
    while(cur != NULL){
      cout << cur->getFirstname() << " " << cur->getLastname() 
           << " " << cur->getMoney() << " " << cur->getPassword() << endl;
      cur = cur->link; 
    }
  }//Show Member 