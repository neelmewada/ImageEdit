#include "cSidePanel.h"
#include "cSideBarWidget.h"

BEGIN_EVENT_TABLE(cSidePanel, wxPanel)
EVT_PAINT(cSidePanel::OnPaint)
END_EVENT_TABLE()

cSidePanel::cSidePanel(wxFrame* parent, cImagePanel* imagePanel, wxWindowID winid, const wxSize minSize) : wxPanel(parent, winid, wxDefaultPosition, minSize)
{
	m_parent = parent;
	m_imagePanel = imagePanel;

	m_mainSizer = new wxBoxSizer(wxVERTICAL);
	cSideBarWidget* widget = new cSideBarWidget(this, "Blur", m_imagePanel, wxID_ANY, minSize, wxRect(20, 20, 20, 10));
	
	//SetSizerAndFit(m_mainSizer);
}

cSidePanel::~cSidePanel()
{
	
}


void cSidePanel::OnPaint(wxPaintEvent& evt)
{
	wxPaintDC dc(this);
	Render(dc);
}

void cSidePanel::PaintNow()
{
	wxPaintDC dc(this);
	Render(dc);
}

void cSidePanel::Render(wxDC& dc)
{
	wxPoint pos = GetPosition();
	wxSize size = GetSize();
	
	const wxPen pen = wxPen(wxColour(220, 220, 220), 4);
	dc.SetPen(pen);

	dc.DrawLine(wxPoint(0, 0), wxPoint(0, size.y));
}