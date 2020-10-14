#include"fluk.h"
using namespace std;
 //created by weradet nopsombun 62160110 2/10/63
class UI{
    private:
    RenewControler *Renew_obj;  
    public:
       UI(){
           Renew_obj = new RenewControler;
       }
       void PrintCustomer(){
           //print customer menu
            cout << "xxx" << endl;  
       }//printcustomer menu
       void PrintAdmin(){
           //print employee menu
           //print interface
           cout << "*****Electic Train*****" << endl;
           cout << "1. Find cycle Time" << endl; 
           cout << "2. Buy Train Ticket" << endl;
           cout << "3. Register Member" << endl;
           cout << "4. Renew Member Card" << endl;
           cout << "5. Add Station" << endl;
           cout << "6. Manage Station" << endl;
           cout << "7. Back" << endl;
           cout << "Please Choose 1 Choice(1-7): ";

       } // print Admin
       void PrintFirstMenu(){
        //print the first menu
        cout << "1.Customer" << endl;
        cout << "2.Admin" << endl;
        cout << "3.Out" << endl;
        cout << "Please Choose 1 Choice(1-3): ";
        }//print FirstMenu
      void CheckMenuAdmin(int menu){
            //check is menu admin in the method PrintAdmin() in UI class
            if(menu == 4){
            //Renew Card
               cout << "Hello";   
            }//if
        }
};
int main(){
     //mainmenu
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
          if(Menu==2){
              //Menu Admin 
            string str_user_name;  // username
            string str_password; //pass
               cout << "User name : "; cin >> str_user_name;
               cout << "Password : ";  cin >> str_password;
               if(isloggin(str_user_name,str_password)){
                      int menu_admin; //set varible menu admin
                   do{
                       //Module Admin 
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
                   cout << "Cannot Loggin" << endl;
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