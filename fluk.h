#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;
class Member{
    //class member 
      private:
        string name,lastname,Tel,IdCard;
        /*data is name of member lastname 
        Telephone number 
        Thai Id Card */ 
      public: 
};
class MemberCard{
       private:
         double Money;
         string DayExpire;  
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
    void PrintInfo(){
        
    }
};
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