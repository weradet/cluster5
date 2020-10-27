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
  cout << "Please Enter to Continue . . . ";
  while((enter = getch()) != '\r'){  
    cin >> enter;
  }
}
void CannotAddstation(){
  char enter = ' ';
  cout << "Cannot Add Station!!" << endl;
  cout << "Please Enter to Continue . . . ";
    while((enter = getch()) != '\r'){  
      cin >> enter;
    }
}
string pass(){
  char ch = '\0',match[20];
  for(int i = 0;i >= 0;){
    ch = getch();
    if(ch != 8 && ch != 13){
      cout << "*";
      match[i] = ch;
      i++;
    }else if(ch == 8){ // if backspace is presssed
      if(i > 0){
        cout << "\b \b"; // moves cursor to the left print <space> again move cursor to left
        i--;
      }
    }else if(ch == 13){
      match[i] = '\0'; // if enter is pressed, last character in match[] becomes null
      break;          // for end of string
    }else{
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
            }else if(menu_customer==1){
                               string Departure,Terminal;
                  do{
                      system ("cls");
                      Interface("CycleTime.txt");
                      obj_ui.Show_Departure();
                      cout << "Enter ID DepartureStation: ";
                      cin >> Departure;
                  }while(obj_ui.Check(Departure)!=true);
                  
                  do{
                    system ("cls");
                    Interface("CycleTime.txt");
                    obj_ui.Show_Terminal(Departure);
                    cout << "Enter ID TerminalStation: ";
                    cin >> Terminal;
                  }while(obj_ui.Check(Terminal)!=true);
                Round *cycle = obj_ui.Show_viewcycles(Terminal);
                Round * Rounds = cycle;
                string retime,Ttime;
                retimess:
                 cycle->first = cycle->head;
                cin.ignore();
                cin.clear();
                cin >> retime;
                 if(retime == "Y"||retime =="y"){
                        goto backs;
                  }
                while(cycle->first != NULL){
                    if(retime == cycle->first->TO){
                        Ttime = retime;
                        goto corrects;
                    }
                    cycle->first = cycle->first->link;
                } 
                goto retimess;
                corrects:
                while(Rounds->first != NULL){
                    if( retime == Rounds ->first->TO){
                        cout<<" Correct "<<endl;
                        cout<<" Time : " << Rounds ->first->TO<<endl;
                        break;
                    }
                    Rounds ->first = Rounds ->first->link;
                }
                  obj_ui.Show_Cost();
                backs:
                  Enter(); 
                  // Memu Buy Ticket //

            }else if(menu_customer==2){
               string Departure,Terminal;
               do{
                      system ("cls");
                      Interface("BuyTicket.txt");
                      obj_ui.BuyTicket_Departure();
                      cout << "Enter ID DepartureStation: ";
                      cin >> Departure;
                  }while(obj_ui.Check_Station(Departure)!=true);
              do{
                    system ("cls");
                    Interface("BuyTicket.txt");
                    obj_ui.BuyTicket_Terminal(Departure);
                    cout << "Enter ID TerminalStation: ";
                    cin >> Terminal;
                  }while(obj_ui.Check_Station(Terminal)!=true);
                Round *cycle = obj_ui.ShowTime_Buyticket(Terminal);
                Round * Rounds = cycle;
                string retime,Ttime;
                retimes:
                 cycle->first = cycle->head;
                cin.ignore();
                cin.clear();
                cin >> retime;
                 if(retime == "Y"||retime =="y"){
                        goto back;
                  }
                while(cycle->first != NULL){
                    if(retime == cycle->first->TO){
                        Ttime = retime;
                        goto correct;
                    }
                    cycle->first = cycle->first->link;
                } 
                goto retimes;
                correct:
                while(Rounds->first != NULL){
                    if( retime == Rounds ->first->TO){
                        cout<<" Correct "<<endl;
                        cout<<" Time : " << Rounds ->first->TO<<endl;
                        break;
                    }
                    Rounds ->first = Rounds ->first->link;
                }
                obj_ui.Buy_Calculate();
                obj_ui.Buy_Ticket_Calculate();
                obj_ui.BuyTicket_Customer(retime);
                back:
                  Enter();            
            }
          }//Try
            catch(int menu){
              cin.clear(); 
              cin.ignore(100, '\n'); 
            }
        }while(menu_customer != 3); 


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
                 string Departure,Terminal;
                  do{
                      system ("cls");
                      Interface("CycleTime.txt");
                      obj_ui.Show_Departure();
                      cout << "Enter ID DepartureStation: ";
                      cin >> Departure;
                  }while(obj_ui.Check(Departure)!=true);
                  
                  do{
                    system ("cls");
                    Interface("CycleTime.txt");
                    obj_ui.Show_Terminal(Departure);
                    cout << "Enter ID TerminalStation: ";
                    cin >> Terminal;
                  }while(obj_ui.Check(Terminal)!=true);
                Round *cycle = obj_ui.Show_viewcycles(Terminal);
                Round * Rounds = cycle;
                string retime,Ttime;
                Retimes:
                 cycle->first = cycle->head;
                cin.ignore();
                cin.clear();
                cin >> retime;
                 if(retime == "Y"||retime =="y"){
                        goto  Menus;
                  }
                while(cycle->first != NULL){
                    if(retime == cycle->first->TO){
                        Ttime = retime;
                        goto Corrects;
                    }
                    cycle->first = cycle->first->link;
                } 
                goto Retimes;
                Corrects:
                while(Rounds->first != NULL){
                    if( retime == Rounds ->first->TO){
                        cout<<" Correct "<<endl;
                        cout<<" Time : " << Rounds ->first->TO<<endl;
                        break;
                    }
                    Rounds ->first = Rounds ->first->link;
                }
                obj_ui.Show_Cost();
                Menus:
                  Enter();          
              }else if(menu_admin == 2){
               string Departure,Terminal;
               do{
                      system ("cls");
                      Interface("BuyTicket.txt");
                      obj_ui.BuyTicket_Departure();
                      cout << "Enter ID DepartureStation: ";
                      cin >> Departure;
                  }while(obj_ui.Check_Station(Departure)!=true);
              do{
                    system ("cls");
                    Interface("BuyTicket.txt");
                    obj_ui.BuyTicket_Terminal(Departure);
                    cout << "Enter ID TerminalStation: ";
                    cin >> Terminal;
                  }while(obj_ui.Check_Station(Terminal)!=true);
                Round *cycle = obj_ui.ShowTime_Buyticket(Terminal);
                Round * Rounds = cycle;
                string retime,Ttime;
                REtimes:
                 cycle->first = cycle->head;
                cin.ignore();
                cin.clear();
                cin >> retime;
                 if(retime == "Y"||retime =="y"){
                        goto BackMenus;
                  }
                while(cycle->first != NULL){
                    if(retime == cycle->first->TO){
                        Ttime = retime;
                        goto Correct;
                    }
                    cycle->first = cycle->first->link;
                } 
                goto REtimes;
                Correct:
                while(Rounds->first != NULL){
                    if( retime == Rounds ->first->TO){
                        cout<<" Correct "<<endl;
                        cout<<" Time : " << Rounds ->first->TO<<endl;
                        break;
                    }
                    Rounds ->first = Rounds ->first->link;
                }
                obj_ui.Buy_Calculate();
                obj_ui.Buy_Ticket_Calculate();
                obj_ui.Buy_Shows(retime);
                BackMenus:
                  Enter();          
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
                do{ 
                  cout << right << setw(61) << "Please Input Your Tel. : "; 
                  cin >> user_tel; 
                  if(user_tel.length() > 10 || user_tel.length() < 10){
                    cout << "Phone Number Must 10 digit" << endl;
                  }
                }while(user_tel.length() != 10);
                obj_ui.loadtopupfile();  
                do{
                  cout << right << setw(80) << "================== Password Card =================" << endl;//
                  cout << right << setw(70) << "Please Input Your Password Card : ";
                  cin >> password_card;
                }while(obj_ui.checkmember(password_card));
                  obj_ui.InputPersonalInformation(user_firstname,user_lastname,user_tel,password_card);
                  obj_ui.ShowInformation(user_firstname,password_card);
                  obj_ui.ShowExprirationDate(user_firstname,password_card); cout << endl;           
                do{
                  cout << right << setw(80) << "================ Topup Money Card ================" << endl;
                  cout << right << setw(65) << "Please Input Your Money : ";
                  cin >> money;
                  if(money > 5000){
                    cout << "OverFlow!!" << endl;
                  }
                }while(money > 5000);
                obj_ui.InputMoneyCard(money,password_card);
                system ("cls");
                cout << right << setw(80) << "============== Customer Information ==============" << endl;
                cout << right << setw(55) << "Name Customer : " << user_firstname << " " << user_lastname << endl;  
                string tel = user_tel.substr(0,3) + "-" + user_tel.substr(3,3) + "-" + user_tel.substr(6,4);
                cout << right << setw(54) << "Phone number : " << tel << endl;
                obj_ui.ShowExprirationDate(user_firstname,password_card);
                obj_ui.ShowRemainingAmount(password_card);                                      
                obj_ui.SaveFile(); cout << endl;
                Enter(); //Register Member                                          
              }else if(menu_admin == 4){
                int menu_renew;
                obj_ui.ClearRenewdata();
                system ("cls");
                Interface("Renew_card.txt");
                do{
                  obj_ui.showmenuRenewCard();
                  cin >> menu_renew;
                  if(!cin){
                    system ("cls");
                    cin.clear(); 
                    cin.ignore(100,'\n'); 
                  }else if(menu_renew == 1){
                    string passwordcard;
                    obj_ui.ClearRenewdata();
                    obj_ui.loaddataRenew();
                    Again:
                    cout << "\n" << right << setw(80) << "Please Input the Password Card : "; 
                    cin >> passwordcard; 
                    if(obj_ui.CheckmemberRenew(passwordcard)){
                        obj_ui.EnterCardcode(passwordcard);
                        obj_ui.SaveDataRenew();
                        Enter();
                    }else{
                        cout << "Password Incorrect!" << endl;
                        goto Again;
                    }
                  }
                }while(menu_renew != 2); //Renew Member Card
              }else if(menu_admin == 5){
                char choice;
	              string StationName,Status,StationID;
                int Cost;
                system ("cls");
                obj_ui.ReadStationFile();
                Interface("Add_station.txt");
                cout << right << setw(95) << "------------------------------------------------------" << endl;
                cout << right << setw(62) << "1.Add Destination" << endl;
                cout << right << setw(91) << "2.Add Departure station,Add station on the way" << endl;
                cout << right << setw(59) << "3.Show Station" << endl;
                cout << right << setw(95) << "------------------------------------------------------" << endl;
                cout << right << setw(70) << "Enter Choice : ";
                cin >> choice;
                if(choice == '1'){
                  system ("cls");
                  obj_ui.show_station();
                  inputID:
                  cout << "Station ID : ";
                  cin >> StationID;
                  while(StationID.length() != 2){
                    cout << right << setw(76) << "!!! Warning !!!\n";
                    cout << right << setw(80) << "Station ID Not equal to 2"<<endl;
                    cin >> StationID;
                  }//while
                   while(obj_ui.checkStationID(StationID)){
                        cout << right << setw(80) << "The Station Already Exist!!!" << endl;
                        StationID = "";
                        goto inputID;
                    }
                    inputName:
                      cout << "Station Name : ";
                      cin >> StationName;
                    while(obj_ui.checkStationName(StationName)){             
                      cout << right << setw(80) << "The Station Already Exist!!!" << endl;
                      StationName = "";
                      goto inputName;              
                    }//invalid
                  inputStatus:
                  cout << "Station Status : ";
                  cin >> Status;
                  if(Status != "open" && Status != "close"){
                    goto inputStatus;
                  }
                  inputcost:
                      cout << "Enter Station Cost : ";
                        try{ 
                            cin >> Cost; //User input
                         if(!cin){
                              throw Cost;
                         }else{
                            obj_ui.Addstation(StationID,StationName,Cost,Status);
                            obj_ui.WriteStationfile();
                            obj_ui.WriteRoundfile();
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
                    cout << right << setw(90) << "Cannot Add Station!!" << endl;
                  }else{
                    int Cost;
                    inputID2:
                    cout << "Station ID : ";
                    cin >> StationID;  
                    while(StationID.length() != 2){
                      cout << right << setw(76) << "!!! Warning !!!\n";
                      cout << right << setw(80) << "Station ID Not equal to 2 " <<endl;
                      goto inputID2;
                    }//while
                    while(obj_ui.checkStationID(StationID)){
                      cout << right << setw(80) << "The Station Already Exist!!!" << endl;
                      StationID = "";
                      goto inputID2;
                    }
                    inputName2:
                      cout << "Station Name : ";
                      cin >> StationName;
                    while(obj_ui.checkStationName(StationName)){             
                      cout << right << setw(80) << "The Station Already Exist!!!" << endl;
                      StationName = "";
                      goto inputName2;             
                  }//invalid
                  inputStatus2:
                    cout << "Station Status : ";
                    cin >> Status;
                    if(Status != "open" && Status != "close"){
                      goto inputStatus2;
                    }
                      inputcost2:
                      cout << "Enter Station Cost : ";
                        try{ 
                            cin >> Cost; //User input
                         if(!cin){
                            throw Cost;
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
                          CannotAddstation();
                        }else{
                          obj_ui.AddStation_ontheway(index,StationName,StationID,Cost,Status);
                          obj_ui.WriteStationfile();
                          obj_ui.WriteRoundfile();
                        }
                      }else{
                        cout << "Choose Position Station(1 - " << size << ") : ";
                        cin >> index; 
                        if(index > size || index < 1){
                          CannotAddstation();
                        }else{
                          obj_ui.AddStation_ontheway(index,StationName,StationID,Cost,Status);
                          obj_ui.WriteStationfile();
                          obj_ui.WriteRoundfile();
                        }
                      } 
                  }
                }else if(choice == '3'){
                  system ("cls");
                  obj_ui.show_station();
                  cout << "\n" << endl;
                  Enter();
                }//Add Station
              }else if(menu_admin == 6){
                system ("cls");
                Interface("Fixstation.txt");
                obj_ui.readfile();
                obj_ui.ShowAllStation();
                string chooseId;
                string menu;
                ch_id:  
                cout << "Choose Station ID : ";
                cin >> chooseId;
                if(chooseId.length() != 2 || obj_ui.CheckID(chooseId) == true){
                  goto ch_id;
                }
                obj_ui.ShowStaiton(chooseId);         
                obj_ui.ShowFixMenuStation();
                ch_fixmenu:     
                cout << "Choose Fix Menu Station : ";
                cin >> menu;
                if(menu < "1" || menu > "3" || menu.length() != 1){
                  goto ch_fixmenu;
                }
                obj_ui.ChooseFixMenu(chooseId,menu);
                obj_ui.WriteFixFile(); //Fix Station
                //obj_ui.WriteStationfile();
                obj_ui.chang();
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
      else if(Menu == 3){
            string password;
            int menu_member;
            obj_ui.clearBuy();
            obj_ui.LoaddataBuymember();
            do{
              cout << endl;
               cout << "1. Input The card" << endl;
               cout << "2. Exit" << endl;
               cout << "Enter the choice : "; cin >>  menu_member;
                 if(!cin){
                  cin.clear(); 
                  cin.ignore(100, '\n');   
                 }else if(menu_member == 1){
                    cout << endl;
                    cout << "Input The Password Card : "; cin >> password;
                    if(obj_ui.checkmemberBuy(password)){
                        int menu_choice;
                        mainmenu:
                        cout << endl;
                        cout << "1. Buy Ticket" << endl;
                        cout << "2. View Cycle Time" << endl;
                        cout << "3. Topup Money" << endl;
                        cout << "4. Exit" << endl;
                        cout << "Enter the Choice : "; cin >> menu_choice;
                         if(!cin){
                          cin.clear(); 
                          cin.ignore(100, '\n');   
                          }
                         else if(menu_choice == 1){ //buy
                                      string Departure,Terminal;
                            do{
                                    system ("cls");
                                    Interface("BuyTicket.txt");
                                    obj_ui.isBuyTicket_Departure();
                                    cout << "Enter ID DepartureStation: ";
                                    cin >> Departure;
                                }while(obj_ui.isCheck_Station(Departure)!=true);
                            do{
                                  system ("cls");
                                  Interface("BuyTicket.txt");
                                  obj_ui.isBuyTicket_Terminal(Departure);
                                  cout << "Enter ID TerminalStation: ";
                                  cin >> Terminal;
                                }while(obj_ui.isCheck_Station(Terminal)!=true);
                              Round *cycle = obj_ui.isShowTime_Buyticket(Terminal);
                              Round * Rounds = cycle;
                              string retime,Ttime;
                              isretimes:
                              cycle->first = cycle->head;
                              cin.ignore();
                              cin.clear();
                              cin >> retime;
                              if(retime == "Y"||retime =="y"){
                                      goto isback;
                                }
                              while(cycle->first != NULL){
                                  if(retime == cycle->first->TO){
                                      Ttime = retime;
                                      goto iscorrect;
                                  }
                                  cycle->first = cycle->first->link;
                              } 
                              goto isretimes;
                              iscorrect:
                              while(Rounds->first != NULL){
                                  if( retime == Rounds ->first->TO){
                                      cout<<" Correct "<<endl;
                                      cout<<" Time : " << Rounds ->first->TO<<endl;
                                      break;
                                  }
                                  Rounds ->first = Rounds ->first->link;
                              }
                              obj_ui.isBuy_Calculate();
                              if(obj_ui.checkPayment(password)){ // check money
                                obj_ui.isBuy_Ticket_Calculate(password);
                                obj_ui.isBuyTicket_Customer(retime);
                              }else{
                                 cout << "Not Enoungth Money !!!!!!! " << endl;
                              }
                              obj_ui.SavedataBuyMember();
                              isback:
                                Enter();            
                                      }


                         else if(menu_choice == 2){ // View Cycle Time
                              string Departure,Terminal;
                                do{
                              system ("cls");
                              Interface("CycleTime.txt");
                              obj_ui.isShow_Departure(); ///
                              cout << "Enter ID TerminalStation: ";
                              cin >> Departure;
                            }while(obj_ui.isCheck(Departure)!=true);
                                do{
                              system ("cls");
                              Interface("CycleTime.txt");
                              obj_ui.isShow_Terminal(Departure); ///
                              cout << "Enter ID TerminalStation: ";
                              cin >> Terminal;
                            }while(obj_ui.isCheck(Terminal)!=true);
                              Round *cycle = obj_ui.isShow_viewcycles(Terminal);
                              Round * Rounds = cycle;
                              string retime,Ttime;
                              isRetimes:
                              cycle->first = cycle->head;
                              cin.ignore();
                              cin.clear();
                              cin >> retime;
                              if(retime == "Y"||retime =="y"){
                                      goto  isMenus;
                                }
                              while(cycle->first != NULL){
                                  if(retime == cycle->first->TO){
                                      Ttime = retime;
                                      goto isCorrects;
                                  }
                                  cycle->first = cycle->first->link;
                              } 
                              goto isRetimes;
                              isCorrects:
                              while(Rounds->first != NULL){
                                  if( retime == Rounds ->first->TO){
                                      cout<<" Correct "<<endl;
                                      cout<<" Time : " << Rounds ->first->TO<<endl;
                                      break;
                                  }
                                  Rounds ->first = Rounds ->first->link;
                              }
                              isMenus:
                                Enter();
                                goto mainmenu;          
                                      } // 
 
               else if(menu_choice == 3){
                      string pass_card;
                      int menu_member;
                      istopup:
                      system("cls");
                      Interface("Topup card.txt");
                      do{
                        cout << right << setw(80) << "============= MEMBER =============" << endl;
                        cout << right << setw(80) << "=     1. Input The Card          =" << endl;
                        cout << right << setw(80) << "=     2. Back to Menu Customer   =" << endl;
                        cout << right << setw(80) << "==================================" << endl;
                        cout << right << setw(74) << "Please Enter choice (1-2) : ";
                        cin >> menu_member;
                        if(!cin){
                          cin.clear(); 
                          cin.ignore(100,'\n'); 
                        }else if(menu_member == 1){
                          cout << right << setw(74) << "Please Input Your Password Card : "; 
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
                                cout << right << setw(74) << "Input money (MAXIMAM : 5,000 Bath) : ";
                                cin >> money;
                                if(money > 5000){
                                  cout << "Money Overflow !!" << endl; 
                                }
                              }while(money > 5000); //do while loop
                                obj_ui.InputMoney(money,pass_card);
                                obj_ui.savetopupfile();
                              }else if(menu_topup == 2){
                                obj_ui.Showmoney(pass_card);
                                Enter();
                              }else if(menu_topup == 3){
                                goto istopup;
                              }
                            }while(menu_topup != 3);
                          }else{
                            system("cls");
                            cout << right << setw(80) << "===========================================" << endl;
                            cout << right << setw(80) << "Cannot Find Member or Password is Incorrect" << endl;
                            cout << right << setw(80) << "===========================================" << endl;
                          }
                        }//Menu Member is 1
                      }while(menu_member != 2);
                    }//Menu Customer is 3




                    }else{
                      cout << "Password in correct" << endl;
                    }
                 }
                 
            }while(menu_member!=2); 
      } //If Menu = 2 Member
    }//Try Exception  
      catch(string str){
        cout << str << endl;  
        cin.clear(); 
        cin.ignore(100, '\n'); 
      }//Catch Error       
  }while(Menu!=4);
  return 0;
}//main