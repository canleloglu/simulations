#ifndef NS3_MULTCOMMON_H
#define NS3_MULTCOMMON_H


#define g_totalSimulationTime 100
#define g_simulationStartTime 10
#define g_totalUserCount 10
#define g_userPerAp 1
#define g_totalApCount g_totalUserCount/g_userPerAp
#define g_totalGwCount 1
#define g_totalOpCount 1
#define g_totalTTPCount 1
#define g_folderName "tcpExamples/multSimulation/"
#define g_mStep 100
#define g_userYDistance 50
#define g_gridWidth 3
#define g_packetSize 512
#define g_gatewayHeight 90
#define g_packetInterval 2

//probabilities
int becomeActiveProbNonWorker[3] = {40, 60, 60};
int becomeActiveProbStudent[3] = {20, 20, 80};
int becomeActiveProbWorker[3] = {20, 99, 20};


int stayActiveProbNonWorker[3] = {90, 98, 80};
int stayActiveProbStudent[3] = {30, 20, 98};
int stayActiveProbWorker[3] = {30, 99, 20};


vector<string> split(const string& strValue, char separator)
{
    vector<string> vecstrResult;
    int startpos=0;
    int endpos=0;
	
    endpos = strValue.find_first_of(separator, startpos);
    while (endpos != -1)
    {       
        vecstrResult.push_back(strValue.substr(startpos, endpos-startpos)); // add to vector
        startpos = endpos+1; //jump past sep
        endpos = strValue.find_first_of(separator, startpos); // find next
        if(endpos==-1)
        {
            //lastone, so no 2nd param required to go to end of string
            vecstrResult.push_back(strValue.substr(startpos));
        }
    }
	
    return vecstrResult;
}

std::string itoa(int value, int base)
{
	std::string buf = "";
	int i = 30;
    
	buf = "";
    
    if(value == 0)
        return "0";
    
	for(; value && i ; --i, value /= base) buf = "0123456789abcdef"[value % base] + buf;
	return buf;
}

string replace( string source, const string find, string replace ) {
	
	size_t j;
	for ( ; (j = source.find( find )) != string::npos ; ) {
		source.replace( j, find.length(), replace );
	}
	return source;
}

#endif