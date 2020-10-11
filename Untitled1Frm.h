///-----------------------------------------------------------------
///
/// @file      Untitled1Frm.h
/// @author    NULLZKR
/// Created:   5/12/2019 4:29:29 AM
/// @section   DESCRIPTION
///            Untitled1Frm class declaration
///
///------------------------------------------------------------------

#ifndef __UNTITLED1FRM_H__
#define __UNTITLED1FRM_H__

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
#include <wx/filedlg.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/combobox.h>
#include <wx/statbox.h>
#include <wx/panel.h>
////Header Include End

////Dialog Style Start
#undef Untitled1Frm_STYLE
#define Untitled1Frm_STYLE wxCAPTION | wxSYSTEM_MENU | wxSTAY_ON_TOP | wxCLOSE_BOX | wxFRAME_SHAPED
////Dialog Style End

class Untitled1Frm : public wxFrame
{
	private:
		DECLARE_EVENT_TABLE();
		
	public:
		Untitled1Frm(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Untitled1"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = Untitled1Frm_STYLE);
		virtual ~Untitled1Frm();
		void WxButton1Click(wxCommandEvent& event);
		void CREATEClick(wxCommandEvent& event);
		void Untitled1FrmActivate(wxActivateEvent& event);
		void WxButton1Click0(wxCommandEvent& event);
		void WxButton2Click(wxCommandEvent& event);
		
	private:
		//Do not add custom control declarations between
		//GUI Control Declaration Start and GUI Control Declaration End.
		//wxDev-C++ will remove them. Add custom code after the block.
		////GUI Control Declaration Start
		wxFileDialog *WxOpenFileDialog1;
		wxStaticText *WxStaticText2;
		wxStaticText *WxStaticText3;
		wxStaticText *WxStaticText1;
		wxButton *WxButton2;
		wxTextCtrl *WxEdit1;
		wxButton *WxButton1;
		wxStaticBox *WxStaticBox3;
		wxComboBox *WxComboBox1;
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
			ID_WXSTATICTEXT2 = 13,
			ID_WXSTATICTEXT3 = 12,
			ID_WXSTATICTEXT1 = 9,
			ID_WXBUTTON2 = 8,
			ID_WXEDIT1 = 7,
			ID_WXBUTTON1 = 6,
			ID_WXSTATICBOX3 = 5,
			ID_WXCOMBOBOX1 = 4,
			ID_WXSTATICBOX2 = 3,
			ID_WXSTATICBOX1 = 2,
			ID_WXPANEL1 = 1,
			////GUI Enum Control ID End
			ID_DUMMY_VALUE_ //don't remove this value unless you have other enum values
		};
		
	private:
		void OnClose(wxCloseEvent& event);
		void CreateGUIControls();
};

#endif
