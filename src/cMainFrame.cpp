
#include "cMainFrame.h"
#include "include.h"
#include <wx/wfstream.h>


BEGIN_EVENT_TABLE(cMainFrame, wxFrame)
	//EVT_MENU(MENU_FILE_NEW_ID, cMainFrame::OnMenuNew)
	EVT_MENU(MENU_FILE_OPEN_ID, cMainFrame::OnMenuOpen)
	EVT_MENU(MENU_FILE_SAVE_ID, cMainFrame::OnMenuSave)
	EVT_MENU(MENU_FILE_SAVEAS_ID, cMainFrame::OnMenuSaveAs)
	EVT_MENU(MENU_FILE_EXIT_ID, cMainFrame::OnMenuExit)
END_EVENT_TABLE()


cMainFrame::cMainFrame() : wxFrame(nullptr, wxID_ANY, "ImageEdit", wxPoint(30, 30), DEFAULT_WIN_SIZE)
{
	this->m_backgroundColour = wxColour("white");

	Maximize();

	m_menuBar = new wxMenuBar();
	SetMenuBar(m_menuBar);

	wxMenu* menuFile = new wxMenu;
	//menuFile->Append(MENU_FILE_NEW_ID, "New");
	menuFile->Append(MENU_FILE_OPEN_ID, "Open");
	menuFile->Append(MENU_FILE_SAVE_ID, "Save");
	menuFile->Append(MENU_FILE_SAVEAS_ID, "Save As");
	menuFile->Append(MENU_FILE_EXIT_ID, "Exit");

	m_menuBar->Append(menuFile, "File");
	
	m_imagePanel = new cImagePanel(this, IMAGEPANEL_ID, "", wxBITMAP_TYPE_PNG, DEFAULT_WIN_SIZE);
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
	wxFileDialog* dialog = new wxFileDialog(this, "Open an Image...", "", "", "Image files (*.png;*.jpg)|*.png;*.jpg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
	if (dialog->ShowModal() == wxID_CANCEL)
	{
		evt.Skip();
		return;
	}

	wxString fileName = dialog->GetPath();
	m_imagePanel->LoadImageFromPath(fileName);

	evt.Skip();
}

void cMainFrame::OnMenuSave(wxCommandEvent& evt)
{
	if (m_currentSavePath != wxEmptyString)
	{
		m_imagePanel->bitmap.SaveFile(m_currentSavePath, m_imagePanel->GetCurrentFormat());
		return;
	}

	wxFileDialog* dialog = new wxFileDialog(this, "Save the Image...", "", "", "Image files (*.png;*.jpg)|*.png;*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (dialog->ShowModal() == wxID_CANCEL)
	{
		evt.Skip();
		return;
	}

	wxString filePath = dialog->GetPath();
	wxFileOutputStream outputStream(filePath);
	if (!outputStream.IsOk())
	{
		wxLogError("Cannot save current contents in file '%s'.", filePath);
		evt.Skip();
		return;
	}

	m_currentSavePath = filePath;
	m_imagePanel->bitmap.SaveFile(filePath, m_imagePanel->GetCurrentFormat());
}

void cMainFrame::OnMenuSaveAs(wxCommandEvent& evt)
{
	wxFileDialog* dialog = new wxFileDialog(this, "Save the Image...", m_currentSavePath, "", "Image files (*.png;*.jpg)|*.png;*.jpg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	if (dialog->ShowModal() == wxID_CANCEL)
	{
		evt.Skip();
		return;
	}

	wxString filePath = dialog->GetPath();
	wxFileOutputStream outputStream(filePath);
	if (!outputStream.IsOk())
	{
		wxLogError("Cannot save current contents in file '%s'.", filePath);
		evt.Skip();
		return;
	}

	m_currentSavePath = filePath;
	m_imagePanel->bitmap.SaveFile(filePath, m_imagePanel->GetCurrentFormat());
}

void cMainFrame::OnMenuExit(wxCommandEvent& evt)
{
	Close();
	evt.Skip();
}
