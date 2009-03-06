#ifndef KALAEFFECT_H_INCLUDED
#define KALAEFFECT_H_INCLUDED


#include "wx/wx.h"
#include "wx/string.h"

struct kalaEffect{
    long id;
    wxString name;
    wxString description;
    wxString modelString;
    wxString author;
    wxString homepage;
    wxString email;
    kalaEffect* next;
};

wxString kalaEffect_get_modelString(long id);
int kalaEffect_add_effect(wxString& wxPath);
int kalaEffect_load(const wxString& folder);

extern long kalaEffect_var_nextID;
extern long kalaEffect_var_count;
extern kalaEffect* kalaEffect_var_foot;
extern kalaEffect* kalaEffect_var_head;

#endif // KALAEFFECT_H_INCLUDED
