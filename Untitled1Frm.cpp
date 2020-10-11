///-----------------------------------------------------------------
///
/// @file      Untitled1Frm.cpp
/// @author    NULLZKR
/// Created:   5/12/2019 4:29:30 AM
/// @section   DESCRIPTION
///            Untitled1Frm class implementation
///
///------------------------------------------------------------------

#include "Untitled1Frm.h"
#include <iostream>
#include <fstream>
#include <wx/dir.h>

using namespace std;
//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End
class wxDirectoriesEnumerator : public wxDirTraverser {
public:
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
// Untitled1Frm
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(Untitled1Frm,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(Untitled1Frm::OnClose)
	EVT_ACTIVATE(Untitled1Frm::Untitled1FrmActivate)
	EVT_BUTTON(ID_WXBUTTON2,Untitled1Frm::WxButton2Click)
	EVT_BUTTON(ID_WXBUTTON1,Untitled1Frm::WxButton1Click0)
END_EVENT_TABLE()
////Event Table End

Untitled1Frm::Untitled1Frm(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

Untitled1Frm::~Untitled1Frm()
{
}

void Untitled1Frm::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(-4, 0), wxSize(462, 194));

	WxStaticBox1 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX1, _(""), wxPoint(5, 0), wxSize(444, 184));

	WxStaticBox2 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX2, _("CHOOSE TOOLS CATEGORY"), wxPoint(16, 96), wxSize(420, 56));

	wxArrayString arrayStringFor_WxComboBox1;
	WxComboBox1 = new wxComboBox(WxPanel1, ID_WXCOMBOBOX1, _(""), wxPoint(31, 116), wxSize(380, 23), arrayStringFor_WxComboBox1, wxCB_SIMPLE | wxCB_READONLY, wxDefaultValidator, _("WxComboBox1"));

	WxStaticBox3 = new wxStaticBox(WxPanel1, ID_WXSTATICBOX3, _("SOURCE [Target EXE]"), wxPoint(17, 15), wxSize(418, 78));

	WxButton1 = new wxButton(WxPanel1, ID_WXBUTTON1, _("BROWSE"), wxPoint(338, 29), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));

	WxEdit1 = new wxTextCtrl(WxPanel1, ID_WXEDIT1, _(""), wxPoint(31, 61), wxSize(381, 19), 0, wxDefaultValidator, _("WxEdit1"));
	WxEdit1->Enable(false);

	WxButton2 = new wxButton(WxPanel1, ID_WXBUTTON2, _("IMPORT"), wxPoint(339, 155), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton2"));
	WxButton2->Enable(false);

	WxStaticText1 = new wxStaticText(WxPanel1, ID_WXSTATICTEXT1, _("Tools Name"), wxPoint(32, 41), wxDefaultSize, 0, _("WxStaticText1"));

	WxStaticText3 = new wxStaticText(this, ID_WXSTATICTEXT3, _("WxStaticText3"), wxPoint(466, 65), wxDefaultSize, 0, _("WxStaticText3"));

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("WxStaticText2"), wxPoint(463, 84), wxDefaultSize, 0, _("WxStaticText2"));

	WxOpenFileDialog1 =  new wxFileDialog(this, _("Choose a file"), _(""), _(""), _("*.*"), wxFD_OPEN);

	SetTitle(_("IMPORT CONFIG"));
	SetIcon(wxNullIcon);
	SetSize(8,8,464,218);
	Center();
	
	////GUI Items Creation End
}

void Untitled1Frm::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * WxButton1Click
 */
void Untitled1Frm::WxButton1Click(wxCommandEvent& event)
{
    //if(WxOpenFileDialog1->ShowModal()==wxID_OK){
//        WxEdit1->SetLabel(WxOpenFileDialog1->GetDirectory());
//        WxStaticText1->SetLabel(WxOpenFileDialog1->GetFilename());
//        WxEdit2->SetLabel(WxOpenFileDialog1->GetDirectory());
//    }
        
	// insert your code here
}

