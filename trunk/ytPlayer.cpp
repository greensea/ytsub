/***************************************************************
 * Name:      ytsubMain.cpp
 * Purpose:   Code for Application Frame
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
#include "ytPlayer.h"
#include "kalaEffect.h"

DECLARE_APP(ytsubApp)

ytPlayer::ytPlayer()
{
    mp = NULL;
}

ytPlayer::~ytPlayer()
{
    if(mp != NULL){
        fputs("quit", mp);
        pclose(mp);
        mp = NULL;
    }
}

bool ytPlayer::loadFilm(const char* path)
{
    char cmd[5000];

    if(mp) return false;

    unlink("/tmp/cmd");
    mkfifo("/tmp/cmd", 0777);
    sprintf(cmd, "mplayer -vo x11 -zoom -quiet -slave -input file=/tmp/cmd '%s'", path);
    printf("ytsub exec: %s\n", cmd);
    mp = popen(cmd, "r");
    if(mp == NULL) return false;
    wxGetApp().kalaok->Show();
    return true;
}

double ytPlayer::getCurrentTime()
{
    double t;
    char buf[1002] = {0};

    if(mp == NULL) return -1.0;

    system("echo \"get_time_pos\" >/tmp/cmd");
    do{

        //fread(buf, 2000, 1, mp);
        fgets(buf, 1000, mp);
        printf("ytsub: get_time_pos return buf=%s", buf);
    }while(strncmp(buf, "ANS_TIME_POSITION=", strlen("ANS_TIME_POSITION=")) != 0);


    t = atof(buf + strlen("ANS_TIME_POSITION="));

    printf("ytsub: getCurrentTime return %lf\n", t);
    return t;
}
