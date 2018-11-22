#include "TestGui.h"

#define IMAGECLASS TutorialImg
#define IMAGEFILE <TestGui/images.iml>
#include <Draw/iml_source.h>

void TestGui::TabMainScreen(){

	//Size sz = tabMain.image_gr_h.GetSize();
	//tabMain.image_target.SetImage(TutorialImg::target2());
	//tabMain.imageshag.SetImage(TutorialImg::shag());
	
	//tabMain.image_gr_h.SetImage(TutorialImg::Grapfic_h()).GetMaxSize();
	//tabMain.image_gr_h_2.SetImage(TutorialImg::Grapfic_h()).GetMaxSize();
	//tabMain.image_gr_acc.SetImage(TutorialImg::Grapfic_acc());
	
	//tabMain.image_logo.SetImage(TutorialImg::logo_iaz());
	
	// Графики в левой части
	tabMain.scatter1.SetRange(10, 200);
	tabMain.scatter2.SetRange(10, 200);
	tabMain.scatter1.AddSeries(H).Legend("H").MarkBorderColor();
	tabMain.scatter2.AddSeries(SD).Legend("SD").NoMark();
	tabMain.bPgUpsc1.SetImage(CtrlImg::SmallUp());
	tabMain.bPgUpsc2.SetImage(CtrlImg::SmallUp());
	tabMain.bPgDownsc1.SetImage(CtrlImg::SmallDown());
	tabMain.bPgDownsc2.SetImage(CtrlImg::SmallDown());
	
	// Кнопки управления графиками
	tabMain.bPgDownsc1.WhenPush = THISBACK(PgDownsc1);
	tabMain.bPgUpsc1.WhenPush = THISBACK(PgUpsc1);
	tabMain.bPlussc1.WhenPush = THISBACK(Plussc1);
	tabMain.bMinussc1.WhenPush = THISBACK(Minussc1);
	tabMain.bPgDownsc2.WhenPush = THISBACK(PgDownsc2);
	tabMain.bPgUpsc2.WhenPush = THISBACK(PgUpsc2);
	tabMain.bPlussc2.WhenPush = THISBACK(Plussc2);
	tabMain.bMinussc2.WhenPush = THISBACK(Minussc2);
	tabMain.bPgBack.WhenPush = THISBACK(PgBack);
	tabMain.bPgForward.WhenPush = THISBACK(PgForward);
	tabMain.imageeguat_osn.SetImage(TutorialImg::imageeguat_osn());
	
	// Иконки поправок
	tabMain.imageeguat_ion.SetImage(TutorialImg::imageeguat_ion_np());
	tabMain.imageeguat_trop.SetImage(TutorialImg::imageeguat_trop_np());
	tabMain.imageeguat_zsap.SetImage(TutorialImg::imageeguat_zsap_np());
	tabMain.imageeguat_zsas.SetImage(TutorialImg::imageeguat_zsas_np());
	tabMain.imageeguat_vm.SetImage(TutorialImg::imageeguat_vm_np());
	tabMain.imageeguat_shum.SetImage(TutorialImg::imageeguat_shum_np());
	
	// Основные кнопки
	//ZeroTarget();
	tabMain.show_coord <<= THISBACK(ShowCoordSwitch);
	tabMain.btnZero.WhenPush = THISBACK(ZeroTarget);
	tabMain.btnStop.WhenPush = THISBACK(ButStop);
	tabMain.btnZeropop.WhenPush = THISBACK(ButZeropop);
	
	this->butstop = false;
	//colpoint = 1.;
	tabMain.btnStart.WhenAction = [=] {
		this->butstop = false;
		KillTimeCallback(); // удаление предыдущего запуска если он есть
		SetTimeCallback(-200, tabMain.btnStart.WhenPush = THISBACK(ButStart));
	};
	
	// Появление иконо при выборе дополнения
	tabMain.imageeguat_dop1.SetImage(TutorialImg::imageeguat_ion0());
	tabMain.imageeguat_dop2.SetImage(TutorialImg::imageeguat_trop0());
	tabMain.imageeguat_dop3.SetImage(TutorialImg::imageeguat_zsap0());
	tabMain.imageeguat_dop4.SetImage(TutorialImg::imageeguat_zsas0());
	tabMain.imageeguat_dop5.SetImage(TutorialImg::imageeguat_vm0());
	tabMain.imageeguat_dop6.SetImage(TutorialImg::imageeguat_shum0());
	
	// Условия выбора дополнений
	// Реализовано пока только изменение картинок
	tabMain.opt1.WhenAction = [=] {
		if (~tabMain.opt1 == true) {
			tabMain.imageeguat_dop1.SetImage(TutorialImg::imageeguat_ion());
		}
		else{
			tabMain.imageeguat_dop1.SetImage(TutorialImg::imageeguat_ion0());
		}
	};
	tabMain.opt2.WhenAction = [=] {
		if (~tabMain.opt2 == true) {
			tabMain.imageeguat_dop2.SetImage(TutorialImg::imageeguat_trop());
		}
		else{
			tabMain.imageeguat_dop2.SetImage(TutorialImg::imageeguat_trop0());
		}
	};
	tabMain.opt3.WhenAction = [=] {
		if (~tabMain.opt3 == true) {
			tabMain.imageeguat_dop3.SetImage(TutorialImg::imageeguat_zsap());
		}
		else{
			tabMain.imageeguat_dop3.SetImage(TutorialImg::imageeguat_zsap0());
		}
	};
	tabMain.opt4.WhenAction = [=] {
		if (~tabMain.opt4 == true) {
			tabMain.imageeguat_dop4.SetImage(TutorialImg::imageeguat_zsas());
		}
		else{
			tabMain.imageeguat_dop4.SetImage(TutorialImg::imageeguat_zsas0());
		}
	};
	tabMain.opt5.WhenAction = [=] {
		if (~tabMain.opt5 == true) {
			tabMain.imageeguat_dop5.SetImage(TutorialImg::imageeguat_vm());
		}
		else{
			tabMain.imageeguat_dop5.SetImage(TutorialImg::imageeguat_vm0());
		}
	};
	tabMain.opt6.WhenAction = [=] {
		if (~tabMain.opt6 == true) {
			tabMain.imageeguat_dop6.SetImage(TutorialImg::imageeguat_shum());
		}
		else{
			tabMain.imageeguat_dop6.SetImage(TutorialImg::imageeguat_shum0());
		}
	};
}

