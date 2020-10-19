/* Create By Weradet Nopsombun 62160110 
   Use Case - Renew Card
            - Register Member
    *** Add class MemberList
*/ 
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

//Class
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

class RenewControler{
    //Contro Usecase Renew Card
private:
    Member user_member;  
public:
    void PrintRenewMenu(){
        //print interface ewnew card menu
        cout << "****Renew Card****" << endl;
        cout << "1.Renew Card" << endl;
        cout << "2. Back " << endl;
    }//print renewcard
};

// Function
bool isloggin(string user_name,string pass){
    //get parameter username and pass for check 
    // is true return true 
    string line,us,ps;
    int found;
     ifstream  userfile("data.txt",ios::in);
     //openfile datamanager
     if(userfile.is_open()){
          while(getline(userfile,line)){
              //get all line in file
             found = line.find(" "); //find /t
             us = line.substr(0,found);
             ps = line.substr(found+1,string::npos);
               if(us==user_name&&ps==pass){
                   //check username and pass is true
                   return true;
               }
          }
          userfile.close();
     }
     else{
         cout << "Fail to loggin" << endl;
     }
     return false;
}