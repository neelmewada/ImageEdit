#include "cFloatField.h"
#include <wx/valnum.h>

BEGIN_EVENT_TABLE(cFloatField, wxPanel)
	EVT_SIZE(cFloatField::OnResize)
	EVT_PAINT(cFloatField::OnPaint)
END_EVENT_TABLE()

cFloatField::cFloatField(wxWindow* parent, wxWindowID winid, const wxString& label, const wxRect& padding, const wxPoint &pos, const wxSize &size)
	: wxPanel(parent, winid, pos, size)
{
	wxPoint _pos = GetPosition();
	wxSize _size = GetSize();

	m_mainSizer = new wxBoxSizer(wxHORIZONTAL);

	m_label = new wxStaticText(this, winid, label, wxPoint(0, 0), wxSize(_size.x / 3, 20));

	m_textInput = new wxTextCtrl(this, wxID_ANY, "0", wxPoint(0 + _size.x / 3, 0), wxSize(_size.x * 2 / 3 - 10, 20));
	m_textInput->SetValidator(wxFloatingPointValidator<float>());

	m_mainSizer->Add(m_label, 1, wxEXPAND);
	m_mainSizer->Add(m_textInput, 2, wxEXPAND);

	SetSizerAndFit(m_mainSizer);
}

cFloatField::~cFloatField()
{
}

float cFloatField::GetValue()
{
	return std::stof(m_textInput->GetValue().ToStdString());
}

void cFloatField::Resize()
{
	
}

void cFloatField::OnPaint(wxPaintEvent& evt)
{
	
}

void cFloatField::OnResize(wxSizeEvent& evt)
{
	
}
