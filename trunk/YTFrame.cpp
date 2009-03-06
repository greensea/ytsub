///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 21 2008)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "YTFrame.h"

///////////////////////////////////////////////////////////////////////////

frmMain::frmMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	barMain = new wxMenuBar( 0 );
	menu_file = new wxMenu();
	wxMenuItem* barmain_file_newProject;
	barmain_file_newProject = new wxMenuItem( menu_file, wxID_NEWPROJECT, wxString( wxT("新建工程(&N)\tCtrl+N") ) , wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( barmain_file_newProject );
	
	menu_file->AppendSeparator();
	
	wxMenuItem* barmain_file_openFilm;
	barmain_file_openFilm = new wxMenuItem( menu_file, wxID_OPENFILM, wxString( wxT("打开影片(&O)") ) , wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( barmain_file_openFilm );
	
	wxMenuItem* barmain_file_openSub;
	barmain_file_openSub = new wxMenuItem( menu_file, wxID_OPENSUB, wxString( wxT("打开字幕(&U)") ) , wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( barmain_file_openSub );
	
	menu_file->AppendSeparator();
	
	wxMenuItem* barmain_file_save;
	barmain_file_save = new wxMenuItem( menu_file, wxID_SAVEPROJECT, wxString( wxT("保存工程(&S)\tCtrl+S") ) , wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( barmain_file_save );
	
	wxMenuItem* barmain_file_saveAs;
	barmain_file_saveAs = new wxMenuItem( menu_file, wxID_SAVEPROJECTAS, wxString( wxT("工程另存为(&A)\tCtrl+Shift+S") ) , wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( barmain_file_saveAs );
	
	menu_file->AppendSeparator();
	
	wxMenuItem* barmain_file_quit;
	barmain_file_quit = new wxMenuItem( menu_file, wxID_QUIT, wxString( wxT("退出(&Q)\tAlt+F4") ) , wxEmptyString, wxITEM_NORMAL );
	menu_file->Append( barmain_file_quit );
	
	barMain->Append( menu_file, wxT("文件(&F)") );
	
	menu_edit = new wxMenu();
	wxMenuItem* barmain_edit_config;
	barmain_edit_config = new wxMenuItem( menu_edit, wxID_CONFIG, wxString( wxT("设置(&C)") ) , wxEmptyString, wxITEM_NORMAL );
	menu_edit->Append( barmain_edit_config );
	
	barMain->Append( menu_edit, wxT("编辑(&E)") );
	
	menu_help = new wxMenu();
	wxMenuItem* barmain_help_onlineDoc;
	barmain_help_onlineDoc = new wxMenuItem( menu_help, wxID_HELP, wxString( wxT("在线文档(&O)") ) , wxEmptyString, wxITEM_NORMAL );
	menu_help->Append( barmain_help_onlineDoc );
	
	menu_help->AppendSeparator();
	
	wxMenuItem* barmain_help_about;
	barmain_help_about = new wxMenuItem( menu_help, wxID_ABOUT, wxString( wxT("关于(&A)") ) , wxEmptyString, wxITEM_NORMAL );
	menu_help->Append( barmain_help_about );
	
	barMain->Append( menu_help, wxT("帮助(&H)") );
	
	this->SetMenuBar( barMain );
	
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( frmMain::OnClose ) );
	this->Connect( barmain_file_openFilm->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnOpenFilm ) );
	this->Connect( barmain_file_openSub->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnOpenSub ) );
	this->Connect( barmain_file_save->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnSaveProject ) );
	this->Connect( barmain_file_saveAs->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnSaveProjectAs ) );
	this->Connect( barmain_file_quit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnQuit ) );
	this->Connect( barmain_edit_config->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnConfig ) );
	this->Connect( barmain_help_onlineDoc->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnHelp ) );
	this->Connect( barmain_help_about->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnAbout ) );
}

frmMain::~frmMain()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( frmMain::OnClose ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnOpenFilm ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnOpenSub ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnSaveProject ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnSaveProjectAs ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnQuit ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnConfig ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnHelp ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmMain::OnAbout ) );
}

