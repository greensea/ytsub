///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 21 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __YTFrame__
#define __YTFrame__

#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/listbox.h>
#include <wx/stattext.h>
#include <wx/statbox.h>

///////////////////////////////////////////////////////////////////////////

#define wxID_FRMMAIN 1000
#define wxID_NEWPROJECT 1001
#define wxID_OPENFILM 1002
#define wxID_OPENSUB 1003
#define wxID_SAVEPROJECT 1004
#define wxID_SAVEPROJECTAS 1005
#define wxID_QUIT 1006
#define wxID_CONFIG 1007
#define wxID_FRMSUBEDITOR 1008
#define wxID_FRMKALAOK 1009
#define wxID_MENU_CLOSE 1010
#define wxID_EDITOR 1011
#define wxID_RESULT 1012
#define wxID_FRMKALAEFFECT 1013
#define wxID_LIST 1014
#define wxID_STATICBOX 1015
#define wxID_INFO 1016

///////////////////////////////////////////////////////////////////////////////
/// Class frmMain
///////////////////////////////////////////////////////////////////////////////
class frmMain : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* barMain;
		wxMenu* menu_file;
		wxMenu* menu_edit;
		wxMenu* menu_help;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ){ event.Skip(); }
		virtual void OnOpenFilm( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnOpenSub( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSaveProject( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSaveProjectAs( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnConfig( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnHelp( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		frmMain( wxWindow* parent, wxWindowID id = wxID_FRMMAIN, const wxString& title = wxT("ytsub"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~frmMain();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class frmSubEditor
///////////////////////////////////////////////////////////////////////////////
class frmSubEditor : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* barSubEditor;
		wxMenu* barSubEditor_file;
		wxGrid* grdSubEditor;
		wxStatusBar* stsSubEditor;
		wxToolBar* m_toolBar3;
	
	public:
		frmSubEditor( wxWindow* parent, wxWindowID id = wxID_FRMSUBEDITOR, const wxString& title = wxT("时间轴"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 727,452 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~frmSubEditor();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class frmKalaok
///////////////////////////////////////////////////////////////////////////////
class frmKalaok : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* barKalaok;
		wxMenu* barKalaok_file;
		wxToolBar* tlbKalaok;
		wxStatusBar* stsKalaok;
		wxTextCtrl* txtKalaokEditor;
		wxTextCtrl* txtKalaokResult;
		
		wxButton* btnKalaokApply;
		wxButton* btnKalaokEffect;
		wxButton* btnKalaokCopy;
		wxButton* btnKalaokHelp;
		wxButton* btnKalaokClose;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnEditorKeyDown( wxKeyEvent& event ){ event.Skip(); }
		virtual void OnEditorKeyUp( wxKeyEvent& event ){ event.Skip(); }
		virtual void OnLeftDown( wxMouseEvent& event ){ event.Skip(); }
		virtual void OnLeftUp( wxMouseEvent& event ){ event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnSelectEffect( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCopy( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnHelp( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		frmKalaok( wxWindow* parent, wxWindowID id = wxID_FRMKALAOK, const wxString& title = wxT("咔啦OK效果"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 503,550 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~frmKalaok();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class frmKalaEffect
///////////////////////////////////////////////////////////////////////////////
class frmKalaEffect : public wxFrame 
{
	private:
	
	protected:
		wxListBox* lstKalaEffectList;
		wxStaticText* lblKalaEffectInfo;
		wxButton* btnKalaEffectCancel;
		wxButton* btnKalaEffectOK;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelectEffect( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnApply( wxCommandEvent& event ){ event.Skip(); }
		virtual void OnCancel( wxCommandEvent& event ){ event.Skip(); }
		
	
	public:
		frmKalaEffect( wxWindow* parent, wxWindowID id = wxID_FRMKALAEFFECT, const wxString& title = wxT("选择卡啦OK效果插件"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 439,334 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		~frmKalaEffect();
	
};

#endif //__YTFrame__
