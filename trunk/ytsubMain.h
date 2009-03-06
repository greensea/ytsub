/***************************************************************
 * Name:      wxtestMain.h
 * Purpose:   Defines Application Frame
 * Author:    greensea (midoriumi@sohu.com)
 * Created:   2009-01-04
 * Copyright: greensea (http://www.gsea.com.cn)
 * License:
 **************************************************************/

#ifndef WXTESTMAIN_H
#define WXTESTMAIN_H

#include "YTFrame.h"
#include "ytKalaokProc.h"
#include "kalaEffect.h"


class ytsubFrame: public frmMain
{
    public:
        ytsubFrame(wxFrame *frame);
        ~ytsubFrame();
    private:
		FILE* mp;

        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
        virtual void OnOpenFilm(wxCommandEvent& event);
};

class kalaokFrame: public frmKalaok
{
    public:
        kalaokFrame(wxFrame *frame);
        ~kalaokFrame();
    private:
        bool making;
        ytKalaokProc* kalaproc;
        long lightReady, lightWait;

        virtual void OnClose(wxCloseEvent& event);
        virtual void OnClose(wxCommandEvent& event);
        virtual void OnHelp(wxCommandEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnEditorKeyDown(wxKeyEvent& event);
        virtual void OnEditorKeyUp(wxKeyEvent& event);
        virtual void OnLeftDown(wxMouseEvent& event);
        virtual void OnLeftUp(wxMouseEvent& event);
        virtual void OnSelectEffect(wxCommandEvent& event);

        void setEditorStatus();
        void updateHighlight();
};

class kalaEffectFrame: public frmKalaEffect
{
    public:
        kalaEffectFrame(wxFrame *frame);
        ~kalaEffectFrame();
    private:
		virtual void OnSelectEffect( wxCommandEvent& event );
		virtual void OnApply( wxCommandEvent& event );
		virtual void OnCancel( wxCommandEvent& event );

		void applyEffect(long id);
		void showEffectInfo(kalaEffect* effect);
};

#endif // WXTESTMAIN_H
