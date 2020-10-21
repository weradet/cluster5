#ifndef PATH_H
#define PATH_H
#include"include.h"
#include"station.h"
class Path{
    public:
        Station *head;
        Station *tail;
        int count;
        void add_path(string id,string sta_name,string sta_stu,int cost);
        Path();
        void read_file();
        void show();
        void calculate_cost(string DepartureStation,string TerminalStation);
};

#endif