#ifndef NODE_TIME_H
#define NODE_TIME_H
#include "include.h"
class TimeOut{
    private:
       
    public:
        TimeOut *link;
        TimeOut *plink;
        string TO;
        TimeOut(string T);
        TimeOut();
};
#endif