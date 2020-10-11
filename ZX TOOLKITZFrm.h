///-----------------------------------------------------------------
///
/// @file      ZX TOOLKITZFrm.h
/// @author    ZUDO X
/// Created:   5/7/2019 5:41:15 AM
/// @section   DESCRIPTION
///            ZX_TOOLKITZFrm class declaration
///
///------------------------------------------------------------------

#ifndef __ZX_TOOLKITZFRM_H__
#define __ZX_TOOLKITZFRM_H__

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
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/listbox.h>
#include <wx/statbox.h>
#include <wx/panel.h>
////Header Include End

////Dialog Style Start
#undef ZX_TOOLKITZFrm_STYLE
#define ZX_TOOLKITZFrm_STYLE wxCAPTION | wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX
////Dialog Style End

class ZX_TOOLKITZFrm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		ZX_TOOLKITZFrm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("ZX TOOLKITZ"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = ZX_TOOLKITZFrm_STYLE);
		virtual ~ZX_TOOLKITZFrm();
		void ZX_TOOLKITZFrmActivate(wxActivateEvent& event);
		void WxComboBox1Selected(wxCommandEvent& event );
		void WxListBox1DoubleClicked(wxCommandEvent& event);
		void WxButton1Click0(wxCommandEvent& event);
		void WxButton1Click(wxCommandEvent& event);
		void Mnuimporttools1008Click(wxCommandEvent& event);
		void Mnuoptions1010Click(wxCommandEvent& event);
		void Mnusettings1010Click(wxCommandEvent& event);
		void Mnuimporttools1008Click0(wxCommandEvent& event);
		void Mnusettings1010Click0(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxMenuBar *WxMenuBar1;
		wxStatusBar *WxStatusBar1;
		wxButton *WxButton1;
		wxComboBox *WxComboBox1;
		wxListBox *WxListBox1;
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
			ID_MNU_FILE_1007 = 1007,
			ID_MNU_IMPORTTOOLS_1008 = 1008,
			ID_MNU_OPTIONS_1009 = 1009,
			ID_MNU_SETTINGS_1010 = 1010,
			
			ID_WXSTATUSBAR1 = 1004,
			ID_WXBUTTON1 = 1006,
			ID_WXCOMBOBOX1 = 1005,
			ID_WXLISTBOX1 = 1003,
			ID_WXSTATICBOX1 = 1002,
			ID_WXPANEL1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
