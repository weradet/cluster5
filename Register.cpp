  #include"Register.h"
  RegisterController ::RegisterController(){
            //list_member = new ListMember;
            head = NULL;
            tail=NULL;
            Loaddata();
        } 
        RegisterController::~RegisterController(){
        }//destructer
        void RegisterController :: SetMemberInformation(string f,string l,string t,string pw){
            //UserMember
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

        void RegisterController:: ShowUserInformation(string name,string pass){
            Member *customer = head;
            while(customer != NULL){
                 if(customer->getFirstname()==name&&customer->getPassword()==pass){
                system ("cls");
                cout << "============== Customer Information ==============" << endl;
                cout << "Firstname : " << customer->getFirstname() << endl;
                cout << "Lastname : " << customer->getLastname() << endl;
                cout << "Tel. : " << customer->getTel() << endl;
                //cout << "Password : " << customer->getPassword() << endl;
              }
              customer = customer->link;
            }
              
        }
        void RegisterController:: ShowExpireCard(string name,string pass){
            Member *customer = head;
            while(customer != NULL){
              if(customer->getFirstname()==name&&customer->getPassword()==pass){
                    cout << "ExpireCard : " << customer->getExpire() << endl;     
              }
              customer = customer->link;
            }
        }
        void RegisterController::SetMemberIndata(string firstname,string lastname,string tel,string password,string expire,string money){
             Member *new_member = new Member(firstname,lastname,tel,password,expire,money);
                 if(head == NULL){
                    head = new_member;
                    tail = new_member; 
                  }else{
                   tail->link = new_member;
                   tail = new_member;
                }  
        }
         void RegisterController::savedata(){
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

        void RegisterController::Loaddata(){
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
        
        void RegisterController::Showallmember(){
                   Member *cur = head;
                   while(cur != NULL){
                         cout << cur->getFirstname() << " " << cur->getLastname() 
                         << " " << cur->getMoney() << " " << cur->getPassword() << endl;
                         cur = cur->link; 
                   }
        } 