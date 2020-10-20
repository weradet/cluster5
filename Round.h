#include "include.h"
class Round{
        private:
            string TimeOut[9];
            string Name;
        public:
            Round *head;
            Round *tail;
            Round *link;
            Round *plink;
            int count;
            Round(){
            	head = NULL;
            	tail = NULL;
            	link = NULL;
            	plink = NULL;
            	count = 0;
			}
            Round(string timeout,int i){
                TimeOut[i] = timeout;
            }
            Round(string name){
                Name = name;
            }
            void add(string name){
                Round *temp = new Round(name);
                if(head == NULL){
                    head = temp;
                    tail = temp;
                    count++;
                }else{
                    tail->link = temp;	
				    temp->plink = tail;
				    tail = temp;
                    count++;
                }
            }
            void add(string timeout,int i){
                Round *temp = new Round(timeout,i);
                if(head == NULL){
                    head = temp;
                    tail = temp;
                    count++;
                }else{
                    tail->link = temp;	
				    temp->plink = tail;
				    tail = temp;
                    count++;
                }
            }
            void Readfile(){
                string filein,name,timeout[9];
                ifstream file("Round.txt",ios::in);
                if(file.is_open()){
                    while(getline(file,filein)){
                        name = filein.substr(0,filein.find(','));
						     filein.erase(0,filein.find(',')+1);
                        for(int i=0;i<9;i++){
                            timeout[i] = filein.substr(0,filein.find(','));
						     filein.erase(0,filein.find(',')+1);
                            add(timeout[i],i);
                        }
                    add(name);
                    }
                //file.close();
                }
            }
            void Show(){
            	Round *temp = head;
            
                while(temp != NULL){
            		cout << temp->Name;
            		for(int i=0;i<9;i++){
            			cout << temp->TimeOut[i];
					}
					cout << endl;
					temp = temp->link;
				}
			}
};