#include "TestGui.h"

void TestGui::PgChDown()
{
	if (tabCharts.seriesList != "XYZ") {
		tabCharts.scatter.SetXYMin(tabCharts.scatter.GetXMin(), tabCharts.scatter.GetYMin()-5);
	}
	else{
		tabCharts.scatter.SetXYMin(tabCharts.scatter.GetXMin(), tabCharts.scatter.GetYMin()-100000);
	}
	
	tabCharts.scatter.Refresh();
}

void TestGui::PgChUp()
{
	if (tabCharts.seriesList != "XYZ") {
		tabCharts.scatter.SetXYMin(tabCharts.scatter.GetXMin(), tabCharts.scatter.GetYMin()+5);
	}
	else{
		tabCharts.scatter.SetXYMin(tabCharts.scatter.GetXMin(), tabCharts.scatter.GetYMin()+100000);
	}
	tabCharts.scatter.Refresh();
}

void TestGui::PgChBack()
{
	tabCharts.scatter.SetXYMin(tabCharts.scatter.GetXMin()-5, tabCharts.scatter.GetYMin());
	tabCharts.scatter.Refresh();
}

void TestGui::PgChForward()
{
	tabCharts.scatter.SetXYMin(tabCharts.scatter.GetXMin()+5, tabCharts.scatter.GetYMin());
	tabCharts.scatter.Refresh();
}

void TestGui::PgChPlus()
{
	tabCharts.scatter.SetRange(tabCharts.scatter.GetXRange()/1.5, tabCharts.scatter.GetYRange()/1.5);
	tabCharts.scatter.Refresh();
}

void TestGui::PgChMinus()
{
	tabCharts.scatter.SetRange(tabCharts.scatter.GetXRange()*1.5, tabCharts.scatter.GetYRange()*1.5);
	tabCharts.scatter.Refresh();
}

void TestGui::PgChPlusX()
{
	tabCharts.scatter.SetRange(tabCharts.scatter.GetXRange()/1.5, tabCharts.scatter.GetYRange());
	tabCharts.scatter.Refresh();
}

void TestGui::PgChMinusX()
{
	tabCharts.scatter.SetRange(tabCharts.scatter.GetXRange()*1.5, tabCharts.scatter.GetYRange());
	tabCharts.scatter.Refresh();
}

void TestGui::PgChPlusY()
{
	tabCharts.scatter.SetRange(tabCharts.scatter.GetXRange(), tabCharts.scatter.GetYRange()/1.5);
	tabCharts.scatter.Refresh();
}

void TestGui::PgChMinusY()
{
	tabCharts.scatter.SetRange(tabCharts.scatter.GetXRange(), tabCharts.scatter.GetYRange()*1.5);
	tabCharts.scatter.Refresh();
}

/*
void TestGui::ButChZeropop()
{
	if (tabCharts.seriesList == "XYZ") {
		//tabCharts.scatter.Reset();
		tabCharts.scatter.RemoveAllSeries();
	}
	tabCharts.optX = false;
	tabCharts.optY = false;
	tabCharts.optZ = false;
}
*/

