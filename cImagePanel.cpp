#include "cImagePanel.h"

BEGIN_EVENT_TABLE(cImagePanel, wxPanel)
// some useful events
/*
 EVT_MOTION(cImagePanel::mouseMoved)
 EVT_LEFT_DOWN(cImagePanel::mouseDown)
 EVT_LEFT_UP(cImagePanel::mouseReleased)
 EVT_RIGHT_DOWN(cImagePanel::rightClick)
 EVT_LEAVE_WINDOW(cImagePanel::mouseLeftWindow)
 EVT_KEY_DOWN(cImagePanel::keyPressed)
 EVT_KEY_UP(cImagePanel::keyReleased)
 EVT_MOUSEWHEEL(cImagePanel::mouseWheelMoved)
 */

 // catch paint events
	EVT_PAINT(cImagePanel::paintEvent)
	EVT_SIZE(cImagePanel::OnResize)
END_EVENT_TABLE()


cImagePanel::cImagePanel(wxFrame* parent, wxWindowID windid, wxString file, wxBitmapType format, const wxSize size)
	: wxPanel(parent, windid, wxPoint(0, 0), size)
{
	m_fileName = file;
	m_format = format;
	m_parent = parent;
	
	if (m_fileName != wxEmptyString)
	{
		image = wxImage(m_fileName, m_format);
		bitmap = wxBitmap(image);
	}
}

cImagePanel::~cImagePanel()
{
}

void cImagePanel::RefreshImage()
{
	bitmap = wxBitmap(image);
	Refresh();
}

void cImagePanel::OnResize(wxSizeEvent &evt)
{
	if (!bitmap.IsOk())
		return;

	wxSize newSize = m_parent->GetClientSize();
	wxSize imageSize = bitmap.GetSize();

	m_imagePos = wxPoint(m_imageMargin.x + newSize.x / 2 - imageSize.x / 2 - m_imageMargin.width, 
		m_imageMargin.y + newSize.y / 2 - imageSize.y / 2 - m_imageMargin.height);
	Refresh();
}

void cImagePanel::paintEvent(wxPaintEvent& evt)
{
	wxPaintDC dc(this);
	render(dc);
}

void cImagePanel::paintNow()
{
	wxPaintDC dc(this);
	render(dc);
}

void cImagePanel::render(wxDC& dc)
{
	dc.DrawBitmap(bitmap, m_imagePos, false);
}

void cImagePanel::SetImageMargin(int left, int top, int right, int bottom)
{
	m_imageMargin = wxRect(left, top, right, bottom);
}

