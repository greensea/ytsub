/***************************************************************
 * Name:      ytsubApp.cpp
 * Purpose:   Code for Application Class
 * Author:    greensea (midoriumi@sohu.com)
 * Created:   2009-01-05
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
#include "kalaEffect.h"

DECLARE_APP(ytsubApp)
IMPLEMENT_APP(ytsubApp)

ytsubApp::ytsubApp()
{
    player = new ytPlayer;
}

bool ytsubApp::OnInit()
{
    effectWindow = NULL;

    kalaEffect_load(wxT("/plugins/kalaok"));

    ytsubFrame* frame = new ytsubFrame(0L);
    frame->Show();
    kalaok = new kalaokFrame(0L);

    return true;
}

bool ytsubApp::openFilm(const char* path)
{
   return wxGetApp().player->loadFilm(path);
}
