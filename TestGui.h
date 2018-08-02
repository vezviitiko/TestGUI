#ifndef _TestGui_TestGui_h
#define _TestGui_TestGui_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <TestGui/TabDlg.lay>
#include <CtrlCore/lay.h>

#include <kamaz/kamaz.h>
#include <MNK/NavSolJps2.h>

class TestGui : public TopWindow {
public:
	typedef TestGui CLASSNAME;
	TestGui();
	MenuBar menu;
	TabDlg dlg;
	void Exit();
	void ButtonMaps();
	void SubMenu(Bar& bar);
	
	WithTab1Layout<ParentCtrl> tab1;
	void Tab1Screen();
	void StartCalc();
	void ZeroOutIn();
	void ZeroOutEf();
	void DefaultIn();
	void DefaultEf();
	void CopyOut();
	WithTab2Layout<ParentCtrl> tab2;
	void Tab2Screen();
	void TranslatIntoGeo();
	void TranslatIntoTop();
	void DisplayMap();
	void DisplayMapMove();
	void DefaultGeo();
	void SubstituteHeight();
	WithTab3Layout<ParentCtrl> tab3;
	
	

};

#endif
