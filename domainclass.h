#include"include.h"
class MemberCard{
      private:
        string Password;
        double Money;
        string DayExpire;  
      public:
        MemberCard(){
          Money = 0;
        }
        void PasswordCard(string pass){
          Password = pass; 
        }    
        string getPassword(){
          return Password;
        }
        string getDayExpire(){
          return DayExpire;
        }
        void GenerateExpire(){
          time_t now = time(0);
          tm *ltm = localtime(&now);
          stringstream ss;
          ss <<  1901+ltm->tm_year << "-" << 1+ltm->tm_mon << "-" << ltm->tm_mday;
          string date = ss.str();
          DayExpire = date;
        }
        double getMoney(){
          return Money;
        }
        void TopupMoney(double money){
            Money += money;
        }
        void setMoney(double money){
             Money = money;
        }
        void PayTicket(double money){
            Money -= money;
        }
        void setdateExpire(string dayexpire){
              DayExpire = dayexpire;
        }
        
};

class Member{
    //class member 
      private:
        string Firstname,Lastname,Tel;
        MemberCard member_card; 
        /*data is name of member lastname 
        Telephone number 
        Thai Id Card */ 
      public: 
        Member *link;
        Member(){
        link = NULL;
        }
        Member(string firstname,string lastname,string tel,string password,string dateexpire,string money){
            Firstname = firstname;
            Lastname = lastname;
            Tel = tel;
            member_card.PasswordCard(password);
            stringstream ss;
            ss << money;
            double Money;
            ss >> Money;
            member_card.setdateExpire(dateexpire);
            member_card.setMoney(Money);
            link = NULL;
        }
        Member(string firstname,string lastname,string tel,string password){
            Firstname = firstname;
            Lastname = lastname;
            Tel = tel;
            member_card.PasswordCard(password);  
            link = NULL;
            member_card.GenerateExpire();  
        }
        void Setmember(string firstname,string lastname,string tel,string password){
          //set up member
            Firstname = firstname;
            Lastname = lastname;
            Tel = tel;
            member_card.PasswordCard(password);
            member_card.GenerateExpire();  
        }//set up member
        string getFirstname(){
          return Firstname;
        }
         string getLastname(){
          return Lastname;
        }
         string getTel(){
          return Tel;
        }
        string getPassword(){
          return member_card.getPassword();
        }
        string getExpire(){
          return member_card.getDayExpire();
        }
        double getMoney(){
          return member_card.getMoney();
        }
        void Topupmoney(double money){
            member_card.TopupMoney(money);
        }
};

class ListMember{
//Linked list Member 
      private:
        Member *head;
        Member *tail;
      public:
        ListMember(){
            head = NULL;
            tail = NULL;
            Loaddata();
        }
        ~ListMember(){
          //savedata();
        }
        void printlist(){
          Member *cur = head;
          while(cur!=NULL){
                cout << cur->getFirstname() << " " << cur->getLastname() << endl;
                cur = cur->link;
          }
        }
        void Addmember(Member newmember){
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
        void Addmember(string name,string lastname,string tel,string pass,string expire,string money){
           //Add data to the linklist
            Member *new_member = new Member(name,lastname,tel,pass,expire,money);
            if(head == NULL){
              head = new_member;
              tail = new_member; 
            }else{
              tail->link = new_member;
              tail = new_member;
            } 
            //savedata();
        }
        Member *searchMember(string name){
                Member *cur = head;
                while(cur!=NULL){
                    if(cur->getFirstname()==name){
                        return cur;
                        break;
                    }
                    cur = cur->link;
                }
                return NULL;
        }
        Member *getmember(string password_card){
                Member *cur = head;
                while(cur != NULL){
                  //cout << cur->getPassword() << endl;
                   if(cur->getPassword()==password_card){
                      return cur;  
                      break;
                   }
                   cur = cur->link;
                }   
                return NULL;
        }
        void savedata(){
              Member *cur = head;
              ofstream file("member.txt",ios::out);
              if(file.is_open()){
                    while (cur!=NULL){ 
                       file<< cur->getFirstname() <<","<<cur->getLastname()<< "," << cur->getTel() << "," 
                       << cur->getPassword() << ","<< cur->getExpire() << "," << cur->getMoney()<< endl;   
                        cur=cur->link;
                   }
              }
        }
         void Loaddata(){
            //à¹‚à¸«à¸¥à¸”à¸‚à¹‰à¸­à¸¡à¸¹à¸¥à¸ˆà¸²à¸à¹„à¸Ÿà¸¥à¹Œà¹€à¸‚à¹‰à¸²à¸ªà¸¹à¹ˆLinkedlist
           string line,user_name,lastname,tel,pass,dateexpire,money;
           ifstream data("member.txt",ios::in);
           if(data.is_open()){
                  while(getline(data,line)){ 
                    user_name = line.substr(0,line.find(','));
                               line.erase(0,line.find(',')+1); 
                    lastname = line.substr(0,line.find(','));
                               line.erase(0,line.find(',')+1); 
                       tel =   line.substr(0,line.find(','));
                               line.erase(0,line.find(',')+1); 
                      pass = line.substr(0,line.find(','));
                               line.erase(0,line.find(',')+1); 
                      dateexpire = line.substr(0,line.find(','));
                               line.erase(0,line.find(',')+1); 
                      money = line.substr(0,line.find(','));
                               line.erase(0,line.find(',')+1); 
                  Addmember(user_name,lastname,tel,pass,dateexpire,money);
            }//while
          }else{
             cout << "Error File!!" << endl;
           }
         } 
         /*void savefile(){
                   NodeCheckin *cur = head;
                  //string student_code,numfac,date,timein,timeout;
                  ofstream file("checking.dat",ios::out);
                  if(file.is_open()){
                    while (cur!=NULL){ 
                       file<< cur->student_code <<","<<cur->numfac<< "," << cur->date << "," 
                       << cur->timein << "," << cur->timeout << endl;   
                        cur=cur->next;
                   }
               }
            } */
};
