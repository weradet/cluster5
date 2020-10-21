#include"Round.h"
        Round::Round(){
            	head = NULL;
            	tail = NULL;
            	link = NULL;
            	plink = NULL;
            	count = 0;
			}
        Round::Round(string timeout,int i){
                TimeOut[i] = timeout;
            }
        Round::Round(string name){
                Name = name;
            }
        void Round::add(string name){
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
        void Round::add(string timeout,int i){
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
        void Round:: Readfile(){
                string filein,name,timeout[9];
                ifstream file("Round.txt",ios::in);
                if(file.is_open()){
                    while(getline(file,filein)){
                        name = filein.substr(0,filein.find(','));
						     filein.erase(0,filein.find(',')+1);
                             add(name);
                        for(int i=0;i<9;i++){
                            timeout[i] = filein.substr(0,filein.find(','));
						     filein.erase(0,filein.find(',')+1);
                            add(timeout[i],i);
                        }
                    
                    }
                //file.close();
                }
            }
        void Round::Show(){
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