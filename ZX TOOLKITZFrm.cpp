///-----------------------------------------------------------------
///
/// @file      ZX TOOLKITZFrm.cpp
/// @author    ZUDO X
/// Created:   5/7/2019 5:41:15 AM
/// @section   DESCRIPTION
///            ZX_TOOLKITZFrm class implementation
///
///------------------------------------------------------------------

#include "ZX TOOLKITZFrm.h"
#include <wx/dir.h>
#include "Untitled1Frm.h"
#include "settings.h"
#include <cstdlib>
#include <iostream>



using namespace std;

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End
class wxDirectoriesEnumerator : public wxDirTraverser {
public:
    virtual bool OnInit();
    wxArrayString *dirs;
    wxArrayString *fils;
    wxDirectoriesEnumerator(wxArrayString* dirs_)  {
        dirs=dirs_;
        fils=dirs_;
    }
    //This function will be called when a file is found
    virtual wxDirTraverseResult OnFile(const wxString& filename) {
        //Do nothing, continue with the next file or directory
        fils->Add(filename);
        return wxDIR_CONTINUE;
    }
    //This function will be called when a directory is found
    virtual wxDirTraverseResult OnDir(const wxString& dirname) {
        //Add the directory to the results
        dirs->Add(dirname);
        //Do NOT enter this directory
        return wxDIR_IGNORE;
    }
};
//----------------------------------------------------------------------------
// ZX_TOOLKITZFrm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(ZX_TOOLKITZFrm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(ZX_TOOLKITZFrm::OnClose)
	EVT_ACTIVATE(ZX_TOOLKITZFrm::ZX_TOOLKITZFrmActivate)
	EVT_MENU(ID_MNU_IMPORTTOOLS_1008, ZX_TOOLKITZFrm::Mnuimporttools1008Click0)
	EVT_MENU(ID_MNU_SETTINGS_1010, ZX_TOOLKITZFrm::Mnusettings1010Click0)
	EVT_BUTTON(ID_WXBUTTON1,ZX_TOOLKITZFrm::WxButton1Click)
	EVT_COMBOBOX(ID_WXCOMBOBOX1,ZX_TOOLKITZFrm::WxComboBox1Selected)
	
	EVT_LISTBOX_DCLICK(ID_WXLISTBOX1,ZX_TOOLKITZFrm::WxListBox1DoubleClicked)
END_EVENT_TABLE()
////Event Table End

ZX_TOOLKITZFrm::ZX_TOOLKITZFrm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

ZX_TOOLKITZFrm::~ZX_TOOLKITZFrm()
{
}

void ZX_TOOLKITZFrm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(-2, -2), wxSize(490, 300));

	WxStaticBox1 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX1, _("TOOLS"), wxPoint(22, 47), wxSize(442, 157));

	wxArrayString arrayStringFor_WxListBox1;
	WxListBox1 = new wxListBox(WxPanel1, ID_WXLISTBOX1, wxPoint(35, 68), wxSize(414, 125), arrayStringFor_WxListBox1, wxLB_SINGLE);
	WxListBox1->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, _("Lucida Console")));

	wxArrayString arrayStringFor_WxComboBox1;
	WxComboBox1 = new wxComboBox(WxPanel1, ID_WXCOMBOBOX1, _(""), wxPoint(37, 19), wxSize(411, 21), arrayStringFor_WxComboBox1, wxVSCROLL, wxDefaultValidator, _("WxComboBox1"));
	WxComboBox1->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, _("Lucida Console")));

	WxButton1 = new wxButton(WxPanel1, ID_WXBUTTON1, _("WxButton1"), wxPoint(300, 238), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));

	WxStatusBar1 = new wxStatusBar(this, ID_WXSTATUSBAR1);
	WxStatusBar1->SetFieldsCount(1);
	WxStatusBar1->SetStatusText(_("   CODED BY: ZUDO X | ZX                                 © 2019, All Rights Reserve."),0);
	int WxStatusBar1_Widths[1];
	WxStatusBar1_Widths[0] = -1;
	WxStatusBar1->SetStatusWidths(1,WxStatusBar1_Widths);

	WxMenuBar1 = new wxMenuBar();
	wxMenu *ID_MNU_FILE_1007_Mnu_Obj = new wxMenu();
	ID_MNU_FILE_1007_Mnu_Obj->Append(ID_MNU_IMPORTTOOLS_1008, _("IMPORT TOOLS"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_FILE_1007_Mnu_Obj, _("FILE"));
	
	wxMenu *ID_MNU_OPTIONS_1009_Mnu_Obj = new wxMenu();
	ID_MNU_OPTIONS_1009_Mnu_Obj->Append(ID_MNU_SETTINGS_1010, _("SETTINGS"), _(""), wxITEM_NORMAL);
	WxMenuBar1->Append(ID_MNU_OPTIONS_1009_Mnu_Obj, _("OPTIONS"));
	SetMenuBar(WxMenuBar1);

	SetStatusBar(WxStatusBar1);
	SetTitle(_("ZX TOOLKITZ"));
	SetIcon(wxNullIcon);
	SetSize(8,8,499,290);
	Center();
	
	////GUI Items Creation End
}

