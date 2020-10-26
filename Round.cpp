#include"Round.h"
        Round::Round(){
            	link = NULL;
            	plink = NULL;
                first = NULL;
                last = NULL;
                Name = " ";
                head = NULL;
                count = 0;
			}
        Round::Round(string name){
                Name = name;
                link = NULL;
            	plink = NULL;
                first = NULL;
                last = NULL;
                head = NULL;

            }
        void Round::add_time(string timeout){
                TimeOut *temp = new TimeOut(timeout);
                if(first == NULL){
                    first = temp;
                    last = temp;
                    head = first;
                    //count++;
                }else{
                    last->link = temp;	
				    temp->plink = last;
				    last = temp;
                    
                }
                count++;
            }