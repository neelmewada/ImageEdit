#pragma once

#include <wx/wx.h>

class cFloatField : public wxPanel
{
public:
	cFloatField(wxWindow* parent, wxWindowID winid, const wxString& label, const wxRect& padding, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
	~cFloatField();
};

