#ifndef _TestGui_MapDlg_h_
#define _TestGui_MapDlg_h_

struct MapImage : public Ctrl {
	Image  map;
	String error;
	Point  home;
	
	Callback1<Point> WhenLeftClick;
	
	virtual void LeftDown(Point p, dword)
	{
		WhenLeftClick(p);
	}
	
	virtual void Paint(Draw& w) {
		Size sz = GetSize();
		w.DrawRect(sz, SColorPaper());
		if(IsNull(map))
			w.DrawText(0, 0, error);
		else {
			w.DrawImage(0, 0, map);
			Point p = TutorialImg::Pin().GetHotSpot();
			w.DrawImage(home.x - p.x, home.y - p.y, TutorialImg::Pin());
		}
	}
	
	MapImage() { SetFrame(ViewFrame()); BackPaint(); }
};

struct MapDlgDlg : public WithTabMapLayout<TopWindow> {
	typedef MapDlgDlg CLASSNAME;

	Pointf   home;
	Pointf   center;
	MapImage map;
	
	void LoadMap();
	void SetHome();
	void MapClick(Point p);
	
	void ZoomIn();
	void ZoomOut();
	void Move(int x, int y);
	
	void   Set(Pointf p);
	Pointf Get() { return home; }
	
	MapDlgDlg();
};

void   SetGoogleMapsKey(const char *key);
String GetGoogleMap(double center_x, double center_y, int zoom, int cx, int cy,
                    const char *format = "png", String *error = NULL);
Image  GetGoogleMapImage(double center_x, double center_y, int zoom, int cx, int cy,
                         const char *format = "png", String *error = NULL);
double CvDeg(double deg, double minutes, double seconds);

Pointf GoogleMapsPixelToGps(Pointf center, int zoom, Point diff);
Pointf GoogleMapsPixelToGps(Pointf center, int zoom, Size sz, Point p);
Pointf GoogleMapsGpsToPixelDiff(Pointf center, int zoom, Pointf gps);
Pointf GoogleMapsGpsToPixel(Pointf center, int zoom, Size sz, Pointf gps);

Pointf ScanGPS(const char *s);

String FormatGPSX(double x);
String FormatGPSY(double y);
String FormatGPS(Pointf p);

bool MapDlg(Pointf& p);

#endif