void ZX_TOOLKITZFrm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * ZX_TOOLKITZFrmActivate
 */
void ZX_TOOLKITZFrm::ZX_TOOLKITZFrmActivate(wxActivateEvent& event)
{
    WxComboBox1->Clear();
    WxComboBox1->SetLabel("---SELECT TOOLS---");
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Bin\\Data\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    }};
}

/*
 * WxComboBox1Selected
 */
void ZX_TOOLKITZFrm::WxComboBox1Selected(wxCommandEvent& event )
{
    WxStaticBox1->SetLabel(WxComboBox1->GetStringSelection());
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Bin\\Data\\"+WxComboBox1->GetStringSelection()+"\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    WxListBox1->Clear();
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    WxListBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    }};
}

/*
 * WxListBox1DoubleClicked
 */
void ZX_TOOLKITZFrm::WxListBox1DoubleClicked(wxCommandEvent& event)
{
    system("@ECHO OFF & color fc & mode con: cols=40 lines=10 & IF EXIST %TEMP%\\WIZDOMZE7EN DEL /S /Q ""%TEMP%\\WIZDOMZE7EN"" & CLS & color fc & Bin\\Resources\\uharc.exe x -pwzudox414 -t""%TEMP%\\WIZDOMZE7EN"" -y+ \"Bin\\Data\\"+WxStaticBox1->GetLabel()+"\\"+WxListBox1->GetStringSelection()+"\" & for /F %I in ('dir %TEMP%\\WIZDOMZE7EN\\CONFIG.cmd /b /s ') do (call ""%I"" Exit) ELSE (CLS & color fc & mode con: cols=40 lines=10 & Bin\\Resources\\uharc.exe x -pwzudox414 -t""%TEMP%\\WIZDOMZE7EN"" -y+ \"Bin\\Data\\"+WxStaticBox1->GetLabel()+"\\"+WxListBox1->GetStringSelection()+"\" & for /F %I in ('dir %TEMP%\\WIZDOMZE7EN\\CONFIG.cmd /b /s ') do (call ""%I""))");
}

/*
 * WxButton1Click
 */
void ZX_TOOLKITZFrm::WxButton1Click(wxCommandEvent& event)
{
   Untitled1Frm * mkConfig = new Untitled1Frm(this);
   mkConfig->Show();
	// insert your code here
}

/*
 * Mnuimporttools1008Click
 */
void ZX_TOOLKITZFrm::Mnuimporttools1008Click(wxCommandEvent& event)
{
    
	// insert your code here
}

/*
 * Mnuimporttools1008Click0
 */
void ZX_TOOLKITZFrm::Mnuimporttools1008Click0(wxCommandEvent& event)
{
    Untitled1Frm * mkConfig = new Untitled1Frm(this);
   mkConfig->Show();
	// insert your code here
}

/*
 * Mnusettings1010Click
 */
void ZX_TOOLKITZFrm::Mnusettings1010Click(wxCommandEvent& event)
{
    
	// insert your code here
}

/*
 * Mnuoptions1010Click
 */
void ZX_TOOLKITZFrm::Mnuoptions1010Click(wxCommandEvent& event)
{
	// insert your code here
}

/*
 * Mnusettings1010Click0
 */
void ZX_TOOLKITZFrm::Mnusettings1010Click0(wxCommandEvent& event)
{
    settings * sett = new settings(this);
    sett->Show();
	// insert your code here
}

/*
 * WxButton2Click
 */
void ZX_TOOLKITZFrm::WxButton2Click(wxCommandEvent& event)
{
	// insert your code here
}
