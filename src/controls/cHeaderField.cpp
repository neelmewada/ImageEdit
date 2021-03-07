#include "cHeaderField.h"

#include "../include.h"

cHeaderField::cHeaderField(wxWindow* parent, wxWindowID winid, const wxString& label, const wxRect& padding, const wxPoint& pos, const wxSize& size) :
	wxStaticText(parent, winid, label)
{
	wxSize _size = GetSize();
	_size.x -= padding.x + padding.width;
	_size.y -= padding.y + padding.height;
	wxPoint _pos = GetPosition();
	_pos.x += padding.x;
	_pos.y += padding.y;

	SetPosition(_pos);
	SetSize(_size);
	
	wxFont font = GetFont();
	font.SetPointSize(12);
	font.Bold();
	SetFont(font);
}

cHeaderField::~cHeaderField()
{
}
