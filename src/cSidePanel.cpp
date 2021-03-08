#include "cSidePanel.h"

#include "widgets/cSBBlurWidget.h"

BEGIN_EVENT_TABLE(cSidePanel, wxPanel)
EVT_PAINT(cSidePanel::OnPaint)
END_EVENT_TABLE()

cSidePanel::cSidePanel(wxFrame* parent, cImagePanel* imagePanel, wxWindowID winid, const wxSize minSize) : wxPanel(parent, winid, wxDefaultPosition, minSize)
{
	m_parent = parent;
	m_imagePanel = imagePanel;

	m_mainSizer = new wxBoxSizer(wxVERTICAL);
	cSBBlurWidget* widget = new cSBBlurWidget(this, m_imagePanel, minSize);

	m_mainSizer->Add(widget, 0, wxEXPAND | wxTOP | wxLEFT | wxRIGHT, 20);
	//m_mainSizer->Add(widget2, 0, wxEXPAND | wxALL, 20);

	SetSizerAndFit(m_mainSizer);
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
	
	const wxPen pen = wxPen(wxColour(235, 235, 235), 4);
	dc.SetPen(pen);

	dc.DrawLine(wxPoint(0, 0), wxPoint(0, size.y));
}