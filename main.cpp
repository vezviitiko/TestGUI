#include "TestGui.h"

TestGui::TestGui()
{
	dlg.Sizeable().Zoomable().Icon(TutorialImg::logo_iaz());
	//dlg.MaximizeBox();
	//dlg.Maximize();
	
	Pointf p(37.8090947, 55.9121311);
	tabMap.Set(p);
	
	dlg(tabMain, "Главная")(tabCharts, "Графики")(tabMap, "Карта")(tabPath, "Пути")(tabMan, "Руководство").Title("Kamaz-SolNavPro Interface");
	
	// если потребуется меню сверху
	//dlg(tab1, "OLD_Main")(tab2, "Maps")(tab3, "Path")(tabMain, "Main")
	/*dlg(tabMain, "Main")
	   .Title("Kamaz-Migo Interface")
	   .AddFrame(menu);*/
	/*
	menu.Set([=](Bar& bar) {
		bar.Sub("Menu", [=](Bar& bar) { SubMenu(bar); });
	});*/
	
	TabMainScreen();
	TabPathScreen();
	TabManScreen();
	TabChartsScreen();
	
	dlg.Run();
}

GUI_APP_MAIN
{
	LOG("START");
	TestGui();
	LOG("END");
}
