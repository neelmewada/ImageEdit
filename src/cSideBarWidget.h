#pragma once

#include <wx/wx.h>
#include "cSidePanel.h"
#include "include.h"

#include "controls/cHeaderField.h"


class cSideBarWidget : public wxPanel
{
public:
	cSideBarWidget(cSidePanel* parent, wxString title, cImagePanel* imagePanel, wxWindowID winid, const wxSize minSize, const wxRect margin = wxRect());
	~cSideBarWidget();

protected:
	cSidePanel* m_parent;
	cImagePanel* m_imagePanel;
	cHeaderField* m_headerField;
	wxTextCtrl* m_textInput;

public:
	wxString title;

public:
	virtual void OnResize(wxSizeEvent& evt);
	void OnPaint(wxPaintEvent& evt);
	void Render(wxDC& dc);
	void OnApplyEffect(wxCommandEvent& evt);

	virtual int GetWidgetHeight();
	virtual bool ApplyEffect(wxImage& image);

	DECLARE_EVENT_TABLE()
};

