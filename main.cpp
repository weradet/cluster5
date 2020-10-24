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
      cout << right << setw(70) << "Cannot Login!! Try Again." << endl;
    }
    return false;
}//get parameter Username and Password for check Login 
void Interface(string file){
  string line;
  ifstream myfile(file,ios::in);
  if(myfile.is_open()){
    while(getline(myfile,line)){
      cout << line << endl;
    }
  }
  myfile.close();
}
void Enter(){
  char enter = ' ';
  cout << "Please Enter to Continue : ";
  while((enter = getch()) != '\r'){  
    cin >> enter;
  }
}
void CannotAddstation(){
  char enter = ' ';
  cout << "Cannot Add Station!!" << endl;
  cout << "Please Enter to Continue : ";
    while((enter = getch()) != '\r'){  
      cin >> enter;
    }
}
string pass(){
   // int i;
    char ch='\0',match[20];
    for(int i=0;i>=0;)
     {
       ch=getch();

      if(ch!=8&&ch!=13)
        {
         cout<<"*";
         match[i]=ch;
         i++;
        }
      else if (ch==8) // if backspace is presssed
       {
           if(i>0){
            cout<<"\b \b"; // moves cursor to the left print <space> again move cursor to left
             i--;
           }else{

           }
       }
      else if(ch==13)
    {
         match[i]='\0'; // if enter is pressed, last character in match[] becomes null
        break;         // for end of string
    }
    else
    {
         break;
    }
  }
  return match;
}
int main(){
  int Menu;
  UI obj_ui;
  string str_error = "404 Not found! Your Input Incorrect. Please Try Again";
  do{
    // loop for all Program
    try{
      system("cls");
      Interface("Train.txt"); 
      obj_ui.PrintFirstMenu(); 
      cin >> Menu;
      if(!cin){
        throw str_error; //If not input
      }else if(Menu == 1){
        int menu_customer;
        do{
          system("cls");
          Interface("TrainPersonal.txt");
          obj_ui.PrintCustomer();
          try{ 
            cin >> menu_customer; //User input
            if(!cin){
              throw menu_customer;
            }else if(menu_customer == 3){
              string pass_card;
              int menu_member;
              do{
                cout << "\t\t\t============= MEMBER =============" << endl;
                cout << "\t\t\t=     1. Input The Card          =" << endl;
                cout << "\t\t\t=     2. Back to Menu Customer   =" << endl;
                cout << "\t\t\t==================================" << endl;
                cout << "\t\t\tPlease Enter choice (1-2) : ";
                cin >> menu_member;
                if(!cin){
                  cin.clear(); 
                  cin.ignore(100,'\n'); 
                }else if(menu_member == 1){
                  cout << "Please Input Your Password Card : "; 
                  cin >> pass_card;
                  obj_ui.Clear();
                  obj_ui.loadtopupfile();
                  if(obj_ui.checkmember(pass_card)){
                    int menu_topup;
                    double money;
                    obj_ui.PrintCustomer();
                    do{obj_ui.ShowMenu();
                      cin >> menu_topup;
                      if(menu_topup == 1){
                       do{
                        cout << endl;
                        cout << "\t\tInput money (MAXIMAM : 5,000 Bath) : ";
                        cin >> money;
                        if(money > 5000){
                           cout << "\nMoney Overflow !!" << endl; 
                        }  
                       }while(money > 5000); //do while loop
                        obj_ui.InputMoney(money,pass_card);
                        obj_ui.savetopupfile();
                      }else if(menu_topup == 2){
                        obj_ui.Showmoney(pass_card);
                      }
                    }while(menu_topup != 3);
                  }else{
                    system("cls");
                    cout << "\t\t===========================================" << endl;
                    cout << "\t\tCannot Find Member or Password is Incorrect" << endl;
                    cout << "\t\t===========================================" << endl;
                  }
                }//Menu Member is 1
              }while(menu_member != 2);
            }//Menu Customer is 3
          }//Try
            catch(int menu){
              cin.clear(); 
              cin.ignore(100, '\n'); 
            }
        }while(menu_customer != 4);   
      }else if(Menu == 2){
        string str_user_name;
        string str_password = "";
        cout << "\n" << right << setw(80) << "************************************" << endl;
        cout << right << setw(60) << "Username : "; cin >> str_user_name;
        cout << right << setw(60) << "Password : "; str_password = pass();
        if(Islogin(str_user_name,str_password)){
          int menu_admin; //set varible menu admin
          do{
            system("cls");
            Interface("TrainPersonal.txt");
            obj_ui.PrintAdmin();
            try{ 
              cin >> menu_admin; //Input 2
              if(!cin){
                throw str_error;
              }else if(menu_admin == 1){
                system ("cls");
                Interface("CycleTime.txt");
                obj_ui.View(); //Find Cycle Time
              }else if(menu_admin == 2){
                system ("cls");
                Interface("BuyTicket.txt");
                //Buy Train Ticket
              }else if(menu_admin == 3){
                //ประกาศตัวแปร ข้อมูลของลูกค้าในบัตร
                string user_firstname,user_lastname,user_tel,password_card;
                double money;
                obj_ui.ClearRegister();
                system ("cls");
                Interface("Register.txt");
                cout << "\n" << right << setw(66) << "Please Input Your Firstname : ";
                cin >> user_firstname;
                cout << right << setw(65) << "Please Input Your Lastname : ";
                cin >> user_lastname;
                cout << right << setw(61) << "Please Input Your Tel. : ";
                cin >> user_tel;    
                cout << right << setw(80) << "================== Password Card =================" << endl;
                cout << right << setw(70) << "Please Input Your Password Card : ";
                cin >> password_card;
                obj_ui.InputPersonalInformation(user_firstname,user_lastname,user_tel,password_card);
                obj_ui.ShowInformation(user_firstname,password_card);
                obj_ui.ShowExprirationDate(user_firstname,password_card); cout << endl;           
                cout << right << setw(80) << "================ Topup Money Card ================" << endl;
                cout << right << setw(65) << "Please Input Your Money : ";
                cin >> money;
                obj_ui.InputMoneyCard(money,password_card);
                system ("cls");
                cout << right << setw(80) << "============== Customer Information ==============" << endl;
                cout << right << setw(55) << "Name Customer : " << user_firstname << " " << user_lastname << endl;  
                string tel = user_tel.substr(0,3) + "-" + user_tel.substr(3,3) + "-" + user_tel.substr(6,4);
                cout << right << setw(54) << "Phone number : " << user_tel << endl;
                obj_ui.ShowExprirationDate(user_firstname,password_card);
                obj_ui.ShowRemainingAmount(password_card);                                      
                obj_ui.SaveFile(); cout << endl;
                Enter(); //Register Member                                          
              }else if(menu_admin == 4){
                int menu_renew;
                system ("cls");
                Interface("Renew_card.txt");
                do{
                  obj_ui.showmenuRenewCard();
                  cin >> menu_renew;
                  if(!cin){
                    cin.clear(); 
                    cin.ignore(100,'\n'); 
                  }else if(menu_renew == 1){
                    string passwordcard;
                    obj_ui.loaddataRenew();
                    cout << "\n" << right << setw(80) << "Please Input the Password Card : "; 
                    cin >> passwordcard; 
                    obj_ui.EnterCardcode(passwordcard);
                    obj_ui.SaveDataRenew();
                    Enter();
                  }
                }while(menu_renew != 2); //Renew Member Card
              }else if(menu_admin == 5){
                char choice;
	              string StationName,Status,StationID;
                int Cost;
                system ("cls");
                Interface("Add_station.txt");
                cout << "1.Add Destination" << endl;
                cout << "2.Add Departure station,Add station on the way" << endl;
                cout << "3.Show" << endl;
                cout << "Enter ==> ";
                cin >> choice;
                if(choice == '1'){
                  obj_ui.show_station();
                  cout << "Station ID : ";
                  cin >> StationID;
                  while(StationID.length() != 2){
                    cout << "!!! Warning !!!\n";
                    cout << "Station ID Not equal to 2"<<endl;
                    cin >> StationID;
                  }//while
                   while(obj_ui.checkStationID(StationID)){
                        cout << "The Station Already Exist!!!" << endl;
                        StationID = "";
                        cin >> StationID;
                    }
                      cout << "Station Name : ";
                      cin >> StationName;
                    while(obj_ui.checkStationName(StationName)){             
                      cout << "The Station Already Exist!!!" << endl;
                      StationName = "";
                      cin >> StationName;              
                    }//invalid
                  inputStatus:
                  cout << "Station Status : ";
                  cin >> Status;
                  if(Status != "open" && Status != "close"){
                    goto inputStatus;
                  }
                  //cout << "Station Cost : ";
                //  cin >> Cost;
          
            inputcost:cout << "Enter Station Cost : ";
                        try{ 
                            cin >> Cost; //User input
                         if(!cin){
                              throw Cost;
                         }else{
                            obj_ui.Addstation(StationID,StationName,Cost,Status);//bug
                          //  obj_ui.WriteRoundfile();
                         }
                        }catch(int x){  
                            cin.clear(); 
                            cin.ignore(100, '\n');
                            goto inputcost;
                        }
              
                }else if(choice == '2'){
                  int index;
                  int size = obj_ui.StationNumber();
                  if(size == 0){
                    cout << "Cannot Add Station!!" << endl;
                  }else{
                    int Cost;
                    cout << "Station ID : ";
                    cin >> StationID;  
                    while(StationID.length() != 2){
                      cout << "!!! Warning !!!\n";
                      cout << "Station ID Not equal to 2 " <<endl;
                      cin >> StationID;
                    }//while
                    while(obj_ui.checkStationID(StationID)){
                      cout << "The Station Already Exist!!!" << endl;
                      StationID = "";
                      cin >> StationID;
                    }
                      cout << "Station Name : ";
                      cin >> StationName;
                    while(obj_ui.checkStationName(StationName)){             
                      cout << "The Station Already Exist!!!" << endl;
                      StationName = "";
                      cin >> StationName;              
                  }//invalid
                  inputStatus2:
                    cout << "Station Status : ";
                    cin >> Status;
                    if(Status!="open" && Status!="close"){
                      goto inputStatus2;
                    }
                      inputcost2:cout << "Enter Station Cost : ";
                        try{ 
                            cin >> Cost; //User input
                         if(!cin){
                              throw Cost;
                         }else{
                            obj_ui.Addstation(StationID,StationName,Cost,Status);//bug
                          //  obj_ui.WriteRoundfile();
                         }
                        }catch(int x){  
                            cin.clear(); 
                            cin.ignore(100, '\n');
                            goto inputcost2;
                        }
                      if(size == 1){
                        cout << "Input Position (1) : ";
                        cin >> index;
                        if(index > size || index < 1){
                          //cout << "Cannot Add Station!!" << endl;
                          CannotAddstation();
                        }else{
                          obj_ui.AddStation_ontheway(index,StationName,StationID,Cost,Status);
                          obj_ui.WriteRoundfile();
                        }
                      }else{
                        cout << "Choose Position Station(1 - " << size << ") : ";
                        cin >> index; 
                        if(index > size || index < 1){
                          //cout << "Cannot Add Station!!" << endl;
                          CannotAddstation();
                        }else{
                          obj_ui.AddStation_ontheway(index,StationName,StationID,Cost,Status);
                          //obj_ui.WriteRoundfile();
                        }
                      }
                      obj_ui.WriteStationfile();
                  }
                }else if(choice == '3'){
                  obj_ui.show_station();
                  Enter();
                }//Add Station
              }else if(menu_admin == 6){
                system ("cls");
                Interface("Fixstation.txt");
                obj_ui.readfile();
                obj_ui.ShowAllStation();
                string chooseId;
                string menu;
        ch_id:  cout << "Choose Station ID : ";
                cin >> chooseId;
                if(chooseId.length() != 2 || obj_ui.CheckID(chooseId) == true){
                  goto ch_id;
                }
                obj_ui.ShowStaiton(chooseId);         
                obj_ui.ShowFixMenuStation();
ch_fixmenu:     cout << "Choose Fix Menu Station : ";
                cin >> menu;
                if(menu < "1" || menu > "3" || menu.length() != 1){
                  goto ch_fixmenu;
                }
                obj_ui.ChooseFixMenu(chooseId,menu);
                obj_ui.WriteFixFile(); //Fix Station
                obj_ui.remove();
                Enter();
              }else if(menu_admin == 7){

              }// back menu
            }//Try
            catch(string str){
              cout << str << endl;  
              cin.clear(); 
              cin.ignore(100, '\n'); 
            }//catch  
          }while(menu_admin != 7);      
        }else{
          cout << "\nCannot Login!!" << endl;
        }//If Login Fail
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