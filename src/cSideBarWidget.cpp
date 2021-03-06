#include "cSideBarWidget.h"
#include <wx/valnum.h>
#include <string>

#include "utils.h"

BEGIN_EVENT_TABLE(cSideBarWidget, wxPanel)
	EVT_SIZE(cSideBarWidget::OnResize)
	EVT_PAINT(cSideBarWidget::OnPaint)
	EVT_BUTTON(15001, cSideBarWidget::OnApplyEffect)
END_EVENT_TABLE()

cSideBarWidget::cSideBarWidget(cSidePanel* parent, wxString title, cImagePanel* imagePanel, wxWindowID winid, const wxSize minSize, const wxRect margin)
	: wxPanel(parent, winid, wxDefaultPosition, minSize)
{
	m_parent = parent;
	m_imagePanel = imagePanel;
	this->title = title;
	
	wxPoint pos = GetPosition();
	wxSize size = GetClientSize();

	pos += wxPoint(margin.x, margin.y);
	size -= wxSize(margin.width + margin.x, margin.height + margin.y);
	size.y = GetWidgetHeight();

	SetPosition(pos);
	SetClientSize(size);

	SetBackgroundColour(wxColour(200, 200, 200));

	m_titleText = new wxStaticText(this, wxID_ANY, title, wxPoint(10, 5), wxSize(size.x - 20, 30));
	wxFont font = m_titleText->GetFont();
	font.SetPointSize(12);
	font.Bold();
	m_titleText->SetFont(font);

	wxStaticText* amountLabel = new wxStaticText(this, wxID_ANY, "Amount", wxPoint(10, 35), wxSize(size.x / 3, 20));
	//amountLabel->Center();

	m_textInput = new wxTextCtrl(this, wxID_ANY, "0", wxPoint(10 + size.x / 3, 35), wxSize(size.x * 2 / 3 - 20, 20));
	m_textInput->SetValidator(wxFloatingPointValidator<float>());

	wxButton* btn = new wxButton(this, 15001, "Apply", wxPoint(10, 65), wxSize(size.x - 20, 30));
}

cSideBarWidget::~cSideBarWidget()
{
}

void cSideBarWidget::ApplyEffect(wxBitmap &bitmap, wxImage &image)
{
	Mat mat = mat_from_wx(image);
	Mat matBlur;
	GaussianBlur(mat, matBlur, Size(7, 7), 5, 0);
	image = wx_from_mat(matBlur);

	Refresh();
}

void cSideBarWidget::OnApplyEffect(wxCommandEvent &evt)
{
	ApplyEffect(m_imagePanel->bitmap, m_imagePanel->image);
	m_imagePanel->RefreshImage();
	
	evt.Skip();
}

int cSideBarWidget::GetWidgetHeight()
{
	return 105;
}

void cSideBarWidget::OnResize(wxSizeEvent& evt)
{
	Refresh();
}

void cSideBarWidget::OnPaint(wxPaintEvent& evt)
{
	wxPaintDC dc(this);
	Render(dc);
}

void cSideBarWidget::Render(wxDC& dc)
{
	const wxPen pen = wxPen(wxColour(100, 100, 100), 2);
	dc.SetPen(pen);

	wxSize size = GetSize();
	dc.DrawLine(wxPoint(0, 0), wxPoint(0, size.y));
	dc.DrawLine(wxPoint(0, 0), wxPoint(size.x, 0));
	dc.DrawLine(wxPoint(0, size.y), wxPoint(size.x, size.y));
	dc.DrawLine(wxPoint(size.x, 0), wxPoint(size.x, size.y));
}
