#include"Renewcard.h"
#include"station.h"
#include"Ui.h"
#include<conio.h>
using namespace std;
 /*created by weradet nopsombun 62160110 2/10/63
   Class UI 
   function main 
 */  

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

                 }catch(int menu){
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
                       }//Try
                       catch(string str){
                            cout << str << endl;  
                            cin.clear(); 
                            cin.ignore(100, '\n'); 
                       }//catch
                       obj_ui.CheckMenuAdmin(menu_admin);
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