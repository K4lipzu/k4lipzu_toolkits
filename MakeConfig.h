///-----------------------------------------------------------------
///
/// @file      MakeConfig.h
/// @author    ZUDO X
/// Created:   5/8/2019 5:32:27 AM
/// @section   DESCRIPTION
///            MakeConfig class declaration
///
///------------------------------------------------------------------

#ifndef __MAKECONFIG_H__
#define __MAKECONFIG_H__

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include <wx/wx.h>
	#include <wx/frame.h>
#else
	#include <wx/wxprec.h>
#endif

//Do not add custom headers between 
//Header Include Start and Header Include End.
//wxDev-C++ designer will remove them. Add custom headers after the block.
////Header Include Start
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/radiobut.h>
#include <wx/statbox.h>
#include <wx/panel.h>
////Header Include End

////Dialog Style Start
#undef MakeConfig_STYLE
#define MakeConfig_STYLE wxCAPTION | wxSYSTEM_MENU | wxCLOSE_BOX
////Dialog Style End

class MakeConfig : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		MakeConfig(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("MakeConfig"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = MakeConfig_STYLE);
		void WxRadioButton1Click(wxCommandEvent& event);
		virtual ~MakeConfig();
		void MakeConfigActivate(wxActivateEvent& event);
		void WxRadioButton2Click(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
	
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxTextCtrl *WxEdit5;
		wxButton *WxButton6;
		wxTextCtrl *WxEdit4;
		wxButton *WxButton5;
		wxTextCtrl *WxEdit3;
		wxButton *WxButton4;
		wxTextCtrl *WxEdit2;
		wxButton *WxButton3;
		wxTextCtrl *WxEdit1;
		wxButton *WxButton2;
		wxButton *WxButton1;
		wxStaticBox *WxStaticBox5;
		wxRadioButton *WxRadioButton2;
		wxRadioButton *WxRadioButton1;
		wxStaticBox *WxStaticBox4;
		wxStaticBox *WxStaticBox3;
		wxStaticBox *WxStaticBox2;
		wxStaticBox *WxStaticBox1;
		wxPanel *WxPanel1;
		////GUI Control Declaration End
		
	private:
		//Note: if you receive any error with these enum IDs, then you need to
		//change your old form code that are based on the #define control IDs.
		//#defines may replace a numeric value for the enum names.
		//Try copy and pasting the below block in your old form header files.
		enum
		{
			////GUI Enum Control ID Start
			ID_WXEDIT5 = 1027,
			ID_WXBUTTON6 = 1025,
			ID_WXEDIT4 = 1024,
			ID_WXBUTTON5 = 1023,
			ID_WXEDIT3 = 1022,
			ID_WXBUTTON4 = 1021,
			ID_WXEDIT2 = 1020,
			ID_WXBUTTON3 = 1019,
			ID_WXEDIT1 = 1018,
			ID_WXBUTTON2 = 1017,
			ID_WXBUTTON1 = 1016,
			ID_WXSTATICBOX5 = 1015,
			ID_WXRADIOBUTTON2 = 1013,
			ID_WXRADIOBUTTON1 = 1012,
			ID_WXSTATICBOX4 = 1011,
			ID_WXSTATICBOX3 = 1010,
			ID_WXSTATICBOX2 = 1009,
			ID_WXSTATICBOX1 = 1008,
			ID_WXPANEL1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
