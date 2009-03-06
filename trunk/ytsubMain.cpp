/***************************************************************
 * Name:      ytsubMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    greensea (midoriumi@sohu.com)
 * Created:   2009-01-04
 * Copyright: greensea (http://www.gsea.com.cn)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "ytsubApp.h"
#include "ytsubMain.h"
#include "ytKalaokProc.h"
#include "kalaEffect.h"

DECLARE_APP(ytsubApp)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

ytsubFrame::ytsubFrame(wxFrame *frame)
    : frmMain(frame)
{

}

ytsubFrame::~ytsubFrame()
{
}

void ytsubFrame::OnClose(wxCloseEvent &event)
{
    if(!wxGetApp().player) delete(wxGetApp().player);
    delete(wxGetApp().kalaok);
    wxMessageBox(wxT("ytsub will quit"), wxT("info"));
    Destroy();
}

void ytsubFrame::OnQuit(wxCommandEvent &event)
{
    if(!wxGetApp().player) delete(wxGetApp().player);
    delete(wxGetApp().kalaok);
    Destroy();
}

void ytsubFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void ytsubFrame::OnOpenFilm(wxCommandEvent &event)
{
	wxFileDialog dlg(NULL, wxT("Choose a video file"), wxT(""), wxT(""), wxT("Video files (*.avi,*.mkv,*.ogg,*.mpg,*.mpeg,*.rm,*.rmvb)|*.*|All files|*.*"), wxOPEN | wxFILE_MUST_EXIST);
	if(dlg.ShowModal() == wxID_OK){
		char path[4096];
		strcpy(path, dlg.GetPath().mb_str());
		if(!wxGetApp().openFilm(path)){
		    printf("Cant't load film: %s\n", path);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

kalaokFrame::kalaokFrame(wxFrame *frame)
    : frmKalaok(frame)
{
    making = false;
    lightReady = lightWait = -1;
    kalaproc = new ytKalaokProc;
    stsKalaok->SetStatusText(wxT("kalaok editor ready"), 0);
}

kalaokFrame::~kalaokFrame()
{
    delete(kalaproc);
}

void kalaokFrame::OnClose(wxCloseEvent& event)
{
    if(txtKalaokEditor->GetValue().Length() > 0){
        if(wxYES != wxMessageBox(wxT("sure?"), wxT("Kalaok content has modified, are you sure to close window?"), wxYES_NO, this)){
            // Abort Codes here
        }
    }
}

void kalaokFrame::OnClose(wxCommandEvent& event)
{

}


void kalaokFrame::OnQuit(wxCommandEvent& event)
{
}

void kalaokFrame::OnHelp(wxCommandEvent& event)
{
    wxGetApp().player->getCurrentTime();
}

void kalaokFrame::OnEditorKeyUp(wxKeyEvent& event)
{
}

void kalaokFrame::OnEditorKeyDown(wxKeyEvent& event)
{
    int keycode = event.GetKeyCode();
    if(keycode == 13 && event.AltDown()){
        // start making kalaok
        setEditorStatus();
        if(txtKalaokEditor->GetInsertionPoint() == (int)txtKalaokEditor->GetValue().Length()){
            txtKalaokEditor->SetInsertionPoint(0);
            kalaproc->resetPos(0);
            lightReady = 0;
        }
        else{
            kalaproc->resetPos(lightReady = txtKalaokEditor->GetInsertionPoint());
        }
        updateHighlight();
        keycode = 0;
    }
    if(making){
        switch(keycode){
            case WXK_SPACE:
                lightWait = kalaproc->ting();
                lightReady = -1;
                updateHighlight();
                txtKalaokResult->SetValue(kalaproc->getContent());
                break;
            case 13:
                lightReady = kalaproc->tingCut();
                lightWait = -1;
                updateHighlight();
                txtKalaokResult->SetValue(kalaproc->getContent());
            default:
                printf("ytsub: Unhandle keycode %d\n", keycode);
        }
    }
    else{
        if(keycode) event.Skip();
    }
}

void kalaokFrame::setEditorStatus()
{
    making = !making;
    if(making){
        kalaproc->setContent(txtKalaokEditor->GetValue());
        stsKalaok->SetStatusText(wxT("making kalaok..."), 0);
    }
    else{
        kalaproc->reset();
        stsKalaok->SetStatusText(wxT("kalaok ediotr ready"), 0);
    }
}

void kalaokFrame::OnLeftDown(wxMouseEvent& event)
{
    event.Skip();
}

void kalaokFrame::OnLeftUp(wxMouseEvent& event)
{
    if(!making){
        lightReady = txtKalaokEditor->GetInsertionPoint();
        updateHighlight();
    }
    event.Skip();
}

void kalaokFrame::updateHighlight()
{
    wxTextAttr style;

    //clear style
    style.SetBackgroundColour(wxColor(255, 255, 255));
    txtKalaokEditor->SetStyle(0, txtKalaokEditor->GetValue().Length(), style);

    //set ready color
    style.SetBackgroundColour(wxColor(wxColor(255, 128, 128)));
    txtKalaokEditor->SetStyle(lightReady, lightReady + 1, style);

    //set wait color
    style.SetBackgroundColour(wxColor(wxColor(0, 255, 0)));
    txtKalaokEditor->SetStyle(lightWait, lightWait + 1, style);

}

void kalaokFrame::OnSelectEffect(wxCommandEvent& event)
{
    if(!wxGetApp().effectWindow) wxGetApp().effectWindow = new kalaEffectFrame(0L);
    wxGetApp().effectWindow->Show();
}

//////////////// KalaEffect Frame //////////////////

kalaEffectFrame::kalaEffectFrame(wxFrame *frame)
    : frmKalaEffect(frame)
{
    // Load Kalaok effect plugins to list
    wxArrayString list;
    kalaEffect* p = kalaEffect_var_head;

    while(p){
        list.Add(p->name);
        p = p->next;
    }
    lstKalaEffectList->InsertItems(list, 0);
}


kalaEffectFrame::~kalaEffectFrame()
{
}

void kalaEffectFrame::OnCancel(wxCommandEvent& event)
{
    this->Destroy();
    wxGetApp().effectWindow = NULL;
}

void kalaEffectFrame::OnSelectEffect(wxCommandEvent& event)
{
    int id = event.GetInt();
    kalaEffect* p = kalaEffect_var_head;
    while(p){
        if(id == p->id){
            this->showEffectInfo(p);
        }
        p = p->next;
    }
}

void kalaEffectFrame::OnApply(wxCommandEvent& event)
{
}

void kalaEffectFrame::showEffectInfo(kalaEffect* effect)
{
    lblKalaEffectInfo->SetLabel(_("Author:") + effect->author + wxT("\n") +
                                _("Email:") + effect->email + wxT("\n") +
                                _("Homepage:") + effect->homepage + wxT("\n") +
                                _("Description:") + wxT("\n") + effect->description
    );
}
