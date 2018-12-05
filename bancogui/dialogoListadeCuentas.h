#ifndef DIALOGOLISTADECUENTAS_H
#define DIALOGOLISTADECUENTAS_H

//(*Headers(dialogoListadeCuentas)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/listctrl.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)
#include "banco.hpp"
void ListarCuentasTodas(Cliente & cliente,wxListCtrl & Lista);
void ListarCuentasCero(Cliente & cliente,wxListCtrl & Lista);
void ListarCuentasNegativo(Cliente & cliente,wxListCtrl & Lista);
void ListarCuentasPositivo(Cliente & cliente,wxListCtrl & Lista);
class dialogoListadeCuentas: public wxDialog
{
public:

    dialogoListadeCuentas(wxWindow* parent,Banco * banco,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~dialogoListadeCuentas();
    //(*Declarations(dialogoListadeCuentas)
    wxButton* ButtonDialogoListadeCuentasCerrar;
    wxChoice* ChoiceListadeCuentas;
    wxListCtrl* ListCtrlListaDeCuentas;
    wxPanel* Panel1;
    //*)

protected:

    //(*Identifiers(dialogoListadeCuentas)
    static const long ID_CHOICELISTADECUENTAS;
    static const long ID_LISTCTRLLISTADECUENTAS;
    static const long ID_BUTTONDIALOGOLISTADECUENTASCERRAR;
    static const long ID_PANEL1;
    //*)

private:

    //(*Handlers(dialogoListadeCuentas)
    void OnListCtrl1BeginDrag(wxListEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    void OnChoiceListadeCuentasSelect(wxCommandEvent& event);
    //*)
    Banco * bancoPtr;

    DECLARE_EVENT_TABLE()
};

#endif
