#pragma once

#include <wx/wx.h>

class cIntField : public wxPanel
{
public:
	cIntField(wxWindow* parent, wxWindowID winid, const wxString& label, const int& defaultValue, const wxRect& padding, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
	~cIntField();

protected:
	wxStaticText* m_label;
	wxTextCtrl* m_textInput;
	wxBoxSizer* m_mainSizer;

	virtual void Resize();

public:
	int
		GetValue();

	void OnResize(wxSizeEvent& evt);
	void OnPaint(wxPaintEvent& evt);

	DECLARE_EVENT_TABLE()
};