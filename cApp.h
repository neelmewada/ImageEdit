#pragma once

#include "include.h"
#include <wx/wx.h>
#include "cMainFrame.h"

class cApp : public wxApp
{
public:
	cApp();
	~cApp();

private:
	cMainFrame* m_frame1;

public:
	virtual bool OnInit();
};

DECLARE_APP(cApp)
