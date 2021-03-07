#include "cSBBlurWidget.h"
#include <wx/valnum.h>

#include "../utils.h"

cSBBlurWidget::cSBBlurWidget(cSidePanel* sidePanel, cImagePanel* imagePanel, wxSize minSize) : 
	cSideBarWidget(sidePanel, "Blur", imagePanel, wxID_ANY, minSize)
{
	m_parent = sidePanel;
	m_imagePanel = imagePanel;
	this->title = title;

	wxPoint pos = GetPosition();
	wxSize size = GetClientSize();

	wxStaticText* amountLabel = new wxStaticText(this, wxID_ANY, "Amount", wxPoint(10, 35), wxSize(size.x / 3, 20));

	m_textInput = new wxTextCtrl(this, wxID_ANY, "0", wxPoint(10 + size.x / 3, 35), wxSize(size.x * 2 / 3 - 20, 20));
	m_textInput->SetValidator(wxFloatingPointValidator<float>());

	wxButton* btn = new wxButton(this, 15001, "Apply", wxPoint(10, 65), wxSize(size.x - 20, 30));
}

cSBBlurWidget::~cSBBlurWidget()
{
}

int cSBBlurWidget::GetWidgetHeight()
{
	return 105;
}

bool cSBBlurWidget::ApplyEffect(wxImage& image)
{
	Mat mat = mat_from_wx(image);
	Mat matBlur;
	GaussianBlur(mat, matBlur, Size(7, 7), 7, 0);
	image = wx_from_mat(matBlur);

	return true;
}
