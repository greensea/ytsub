#include "kalaEffect.h"
#include "wx/dir.h"
#include "tinyxml.h"

kalaEffect* kalaEffect_var_head = NULL;
kalaEffect* kalaEffect_var_foot = NULL;
long kalaEffect_var_count = 0;
long kalaEffect_var_nextID = -1;

const char* elemText(TiXmlElement* elem)
{
    if(elem) return elem->GetText();
    return 0;
}

wxString kalaEffect_get_modelString(long id){
    kalaEffect* p = kalaEffect_var_head;
    while(p){
        if(p->id == id) return p->modelString;
    }
    return wxT("");
}

int kalaEffect_add_effect(wxString& wxPath){
    char path[1024];
    strcpy(path, wxPath.mb_str());
    TiXmlDocument doc(path);
    doc.LoadFile();
    TiXmlElement* rootElem = doc.RootElement();
    //printf("ytsub: %s\n", rootElem->FirstChildElement("Name")->GetText());

    kalaEffect* effect = new kalaEffect;
    effect->next = NULL;
    effect->id = ++kalaEffect_var_nextID;
    effect->name = wxString(elemText(rootElem->FirstChildElement("Name")), wxConvUTF8);
    effect->description = wxString(elemText(rootElem->FirstChildElement("Description")), wxConvUTF8);
    effect->modelString = wxString(elemText(rootElem->FirstChildElement("ModelString")), wxConvUTF8);
    effect->author = wxString(elemText(rootElem->FirstChildElement("Author")), wxConvUTF8);
    effect->homepage = wxString(elemText(rootElem->FirstChildElement("Homepage")), wxConvUTF8);
    effect->email = wxString(elemText(rootElem->FirstChildElement("Email")), wxConvUTF8);

    // Add effect to linklist
    if(kalaEffect_var_foot){
        kalaEffect_var_foot->next = effect;
        kalaEffect_var_foot = effect;
    }
    else{
        kalaEffect_var_head = kalaEffect_var_foot = effect;
    }
    kalaEffect_var_count++;
    return 0;
}

int kalaEffect_load(const wxString& folder){
    wxDir* dir = new wxDir(wxGetCwd() + folder);
    wxString filename;
    bool cont = dir->GetFirst(&filename, _T("*.xml"), wxDIR_FILES);
    printf("ytsub: Loading Kalaok effect plugins");
    while(cont){
        printf(".");
        filename = wxGetCwd() + wxT("/plugins/kalaok/") + filename;
        kalaEffect_add_effect(filename);
        cont = dir->GetNext(&filename);
    }
    printf(" done\n");
    return 0;
}
