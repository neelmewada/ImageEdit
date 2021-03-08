#include "cIntField.h"
#include <wx/valnum.h>

BEGIN_EVENT_TABLE(cIntField, wxPanel)
EVT_SIZE(cIntField::OnResize)
EVT_PAINT(cIntField::OnPaint)
END_EVENT_TABLE()

cIntField::cIntField(wxWindow* parent, wxWindowID winid, const wxString& label, const int &defaultValue, const wxRect& padding, const wxPoint& pos, const wxSize& size)
	: wxPanel(parent, winid, pos, size)
{
	wxPoint _pos = GetPosition();
	wxSize _size = GetSize();

	m_mainSizer = new wxBoxSizer(wxHORIZONTAL);

	m_label = new wxStaticText(this, winid, label, wxPoint(0, 0), wxSize(_size.x / 3, 20));

	m_textInput = new wxTextCtrl(this, wxID_ANY, wxString(std::to_string(defaultValue)), wxPoint(0 + _size.x / 3, 0), wxSize(_size.x * 2 / 3 - 10, 20));
	m_textInput->SetValidator(wxIntegerValidator<int>());

	m_mainSizer->Add(m_label, 1, wxEXPAND);
	m_mainSizer->Add(m_textInput, 2, wxEXPAND);

	SetSizerAndFit(m_mainSizer);
}

cIntField::~cIntField()
{
}

int cIntField::GetValue()
{
	return std::stoi(m_textInput->GetValue().ToStdString());
}

void cIntField::Resize()
{

}

void cIntField::OnPaint(wxPaintEvent& evt)
{

}

void cIntField::OnResize(wxSizeEvent& evt)
{

}