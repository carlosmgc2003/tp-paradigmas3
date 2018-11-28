// *** ADDED BY HEADER FIXUP ***
#include <string>
// *** END ***
#include "dialogoListadeCuentas.h"

//(*InternalHeaders(dialogoListadeCuentas)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dialogoListadeCuentas)
const long dialogoListadeCuentas::ID_LISTCTRLLISTADECUENTAS = wxNewId();
const long dialogoListadeCuentas::ID_BUTTONDIALOGOLISTADECUENTASCERRAR = wxNewId();
const long dialogoListadeCuentas::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dialogoListadeCuentas,wxDialog)
    //(*EventTable(dialogoListadeCuentas)
    //*)
END_EVENT_TABLE()

dialogoListadeCuentas::dialogoListadeCuentas(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(dialogoListadeCuentas)
    wxBoxSizer* BoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;

    Create(parent, id, _("Lista de Cuentas Activas"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer1 = new wxFlexGridSizer(2, 1, 0, 0);
    ListCtrlListaDeCuentas = new wxListCtrl(Panel1, ID_LISTCTRLLISTADECUENTAS, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRLLISTADECUENTAS"));
    FlexGridSizer1->Add(ListCtrlListaDeCuentas, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonDialogoListadeCuentasCerrar = new wxButton(Panel1, ID_BUTTONDIALOGOLISTADECUENTASCERRAR, _("Cerrar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONDIALOGOLISTADECUENTASCERRAR"));
    FlexGridSizer1->Add(ButtonDialogoListadeCuentasCerrar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel1);
    FlexGridSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_LISTCTRLLISTADECUENTAS,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&dialogoListadeCuentas::OnListCtrl1BeginDrag);
    Connect(ID_BUTTONDIALOGOLISTADECUENTASCERRAR,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dialogoListadeCuentas::OnButton1Click);
    //*)
    ListCtrlListaDeCuentas->InsertColumn(0,"Nro Cuenta");
    ListCtrlListaDeCuentas->InsertColumn(1,"Tipo",wxLIST_FORMAT_LEFT,40);
    ListCtrlListaDeCuentas->InsertColumn(2,"Saldo");

}

dialogoListadeCuentas::~dialogoListadeCuentas()
{
    //(*Destroy(dialogoListadeCuentas)
    //*)
}


void dialogoListadeCuentas::OnListCtrl1BeginDrag(wxListEvent& event)
{
}

void dialogoListadeCuentas::OnButton1Click(wxCommandEvent& event)
{
    Close();
}
