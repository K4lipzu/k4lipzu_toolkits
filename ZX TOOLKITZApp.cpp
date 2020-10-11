//---------------------------------------------------------------------------
//
// Name:        ZX TOOLKITZApp.cpp
// Author:      ZUDO X
// Created:     5/7/2019 5:41:14 AM
// Description: 
//
//---------------------------------------------------------------------------

#include "ZX TOOLKITZApp.h"
#include "ZX TOOLKITZFrm.h"

IMPLEMENT_APP(ZX_TOOLKITZFrmApp)

bool ZX_TOOLKITZFrmApp::OnInit()
{
    ZX_TOOLKITZFrm* frame = new ZX_TOOLKITZFrm(NULL);
    SetTopWindow(frame);
    frame->Show();
    return true;
}
 
int ZX_TOOLKITZFrmApp::OnExit()
{
	return 0;
}
