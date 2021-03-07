#pragma once

#include <wx/wx.h>

class cHeaderField : public wxStaticText
{
public:
	cHeaderField(wxWindow* parent, wxWindowID winid, const wxString& label, const wxRect& padding, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
	~cHeaderField();

private:

public:

};