frmSubEditor::frmSubEditor( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	barSubEditor = new wxMenuBar( 0 );
	barSubEditor_file = new wxMenu();
	wxMenuItem* barSubEditor_file_close;
	barSubEditor_file_close = new wxMenuItem( barSubEditor_file, wxID_CLOSE, wxString( wxT("关闭(&C)") ) , wxEmptyString, wxITEM_NORMAL );
	barSubEditor_file->Append( barSubEditor_file_close );
	
	barSubEditor->Append( barSubEditor_file, wxT("文件(&F)") );
	
	this->SetMenuBar( barSubEditor );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	grdSubEditor = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grdSubEditor->CreateGrid( 10, 3 );
	grdSubEditor->EnableEditing( true );
	grdSubEditor->EnableGridLines( true );
	grdSubEditor->EnableDragGridSize( false );
	grdSubEditor->SetMargins( 0, 0 );
	
	// Columns
	grdSubEditor->SetColSize( 0, 111 );
	grdSubEditor->SetColSize( 1, 111 );
	grdSubEditor->SetColSize( 2, 167 );
	grdSubEditor->EnableDragColMove( false );
	grdSubEditor->EnableDragColSize( true );
	grdSubEditor->SetColLabelSize( 30 );
	grdSubEditor->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grdSubEditor->EnableDragRowSize( false );
	grdSubEditor->SetRowLabelSize( 80 );
	grdSubEditor->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grdSubEditor->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer2->Add( grdSubEditor, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer2 );
	this->Layout();
	stsSubEditor = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	m_toolBar3 = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY ); 
	m_toolBar3->Realize();
	
}

frmSubEditor::~frmSubEditor()
{
}

frmKalaok::frmKalaok( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	barKalaok = new wxMenuBar( 0 );
	barKalaok_file = new wxMenu();
	wxMenuItem* kalaok_close;
	kalaok_close = new wxMenuItem( barKalaok_file, wxID_MENU_CLOSE, wxString( wxT("关闭(&C)") ) , wxEmptyString, wxITEM_NORMAL );
	barKalaok_file->Append( kalaok_close );
	
	barKalaok->Append( barKalaok_file, wxT("文件(&F)") );
	
	this->SetMenuBar( barKalaok );
	
	tlbKalaok = this->CreateToolBar( wxTB_HORIZONTAL, wxID_ANY ); 
	tlbKalaok->AddTool( wxID_HELP, wxT("tool"), wxNullBitmap, wxNullBitmap, wxITEM_NORMAL, wxEmptyString, wxEmptyString );
	tlbKalaok->Realize();
	
	stsKalaok = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	txtKalaokEditor = new wxTextCtrl( this, wxID_EDITOR, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_WORDWRAP );
	bSizer5->Add( txtKalaokEditor, 1, wxALL|wxEXPAND, 5 );
	
	txtKalaokResult = new wxTextCtrl( this, wxID_RESULT, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_WORDWRAP );
	bSizer5->Add( txtKalaokResult, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	
	bSizer7->Add( 0, 0, 1, wxEXPAND, 5 );
	
	btnKalaokApply = new wxButton( this, wxID_APPLY, wxT("应用到时间轴"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( btnKalaokApply, 0, wxALL, 5 );
	
	btnKalaokEffect = new wxButton( this, wxID_ANY, wxT("特效"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( btnKalaokEffect, 0, wxALL, 5 );
	
	btnKalaokCopy = new wxButton( this, wxID_COPY, wxT("复制"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( btnKalaokCopy, 0, wxALL, 5 );
	
	btnKalaokHelp = new wxButton( this, wxID_HELP, wxT("帮助"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( btnKalaokHelp, 0, wxALL, 5 );
	
	btnKalaokClose = new wxButton( this, wxID_CLOSE, wxT("关闭"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( btnKalaokClose, 0, wxALL, 5 );
	
	bSizer5->Add( bSizer7, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer5 );
	this->Layout();
	
	// Connect Events
	this->Connect( kalaok_close->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmKalaok::OnClose ) );
	txtKalaokEditor->Connect( wxEVT_KEY_DOWN, wxKeyEventHandler( frmKalaok::OnEditorKeyDown ), NULL, this );
	txtKalaokEditor->Connect( wxEVT_KEY_UP, wxKeyEventHandler( frmKalaok::OnEditorKeyUp ), NULL, this );
	txtKalaokEditor->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( frmKalaok::OnLeftDown ), NULL, this );
	txtKalaokEditor->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( frmKalaok::OnLeftUp ), NULL, this );
	btnKalaokApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaok::OnApply ), NULL, this );
	btnKalaokEffect->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaok::OnSelectEffect ), NULL, this );
	btnKalaokCopy->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaok::OnCopy ), NULL, this );
	btnKalaokHelp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaok::OnHelp ), NULL, this );
	btnKalaokClose->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaok::OnClose ), NULL, this );
}

