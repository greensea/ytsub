/***************************************************************
 * Name:      ytsubApp.h
 * Purpose:   Defines Application Class
 * Author:    greensea (midoriumi@sohu.com)
 * Created:   2009-01-05
 * Copyright: greensea (http://www.gsea.com.cn)
 * License:
 **************************************************************/

#ifndef YTSUBAPP_H
#define YTSUBAPP_H

#define YTSUB_LINUX
/*#define YTSUB_WIN32*/

#include <wx/app.h>

#include "ytPlayer.h"
#include "YTFrame.h"
#include "ytsubMain.h"

class ytsubApp : public wxApp
{
    public:
        ytPlayer* player;
        kalaokFrame* kalaok;
        kalaEffectFrame* effectWindow;

        ytsubApp();
        virtual bool OnInit();
        //virtual bool openProject(const char* path);
        virtual bool openFilm(const char* path);

};


#endif // YTSUBAPP_H
