#include "include.h"
#include "Ui.h"
bool Islogin(string name,string password){ 
  string line,Username,Password;
  int found;
  ifstream  userfile("data.txt",ios::in); //openfile datamanager
    if(userfile.is_open()){
      while(getline(userfile,line)){
        found = line.find(" ");
        Username = line.substr(0,found);
        Password = line.substr(found+1,string::npos);
        if(Username == name && Password == password){
          return true;
        }//Check Username and Password is true
      }//while
      userfile.close();
    }else{
      cout << "\t\t\tCannot Login!!" << endl;
    }
    return false;
}//get parameter Username and Password for check Login 
int main(){
  int Menu;
  UI obj_ui;
  string str_error = "404 Not found! Your Input Incorrect. Please Try Again";
  obj_ui.readfile();
  do{
    // loop for all Program
    try{ 
      obj_ui.PrintFirstMenu(); 
      cin >> Menu;
      if(!cin){
        throw str_error; //If not input
      }else if(Menu == 1){
        int menu_customer;
        do{
          obj_ui.PrintCustomer();
          try{ 
            cin >> menu_customer; //User input
            if(!cin){
              throw menu_customer;
            }else if(menu_customer == 3){
              string pass_card;
              int menu_member;
              do{
                cout << "=============== MEMBER ===============" << endl;
                cout << "1. Input The card" << endl;
                cout << "2. Back to menu Customer" << endl;
                cout << "======================================" << endl;
                cout << "Please Enter choice (1-2) : "; cin >> menu_member;
                if(!cin){
                  cin.clear(); 
                  cin.ignore(100,'\n'); 
                }else if(menu_member == 1){
                                 cout << "Please Input Yours Password Card : "; cin >> pass_card;
                                 obj_ui.Clear();
                                 obj_ui.loadtopupfile();
                                 if(obj_ui.checkmember(pass_card)){
                                    int menu_topup;
                                    double money;
                                    obj_ui.PrintCustomer();
                                    do{obj_ui.ShowMenu();
                                    cin >> menu_topup;
                                       if(menu_topup==1){
                                          // obj_ui.loadtopupfile();
                                           cout << "Input money : "; cin >> money;
                                           obj_ui.InputMoney(money,pass_card);
                                           obj_ui.savetopupfile();
                                       }else if(menu_topup==2){
                                           obj_ui.Showmoney(pass_card);
                                       }
                                    }while(menu_topup!=3);
                                 }
                                 else{
                                   cout << "Cannot Find Member Or Password is Incorrect" << endl;
                                 }
                             }

                          }while(menu_member != 2);
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
            string str_password = ""; //pass
           // char star;
               cout << "\t\t************************************" << endl;
               cout << "\t\t\tUsername : "; cin >> str_user_name;
               cout << "\t\t\tPassword : "; cin >> str_password;
               if(Islogin(str_user_name,str_password)){
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
                              obj_ui.View();
                          }//find cycle time
                          else if(menu_admin == 2){

                          }//Buy Train Ticket
                          else if(menu_admin == 3){
                              //ประกาศตัวแปร ข้อมูลของลูกค้าในบัตร
                              string user_firstname,user_lastname,user_tel,password_card;
                              double money;
                              system ("cls");
                              cout << "==================== Register ====================" << endl;
                              cout << "Please Enter the Customer Firstname : ";
                                cin >> user_firstname;
                              cout << "Please Enter the Customer Lastname : ";
                                cin >> user_lastname;
                              cout << "Please Enter the Customer Tel. : ";
                                cin >> user_tel;    
                              cout << "================== Password Card =================" << endl;
                              cout << "Please Enter Password Card : ";
                                cin >> password_card;
                              obj_ui.InputPersonalInformation(user_firstname,user_lastname,user_tel,password_card);
                              obj_ui.ShowInformation(user_firstname,password_card);
                              obj_ui.ShowExprirationDate(user_firstname,password_card); cout << endl;           
                             cout << "================= Topup Money Card ===============" << endl;
                             cout << "Please Enter Money : ";
                                cin >> money;
                              cout << "==================================================" << endl;
                              obj_ui.InputMoneyCard(money,password_card);                                          
                              obj_ui.SaveFile();
                          }//Register Member
                          else if(menu_admin == 4){
                            int menu_renew;
                            do{
                                obj_ui.showmenuRenewCard(); cin >> menu_renew;
                                 if(!cin){
                                    cin.clear(); 
                                    cin.ignore(100, '\n'); 
                                 }else if(menu_renew==1){
                                      string passwordcard;
                                       obj_ui.loaddataRenew();
                                       cout << "Please Input the Password Card : "; cin >> passwordcard; 
                                       obj_ui.EnterCardcode(passwordcard);
                                       obj_ui.SaveDataRenew();
                                 }
                            }while(menu_renew!=2);
                          }//Renew Member Card
                          else if(menu_admin == 5){
                              char choice;
	                          string StationName,StationID,Status;
                            int Cost;
                            cout <<"1.Add destination"<<endl;
                            cout <<"2.Add Departure station,Add station on the way"<<endl;
                            cout <<"3.show "<<endl;
                            cout <<"Enter ==> ";
                            cin >> choice;
                          if(choice == '1'){
                                  cout << "Station ID: ";
                                  cin >> StationID;
                                      while(StationID.length() != 5){
                                          cout << "!!! Warning !!!\n";
                                          cout << "Station ID Not equal to 5 ";
                                          cin >> StationID;
                                      }
                                  cout << "StationName: ";
                                  cin >> StationName;
                          if(obj_ui.checkStationID(StationID)==true && obj_ui.checkStationName(StationName)==true){
                            cout << "The station already exists!!!" << endl;
                          }
                                  cout << "Station Status: ";
                                  cin >> Status;
                                  cout << "Station cost: ";
                                  cin >> Cost;
                              obj_ui.Addstation(StationID,StationName,Status,Cost);
                          }
                          else if(choice == '2'){
                              int index;
                              int size = obj_ui.StationNumber();

                              if(size == 0){
                                  cout << "cannot add station" << endl;
                              }
                              else{
                                int Cost;
                                  cout << "Station ID: ";
                                  cin >> StationID;
                                      while(StationID.length() != 5){
                                          cout << "!!! Warning !!!\n";
                                          cout << "Station ID Not equal to 5 ";
                                          cin >> StationID;
                                      }
                                  cout << "StationName: ";
                                  cin >> StationName;
                          if(obj_ui.checkStationID(StationID)==true && obj_ui.checkStationName(StationName)==true){
                            cout << "The station already exists!!!" << endl;
                          }
                                  cout << "Station Status: ";
                                  cin >> Status;
                                  cout << "Station cost: ";
                                  cin >> Cost;
                                  if(size == 1){
                                      cout << "input position (1): ";
                                      cin >> index;
                                      if(index > size || index < 1){
                                        cout << "cannot add station" << endl;
                                      }
                                      else{
                                          obj_ui.AddStation_ontheway(index,StationID,StationName,Status,Cost);
                                      }
                                  }
                                  else{
                                      cout << "choose position station(1 - " << size << "): ";
                                      cin >> index;

                                      
                                      if(index > size || index < 1){
                                        cout << "cannot add station" << endl;
                            }
                            else{
                              obj_ui.AddStation_ontheway(index,StationID,StationName,Status,Cost);
                            }
                                  }
                              }
                          }
                        else if(choice == '3'){
                              obj_ui.show_station();
                  }
                          }//Add Station
                          else if(menu_admin == 6){
                             // obj_ui.readfile();
                              obj_ui.ShowAllStation();
                              string chooseId;
                              int menu;
                              cout << "Choose Station ID : ";
                              cin >> chooseId;
                              obj_ui.ShowStaiton(chooseId);
                              obj_ui.ShowFixMenuStation();
                              cout << "Choose Fix Menu Station : ";
                              cin >> menu;
                              obj_ui.ChooseFixMenu(chooseId,menu);
                              obj_ui.WriteFixFile();
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
                   cout << "\nCannot Login!!" << endl;
               }// Fail
      }//If Menu = 1 
    }//Try Exception  
      catch(string str){
        cout << str << endl;  
        cin.clear(); 
        cin.ignore(100, '\n'); 
      }//Catch Error   
  }while(Menu!=3);
  return 0;
}//main