#ifndef STATIONLIST_H
#define STATIONLIST_H
#include"include.h"
#include"Path.h"
class StationList :public Path{
	public:
		void Addstation(string StationID,string StationName,string Status,int Cost);
		void AddStation_ontheway(int index,string StationID,string StationName,string Status,int Cost);
		bool checkStationID(string id);
		bool checkStationName(string name);
		void show_station();
		void WriteStationfile();
		int StationNumber();
};
#endif