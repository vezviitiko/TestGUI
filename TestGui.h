#ifndef _TestGui_TestGui_h
#define _TestGui_TestGui_h

#include <CtrlLib/CtrlLib.h>
#include <ScatterCtrl/ScatterCtrl.h>	// библиотека графиков
#include <kamaz/kamaz.h>				// библиотека перевода значений
#include <MishenCtrl/MishenCtrl.h>		// библиотека мишени

using namespace Upp;

#define IMAGECLASS TutorialImg
#define IMAGEFILE <TestGui/images.iml>
#include <Draw/iml_header.h>

#define LAYOUTFILE <TestGui/TabDlg.lay>
#include <CtrlCore/lay.h>

// Библиотека Карты
#include "MapDlg.h"

class TestGui : public TopWindow {
public:
	typedef TestGui CLASSNAME;
	TestGui();
	//MenuBar menu;
	TabDlg dlg;
	bool butstop;
	int colpoint = 1; // для подсчета количества отображений
	// ------------ tabMain
	WithTabMainLayout<ParentCtrl> tabMain;
	void TabMainScreen();
	void ButStart();
	void ButStop();
	void ZeroTarget();
	void ButZeropop();
	void ShowCoordinates(bool show = true) {showCoordinates = show;}
	void ShowCoordSwitch();
	
	// кнопки для графиков
	void PgDownsc1();
	void PgUpsc1();
	void Plussc1();
	void Minussc1();
	void PgDownsc2();
	void PgUpsc2();
	void Plussc2();
	void Minussc2();
	void PgBack();
	void PgForward();
	
	// ------------ tabPath
	WithTabPathLayout<ParentCtrl> tabPath;
	void TabPathScreen();
	void OverWritePathIni();
	
	// ------------ tabMap
	MapDlgDlg tabMap;
	
	// ------------ tabCharts
	WithTabChartsLayout<ParentCtrl> tabCharts;
	void TabChartsScreen();
	void PgChDown();
	void PgChUp();
	void PgChBack();
	void PgChForward();
	void PgChPlus();
	void PgChMinus();
	void PgChPlusX();
	void PgChMinusX();
	void PgChPlusY();
	void PgChMinusY();
	void ChOnSeries();
	void ChAnimation(double edx,double edy,double edz,double eddx,double eddy, double eddz, double dlat, double dlon, double dH, double dSD, int N, double t);
	
	// ------------ tabMan
	WithTabManLayout<ParentCtrl> tabMan;
	void TabManScreen();
	
private:
	// ------------ tabMain and tabCharts
	double N, t;
	Vector<Pointf> x, y, z, dx, dy, dz, lat, lon, H, SD;
	bool showCoordinates;
};

struct PathIni
{
	public:
	PathIni(){}
		String pathSP3;
		String pathJPS;
};

PathIni ParsePath(String FileName);

#endif
