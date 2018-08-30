#include "TestGui.h"

#define IMAGECLASS TutorialImg
#define IMAGEFILE <TestGui/images.iml>
#include <Draw/iml_source.h>

void TestGui::TabMainScreen(){
	tabMain.image_target.SetImage(TutorialImg::target2());
	tabMain.image_logo.SetImage(TutorialImg::logo_iaz());
	tabMain.imageeguat_osn.SetImage(TutorialImg::imageeguat_osn());
	
	ZeroTarget();
	
	tabMain.imageeguat_ion.SetImage(TutorialImg::imageeguat_ion_np());
	tabMain.imageeguat_trop.SetImage(TutorialImg::imageeguat_trop_np());
	tabMain.imageeguat_zsap.SetImage(TutorialImg::imageeguat_zsap_np());
	tabMain.imageeguat_zsas.SetImage(TutorialImg::imageeguat_zsas_np());
	tabMain.imageeguat_vm.SetImage(TutorialImg::imageeguat_vm_np());
	tabMain.imageeguat_shum.SetImage(TutorialImg::imageeguat_shum_np());
	
	tabMain.btnZero.WhenPush = THISBACK(ZeroTarget);
	tabMain.btnStop.WhenPush = THISBACK(ButStop);
	tabMain.btnZeropop.WhenPush = THISBACK(ButZeropop);
	
	this->butstop = false;
	colpoint = 1;
	tabMain.btnStart.WhenAction = [=] {
		this->butstop = false;
		KillTimeCallback(); // удаление предыдущего запуска если он есть
		SetTimeCallback(-200, tabMain.btnStart.WhenPush = THISBACK(ButStart));
	};
	
	tabMain.imageeguat_dop1.SetImage(TutorialImg::imageeguat_ion0());
	tabMain.imageeguat_dop2.SetImage(TutorialImg::imageeguat_trop0());
	tabMain.imageeguat_dop3.SetImage(TutorialImg::imageeguat_zsap0());
	tabMain.imageeguat_dop4.SetImage(TutorialImg::imageeguat_zsas0());
	tabMain.imageeguat_dop5.SetImage(TutorialImg::imageeguat_vm0());
	tabMain.imageeguat_dop6.SetImage(TutorialImg::imageeguat_shum0());
	
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
	// файл с путями
	PathIni Pathini_ob;
	Pathini_ob = ParsePath("Path.ini");
	tabPath.pathSP3 <<= Pathini_ob.pathSP3;
	tabPath.pathJPS <<= Pathini_ob.pathJPS;
	tabPath.btnOverWrite.WhenPush = THISBACK(OverWritePathIni);
}
void TestGui::TabManScreen(){
	tabMan.image_logo.SetImage(TutorialImg::logo_obsh());

}
