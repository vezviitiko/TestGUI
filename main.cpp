#include "TestGui.h"

TestGui::TestGui()
{
	dlg(tabMain, "Главная")(tabPath, "Пути")(tabMan, "Руководство");
	
	//dlg(tab1, "OLD_Main")(tab2, "Maps")(tab3, "Path")(tabMain, "Main")
	/*dlg(tabMain, "Main")
	   .Title("Kamaz-Migo Interface")
	   .AddFrame(menu);
	menu.Set([=](Bar& bar) {
		bar.Sub("Menu", [=](Bar& bar) { SubMenu(bar); });
	});*/
	TabMainScreen();
	TabPathScreen();
	TabManScreen();
    dlg.Run();
}

GUI_APP_MAIN
{
	LOG("START");
	TestGui();
	LOG("END");
}
