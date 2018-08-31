#ifndef _TestGui_TestGui_h
#define _TestGui_TestGui_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define IMAGECLASS TutorialImg
#define IMAGEFILE <TestGui/images.iml>
#include <Draw/iml_header.h>

#define LAYOUTFILE <TestGui/TabDlg.lay>
#include <CtrlCore/lay.h>

#include "MapDlg.h"

class TestGui : public TopWindow {
public:
	typedef TestGui CLASSNAME;
	TestGui();
	MenuBar menu;
	TabDlg dlg;
	bool butstop;
	int colpoint;
	WithTabMainLayout<ParentCtrl> tabMain;
	void TabMainScreen();
	void ButStart();
	void ButStop();
	void ZeroTarget();
	void ButZeropop();
	WithTabPathLayout<ParentCtrl> tabPath;
	void TabPathScreen();
	void OverWritePathIni();
	
	MapDlgDlg tabMap;
	
	WithTabManLayout<ParentCtrl> tabMan;
	void TabManScreen();
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
