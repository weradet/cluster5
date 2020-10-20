#include"include.h"
#include"Ui.h"
//using namespace std;
 /*created by weradet nopsombun 62160110 2/10/63
   function main 
 */  
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
 int main(){
     /* In the main program 
        Actor Admin Customer
     */   
     int Menu;
     UI obj_ui;
     string str_error = "404 Not found! Your Input Incorrect ! Please Try Again";
    do{
        // loop for all Program
      try{ 
       obj_ui.PrintFirstMenu(); cin >> Menu; // input 1 
          
          if(!cin){
              throw str_error; // Throw Error
            } // if Not Input
          else if(Menu == 1){
              int menu_customer;
              do{
                  obj_ui.PrintCustomer();
                 try{ 
                     //user input
                   cin >> menu_customer;
                      if(!cin){
                          throw menu_customer;
                        } // if
                      /* Customer have a member Card
                      */  
                      else if(menu_customer==3){
                          string pass_card;
                          //do{
                             
                          //}while();
                      } //else if
                    }//try
                    catch(int menu){
                      cin.clear(); 
                      cin.ignore(100, '\n'); 
                  }
                }while(menu_customer!=4);   
          }// This Customer  
          else if(Menu==2){
              //Menu Admin 
            string str_user_name;  // username
            string str_password=""; //pass
            char star;
               cout << "Username : "; cin >> str_user_name;
               cout << "Password : ";  cin >> str_password;
               if(isloggin(str_user_name,str_password)){
                      int menu_admin; //set varible menu admin
                   do{
                       //Module Admin 
                       cout << endl;
                       obj_ui.PrintAdmin();
                      try{ 
                       cin >> menu_admin; //Input 2
                          if(!cin){
                              throw str_error;
                             } //if check exception
                          else if(menu_admin == 1){

                          }//find cycle time
                          else if(menu_admin == 2){

                          }//Buy Train Ticket
                          else if(menu_admin == 3){
                               //ประกาศตัวแปร ข้อมูลของลูกค้าในบัตร
                               string user_name,user_lastname,user_tel,password_card;
                               cout << "==========Register==========" << endl;
                               cout << "Please Ener the Customer Name : ";
                                 cin >> user_name;
                               cout << "Please Ener the Customer LastName : ";
                                 cin >> user_lastname;
                               cout << "Please Ener the Customer Tel. : ";
                                  cin >> user_tel;    
                               cout << "====Please Enter Password Card====" << endl;
                               cout << "Password Card : "; cin >> password_card;
                               obj_ui.InputPersonalInformation(user_name,user_lastname,user_tel,password_card);
                               obj_ui.showInformation(user_name);
                               obj_ui.ShowExprirationDate(user_name);
                               //obj_ui.ShowExprirationDate();    
                          }//Register Member
                          else if(menu_admin == 4){
                              //obj_ui.CheckMenuAdmin(menu_admin);
                          }//Renew Member Card
                          else if(menu_admin == 5){

                          }//Add Station
                          else if(menu_admin == 6){

                          }//Fix Station
                          else if(menu_admin == 7){

                          }// back menu
                       }//Try
                       catch(string str){
                            cout << str << endl;  
                            cin.clear(); 
                            cin.ignore(100, '\n'); 
                       }//catch  
                   }while( menu_admin !=7);      
               }  //if Correct loggin
               else{
                   cout << "\nCannot Loggin" << endl;
               }// Fail
          } // if Menu =2 
         } // Try Exception  
      catch(string str){
          cout << str << endl;  
          cin.clear(); 
          cin.ignore(100, '\n'); 
      }  // catch Error   
    }while(Menu!=3);
     return 0;
}//main
}