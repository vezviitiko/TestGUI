#include "TestGui.h"

#define IMAGECLASS TutorialImg
#define IMAGEFILE <TestGui/images.iml>
#include <Draw/iml.h>

void TestGui::Exit() {
    if(PromptOKCancel("Exit MyApp?"))
        dlg.Close();
		//Break();
    }
    
void TestGui::ButtonMaps() {
    PromptOK("Page with map is not available");
    }
    
void TestGui::SubMenu(Bar& bar) {
		bar.Add("Exit", TutorialImg::Exit(), [=] { Exit(); });
		bar.Add("Maps", TutorialImg::world_map(), [=] { ButtonMaps(); });
    }
    
void TestGui::StartCalc(){
	//static int i=0;
	//tab1.lbl1 = Format("You pressed 'Кнопка 1' %d times, Znachenie = %d",++i,~tab1.editfld1);
	Vector <InputData> inDatVect;
	Vector <Ephemeris> eph;
	
	//Зададим массив входящих данных
	double inData[2][7];
	inData[0][0] = tab1.editin00;
	inData[0][1] = tab1.editin01;
	inData[0][2] = tab1.editin02;
	inData[0][3] = tab1.editin03;
	inData[0][4] = tab1.editin04;
/*	
	inData[1][0] = 20317.7206562;
	inData[1][1] = 22309.8467601915;
	inData[1][2] = 19305.7438067749;
	inData[1][3] = 19344.8207480251;
	inData[1][4] = 23093.3796233308;


	//Попробуем использовать модельные измерения
	double xx = -3782627.48060055 / 1000.;
	double yy = 706759.897227085 / 1000.;
	double zz = 6330779.72431116 / 1000.;
*/
	//Эфемериды аппаратов

	double ephem[5][3];
	
	ephem[0][0] = tab1.editef00; ephem[0][1] = tab1.editef10; ephem[0][2] = tab1.editef02;	//20-й аппарат
	ephem[1][0] = tab1.editef10; ephem[1][1] = tab1.editef11; ephem[1][2] = tab1.editef12;	//4-й аппарат
	ephem[2][0] = tab1.editef20; ephem[2][1] = tab1.editef21; ephem[2][2] = tab1.editef22;	//21
	ephem[3][0] = tab1.editef30; ephem[3][1] = tab1.editef31; ephem[3][2] = tab1.editef32;	//5
	ephem[4][0] = tab1.editef40; ephem[4][1] = tab1.editef41; ephem[4][2] = tab1.editef42;	//22
	
	tab1.krit1.WhenAction = [=] {
	/*
	double ephem[5][3];
	ephem[0][0] = tab1.editef00; ephem[0][1] = tab1.editef10; ephem[0][2] = tab1.editef02;	//20-й аппарат
	ephem[1][0] = tab1.editef10; ephem[1][1] = tab1.editef11; ephem[1][2] = tab1.editef12;	//4-й аппарат
	ephem[2][0] = tab1.editef20; ephem[2][1] = tab1.editef21; ephem[2][2] = tab1.editef22;	//21
	ephem[3][0] = tab1.editef30; ephem[3][1] = tab1.editef31; ephem[3][2] = tab1.editef32;	//5
	ephem[4][0] = tab1.editef40; ephem[4][1] = tab1.editef41; ephem[4][2] = tab1.editef42;	//22
	*/
	tab1.accur1 = "Решение с использование матрицы Эфемерид";
	};
	
//	inData[1][0] = pow((pow((xx - ephem[0][0]), 2) + pow((yy - ephem[0][1]), 2) + pow((zz - ephem[0][2]), 2)), 0.5);
//	inData[1][1] = pow((pow((xx - ephem[1][0]), 2) + pow((yy - ephem[1][1]), 2) + pow((zz - ephem[1][2]), 2)), 0.5);
//	inData[1][2] = pow((pow((xx - ephem[2][0]), 2) + pow((yy - ephem[2][1]), 2) + pow((zz - ephem[2][2]), 2)), 0.5);
//	inData[1][3] = pow((pow((xx - ephem[3][0]), 2) + pow((yy - ephem[3][1]), 2) + pow((zz - ephem[3][2]), 2)), 0.5);
//	inData[1][4] = pow((pow((xx - ephem[4][0]), 2) + pow((yy - ephem[4][1]), 2) + pow((zz - ephem[4][2]), 2)), 0.5);

	inData[1][0] = tab1.editin10;
	inData[1][1] = tab1.editin11;
	inData[1][2] = tab1.editin12;
	inData[1][3] = tab1.editin13;
	inData[1][4] = tab1.editin14;
	
	//Заполним массивы входящих данных
	for (int i = 0; i < 5; i++){
		inDatVect.Add(InputData(inData[0][i], inData[1][i], 0.0));
		eph.Add(Ephemeris(0, ephem[i][0], ephem[i][1], ephem[i][2]));
	}
	
	LOG("Data test output");
	for (int i = 0; i < inDatVect.GetCount(); i++){
		RDUMP(inDatVect[i].psRangLen);
	}
	
	LOG("In the procedure");
	//Найдём координаты станции
	//Coord statPos = NavProblemPsRang(inDatVect, eph);
	tab1.polosa.Set(0);
	Coord statPos = NewNavProb(inDatVect, eph);
	tab1.polosa.Set(100);
	
	tab1.editoutX = statPos.x;
	tab1.editoutY = statPos.y;
	tab1.editoutZ = statPos.z;
	tab1.editoutT = statPos.t;
	tab1.editacc = statPos.acc;
	
	if (abs(tab1.editacc - 6371.) > 100.){
		tab1.accur = "Точность ужасная";
	}
	else{
		tab1.accur = "Точность шикарная";
	}
	
}
void TestGui::ZeroOutIn(){
	tab1.editin00 = 0;
	tab1.editin01 = 0;
	tab1.editin02 = 0;
	tab1.editin03 = 0;
	tab1.editin04 = 0;
	tab1.editin10 = 0;
	tab1.editin11 = 0;
	tab1.editin12 = 0;
	tab1.editin13 = 0;
	tab1.editin14 = 0;
	}
	
