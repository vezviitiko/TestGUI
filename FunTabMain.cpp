#include "TestGui.h"

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
	colpoint = 1;
	tabMain.editT = 0;
	tabMain.editdT = 0;
	tabMain.editPoint = 0;
	t = 0;
	N = 0;
	lat.Clear();
	lon.Clear();
	H.Clear();
	SD.Clear();
	x.Clear();
	y.Clear();
	z.Clear();
	dx.Clear();
	dy.Clear();
	dz.Clear();
	tabMain.scatter1.SetXYMin(0, 0);
	tabMain.scatter2.SetXYMin(0, 0);
	tabMain.scatter1.Refresh();
	tabMain.scatter2.Refresh();
	tabMain.mishen.Clear();
	tabMain.mishen.Refresh();
	
	tabCharts.scatter.SetXYMin(0, 0);
	tabCharts.scatter.Refresh();
	tabCharts.grid.Reset();
	tabCharts.grid.AddColumn("X", 40);
	tabCharts.grid.AddColumn("Y", 40);
	tabCharts.grid.AddColumn("Z", 40);
	tabCharts.grid.AddColumn("N", 40);
	tabCharts.grid.AddColumn("H", 40);
	tabCharts.grid.AddColumn("SD", 40);
	tabCharts.grid.AddColumn("t", 40);
	tabCharts.grid.Refresh();
	// иначе не начнется с самого начало отображение графика
	tabCharts.seriesList = "XYZ";
	ChOnSeries();
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

void TestGui::ShowCoordSwitch(){
	tabMain.mishen.ShowCoordinates(~tabMain.show_coord);
}

void TestGui::PgBack()
{
	tabMain.scatter1.SetXYMin(tabMain.scatter1.GetXMin()-5, tabMain.scatter1.GetYMin());
	tabMain.scatter2.SetXYMin(tabMain.scatter2.GetXMin()-5, tabMain.scatter1.GetYMin());
	tabMain.scatter1.Refresh();
	tabMain.scatter2.Refresh();
}

void TestGui::PgForward()
{
	tabMain.scatter1.SetXYMin(tabMain.scatter1.GetXMin()+5, tabMain.scatter1.GetYMin());
	tabMain.scatter2.SetXYMin(tabMain.scatter2.GetXMin()+5, tabMain.scatter1.GetYMin());
	tabMain.scatter1.Refresh();
	tabMain.scatter2.Refresh();
}

void TestGui::PgDownsc1()
{
	tabMain.scatter1.SetXYMin(tabMain.scatter1.GetXMin(), tabMain.scatter1.GetYMin()-5);
	tabMain.scatter1.Refresh();
}

void TestGui::PgUpsc1()
{
	tabMain.scatter1.SetXYMin(tabMain.scatter1.GetXMin(), tabMain.scatter1.GetYMin()+5);
	tabMain.scatter1.Refresh();
}

void TestGui::Plussc1()
{
	tabMain.scatter1.SetRange(tabMain.scatter1.GetXRange()/1.5, tabMain.scatter1.GetYRange());
	tabMain.scatter1.Refresh();
}

void TestGui::Minussc1()
{
	tabMain.scatter1.SetRange(tabMain.scatter1.GetXRange()*1.5, tabMain.scatter1.GetYRange());
	tabMain.scatter1.Refresh();
}

void TestGui::PgDownsc2()
{
	tabMain.scatter2.SetXYMin(tabMain.scatter2.GetXMin(), tabMain.scatter2.GetYMin()-5);
	tabMain.scatter2.Refresh();
}

void TestGui::PgUpsc2()
{
	tabMain.scatter2.SetXYMin(tabMain.scatter2.GetXMin(), tabMain.scatter2.GetYMin()+5);
	tabMain.scatter2.Refresh();
}

void TestGui::Plussc2()
{
	tabMain.scatter2.SetRange(tabMain.scatter2.GetXRange()/1.5, tabMain.scatter2.GetYRange());
	tabMain.scatter2.Refresh();
}

void TestGui::Minussc2()
{
	tabMain.scatter2.SetRange(tabMain.scatter2.GetXRange()*1.5, tabMain.scatter2.GetYRange());
	tabMain.scatter2.Refresh();
}
