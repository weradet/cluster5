#ifndef ROUND_H
#define ROUND_H
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
            Round();
            Round(string timeout,int i);
            Round(string name);
            void add(string name);
            void add(string timeout,int i);
            void Readfile();
            void Show();
};
#endif