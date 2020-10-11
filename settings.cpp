///-----------------------------------------------------------------
///
/// @file      settings.cpp
/// @author    NULLZKR
/// Created:   11/19/2019 3:38:28 AM
/// @section   DESCRIPTION
///            settings class implementation
///
///------------------------------------------------------------------

#include "settings.h"
#include <wx/dir.h>

//Do not add custom headers between
//Header Include Start and Header Include End
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End
using namespace std;

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
// settings
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(settings,wxFrame)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(settings::OnClose)
	EVT_ACTIVATE(settings::settingsActivate)
	EVT_BUTTON(ID_WXBUTTON4,settings::WxButton4Click)
	EVT_LISTBOX(ID_WXLISTBOX2,settings::WxListBox2Selected)
	EVT_COMBOBOX(ID_WXCOMBOBOX1,settings::WxComboBox1Selected)
	EVT_BUTTON(ID_WXBUTTON3,settings::WxButton3Click)
END_EVENT_TABLE()
////Event Table End

settings::settings(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxFrame(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

settings::~settings()
{
}

void settings::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxPanel1 = new wxPanel(this, ID_WXPANEL1, wxPoint(-4, -1), wxSize(592, 183));

	WxNotebook1 = new wxNotebook(WxPanel1, ID_WXNOTEBOOK1, wxPoint(16, 7), wxSize(425, 172), wxNB_DEFAULT);

	WxNoteBookPage1 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE1, wxPoint(4, 26), wxSize(417, 142));
	WxNotebook1->AddPage(WxNoteBookPage1, _("ADD TOOL CATEGORY"));

	WxStaticBox1 = new wxStaticBox(WxNoteBookPage1, ID_WXSTATICBOX1, _("ENTER CATEGORY NAME:"), wxPoint(5, 1), wxSize(407, 48));

	WxEdit1 = new wxTextCtrl(WxNoteBookPage1, ID_WXEDIT1, _(""), wxPoint(16, 22), wxSize(385, 19), 0, wxDefaultValidator, _("WxEdit1"));

	wxArrayString arrayStringFor_WxListBox1;
	WxListBox1 = new wxListBox(WxNoteBookPage1, ID_WXLISTBOX1, wxPoint(4, 52), wxSize(406, 62), arrayStringFor_WxListBox1, wxLB_SINGLE);

	WxButton1 = new wxButton(WxNoteBookPage1, ID_WXBUTTON1, _("ADD"), wxPoint(182, 117), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton1"));

	WxButton2 = new wxButton(WxNoteBookPage1, ID_WXBUTTON2, _("CANCEL"), wxPoint(336, 117), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton2"));

	WxNoteBookPage2 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE2, wxPoint(4, 26), wxSize(417, 142));
	WxNotebook1->AddPage(WxNoteBookPage2, _("EDIT TOOLS"));

	WxButton3 = new wxButton(WxNoteBookPage2, ID_WXBUTTON3, _("OK"), wxPoint(176, 118), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton3"));
	WxButton3->Enable(false);

	wxArrayString arrayStringFor_WxComboBox1;
	WxComboBox1 = new wxComboBox(WxNoteBookPage2, ID_WXCOMBOBOX1, _(""), wxPoint(8, 6), wxSize(396, 23), arrayStringFor_WxComboBox1, 0, wxDefaultValidator, _("WxComboBox1"));

	wxArrayString arrayStringFor_WxListBox2;
	WxListBox2 = new wxListBox(WxNoteBookPage2, ID_WXLISTBOX2, wxPoint(9, 34), wxSize(395, 58), arrayStringFor_WxListBox2, wxLB_SINGLE);
	WxListBox2->Enable(false);

	WxButton4 = new wxButton(WxNoteBookPage2, ID_WXBUTTON4, _("CLOSE"), wxPoint(332, 118), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton4"));

	WxEdit2 = new wxTextCtrl(WxNoteBookPage2, ID_WXEDIT2, _(""), wxPoint(9, 96), wxSize(395, 19), 0, wxDefaultValidator, _("WxEdit2"));
	WxEdit2->Enable(false);

	WxButton5 = new wxButton(WxNoteBookPage2, ID_WXBUTTON5, _("OK"), wxPoint(255, 118), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton5"));
	WxButton5->Enable(false);

	WxNoteBookPage3 = new wxPanel(WxNotebook1, ID_WXNOTEBOOKPAGE3, wxPoint(4, 26), wxSize(417, 142));
	WxNotebook1->AddPage(WxNoteBookPage3, _("OTHERS"));

	WxButton6 = new wxButton(WxNoteBookPage1, ID_WXBUTTON6, _("OK"), wxPoint(259, 117), wxSize(75, 25), 0, wxDefaultValidator, _("WxButton6"));

	SetTitle(_("SETTINGS"));
	SetIcon(wxNullIcon);
	SetSize(8,8,460,216);
	Center();
	
	////GUI Items Creation End
}

void settings::OnClose(wxCloseEvent& event)
{
	Destroy();
}

/*
 * settingsActivate
 */
void settings::settingsActivate(wxActivateEvent& event)
{
    WxComboBox1->Clear();
    WxComboBox1->SetLabel("---SELECT TOOLS CATEGORY---");
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Bin\\Data\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    WxListBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    }};
	// insert your code here
}

/*
 * WxComboBox1Selected
 */
void settings::WxComboBox1Selected(wxCommandEvent& event )
{
    WxListBox2->Enable(true);
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Bin\\Data\\"+WxComboBox1->GetStringSelection()+"\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    WxListBox1->Clear();
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    WxListBox2->Append(dirList.Item(i).AfterLast('\\').AfterLast('/').BeforeLast('.'));
    }};
	// insert your code here
}

