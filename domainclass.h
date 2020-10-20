#include"include.h"
class MemberCard{
      private:
        string IdCard;
        double Money;
        string DayExpire;  
      public:
        MemberCard(){
        }
        void SetMemberCard(string id_card){
            IdCard = id_card; 
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
        void Setmember(string user_name,string lastname,string tel,string id_card){
          //set up member
            Firstname = user_name;
            Lastname = lastname;
            Tel = tel;
            //member_card.SetMemberCard(id_card);  
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
            Member *new_member = new Member;
           
            if(head == NULL){
              head = new_member;
              tail = new_member; 
            }else{
              tail->link = new_member;
              tail = new_member;
            } 
        }
};
