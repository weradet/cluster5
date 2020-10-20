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
        }//member
        Member(string user_ame,string lastname,string tel,string passwordcard){
              
              link = NULL;
        }
        string getname(){
          return Firstname;
        }
         string getlastname(){
          return Lastname;
        }
         string gettel(){
          return Tel;
        }
        void Setmember(string user_ame,string lastname,string tel,string passwordcard){
          //set up member
            Firstname = user_name;
            Lastname = lastname;
            Tel = tel;
            member_card.PasswordCard(passwordcard);  
        }//set up member
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
            Member *new_member = new Member(newmember);
           
            if(head == NULL){
              head = new_member;
              tail = new_member; 
            }else{
              tail->link = new_member;
              tail = new_member;
            } 
        }
};