/*
 * WxListBox2Selected
 */
void settings::WxListBox2Selected(wxCommandEvent& event)
{
         WxEdit2->SetLabel(WxListBox2->GetStringSelection());
    WxButton3->SetLabel("EDIT");
    WxButton5->SetLabel("DELETE");
    WxButton4->SetLabel("CANCEL");
    WxButton3->Enable(true);
    WxButton5->Enable(true);
	// insert your code here
}

/*
 * WxButton3Click
 */
void settings::WxButton3Click(wxCommandEvent& event)
{
    if(WxButton3->GetLabel()=="SAVE")
    {
         WxButton3->SetLabel("OK");
          WxButton4->SetLabel("CLOSE");
              WxButton4->Enable(true);
                  WxButton3->Enable(false);
                   WxListBox2->Clear();
                    WxEdit2->Clear();
                  WxComboBox1->Clear();
                  WxEdit2->SetFocus();
    WxComboBox1->SetLabel("---SELECT TOOLS CATEGORY---");
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Bin\\Data\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    }};
    WxEdit2->Enable(false);
        }else{
            WxListBox2->Enable(false);
     WxEdit2->SetLabel(WxListBox2->GetStringSelection());
     WxEdit2->Enable(true);
     WxEdit2->SetFocus();
     WxEdit2->SelectAll();
     WxButton3->SetLabel("SAVE");
    WxButton5->SetLabel("OK");
    WxButton4->SetLabel("CANCEL");
    WxButton4->Enable(true);
    WxButton5->Enable(false);
}
     
	// insert your code here
}

/*
 * WxButton4Click
 */
void settings::WxButton4Click(wxCommandEvent& event)
{
    if(WxButton4->GetLabel()=="CLOSE"){
        Close();
        }
        else{
            if(WxButton3->GetLabel()=="SAVE"){
                 WxButton3->SetLabel("EDIT");
    WxButton5->SetLabel("DELETE");
    WxButton4->SetLabel("CANCEL");
    WxButton3->Enable(true);
    WxButton5->Enable(true);
     WxListBox2->Enable(true);
            }
            else{
                WxButton5->Enable(false);
     WxButton3->Enable(false);
           WxButton3->SetLabel("OK");
          WxButton4->SetLabel("CLOSE");
                  WxButton3->Enable(false);
                   WxListBox2->Clear();
                    WxEdit2->Clear();
                  WxComboBox1->Clear();
                  WxEdit2->SetFocus();
    WxComboBox1->SetLabel("---SELECT TOOLS CATEGORY---");
    wxArrayString dirList;
    wxDirectoriesEnumerator traverser(&dirList);
    wxDir dir("Bin\\Data\\");
    if(dir.IsOpened()){
    dir.Traverse(traverser);
    for(unsigned int i=0; i<dirList.GetCount(); i++) {
    WxComboBox1->Append(dirList.Item(i).AfterLast('\\').AfterLast('/'));
    }};
    WxEdit2->Enable(false);  
}
        }
        
	// insert your code here
}
