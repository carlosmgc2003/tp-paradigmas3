#ifndef DIALOGOLISTADECUENTAS_H
#define DIALOGOLISTADECUENTAS_H

//(*Headers(dialogoListadeCuentas)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)
#include "banco.hpp"

class dialogoListadeCuentas: public wxDialog
{
public:

    dialogoListadeCuentas(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~dialogoListadeCuentas();
    Banco * banco;

    //(*Declarations(dialogoListadeCuentas)
    wxButton* ButtonDialogoListadeCuentasCerrar;
    wxListCtrl* ListCtrlListaDeCuentas;
    wxPanel* Panel1;
    //*)

protected:

    //(*Identifiers(dialogoListadeCuentas)
    static const long ID_LISTCTRLLISTADECUENTAS;
    static const long ID_BUTTONDIALOGOLISTADECUENTASCERRAR;
    static const long ID_PANEL1;
    //*)

private:

    //(*Handlers(dialogoListadeCuentas)
    void OnListCtrl1BeginDrag(wxListEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
