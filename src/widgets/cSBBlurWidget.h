#pragma once

#include <wx/wx.h>
#include "../cImagePanel.h"
#include "../cSidePanel.h"
#include "../cSideBarWidget.h"
#include "../include.h"

class cSBBlurWidget : public cSideBarWidget
{
public:
	cSBBlurWidget(cSidePanel* sidePanel, cImagePanel* imagePanel, wxSize minSize);
	~cSBBlurWidget();

protected:
	cSidePanel* m_parent;
	cImagePanel* m_imagePanel;
	cHeaderField* m_headerField;
	wxTextCtrl* m_textInput;

public:
	wxString title;

public:
	virtual int GetWidgetHeight();
	virtual bool ApplyEffect(wxImage& image);
};

