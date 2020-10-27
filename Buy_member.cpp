#include"Buy_memer.h"
Buy_Member_controller :: Buy_Member_controller(){
        Head  = new Path;
        view = new ViewCycleTime;
        view->SearchRound();
       // mem = new Member;
       head = NULL;
       tail = NULL;
}
void Buy_Member_controller :: SeachDeparture(){
    view->ChooseDepartureStation();
}
void Buy_Member_controller::SeachTerminal(string Departure){
    view->ChooseTerminalStation(Departure);
}
Round* Buy_Member_controller ::ShowTime_Buyticket(string name){
    return view->Times(name);
}
void Buy_Member_controller :: Calculate(){
    view->ShowView();
}
double Buy_Member_controller :: Payment(string password){
    double money = view->Calculate();
    double Change = 0;
    Member *cur = head;
    while(cur!=NULL){
        if(cur->getPassword()==password){
             if(cur->member_card.Money > money){
                cur->member_card.PayTicket(money);
             }else if(cur->member_card.Money < money){
                 return -1;
             }
        }
        cur = cur->link;
    }
}
void Dates(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout<<"DEPARTURE DATE : "<<1900 + ltm->tm_year<<":"<<1 + ltm->tm_mon<<":"<<ltm->tm_mday<<endl;
}
void Buy_Member_controller :: Print_Ticket(string retime){
    cout<<"========================================="<<endl;
    cout<<"ORIGIN : "<<view->DepartureStation <<endl;
    cout<<"DESTINATION  : "<<view->TerminalStation <<endl;
    Dates();
    cout<<"ROUND : "<<retime <<endl;
    cout<<"PRICE : "<<view->Calculate() <<endl;
    cout<<"CHANGE : "<< change <<endl;
    cout<<"========================================="<<endl;
    Sleep(1500);
}
void Buy_Member_controller :: Print_Ticket_Customer(string retime){
    cout<<"========================================="<<endl;
    cout<<"ORIGIN : "<<view->DepartureStation <<endl;
    cout<<"DESTINATION  : "<<view->TerminalStation <<endl;
    Dates();
    cout<<"ROUND : "<<retime <<endl;
    cout<<"PRICE : "<<view->Calculate() <<endl;
   // cout<<"CHANGE : "<< change <<endl;
    cout<<"========================================="<<endl;
    Sleep(1500);
}
bool Buy_Member_controller :: checkmember(string password){
    Member *cur = head;
    while(cur != NULL){
        if(cur->getPassword()==password){
           return true; 
        }  
        cur = cur->link;
    }
    return false;
}
bool Buy_Member_controller :: CheckPayment(string password){
    double money = view->Calculate();
    double Change = 0;
    Member *cur = head;
    while(cur!=NULL){
        if(cur->getPassword()==password){
             if(cur->member_card.Money > money){
                 return true;
             }else if(cur->member_card.Money < money){
                 return false;
             }
        }
        cur = cur->link;
    }
}
void Buy_Member_controller ::Loaddata(){
  string line,firstname,lastname,tel,password,expire,money;
  ifstream data("member.txt",ios::in);
  if(data.is_open()){
    while(getline(data,line)){ 
      firstname = line.substr(0,line.find(','));
                  line.erase(0,line.find(',')+1); 
      lastname = line.substr(0,line.find(','));
                 line.erase(0,line.find(',')+1); 
      tel = line.substr(0,line.find(','));
            line.erase(0,line.find(',')+1); 
      password = line.substr(0,line.find(','));
                 line.erase(0,line.find(',')+1); 
      expire = line.substr(0,line.find(','));
               line.erase(0,line.find(',')+1); 
      money = line.substr(0,line.find(','));
              line.erase(0,line.find(',')+1); 
      SetMemberIndata(firstname,lastname,tel,password,expire,money);
    }//while
  }else{
    cout << right << setw(90) << "File Error!!" << endl;
  }
  data.close();
}
void Buy_Member_controller ::clear(){
  Member *temp = head;
  while(head!=NULL){
    temp = head;
    head = head->link;
    delete temp;
  }
}
void  Buy_Member_controller ::SetMemberIndata(string firstname,string lastname,string tel,string password,string expire,string money){
        Member *new_member = new Member(firstname,lastname,tel,password,expire,money);
            if(head == NULL){
                head = new_member;
                tail = new_member; 
            }else{
                tail->link = new_member;
                tail = new_member;
            } 
}// set Add node

void Buy_Member_controller ::savedata(){
  Member *cur = head;
  ofstream file("member.txt",ios::out);
  if(file.is_open()){
    while (cur != NULL){
      file << cur->getFirstname() << ","<<cur->getLastname() << "," << cur->getTel() << "," 
           << cur->getPassword() << ","<< cur->getExpire() << "," << cur->getMoney() << endl;   
      cur = cur->link;
    }//while
  }//if
  file.close();
}




