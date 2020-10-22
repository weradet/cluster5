#include"node_Addstation.h"
		Node_Addstation::Node_Addstation(string Sid,string name,string stat,int c){
			StationID = Sid;
			StationName = name;
            Status = stat;
            Cost = c;
			link = NULL;
			plink = NULL;
		}

