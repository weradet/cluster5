#ifndef ROUND_H
#define ROUND_H
#include "include.h"
#include "Node_time.h"
class Round{
            
        public:
            string Name;
            TimeOut *first;
            TimeOut *last;
            Round *link;
            Round *plink;
            int count;
            Round();
            Round(string name);
            void add_time(string timeout);
};
#endif