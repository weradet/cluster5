#include"include.h"
class UI{
    /*
    class UI 
    any ui in the project
    */
    private:
    RenewControler *Renew_obj;  
    StationController *station_obj;
    public:
       UI(){
           Renew_obj = new RenewControler;
           station_obj = new StationController;
       }
       void PrintCustomer(){
           //print customer menu
          cout << "*****Electic Train*****" << endl;
          cout << "1. Find cycle Time" << endl; 
          cout << "2. Buy Train Ticket" << endl;
          cout << "3. Have a member" << endl;
          cout << "4. Back to the main menu" << endl;
          cout << "Please Choose 1 Choice(1-4): ";
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
           cout << "6. Fix Station" << endl;
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