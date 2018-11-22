#include "TestGui.h"

PathIni ParsePath(String FileName){
	PathIni Pathini_ob;	
	StringStream inStream;
	String inString;
	//inStream.Open(LoadFile(GetDataFile(FileName)));
	inStream.Open(LoadFile(FileName));
	do{
		inString = inStream.GetLine();
		if (inString.Find("SP3Sourse: ",0) != -1)
			{
				inString.Replace("SP3Sourse: ","");
				Pathini_ob.pathSP3 = inString;
			} 
		else if (inString.Find("JPSSourse: ",0) != -1)
			{
				inString.Replace("JPSSourse: ","");
				Pathini_ob.pathJPS = inString;
			}
		}
		while(!inStream.IsEof());
		
	return Pathini_ob;
}

void TestGui::OverWritePathIni(){
	FILE * pFile;
	pFile = fopen ("Path.ini","w");
	if (pFile!=NULL)
	{
		fputs(Format("SP3Sourse: %s\n",AsString(~tabPath.pathSP3)),pFile);
		fputs(Format("JPSSourse: %s\n",AsString(~tabPath.pathJPS)),pFile);
		fclose(pFile);
	}
	tabPath.komment = "Данные перезаписаны в файл Path.ini";
}
