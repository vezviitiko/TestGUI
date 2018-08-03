#include "TestGui.h"

TestGui::TestGui()
{
	dlg(tab1, "Main")(tab2, "Maps")(tab3, "Time")
	   .Title("Kamaz-Migo Interface")
	   .AddFrame(menu);
	menu.Set([=](Bar& bar) {
		bar.Sub("Menu", [=](Bar& bar) { SubMenu(bar); });
	});
	
	// -- лист 1 - tab1
	Tab1Screen();
	// -- лист 2 - tab2
	Tab2Screen();
	// -- лист 3 - tab3
	Tab3Screen();
	
    dlg.Run();
}

GUI_APP_MAIN
{
	LOG("START");
	TestGui();
	LOG("END");
	
}
