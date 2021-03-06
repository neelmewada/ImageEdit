#pragma once

#include <wx/wx.h>
#include "cImagePanel.h"
#include "cSidePanel.h"

class cMainFrame : public wxFrame
{
public:
	cMainFrame();
	~cMainFrame();

private:
	wxToolBar* m_toolBar;
	wxMenuBar* m_menuBar;
	wxBoxSizer* m_sizer;

	cImagePanel* m_imagePanel;
	cSidePanel* m_sidePanel;

private:
	void OnMenuNew(wxCommandEvent& evt);
	void OnMenuOpen(wxCommandEvent& evt);
	void OnMenuSave(wxCommandEvent& evt);
	void OnMenuExit(wxCommandEvent& evt);

public:

	DECLARE_EVENT_TABLE()
};


