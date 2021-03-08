#pragma once

#include <wx/wx.h>

class cFloatField : public wxPanel
{
public:
	cFloatField(wxWindow* parent, wxWindowID winid, const wxString& label, const wxRect& padding, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
	~cFloatField();

protected:
	wxStaticText* m_label;
	wxTextCtrl* m_textInput;
	wxBoxSizer* m_mainSizer;

	virtual void Resize();

public:
	float GetValue();

	void OnResize(wxSizeEvent &evt);
	void OnPaint(wxPaintEvent& evt);

	DECLARE_EVENT_TABLE()
};

