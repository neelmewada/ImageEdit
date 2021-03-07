#include "cHeaderField.h"

#include "../include.h"

cHeaderField::cHeaderField(wxWindow* parent, wxWindowID winid, const wxString& label, const wxRect& padding) : wxStaticText(parent, winid, label)
{
	wxSize size = GetSize();
	size.x -= padding.x + padding.width;
	size.y -= padding.y + padding.height;
	wxPoint pos = GetPosition();
	pos.x += padding.x;
	pos.y += padding.y;

	SetPosition(pos);
	SetSize(size);
	
	wxFont font = GetFont();
	font.SetPointSize(12);
	font.Bold();
	SetFont(font);
}

cHeaderField::~cHeaderField()
{
}
