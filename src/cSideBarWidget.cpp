#include "cSideBarWidget.h"
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
	wxSize _size = size;
	size.y = GetWidgetHeight();

	SetPosition(pos);
	SetClientSize(size);

	SetBackgroundColour(wxColour(242, 242, 242));

	m_mainSizer = new wxBoxSizer(wxVERTICAL);
	m_mainSizer->SetMinSize(_size);

	m_headerField = new cHeaderField(this, wxID_ANY, title, wxRect(10, 5, 10, 5));

	m_mainSizer->Add(m_headerField, 0, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 0);

	//SetSizerAndFit(m_mainSizer);
}

cSideBarWidget::~cSideBarWidget()
{
}

void cSideBarWidget::AddSizerElement(wxWindow* element, int proportion, int flag, int border)
{
	m_mainSizer->Add(element, proportion, flag, border);

	SetSizerAndFit(m_mainSizer);
}

bool cSideBarWidget::ApplyEffect(wxImage &image)
{
	return true;
}

void cSideBarWidget::OnApplyEffect(wxCommandEvent &evt)
{
	if (m_imagePanel->image.IsOk() && m_imagePanel->bitmap.IsOk())
	{
		ApplyEffect(m_imagePanel->image);
		m_imagePanel->RefreshImage();
	}
	
	Refresh();
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
	const wxPen pen = wxPen(wxColour(200, 200, 200), 1);
	dc.SetPen(pen);

	wxSize size = GetSize();
	dc.DrawLine(wxPoint(0, 0), wxPoint(0, size.y));
	dc.DrawLine(wxPoint(0, 0), wxPoint(size.x, 0));
	dc.DrawLine(wxPoint(0, size.y - 1), wxPoint(size.x, size.y - 1));
	dc.DrawLine(wxPoint(size.x - 1, 0), wxPoint(size.x - 1, size.y));
}