void TestGui::TabPathScreen(){
	PathIni Pathini_ob;
	Pathini_ob = ParsePath("Path.ini");
	tabPath.pathSP3 <<= Pathini_ob.pathSP3;
	tabPath.pathJPS <<= Pathini_ob.pathJPS;
	tabPath.btnOverWrite.WhenPush = THISBACK(OverWritePathIni);
}

void TestGui::TabManScreen(){
	tabMan.image_logo.SetImage(TutorialImg::logo_obsh());
}

void TestGui::TabChartsScreen(){
	tabCharts.bPgDown.WhenPush = THISBACK(PgChDown);
	tabCharts.bPgUp.WhenPush = THISBACK(PgChUp);
	tabCharts.bPgForward.WhenPush = THISBACK(PgChForward);
	tabCharts.bPgBack.WhenPush = THISBACK(PgChBack);
	
	// кнопки изменения масштаба
	
	tabCharts.bMinus.WhenPush = THISBACK(PgChMinus);
	tabCharts.bPlus.WhenPush = THISBACK(PgChPlus);
	tabCharts.bMinusX.WhenPush = THISBACK(PgChMinusX);
	tabCharts.bPlusX.WhenPush = THISBACK(PgChPlusX);
	tabCharts.bMinusY.WhenPush = THISBACK(PgChMinusY);
	tabCharts.bPlusY.WhenPush = THISBACK(PgChPlusY);
	
	tabCharts.bPgUp.SetImage(CtrlImg::SmallUp());
	tabCharts.bPgDown.SetImage(CtrlImg::SmallDown());

	tabCharts.btnStart.WhenAction = [=] {
		this->butstop = false;
		KillTimeCallback(); // удаление предыдущего запуска если он есть
		SetTimeCallback(-200, tabCharts.btnStart.WhenPush = THISBACK(ButStart));
	};

	tabCharts.btnStop.WhenAction = THISBACK(ButStop);
	
	//tabCharts.btnZeropop.WhenAction = THISBACK(ButChZeropop);
	
	tabCharts.seriesList.Add("XYZ").Add("ln(dX)ln(dY)ln(dZ)").Add("Lat&Lon").Add("H").Add("SD");
	
	// для отображения XYZ and ln(dX)ln(dY)ln(dZ)
	tabCharts.seriesList = "ln(dX)ln(dY)ln(dZ)";
	ChOnSeries();
	tabCharts.seriesList = "Lat&Lon";
	ChOnSeries();
	tabCharts.seriesList = "XYZ";
	ChOnSeries();
	//if (colpoint == 1) {	ChOnSeries();	};
	
	tabCharts.grid.AddColumn("X", 50);
	tabCharts.grid.AddColumn("Y", 50);
	tabCharts.grid.AddColumn("Z", 50);
	tabCharts.grid.AddColumn("ln(dX)", 50);
	tabCharts.grid.AddColumn("ln(dY)", 50);
	tabCharts.grid.AddColumn("ln(dZ)", 50);
	tabCharts.grid.AddColumn("Lat", 20);
	tabCharts.grid.AddColumn("Lon", 20);
	tabCharts.grid.AddColumn("H", 20);
	tabCharts.grid.AddColumn("N", 20);
	tabCharts.grid.AddColumn("SD", 50);
	tabCharts.grid.AddColumn("t", 20);
	tabCharts.seriesList.WhenAction = THISBACK(ChOnSeries);
	
	tabCharts.scatter.SetMouseHandling(true, true).ShowContextMenu().ShowPropertiesDlg().ShowProcessDlg();
}