void TestGui::ChOnSeries()
{
	// старая версия с выбором x y z находится в DopFunction.cpp 

	tabCharts.scatter.RemoveAllSeries();
	if (tabCharts.seriesList == "XYZ") {
		tabCharts.scatter.Refresh();
		tabCharts.scatter.SetRange(10, 7500000);
		tabCharts.scatter.AddSeries(x).Legend("X").MarkColor(Yellow()).MarkBorderColor(LtRed()).Stroke(3, Red()).MarkStyle<CircleMarkPlot>();
		tabCharts.scatter.AddSeries(y).Legend("Y").MarkColor(Red()).MarkBorderColor(LtGreen()).Stroke(3, Blue()).MarkStyle<CircleMarkPlot>();
		tabCharts.scatter.AddSeries(z).Legend("Z").MarkColor(LtBlue()).MarkBorderColor(LtRed()).Stroke(3, Green()).MarkStyle<CircleMarkPlot>();
	}
	else if (tabCharts.seriesList == "ln(dX)ln(dY)ln(dZ)") {
		tabCharts.scatter.Refresh();
		tabCharts.scatter.SetRange(10, 50);
		tabCharts.scatter.AddSeries(dx).Legend("ln(dX)").MarkColor(Yellow()).MarkBorderColor(LtRed()).Stroke(3, Red()).MarkStyle<CircleMarkPlot>();
		tabCharts.scatter.AddSeries(dy).Legend("ln(dY)").MarkColor(Red()).MarkBorderColor(LtGreen()).Stroke(3, Blue()).MarkStyle<CircleMarkPlot>();
		tabCharts.scatter.AddSeries(dz).Legend("ln(dZ)").MarkColor(LtBlue()).MarkBorderColor(LtRed()).Stroke(3, Green()).MarkStyle<CircleMarkPlot>();
	}
	else if (tabCharts.seriesList == "Lat&Lon") {
		tabCharts.scatter.Refresh();
		tabCharts.scatter.SetRange(10 , 300);
		tabCharts.scatter.AddSeries(lat).Legend("Широта").MarkBorderColor();
		tabCharts.scatter.AddSeries(lon).Legend("Долгота").MarkBorderColor();
	}
	else if (tabCharts.seriesList == "H") {
		tabCharts.scatter.Refresh();
		tabCharts.scatter.SetRange(10 , 300);
		tabCharts.scatter.AddSeries(H).Legend("H").MarkBorderColor();
	}
	else if (tabCharts.seriesList == "SD") {
		tabCharts.scatter.Refresh();
		tabCharts.scatter.SetRange(10, 100);
		tabCharts.scatter.AddSeries(SD).Legend("SD").MarkBorderColor();
		//tabCharts.scatter.Refresh();
	}
}

void TestGui::ChAnimation(double edx,double edy,double edz,double eddx,double eddy, double eddz, double dlat, double dlon, double dH, double dSD, int N, double t)
{
	tabCharts.grid.Add(edx, edy, edz, log(eddx), log(eddy), log(eddz), dlat, dlon, dH, N, dSD, t);
	tabCharts.grid.Refresh();
	
	x << Pointf(N, edx);
	y << Pointf(N, edy);
	z << Pointf(N, edz);
	dx << Pointf(N, log(eddx));
	dy << Pointf(N, log(eddy));
	dz << Pointf(N, log(eddz));
	H << Pointf(N, dH);
	SD << Pointf(N, dSD);
	lat << Pointf(N, dlat);
	lon << Pointf(N, dlon);
	tabCharts.scatter.Refresh();
	if((N-tabCharts.scatter.GetXMin()) >= tabCharts.scatter.GetXRange())
		tabCharts.scatter.SetXYMin(tabCharts.scatter.GetXMin() + 1, 0);
	
	/*if (tabCharts.seriesList == "XYZ") {
		x << Pointf(N, dx);
		y << Pointf(N, dy);
		z << Pointf(N, dz);
		tabCharts.scatter.Refresh();
		if((N-tabCharts.scatter.GetXMin()) >= tabCharts.scatter.GetXRange())
			tabCharts.scatter.SetXYMin(tabCharts.scatter.GetXMin() + 1, 0);
	}
	else if (tabCharts.seriesList == "H") {
		x << Pointf(N, dx);
		y << Pointf(N, dy);
		z << Pointf(N, dz);
		s1 << Pointf(N, dH);
		tabCharts.scatter.Refresh();
		N += 1;
		if((N-tabCharts.scatter.GetXMin()) >= tabCharts.scatter.GetXRange())
			tabCharts.scatter.SetXYMin(tabCharts.scatter.GetXMin() + 1, 0);

	}
	else if (tabCharts.seriesList == "SD") {
		x << Pointf(N, dx);
		y << Pointf(N, dy);
		z << Pointf(N, dz);
		s2 << Pointf(N, dSD);
		tabCharts.scatter.Refresh();
		if((N-tabCharts.scatter.GetXMin()) >= tabCharts.scatter.GetXRange())
			tabCharts.scatter.SetXYMin(tabCharts.scatter.GetXMin() + 1, 0);
	}*/
}
