#include"node_Addstation.h"
		Node_Addstation::Node_Addstation(string name,string Sid ,int c,string stat){
			StationID = Sid;
			StationName = name;
            Status = stat;
            Cost = c;
			link = NULL;
			//plink = NULL;
		}

