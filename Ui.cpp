#include"Ui.h"
       UI::UI(){
            Renew_obj = new RenewController;
            Regis_obj = new RegisterController;
     //       a = new Buy_ticket_controller;
          station_obj = new StationController;
      //    topupcard = new TopupCardController;
       }
       void UI::PrintCustomer(){
            //print customer menu
            system ("cls");
            cout << "************** Electic Train **************" << endl;
            cout << "*  1. Find cycle Time                     *" << endl; 
            cout << "*  2. Buy Train Ticket                    *" << endl;
            cout << "*  3. Have a member                       *" << endl;
            cout << "*  4. Back to Main menu                   *" << endl;
            cout << "*******************************************" << endl;
            cout << "Please Choose 1 Choice (1-4) : ";
       }//printcustomer menu
       void UI::PrintAdmin(){
           //print employee menu
           //print interface
            system ("cls");
            cout << "************** Electic Train **************" << endl;
            cout << "*  1. Find cycle Time                     *" << endl; 
            cout << "*  2. Buy Train Ticket                    *" << endl;
            cout << "*  3. Register Member                     *" << endl;
            cout << "*  4. Renew Member Card                   *" << endl;
            cout << "*  5. Add Station                         *" << endl;
            cout << "*  6. Fix Station                         *" << endl;
            cout << "*  7. Back to Main menu                   *" << endl;
            cout << "*******************************************" << endl;
            cout << "Please Choose 1 Choice (1-7) : ";
       } // print Admin

       void UI::PrintFirstMenu(){
        //print the first menu
        cout << "************* Personal **************" << endl;
        cout << "*  1.Customer                       *" << endl;
        cout << "*  2.Admin                          *" << endl;
        cout << "*  3.Out                            *" << endl;
        cout << "*************************************" << endl;
        cout << "Please Choose 1 Choice (1-3) : ";
        }
        void UI::ChooseFixMenu(string id,int menu){
            station_obj->ChooseFixMenu(id,menu);
        }
        void UI::ShowFixMenuStation(){
            station_obj->ShowFixMenuStation();
        }
        void UI::ShowAllStation(){
            station_obj->ShowAllStation();
        }
        void UI::InputPersonalInformation(string firstname,string lastname,string tel,string password){
            Regis_obj->SetMemberInformation(firstname,lastname,tel,password);   
        }//inputpersonal
        void UI::ShowExprirationDate(string name){
            Regis_obj->ShowExpireCard(name);
        }
        void UI::ShowInformation(string name){
            Regis_obj->ShowUserInformation(name);
        }
       /* void printfile(){
             a->Departure_Staion("Departure");
        }*/
        void UI::InputMoney(double money,string pass){
            Regis_obj->TopupMoney(money,pass);
            //Regis_obj->list_member->printlist();
        }
        void UI::savefile(){
            Regis_obj->list_member->savedata();
        }
        void UI::loadfile(){
            Regis_obj->list_member->Loaddata();
        }
