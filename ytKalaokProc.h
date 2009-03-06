#include "wx/wx.h"

#ifndef YTKAKAOLPROC_H_INCLUDED
#define YTKAKAOLPROC_H_INCLUDED

class ytKalaokProc
{
    private:
        wxString blocks[1002];
        wxString symbols;
        double times[1002];
        long blockPos;
        long blockNum;
        double ktimer;

        bool isSymbolChar(wxString& c);

    public:
        ytKalaokProc();
        ytKalaokProc(const wxString& con);
        ~ytKalaokProc();

        bool setContent(const wxString& con);
        wxString getContent();
        void reset();
        void clear();
        long ting();
        long ting(int skip, bool isCut);
        long tingCut();
        bool resetPos(long ipos);
};

#endif // YTKAKAOLPROC_H_INCLUDED
