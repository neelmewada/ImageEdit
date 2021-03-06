
#include "cMainFrame.h"
#include "include.h"


BEGIN_EVENT_TABLE(cMainFrame, wxFrame)
	//EVT_MENU(MENU_FILE_NEW_ID, cMainFrame::OnMenuNew)
	EVT_MENU(MENU_FILE_OPEN_ID, cMainFrame::OnMenuOpen)
	EVT_MENU(MENU_FILE_SAVE_ID, cMainFrame::OnMenuSave)
	EVT_MENU(MENU_FILE_EXIT_ID, cMainFrame::OnMenuExit)
END_EVENT_TABLE()


cMainFrame::cMainFrame() : wxFrame(nullptr, wxID_ANY, "ImageEdit", wxPoint(30, 30), DEFAULT_WIN_SIZE)
{
	this->m_backgroundColour = wxColour("white");
	
	m_menuBar = new wxMenuBar();
	SetMenuBar(m_menuBar);

	wxMenu* menuFile = new wxMenu;
	//menuFile->Append(MENU_FILE_NEW_ID, "New");
	menuFile->Append(MENU_FILE_OPEN_ID, "Open");
	menuFile->Append(MENU_FILE_SAVE_ID, "Save");
	menuFile->Append(MENU_FILE_EXIT_ID, "Exit");

	m_menuBar->Append(menuFile, "File");
	
	m_imagePanel = new cImagePanel(this, IMAGEPANEL_ID, "C:\\lambo.png", wxBITMAP_TYPE_PNG, DEFAULT_WIN_SIZE);
	m_sidePanel = new cSidePanel(this, m_imagePanel, SIDEPANEL_ID, wxSize(SIDEPANEL_WIDTH, 100));

	m_sidePanel->SetBackgroundColour(wxColour(255, 255, 255));
	m_imagePanel->SetImageMargin(0, 0, SIDEPANEL_WIDTH / 2, 0);

	m_sizer = new wxBoxSizer(wxHORIZONTAL);
	m_sizer->Add(m_imagePanel, 1, wxEXPAND);
	m_sizer->Add(m_sidePanel, 0, wxEXPAND);

	SetSizerAndFit(m_sizer);
}

cMainFrame::~cMainFrame() 
{

}

void cMainFrame::OnMenuNew(wxCommandEvent& evt)
{
	evt.Skip();
}

void cMainFrame::OnMenuOpen(wxCommandEvent& evt)
{
}

void cMainFrame::OnMenuSave(wxCommandEvent& evt)
{
}

void cMainFrame::OnMenuExit(wxCommandEvent& evt)
{
	Close();
	evt.Skip();
}
