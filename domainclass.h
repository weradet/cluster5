#include"include.h"
class MemberCard{
      private:
        string Password;
        double Money;
        string DayExpire;  
      public:
        MemberCard(){
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
        void savedata(){
              Member *cur = head;
              ofstream file("checking.dat",ios::app);
              if(file.is_open()){
                    while (cur!=NULL){ 
                       file<< cur->getFirstname() <<","<<cur->getLastname()<< "," << cur->getTel() << "," 
                       << cur->getPassword() << ","<< cur->getExpire() << "," << cur->getMoney()<< endl;   
                        cur=cur->link;
                   }
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