/*
 * CREATEClick
 */
void Untitled1Frm::CREATEClick(wxCommandEvent& event)
{
    //if(WxRadioButton1->GetValue()){
//        ofstream config;
//        config.open(WxEdit1->GetValue()+"\\CONFIG.CMD");
//        config << "@pushd \"%~dp0\" & @start \"\" /D\"%TEMP%\\ZUDOX\" \""+WxStaticText1->GetLabel()+"\"";
//        config.close();
//        system("UHARC a -m3 -pe -r -y+ \""+WxEdit2->GetValue()+"\\sample.uha\" \""+WxEdit1->GetValue()+"\\");
//        wxMessageBox("Packed Created!!");
//    }else{
//        ofstream config;
//        config.open(WxEdit1->GetValue()+"\\CONFIG.CMD");
//        config << "for /F %%I in ('dir %TEMP%\\ZUDOX\\"+WxStaticText1->GetLabel()+" /b /s ') do (start ""%%I"" exit)";
//        config.close();
//        system("UHARC a -m3 -pe -r -y+ \""+WxEdit2->GetValue()+"\\sample.uha\" \""+WxEdit1->GetValue()+"\\");
//        wxMessageBox("Packed Created!!");
//    }
	// insert your code here
}

/*
 * Untitled1FrmActivate
 */
void Untitled1Frm::Untitled1FrmActivate(wxActivateEvent& event)
{
    
	// insert your code here
}

/*
 * WxButton1Click0
 */
void Untitled1Frm::WxButton1Click0(wxCommandEvent& event)
{
     if(WxOpenFileDialog1->ShowModal()==wxID_OK)
     {
        WxStaticText2->SetLabel(WxOpenFileDialog1->GetDirectory());
        WxEdit1->SetLabel(WxOpenFileDialog1->GetFilename().BeforeLast('.'));
        WxStaticText3->SetLabel(WxOpenFileDialog1->GetFilename());
    }
     WxEdit1->Enable(true);
     WxButton2->Enable(true);
     WxEdit1->SetFocus();
     WxEdit1->SelectAll();
     
     WxComboBox1->Clear();
     wxArrayString dirList;
     wxDirectoriesEnumerator traverser(&dirList);
     wxDir dir("Bin\\Data\\");
     if(dir.IsOpened()){
     dir.Traverse(traverser);
     for(unsigned int i=0; i<dirList.GetCount(); i++) {
     WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    }};
//	// insert your code here
}

/*
 * WxButton2Click
 */
void Untitled1Frm::WxButton2Click(wxCommandEvent& event)
{
    if(WxComboBox1->GetValue()!="")
    {
        ofstream config;
        config.open(WxStaticText2->GetLabel()+"\\CONFIG.CMD");
//        config << "for /F %%I in ('dir %TEMP%\\WIZDOMZE7EN\\"+WxStaticText3->GetLabel()+" /b /s ') do (start ""%%I"" exit)";
        config << "@pushd \"%~dp0\" & @start \"\" /D\"%TEMP%\\WIZDOMZE7EN\" \""+WxStaticText3->GetLabel()+"\"";
        config.close();
        system("color fc & mode con: cols=55 lines=10 & Bin\\Resources\\UHARC a -m3 -pe -r -y+ \"Bin\\data\\"+WxComboBox1->GetValue()+"\\"+WxEdit1->GetValue()+".uha""\" \""+WxStaticText2->GetLabel()+"\\");
        wxMessageBox("Successfully Imported!","Import Success!",wxICON_INFORMATION|wxOK);
        WxEdit1->Enable(false);
        WxButton2->Enable(false);
        WxEdit1->Clear();
        WxComboBox1->Clear();
    }
    else
    wxMessageBox("Tools category should not be empty!","Import Error!",wxICON_ERROR|wxOK);

	// insert your code here
}
