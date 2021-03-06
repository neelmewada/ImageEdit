#pragma once

#include <wx/wx.h>
#include "include.h"
#include "cImagePanel.h"


class cSidePanel : public wxPanel
{
public:
	cSidePanel(wxFrame* parent, cImagePanel* imagePanel, wxWindowID winid, const wxSize minSize);
	~cSidePanel();

private:
	wxFrame* m_parent;
	cImagePanel* m_imagePanel;
	wxBoxSizer* m_mainSizer;

public:
	void OnPaint(wxPaintEvent& evt);
	void PaintNow();
	void Render(wxDC& dc);
	
	DECLARE_EVENT_TABLE()
};

