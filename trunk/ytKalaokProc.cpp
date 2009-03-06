#include "ytKalaokProc.h"
#include "ytsubApp.h"

DECLARE_APP(ytsubApp)

ytKalaokProc::ytKalaokProc()
{
    blockNum = 0;
    symbols = wxString("\n 　？.。！?,!", wxConvUTF8);
}

ytKalaokProc::ytKalaokProc(const wxString& con)
{
    setContent(con);
}

ytKalaokProc::~ytKalaokProc()
{
}

bool ytKalaokProc::setContent(const wxString& con)
{
    blockNum = con.Length();
    if(blockNum > 1000) return false;
    int i;
    for(i = 0; i < blockNum; i++){
        blocks[i] = con.Mid(i, 1);
    }
    reset();
    return true;
}

wxString ytKalaokProc::getContent()
{
    wxString result;
    char tmp[100];
    int i;
    for(i = 0; i < blockNum; i++){
        if(times[i] >= 0.0){
            sprintf(tmp, "{k%.0lf}", times[i] / 10);
            result += wxString(tmp, wxConvUTF8);
        }
        result += blocks[i];
    }
    return result;
}

void ytKalaokProc::reset()
{
    blockPos = 0;
    ktimer = -1;
    int i;
    for(i = 0; i < 1000; i++) times[i] = -1.0;
}

void ytKalaokProc::clear()
{
    blockNum = 0;
    reset();
}

long ytKalaokProc::ting()
{
    return ting(0, false);
}

long ytKalaokProc::ting(int skip, bool isCut)
{
    while(blocks[blockPos] == wxString("\n", wxConvUTF8)
        || blocks[blockPos] == wxString(" ", wxConvUTF8)
        || blocks[blockPos] == wxString("　", wxConvUTF8)
        || blocks[blockPos] == wxString("!", wxConvUTF8)
        || blocks[blockPos] == wxString(".", wxConvUTF8)
        || blocks[blockPos] == wxString(",", wxConvUTF8)
        || blocks[blockPos] == wxString("?", wxConvUTF8)
        || blocks[blockPos] == wxString("？", wxConvUTF8)
        || blocks[blockPos] == wxString("。", wxConvUTF8)
        || blocks[blockPos] == wxString("！", wxConvUTF8)
    ){
        times[blockPos] = -2;
        blockPos++;
        if(blockPos > blockNum) return -1;
    }

    if(skip > 0){
        blockPos += skip;
    }
    else{
        double curtime = wxGetApp().player->getCurrentTime();
        if(ktimer > 0){
            times[blockPos] = (curtime - ktimer) * 1000;
            printf("ytsub: set times[%ld]=%lf\n", blockPos, times[blockPos]);
            blockPos++;
            if(isCut){
                ktimer = -1;
            }
            else{
                ktimer = curtime;
            }
        }
        else{
            ktimer = curtime;
        }
    }
    // return next position that should be proc
    while(isSymbolChar(blocks[blockPos])){
        blockPos++;
        if(blockPos > blockNum) return -2;
    }
    printf("ytsub: return blockPos=%ld\n", blockPos);
    return blockPos;
}

long ytKalaokProc::tingCut()
{
    return ting(0, true);
}

bool ytKalaokProc::resetPos(long ipos)
{
    long i;
    if(ipos > blockNum) ipos = 0;
    blockPos = ipos;
    for(i = 0; i < blockNum; i++) times[i] = -1;
    return true;
}

bool ytKalaokProc::isSymbolChar(wxString& c)
{
    unsigned long i;
    for(i = 0; i < symbols.Length(); i++){
        if(symbols.Mid(i, 1) == c) return true;
    }
    return false;
}
