  #include"Register.h"
  RegisterController ::RegisterController(){
            list_member = new ListMember;
        } 
        RegisterController::~RegisterController(){
        }//destructer
        void RegisterController :: SetMemberInformation(string f,string l,string t,string pw){
            //UserMember
            UserMember.setMember(f,l,t,pw);  
            list_member->Addmember(UserMember);   
            //list_member->savedata();       
        }
        void RegisterController:: ShowUserInformation(string name){
            Member *customer = list_member->searchMember(name);
            if(customer != NULL){
                system ("cls");
                cout << "============== Customer Information ==============" << endl;
                cout << "Firstname : " << customer->getFirstname() << endl;
                cout << "Lastname : " << customer->getLastname() << endl;
                cout << "Tel. : " << customer->getTel() << endl;
                //cout << "Password : " << customer->getPassword() << endl;
            }else{
                cout << "Information Error!!" << endl;
            }    
        }
        void RegisterController:: ShowExpireCard(string name){
            Member *customer = list_member->searchMember(name);
            //list_member->printlist();
            if(customer != NULL){
                cout << "ExpireCard : " << customer->getExpire() << endl; 
            }else{
                cout << "Information Error!!" << endl;
            }
        }
        void RegisterController:: TopupMoney(double money,string password){
            Member *customer = list_member->getMember(password);
            //cout <<"2 "<< password << endl;
            //list_member->printlist();
            //list_member->Loaddata();
            if(customer != NULL){
                customer->Topupmoney(money);
                ShowRemainingAmount(password);
                // list_member->Loaddata();
            }else{
                cout << "Information Error!!" << endl;
            }
        } 
        void RegisterController:: ShowRemainingAmount(string password){
            Member *customer = list_member->getMember(password);
            if(customer != NULL){
                cout << "Remaining Amount : " << customer->getMoney();
                cout << "\n==================================================" << endl;   
            }else{
                cout << "Information Error!!" << endl;
            }
        }