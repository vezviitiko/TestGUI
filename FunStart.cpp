#include "TestGui.h"

void TestGui::ButStart(){
	
	if (this->butstop) {
		this->butstop = false;
		KillTimeCallback();
	}
	
	// значения по умолчанию
	// значения координат
	if (colpoint % 20 == 1){
		tabMain.editLat = 55.9121311;
		tabMain.editLon = 37.8090947;
		tabMain.editH = 160.;
		tabMain.editT = colpoint+120;
		tabMain.editdT = rand() % 10;
	}
	else{
		tabMain.editLat = rand() % 30+50;
		tabMain.editLon = rand() % 30+50;
		tabMain.editH = rand() % 100+100;
		tabMain.editT = colpoint+120;
		tabMain.editdT = rand() % 10;
	};
	
	tabMain.editPoint = colpoint;
	
	// значение геоцентричекие координат
	// значение геоцентричекие координат
	CCartesian car;
	
	double lat = tabMain.editLat;
	double lon = tabMain.editLon;
	double hgt = tabMain.editH;
	
	car = SphCoordToDec(CSpherical(lat, lon , hgt));
	
	tabMain.editX = car.x;
	tabMain.editY = car.y;
	tabMain.editZ = car.z;
	
	tabMain.editdX = car.x;
	tabMain.editdY = car.y;
	tabMain.editdZ = car.z;
	
	// значение погрешности
	double dSD = 50+30*cos(colpoint);

	// отрисовка графиков на странице "Главная"
	H << Pointf(colpoint, tabMain.editH);
	SD << Pointf(colpoint, dSD);
	tabMain.scatter1.Refresh();
	tabMain.scatter2.Refresh();
	
	if((colpoint-tabMain.scatter1.GetXMin()) >= tabMain.scatter1.GetXRange())
		tabMain.scatter1.SetXYMin(tabMain.scatter1.GetXMin() + 1, 0);
	
	if((colpoint-tabMain.scatter2.GetXMin()) >= tabMain.scatter2.GetXRange())
		tabMain.scatter2.SetXYMin(tabMain.scatter2.GetXMin() + 1, 0);
	
	// отрисовка графиков на странице "Графики"
	ChAnimation(tabMain.editX, tabMain.editY, tabMain.editZ, tabMain.editdX, tabMain.editdY, tabMain.editdZ, tabMain.editLat, tabMain.editLon, tabMain.editH, dSD, colpoint, tabMain.editT);
	
	// отрисовка мишени на странице "Главная"
	tabMain.mishen.PutPoint(car.x, car.y, 1);
	tabMain.mishen.Refresh();
	
	colpoint++;
}
