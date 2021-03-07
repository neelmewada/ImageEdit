#pragma once

#include <wx/wx.h>
#include "include.h"


class cImagePanel : public wxPanel
{
public:
	cImagePanel(wxFrame* parent, wxWindowID windid, wxString file, wxBitmapType format, const wxSize minSize);
	~cImagePanel();

private:
	wxString m_fileName;
	wxBitmapType m_format;
	wxFrame* m_parent;

	wxPoint m_imagePos;
	wxRect m_imageMargin;

public:
	wxBitmap bitmap;
	wxImage image;

public:
	wxBitmapType GetCurrentFormat();
	bool SaveFileToPath(wxString path);
	bool LoadImageFromPath(wxString path);
	bool IsImageLoaded();

	void SetImageMargin(int left, int top, int right, int bottom);
	void paintEvent(wxPaintEvent& evt);
	void paintNow();
	void RefreshImage();

	void render(wxDC& dc);
	void OnResize(wxSizeEvent& evt);

private:
	void Resize();

	DECLARE_EVENT_TABLE()
};

