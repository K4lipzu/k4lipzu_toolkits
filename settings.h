///-----------------------------------------------------------------
///
/// @file      settings.h
/// @author    NULLZKR
/// Created:   11/19/2019 3:38:28 AM
/// @section   DESCRIPTION
///            settings class declaration
///
///------------------------------------------------------------------

#ifndef __SETTINGS_H__
#define __SETTINGS_H__

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
#include <wx/combobox.h>
#include <wx/button.h>
#include <wx/listbox.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/notebook.h>
#include <wx/panel.h>
////Header Include End

////Dialog Style Start
#undef settings_STYLE
#define settings_STYLE wxCAPTION | wxSYSTEM_MENU | wxCLOSE_BOX | wxFRAME_FLOAT_ON_PARENT
////Dialog Style End

class settings : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		settings(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Untitled1"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = settings_STYLE);
		virtual ~settings();
		void settingsActivate(wxActivateEvent& event);
		void WxComboBox1Selected(wxCommandEvent& event );
		void WxListBox2Selected(wxCommandEvent& event);
		void WxButton3Click(wxCommandEvent& event);
		void WxButton4Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxButton *WxButton6;
		wxPanel *WxNoteBookPage3;
		wxButton *WxButton5;
		wxTextCtrl *WxEdit2;
		wxButton *WxButton4;
		wxListBox *WxListBox2;
		wxComboBox *WxComboBox1;
		wxButton *WxButton3;
		wxPanel *WxNoteBookPage2;
		wxButton *WxButton2;
		wxButton *WxButton1;
		wxListBox *WxListBox1;
		wxTextCtrl *WxEdit1;
		wxStaticBox *WxStaticBox1;
		wxPanel *WxNoteBookPage1;
		wxNotebook *WxNotebook1;
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
			ID_WXBUTTON6 = 1028,
			ID_WXNOTEBOOKPAGE3 = 1005,
			ID_WXBUTTON5 = 1027,
			ID_WXEDIT2 = 1026,
			ID_WXBUTTON4 = 1025,
			ID_WXLISTBOX2 = 1024,
			ID_WXCOMBOBOX1 = 1023,
			ID_WXBUTTON3 = 1022,
			ID_WXNOTEBOOKPAGE2 = 1004,
			ID_WXBUTTON2 = 1018,
			ID_WXBUTTON1 = 1017,
			ID_WXLISTBOX1 = 1016,
			ID_WXEDIT1 = 1014,
			ID_WXSTATICBOX1 = 1012,
			ID_WXNOTEBOOKPAGE1 = 1003,
			ID_WXNOTEBOOK1 = 1002,
			ID_WXPANEL1 = 1001,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
