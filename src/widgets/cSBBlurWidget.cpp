#include "cSBBlurWidget.h"
#include <wx/valnum.h>

#include "../utils.h"

cSBBlurWidget::cSBBlurWidget(cSidePanel* sidePanel, cImagePanel* imagePanel, wxSize minSize) : 
	cSideBarWidget(sidePanel, "Gaussian Blur", imagePanel, wxID_ANY, minSize)
{
	m_parent = sidePanel;
	m_imagePanel = imagePanel;
	this->title = title;

	wxPoint pos = GetPosition();
	wxSize size = GetClientSize();
	
	m_blurAmtInput = new cFloatField(this, wxID_ANY, "Amount", wxRect(10, 5, 10, 5), wxPoint(10, 35), wxSize(size.x - 10, 20));
	m_blurRadiusInput = new cIntField(this, wxID_ANY, "Radius", 7, wxRect(10, 5, 10, 5), wxPoint(10, 60), wxSize(size.x - 10, 20));
	
	wxButton* btn = new wxButton(this, 15001, "Apply", wxPoint(10, 90), wxSize(size.x - 20, 30));

	m_mainSizer->Add(m_blurAmtInput, 1, wxEXPAND);
	m_mainSizer->Add(m_blurRadiusInput, 1, wxEXPAND);
	m_mainSizer->Add(btn, 1, wxEXPAND);
	m_mainSizer->SetMinSize(wxSize(size.x, GetWidgetHeight()));

	SetSizerAndFit(m_mainSizer);
	Refresh();
}

cSBBlurWidget::~cSBBlurWidget()
{
	
}

int cSBBlurWidget::GetWidgetHeight()
{
	return 130;
}

bool cSBBlurWidget::ApplyEffect(wxImage& image)
{
	float value = m_blurAmtInput->GetValue();
	int radius = m_blurRadiusInput->GetValue();
	if (radius % 2 == 0)
	{
		wxMessageBox("Blur Radius should be an odd number!");
		return false;
	}

	Mat mat = mat_from_wx(image);
	Mat matBlur;
	GaussianBlur(mat, matBlur, Size(radius, radius), value, 0);
	image = wx_from_mat(matBlur);

	return true;
}