void TestGui::ZeroOutEf(){
	tab1.editef00 = 0;
	tab1.editef01 = 0;
	tab1.editef02 = 0;
	tab1.editef10 = 0;
	tab1.editef11 = 0;
	tab1.editef12 = 0;
	tab1.editef20 = 0;
	tab1.editef21 = 0;
	tab1.editef22 = 0;
	tab1.editef30 = 0;
	tab1.editef31 = 0;
	tab1.editef32 = 0;
	tab1.editef40 = 0;
	tab1.editef41 = 0;
	tab1.editef42 = 0;
	}
	
void TestGui::DefaultIn(){
	// значения по умолчанию
	tab1.editin00 = 20;
	tab1.editin01 = 4;
	tab1.editin02 = 21;
	tab1.editin03 = 5;
	tab1.editin04 = 22;
	tab1.editin10 = 20317.7206562;
	tab1.editin11 = 22309.8467601915;
	tab1.editin12 = 19305.7438067749;
	tab1.editin13 = 19344.8207480251;
	tab1.editin14 = 19344.8207480251;
	}
	
void TestGui::DefaultEf(){
	// значения по умолчанию
	tab1.editef00 = 8852.877527;
	tab1.editef01 = 19812.499427;
	tab1.editef02 = 13455.272608;
	tab1.editef10 = -12198.743176;
	tab1.editef11 = 6387.390091;
	tab1.editef12 = 21491.421479;
	tab1.editef20 = 10976.098464;
	tab1.editef21 = 2307.666364;
	tab1.editef22 = 22904.680281;
	tab1.editef30 = 5644.592226;
	tab1.editef31 = 12957.107325;
	tab1.editef32 = 21231.360978;
	tab1.editef40 = 5752.717420;
	tab1.editef41 = -16816.611187;
	tab1.editef42 = 18235.134882;
	}

void TestGui::CopyOut(){
	double x = tab1.editoutX;
	double y = tab1.editoutY;
	double z = tab1.editoutZ;
	tab2.editX = x;
	tab2.editY = y;
	tab2.editZ = z;
	
	tab1.komment = "Данные скопированы на следующую страницу";
}
	
void TestGui::TranslatIntoGeo(){
	CCartesian car;
	CSpherical sph;
	
	car.x = tab2.editX;
	car.y = tab2.editY;
	car.z = tab2.editZ;
	
	sph = DecToSphCoord(car);
	
	tab2.editLat = sph.lat;
	tab2.editLon = sph.lon;
	tab2.editH = sph.hgt;
	}

void TestGui::TranslatIntoTop(){
	CCartesian car;
	
	double lat = tab2.editLat;
	double lon = tab2.editLon;
	double hgt = tab2.editH;
	
	car = SphCoordToDec(CSpherical(lat, lon , hgt));
	
	tab2.editX = car.x;
	tab2.editY = car.y;
	tab2.editZ = car.z;
	}

void TestGui::DisplayMap(){
	// реализовано поверхсностно -  неточно
	tab2.imagePoint.VSizePos(tab2.editLat*(-5.55)).HSizePos(tab2.editLon*5.52);
	tab2.imagePoint.SetImage(TutorialImg::Point());
	tab2.imagePoint.Enable(false);
	}
void TestGui::DisplayMapMove(){
	tab2.imagePoint.Hide();
	}
	
void TestGui::SubstituteHeight(){
	tab2.editH = 160.;
	}

void TestGui::DefaultGeo(){
	// значения по умолчанию
	tab2.editLat = 55.9121311;
	tab2.editLon = 37.8090947;
	tab2.editH = 160.;
	}

void TestGui::Tab1Screen(){
	tab1.btnResh.WhenPush = THISBACK(StartCalc);
	tab1.btn1.WhenPush = THISBACK(DefaultIn);
	tab1.btn2.WhenPush = THISBACK(DefaultEf);
	tab1.btnZeroIn.WhenPush = THISBACK(ZeroOutIn);
	tab1.btnZeroEf.WhenPush = THISBACK(ZeroOutEf);
	tab1.btnCopy.WhenPush = THISBACK(CopyOut);
	//tab1.btn2.WhenPush = [=] { tab1.editfld1 <<= 10;};
	tab1.path1 <<= "/path";
	tab1.path2 <<= "/path/config";
	tab1.path3 <<= "/path/main";
	
	tab1.opt1.WhenAction = [=] {
		tab1.accur1 = "Решение производится с критерием 1 ";
	};
}

void TestGui::Tab2Screen(){
	tab2.image_map.SetImage(TutorialImg::map_base());
	tab2.btn1.WhenPush = THISBACK(TranslatIntoGeo);
	tab2.btn2.WhenPush = THISBACK(TranslatIntoTop);
	tab2.btn3.WhenPush = THISBACK(DisplayMap);
	tab2.btn6.WhenPush = THISBACK(DisplayMapMove);
	tab2.btn4.WhenPush = THISBACK(SubstituteHeight);
	tab2.btn5.WhenPush = THISBACK(DefaultGeo);
	
	}
