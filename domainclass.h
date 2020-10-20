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
        string getpasswordcard(){
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
        Member(string user_name,string lastname,string tel,string passwordcard){
            Firstname = user_name;
            Lastname = lastname;
            Tel = tel;
            member_card.PasswordCard(passwordcard);  
            link = NULL;
            member_card.GenerateExpire();  
        }
        void Setmember(string user_name,string lastname,string tel,string passwordcard){
          //set up member
            Firstname = user_name;
            Lastname = lastname;
            Tel = tel;
            member_card.PasswordCard(passwordcard);
            member_card.GenerateExpire();  
        }//set up member
        string getname(){
          return Firstname;
        }
         string getlastname(){
          return Lastname;
        }
         string gettel(){
          return Tel;
        }
        string getpasswordcard(){
          return member_card.getpasswordcard();
        }
        string getExpire(){
          return member_card.getDayExpire();
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
            Member *new_member = new Member(newmember.getname(),newmember.getlastname(),newmember.gettel(),newmember.getpasswordcard());
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
                    if(cur->getname()==name){
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
                       file<< cur->getname() <<","<<cur->getlastname()<< "," << cur->gettel() << "," 
                       << cur->getpasswordcard() << "," << endl;   
                        cur=cur->link;
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
