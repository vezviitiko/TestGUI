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

void TestGui::ButStart(){
	if (this->butstop) {
		this->butstop = false;
		KillTimeCallback();
	}
	
	// значения по умолчанию
	tabMain.editLat = 55.9121311;
	tabMain.editLon = 37.8090947;
	tabMain.editH = 160.;
	tabMain.editshag = 1.;
	/*
	CCartesian car;
	
	double lat = tabMain.editLat;
	double lon = tabMain.editLon;
	double hgt = tabMain.editH;
	
	car = SphCoordToDec(CSpherical(lat, lon , hgt));
	
	tabMain.editX = car.x;
	tabMain.editY = car.y;
	tabMain.editZ = car.z;
	*/
	
	//tabMain.imagePoint.Enable(true);
	//tabMain.imagePoint.Enable(true);
	//tabMain.imagePoint.SetImage(TutorialImg::p());
	//tabMain.imagePoint.Enable(false);
	//tabMain.imagePoint.TopPosZ(10).LeftPosZ(10, 10);
	
	double x;//x = -166;
	double y;//y = 0;
	
	do {
		x = rand() % 332-142;
		y = rand() % 308-142;
	} while ((sqr(x)+sqr(y)>15000));
	
	tabMain.editcoltek = colpoint;
	
	if (colpoint % 20 == 1) {
		tabMain.imagePoint1.Show();
		tabMain.imagePoint1.SetImage(TutorialImg::point());
		//tabMain.imagePoint1.TopPosZ(303+y, 100).LeftPosZ(308+x, 100);
		tabMain.imagePoint1.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		if (colpoint - 20 > 0){
			tabMain.imagePoint12.SetImage(TutorialImg::point_less0());
			tabMain.imagePoint8.SetImage(TutorialImg::point_less1());
			tabMain.imagePoint4.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 2) {
		tabMain.imagePoint2.Show();
		tabMain.imagePoint2.SetImage(TutorialImg::point());
		tabMain.imagePoint2.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		if (colpoint - 20 > 0){
			tabMain.imagePoint13.SetImage(TutorialImg::point_less0());
			tabMain.imagePoint9.SetImage(TutorialImg::point_less1());
			tabMain.imagePoint5.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 3) {
		tabMain.imagePoint3.Show();
		tabMain.imagePoint3.SetImage(TutorialImg::point());
		tabMain.imagePoint3.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		if (colpoint - 20 > 0){
			tabMain.imagePoint14.SetImage(TutorialImg::point_less0());
			tabMain.imagePoint10.SetImage(TutorialImg::point_less1());
			tabMain.imagePoint6.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 4) {
		tabMain.imagePoint4.Show();
		tabMain.imagePoint4.SetImage(TutorialImg::point());
		tabMain.imagePoint4.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		if (colpoint - 20 > 0){
			tabMain.imagePoint15.SetImage(TutorialImg::point_less0());
			tabMain.imagePoint11.SetImage(TutorialImg::point_less1());
			tabMain.imagePoint7.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 5) {
		tabMain.imagePoint5.Show();
		tabMain.imagePoint5.SetImage(TutorialImg::point());
		tabMain.imagePoint5.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		if (colpoint - 20 > 0){
			tabMain.imagePoint16.SetImage(TutorialImg::point_less0());
			tabMain.imagePoint12.SetImage(TutorialImg::point_less1());
			tabMain.imagePoint8.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 6) {
		tabMain.imagePoint6.Show();
		tabMain.imagePoint6.SetImage(TutorialImg::point());
		tabMain.imagePoint6.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		if (colpoint - 20 > 0){
			tabMain.imagePoint17.SetImage(TutorialImg::point_less0());
			tabMain.imagePoint13.SetImage(TutorialImg::point_less1());
			tabMain.imagePoint9.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 7) {
		tabMain.imagePoint7.Show();
		tabMain.imagePoint7.SetImage(TutorialImg::point());
		tabMain.imagePoint7.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		if (colpoint - 20 > 0){
			tabMain.imagePoint18.SetImage(TutorialImg::point_less0());
			tabMain.imagePoint14.SetImage(TutorialImg::point_less1());
			tabMain.imagePoint10.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 8) {
		tabMain.imagePoint8.Show();
		tabMain.imagePoint8.SetImage(TutorialImg::point());
		tabMain.imagePoint8.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		if (colpoint - 20 > 0){
			tabMain.imagePoint19.SetImage(TutorialImg::point_less0());
			tabMain.imagePoint15.SetImage(TutorialImg::point_less1());
			tabMain.imagePoint11.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 9) {
		tabMain.imagePoint9.Show();
		tabMain.imagePoint9.SetImage(TutorialImg::point());
		tabMain.imagePoint9.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		if (colpoint - 20 > 0){
			tabMain.imagePoint20.SetImage(TutorialImg::point_less0());
			tabMain.imagePoint16.SetImage(TutorialImg::point_less1());
			tabMain.imagePoint12.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 10) {
		tabMain.imagePoint10.Show();
		tabMain.imagePoint10.SetImage(TutorialImg::point());
		tabMain.imagePoint10.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		tabMain.imagePoint1.SetImage(TutorialImg::point_less0());
		if (colpoint - 20 > 0){
			tabMain.imagePoint17.SetImage(TutorialImg::point_less1());
			tabMain.imagePoint13.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 11) {
		tabMain.imagePoint11.Show();
		tabMain.imagePoint11.SetImage(TutorialImg::point());
		tabMain.imagePoint11.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		tabMain.imagePoint2.SetImage(TutorialImg::point_less0());
		if (colpoint - 20 > 0){
			tabMain.imagePoint18.SetImage(TutorialImg::point_less1());
			tabMain.imagePoint14.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 12) {
		tabMain.imagePoint12.Show();
		tabMain.imagePoint12.SetImage(TutorialImg::point());
		tabMain.imagePoint12.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		tabMain.imagePoint3.SetImage(TutorialImg::point_less0());
		if (colpoint - 20 > 0){
			tabMain.imagePoint19.SetImage(TutorialImg::point_less1());
			tabMain.imagePoint15.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 13) {
		tabMain.imagePoint13.Show();
		tabMain.imagePoint13.SetImage(TutorialImg::point());
		tabMain.imagePoint13.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		tabMain.imagePoint4.SetImage(TutorialImg::point_less0());
		if (colpoint - 20 > 0){
			tabMain.imagePoint20.SetImage(TutorialImg::point_less1());
			tabMain.imagePoint16.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 14) {
		tabMain.imagePoint14.Show();
		tabMain.imagePoint14.SetImage(TutorialImg::point());
		tabMain.imagePoint14.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		tabMain.imagePoint5.SetImage(TutorialImg::point_less0());
		tabMain.imagePoint1.SetImage(TutorialImg::point_less1());
		if (colpoint - 20 > 0){
			tabMain.imagePoint17.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 15) {
		tabMain.imagePoint15.Show();
		tabMain.imagePoint15.SetImage(TutorialImg::point());
		tabMain.imagePoint15.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		tabMain.imagePoint6.SetImage(TutorialImg::point_less0());
		tabMain.imagePoint2.SetImage(TutorialImg::point_less1());
		if (colpoint - 20 > 0){
			tabMain.imagePoint18.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 16) {
		tabMain.imagePoint16.Show();
		tabMain.imagePoint16.SetImage(TutorialImg::point());
		tabMain.imagePoint16.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		tabMain.imagePoint7.SetImage(TutorialImg::point_less0());
		tabMain.imagePoint3.SetImage(TutorialImg::point_less1());
		if (colpoint - 20 > 0){
			tabMain.imagePoint19.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 17) {
		tabMain.imagePoint17.Show();
		tabMain.imagePoint17.SetImage(TutorialImg::point());
		tabMain.imagePoint17.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		tabMain.imagePoint8.SetImage(TutorialImg::point_less0());
		tabMain.imagePoint4.SetImage(TutorialImg::point_less1());
		if (colpoint - 20 > 0){
			tabMain.imagePoint20.SetImage(TutorialImg::point_less2());
		}
		colpoint++;
	}
	else if (colpoint % 20 == 18) {
		tabMain.imagePoint18.Show();
		tabMain.imagePoint18.SetImage(TutorialImg::point());
		tabMain.imagePoint18.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		tabMain.imagePoint9.SetImage(TutorialImg::point_less0());
		tabMain.imagePoint5.SetImage(TutorialImg::point_less1());
		tabMain.imagePoint1.SetImage(TutorialImg::point_less2());
		colpoint++;
	}
	else if (colpoint % 20 == 19) {
		tabMain.imagePoint19.Show();
		tabMain.imagePoint19.SetImage(TutorialImg::point());
		tabMain.imagePoint19.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		tabMain.imagePoint10.SetImage(TutorialImg::point_less0());
		tabMain.imagePoint6.SetImage(TutorialImg::point_less1());
		tabMain.imagePoint2.SetImage(TutorialImg::point_less2());
		colpoint++;
	}
	else if (colpoint % 20 == 0) {
		tabMain.imagePoint20.Show();
		tabMain.imagePoint20.SetImage(TutorialImg::point());
		tabMain.imagePoint20.TopPosZ(308+y, 100).LeftPosZ(332+x, 100);
		tabMain.imagePoint11.SetImage(TutorialImg::point_less0());
		tabMain.imagePoint7.SetImage(TutorialImg::point_less1());
		tabMain.imagePoint3.SetImage(TutorialImg::point_less2());
		colpoint++;
	}
	}
	
void TestGui::ButStop(){
		this->butstop = true;
	}
	
void TestGui::ZeroTarget(){
	tabMain.editLat = 0;
	tabMain.editLon = 0;
	tabMain.editH = 0;
	tabMain.editX = 0;
	tabMain.editY = 0;
	tabMain.editZ = 0;
	tabMain.editdX = 0;
	tabMain.editdY = 0;
	tabMain.editdZ = 0;
	tabMain.imagePoint1.Hide();
	tabMain.imagePoint2.Hide();
	tabMain.imagePoint3.Hide();
	tabMain.imagePoint4.Hide();
	tabMain.imagePoint5.Hide();
	tabMain.imagePoint6.Hide();
	tabMain.imagePoint7.Hide();
	tabMain.imagePoint8.Hide();
	tabMain.imagePoint9.Hide();
	tabMain.imagePoint10.Hide();
	tabMain.imagePoint11.Hide();
	tabMain.imagePoint12.Hide();
	tabMain.imagePoint13.Hide();
	tabMain.imagePoint14.Hide();
	tabMain.imagePoint15.Hide();
	tabMain.imagePoint16.Hide();
	tabMain.imagePoint17.Hide();
	tabMain.imagePoint18.Hide();
	tabMain.imagePoint19.Hide();
	tabMain.imagePoint20.Hide();
	colpoint = 1;
	tabMain.editshag = 1;
	tabMain.editcoltek = 0;
}

void TestGui::ButZeropop(){
	tabMain.opt1 = false;
	tabMain.opt2 = false;
	tabMain.opt3 = false;
	tabMain.opt4 = false;
	tabMain.opt5 = false;
	tabMain.opt6 = false;
	tabMain.imageeguat_dop1.SetImage(TutorialImg::imageeguat_ion0());
	tabMain.imageeguat_dop2.SetImage(TutorialImg::imageeguat_trop0());
	tabMain.imageeguat_dop3.SetImage(TutorialImg::imageeguat_zsap0());
	tabMain.imageeguat_dop4.SetImage(TutorialImg::imageeguat_zsas0());
	tabMain.imageeguat_dop5.SetImage(TutorialImg::imageeguat_vm0());
	tabMain.imageeguat_dop6.SetImage(TutorialImg::imageeguat_shum0());
}
