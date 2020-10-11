//---------------------------------------------------------------------------
//
// Name:        ZX TOOLKITZApp.h
// Author:      ZUDO X
// Created:     5/7/2019 5:41:14 AM
// Description: 
//
//---------------------------------------------------------------------------

#ifndef __ZX_TOOLKITZFRMApp_h__
#define __ZX_TOOLKITZFRMApp_h__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#else
	#include <wx/wxprec.h>
#endif

class ZX_TOOLKITZFrmApp : public wxApp
{
	public:
		bool OnInit();
		int OnExit();
};

#endif
