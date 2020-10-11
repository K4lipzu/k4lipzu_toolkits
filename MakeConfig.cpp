///-----------------------------------------------------------------
///
/// @file      MakeConfig.cpp
/// @author    ZUDO X
/// Created:   5/8/2019 5:32:27 AM
/// @section   DESCRIPTION
///            MakeConfig class implementation
///
///------------------------------------------------------------------

#include "MakeConfig.h"
#include <iostream>
#include <fstream>

using namespace std;
//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

//----------------------------------------------------------------------------
// MakeConfig
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(MakeConfig,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(MakeConfig::OnClose)
	EVT_ACTIVATE(MakeConfig::MakeConfigActivate)
	EVT_BUTTON(ID_WXBUTTON2,MakeConfig::WxButton2Click)
	EVT_RADIOBUTTON(ID_WXRADIOBUTTON2,MakeConfig::WxRadioButton2Click)
	EVT_RADIOBUTTON(ID_WXRADIOBUTTON1,MakeConfig::WxRadioButton1Click)
END_EVENT_TABLE()
////Event Table End

MakeConfig::MakeConfig(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

MakeConfig::~MakeConfig()
{
}

void MakeConfig::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(0, 0), wxSize(716, 170));

	WxStaticBox1 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX1, _(""), wxPoint(4, 4), wxSize(232, 159));

	WxStaticBox2 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX2, _("SOURCE"), wxPoint(12, 22), wxSize(214, 48));

	WxStaticBox3 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX3, _("TARGET"), wxPoint(11, 90), wxSize(214, 50));

	WxStaticBox4 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX4, _(""), wxPoint(240, 4), wxSize(271, 159));

	WxRadioButton1 = new wxRadioButton(WxPanel1, ID_WXRADIOBUTTON1, _("SINGLE EXE"), wxPoint(255, 15), wxSize(113, 17), 0, wxDefaultValidator, _("WxRadioButton1"));

	WxRadioButton2 = new wxRadioButton(WxPanel1, ID_WXRADIOBUTTON2, _("DOUBLE EXE"), wxPoint(408, 14), wxSize(90, 17), 0, wxDefaultValidator, _("WxRadioButton2"));

	WxStaticBox5 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX5, _("TARGET EXE FILE"), wxPoint(253, 36), wxSize(243, 84));

	WxButton1 = new wxButton(WxPanel1, ID_WXBUTTON1, _("CANCEL"), wxPoint(421, 129), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));

	WxButton2 = new wxButton(WxPanel1, ID_WXBUTTON2, _("CREATE"), wxPoint(333, 129), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton2"));

	WxEdit1 = new wxTextCtrl(WxPanel1, ID_WXEDIT1, _(""), wxPoint(262, 59), wxSize(156, 19), 0, wxDefaultValidator, _("WxEdit1"));

	WxButton3 = new wxButton(WxPanel1, ID_WXBUTTON3, _("Browse"), wxPoint(426, 57), wxSize(64, 25), 0, wxDefaultValidator, _("WxButton3"));

	WxEdit2 = new wxTextCtrl(WxPanel1, ID_WXEDIT2, _(""), wxPoint(263, 90), wxSize(155, 19), 0, wxDefaultValidator, _("WxEdit2"));

	WxButton4 = new wxButton(WxPanel1, ID_WXBUTTON4, _("Browse"), wxPoint(425, 86), wxSize(65, 25), 0, wxDefaultValidator, _("WxButton4"));

	WxEdit3 = new wxTextCtrl(WxPanel1, ID_WXEDIT3, _(""), wxPoint(21, 42), wxSize(134, 19), 0, wxDefaultValidator, _("WxEdit3"));

	WxButton5 = new wxButton(WxPanel1, ID_WXBUTTON5, _("Browse"), wxPoint(160, 39), wxSize(60, 25), 0, wxDefaultValidator, _("WxButton5"));

	WxEdit4 = new wxTextCtrl(WxPanel1, ID_WXEDIT4, _(""), wxPoint(18, 111), wxSize(136, 19), 0, wxDefaultValidator, _("WxEdit4"));

	WxButton6 = new wxButton(WxPanel1, ID_WXBUTTON6, _("Browse"), wxPoint(160, 107), wxSize(59, 25), 0, wxDefaultValidator, _("WxButton6"));

	WxEdit5 = new wxTextCtrl(WxPanel1, ID_WXEDIT5, _(""), wxPoint(525, 9), wxSize(164, 149), wxTE_MULTILINE, wxDefaultValidator, _("WxEdit5"));

	SetTitle(_("MakeConfig"));
	SetIcon(wxNullIcon);
	SetSize(8,8,726,200);
	Center();
	
	////GUI Items Creation End
}

void MakeConfig::OnClose(wxCloseEvent& event)
{
	Destroy();
}



/*
 * WxRadioButton1Click
 */
void MakeConfig::WxRadioButton1Click(wxCommandEvent& event)
{
    WxEdit1->Enable(true);
    WxButton3->Enable(true);
    WxEdit2->Enable(false);
    WxButton4->Enable(false);
	// insert your code here
}

/*
 * MakeConfigActivate
 */
void MakeConfig::MakeConfigActivate(wxActivateEvent& event)
{
//    WxEdit1->Enable(false);
    WxEdit2->Enable(false);
    WxButton4->Enable(false);
//    WxButton3->Enable(false);
    WxRadioButton1->SetValue(true);
	// insert your code here
}

/*
 * WxRadioButton2Click
 */
void MakeConfig::WxRadioButton2Click(wxCommandEvent& event)
{
    WxEdit1->Enable(true);
    WxEdit2->Enable(true);
    WxButton4->Enable(true);
    WxButton3->Enable(true);
	// insert your code here
}

/*
 * WxButton2Click
 */
void MakeConfig::WxButton2Click(wxCommandEvent& event)
{
    ofstream config;
    config.open("CONFIG.CMD");
    config << WxEdit5->GetValue();
    config.close();
	// insert your code here
}
