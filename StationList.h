#ifndef STATIONLIST_H
#define STATIONLIST_H
#include"include.h"
#include"node_Addstation.h"
class StationList{
	private:		
		Node_Addstation *head;
		Node_Addstation *tail;
		int count;
	public:
		StationList();
		~StationList();
		void Addstation(string StationID,string StationName,string Status,string Cost);
		void AddStation_ontheway(int index,string StationID,string StationName,string Status,string Cost);
		bool checkStationID(string id);
		bool checkStationName(string name);
		void show_station();
		void WriteStationfile();
		int StationNumber();
};
#endif