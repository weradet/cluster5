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
        string Name,Lastname,Tel;
        MemberCard member_card; 
        /*data is name of member lastname 
        Telephone number 
        Thai Id Card */ 
      public: 
      Member *next;
      void Setmember(string user_ame,string lastname,string tel,string id_card){
        //set up member
          Name = user_ame;
          Lastname = lastname;
          Tel = tel;
           member_card.SetMemberCard(id_card);  
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
               tail->next = new_member;
               tail = new_member;
               } 
             }
};