frmKalaok::~frmKalaok()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frmKalaok::OnClose ) );
	txtKalaokEditor->Disconnect( wxEVT_KEY_DOWN, wxKeyEventHandler( frmKalaok::OnEditorKeyDown ), NULL, this );
	txtKalaokEditor->Disconnect( wxEVT_KEY_UP, wxKeyEventHandler( frmKalaok::OnEditorKeyUp ), NULL, this );
	txtKalaokEditor->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( frmKalaok::OnLeftDown ), NULL, this );
	txtKalaokEditor->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( frmKalaok::OnLeftUp ), NULL, this );
	btnKalaokApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaok::OnApply ), NULL, this );
	btnKalaokEffect->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaok::OnSelectEffect ), NULL, this );
	btnKalaokCopy->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaok::OnCopy ), NULL, this );
	btnKalaokHelp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaok::OnHelp ), NULL, this );
	btnKalaokClose->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaok::OnClose ), NULL, this );
}

frmKalaEffect::frmKalaEffect( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxGridSizer* gSizer4;
	gSizer4 = new wxGridSizer( 1, 2, 0, 0 );
	
	lstKalaEffectList = new wxListBox( this, wxID_LIST, wxDefaultPosition, wxSize( -1,-1 ), 0, NULL, 0 ); 
	gSizer4->Add( lstKalaEffectList, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_STATICBOX, wxT("插件信息") ), wxVERTICAL );
	
	lblKalaEffectInfo = new wxStaticText( this, wxID_INFO, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxST_NO_AUTORESIZE );
	lblKalaEffectInfo->Wrap( 100 );
	sbSizer3->Add( lblKalaEffectInfo, 1, wxALL|wxEXPAND, 5 );
	
	bSizer5->Add( sbSizer3, 1, wxEXPAND, 5 );
	
	wxGridSizer* gSizer6;
	gSizer6 = new wxGridSizer( 1, 2, 0, 0 );
	
	btnKalaEffectCancel = new wxButton( this, wxID_CANCEL, wxT("取消"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer6->Add( btnKalaEffectCancel, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	btnKalaEffectOK = new wxButton( this, wxID_OK, wxT("应用"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer6->Add( btnKalaEffectOK, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	bSizer5->Add( gSizer6, 0, wxALIGN_RIGHT, 5 );
	
	gSizer4->Add( bSizer5, 1, wxEXPAND, 5 );
	
	this->SetSizer( gSizer4 );
	this->Layout();
	
	// Connect Events
	lstKalaEffectList->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( frmKalaEffect::OnSelectEffect ), NULL, this );
	lstKalaEffectList->Connect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frmKalaEffect::OnApply ), NULL, this );
	btnKalaEffectCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaEffect::OnCancel ), NULL, this );
	btnKalaEffectOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaEffect::OnApply ), NULL, this );
}

frmKalaEffect::~frmKalaEffect()
{
	// Disconnect Events
	lstKalaEffectList->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( frmKalaEffect::OnSelectEffect ), NULL, this );
	lstKalaEffectList->Disconnect( wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, wxCommandEventHandler( frmKalaEffect::OnApply ), NULL, this );
	btnKalaEffectCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaEffect::OnCancel ), NULL, this );
	btnKalaEffectOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frmKalaEffect::OnApply ), NULL, this );
}
