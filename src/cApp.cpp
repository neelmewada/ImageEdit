#include "cApp.h"

IMPLEMENT_APP(cApp)

cApp::cApp()
{
	
}

cApp::~cApp()
{
	
}

bool cApp::OnInit()
{
	wxInitAllImageHandlers();

	m_frame1 = new cMainFrame();
	m_frame1->Show();
	return true;
}
