#ifndef NODE_ADDSTATION_H
#define NODE_ADDSTATION_H
#include"include.h"
class Node_Addstation{
	public:
		string StationName,StationID,Status;
		int Cost;
		Node_Addstation *link;
		Node_Addstation *plink;
		Node_Addstation(string Sid,string name,int Cost,string stat);

};
#endif