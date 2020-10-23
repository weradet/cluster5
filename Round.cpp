#include"Round.h"
        Round::Round(){
            	link = NULL;
            	plink = NULL;
                first = NULL;
                last = NULL;
			}
        Round::Round(string name){
                Name = name;
            }
        void Round::add_time(string timeout){
                TimeOut *temp = new TimeOut(timeout);
                if(first == NULL){
                    first = temp;
                    last = temp;
                    count++;
                }else{
                    last->link = temp;	
				    temp->plink = last;
				    last = temp;
                    count++;
                }
            }