#ifndef STATIONLIST_H
#define STATIONLIST_H
#include"include.h"
#include"Round.h"
#include"node_Addstation.h"
#include"ViewCycleTimes.h"
class StationList{
	private:		
		Node_Addstation *head;
		Node_Addstation *tail;
		int count;
	public:
		ViewCycleTime *cycle;
		StationList();
		~StationList();
		void Addstation(string StationID,string StationName,int Cost,string Status);
		void AddStation_ontheway(int index,string StationID,string StationName,int Cost,string Status);
		void ReadStationFile();
		bool checkStationID(string id);
		bool checkStationName(string name);
		void show_station();
		void WriteStationfile();
		void WriteRoundfile();
		void remove();
		int StationNumber();
};
#endif