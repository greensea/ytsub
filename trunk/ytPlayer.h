#ifndef YTPLAYER_H_INCLUDED
#define YTPLAYER_H_INCLUDED

#include "wx/wx.h"

class ytPlayer
{
    protected:
        FILE* mp;

    public:
        ytPlayer();
        ~ytPlayer();
        bool loadFilm(const char* path);
        bool loadSub(const char* path);
        void play();
        void pause();
        void stop();
        void seek(double pos);
        double getCurrentTime();
};

#endif // YTPLAYER_H_INCLUDED
