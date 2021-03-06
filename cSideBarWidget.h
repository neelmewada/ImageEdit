#pragma once

#include <wx/wx.h>
#include "cSidePanel.h"
#include "include.h"

class cSideBarWidget : public wxPanel
{
public:
	cSideBarWidget(cSidePanel* parent, wxString title, cImagePanel* imagePanel, wxWindowID winid, const wxSize minSize, const wxRect margin);
	~cSideBarWidget();

protected:
	cSidePanel* m_parent;
	cImagePanel* m_imagePanel;
	wxStaticText* m_titleText;
	wxTextCtrl* m_textInput;

public:
	wxString title;

public:
	virtual void OnResize(wxSizeEvent& evt);
	void OnPaint(wxPaintEvent& evt);
	void Render(wxDC& dc);
	void OnApplyEffect(wxCommandEvent& evt);

	virtual int GetWidgetHeight();
	virtual void ApplyEffect(wxBitmap& bitmap, wxImage& image);

	DECLARE_EVENT_TABLE()
};

