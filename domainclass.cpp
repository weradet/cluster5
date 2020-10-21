#include"include.h"
#include"domainclass.h"
        MemberCard::MemberCard(){
          Money = 0;
        }
        void MemberCard::PasswordCard(string pass){
          Password = pass; 
        }    
        string MemberCard::getPassword(){
          return Password;
        }
        string MemberCard::getDayExpire(){
          return DayExpire;
        }
        void MemberCard::GenerateExpire(){
          time_t now = time(0);
          tm *ltm = localtime(&now);
          stringstream ss;
          ss <<  1901+ltm->tm_year << "-" << 1+ltm->tm_mon << "-" << ltm->tm_mday;
          string date = ss.str();
          DayExpire = date;
        }
        double MemberCard::getMoney(){
          return Money;
        }
        void MemberCard::TopupMoney(double money){
          Money += money;
        }
        void MemberCard::setMoney(double money){
          Money = money;
        }
        void MemberCard::PayTicket(double money){
          Money -= money;
        }
        void MemberCard::setDateExpire(string dayexpire){
          DayExpire = dayexpire;
        }
     
     
        Member::Member(){
        link = NULL;
        }
        Member::Member(string firstname,string lastname,string tel,string password,string expire,string money){
          Firstname = firstname;
          Lastname = lastname;
          Tel = tel;
          member_card.PasswordCard(password);
          stringstream ss;
          ss << money;
          double Money;
          ss >> Money;
          member_card.setDateExpire(expire);
          member_card.setMoney(Money);
          link = NULL;
        }
        Member::Member(string firstname,string lastname,string tel,string password){
          Firstname = firstname;
          Lastname = lastname;
          Tel = tel;
          member_card.PasswordCard(password); 
          member_card.GenerateExpire(); 
          link = NULL; 
        }
        void Member::setMember(string firstname,string lastname,string tel,string password){
          Firstname = firstname;
          Lastname = lastname;
          Tel = tel;
          member_card.PasswordCard(password);
          member_card.GenerateExpire();  
        }//set up member
        string Member::getFirstname(){
          return Firstname;
        }
         string Member::getLastname(){
          return Lastname;
        }
         string Member::getTel(){
          return Tel;
        }
        string Member::getPassword(){
          return member_card.getPassword();
        }
        string Member::getExpire(){
          return member_card.getDayExpire();
        }
        double Member::getMoney(){
          return member_card.getMoney();
        }
        void Member::Topupmoney(double money){
          member_card.TopupMoney(money);
        }

        ListMember::ListMember(){
          head = NULL;
          tail = NULL;
          Loaddata();
        }
         ListMember::~ListMember(){
        }//destructor
        void ListMember::Printlist(){
          Member *cur = head;
          while(cur!=NULL){
                cout << cur->getFirstname() << " " << cur->getLastname() << endl;
                cur = cur->link;
          }
        }
        void ListMember::Addmember(Member newmember){
          //Add data to the linklist
          Member *new_member = new Member(newmember.getFirstname(),newmember.getLastname(),newmember.getTel(),newmember.getPassword());
          if(head == NULL){
            head = new_member;
            tail = new_member; 
          }else{
            tail->link = new_member;
            tail = new_member;
          } 
        }
        void ListMember::Addmember(string firstname,string lastname,string tel,string password,string expire,string money){
          //Add data to the linklist
          Member *new_member = new Member(firstname,lastname,tel,password,expire,money);
          if(head == NULL){
            head = new_member;
            tail = new_member; 
          }else{
            tail->link = new_member;
            tail = new_member;
          } 
          //savedata();
        }
        Member *ListMember::searchMember(string name){
          Member *cur = head;
          while(cur != NULL){
            if(cur->getFirstname() == name){
              return cur;
              break;
            }
          cur = cur->link;
          }//while
          return NULL;
        }
        Member *ListMember::getMember(string password_card){
          Member *cur = head;
          while(cur != NULL){
          //cout << cur->getPassword() << endl;
            if(cur->getPassword()==password_card){
              return cur;  
              break;
            }
          cur = cur->link;
          }//while   
          return NULL;
        }
        void ListMember::savedata(){
          Member *cur = head;
          ofstream file("member.txt",ios::out);
          if(file.is_open()){
            while (cur!=NULL){ 
              file<< cur->getFirstname() <<","<<cur->getLastname()<< "," << cur->getTel() << "," 
              << cur->getPassword() << ","<< cur->getExpire() << "," << cur->getMoney()<< endl;   
              cur=cur->link;
            }//while
          }
        }
        void ListMember::Loaddata(){
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
            Addmember(firstname,lastname,tel,password,expire,money);
            }//while
          }else{
            cout << "File Error!!" << endl;
          }
        } 
