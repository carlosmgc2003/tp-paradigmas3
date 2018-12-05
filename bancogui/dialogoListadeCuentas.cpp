// *** ADDED BY HEADER FIXUP ***
#include <string>
#include "bancoguiMain.h"
// *** END ***
#include "dialogoListadeCuentas.h"
//(*InternalHeaders(dialogoListadeCuentas)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(dialogoListadeCuentas)
const long dialogoListadeCuentas::ID_CHOICELISTADECUENTAS = wxNewId();
const long dialogoListadeCuentas::ID_LISTCTRLLISTADECUENTAS = wxNewId();
const long dialogoListadeCuentas::ID_BUTTONDIALOGOLISTADECUENTASCERRAR = wxNewId();
const long dialogoListadeCuentas::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dialogoListadeCuentas,wxDialog)
    //(*EventTable(dialogoListadeCuentas)
    //*)
END_EVENT_TABLE()



dialogoListadeCuentas::dialogoListadeCuentas(wxWindow* parent,Banco * banco,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    bancoPtr = banco;
    //(*Initialize(dialogoListadeCuentas)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;

    Create(parent, id, _("Lista de Cuentas Activas"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    ChoiceListadeCuentas = new wxChoice(Panel1, ID_CHOICELISTADECUENTAS, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICELISTADECUENTAS"));
    ChoiceListadeCuentas->SetSelection( ChoiceListadeCuentas->Append(_("Cuentas Activas")) );
    ChoiceListadeCuentas->Append(_("Cuentas con saldo $0"));
    ChoiceListadeCuentas->Append(_("Cuentas con saldo negativo"));
    ChoiceListadeCuentas->Append(_("Cuentas con saldo positivo"));
    BoxSizer2->Add(ChoiceListadeCuentas, 0, wxEXPAND, 0);
    ListCtrlListaDeCuentas = new wxListCtrl(Panel1, ID_LISTCTRLLISTADECUENTAS, wxDefaultPosition, wxSize(204,270), wxLC_REPORT, wxDefaultValidator, _T("ID_LISTCTRLLISTADECUENTAS"));
    BoxSizer2->Add(ListCtrlListaDeCuentas, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    ButtonDialogoListadeCuentasCerrar = new wxButton(Panel1, ID_BUTTONDIALOGOLISTADECUENTASCERRAR, _("Cerrar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONDIALOGOLISTADECUENTASCERRAR"));
    BoxSizer2->Add(ButtonDialogoListadeCuentasCerrar, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);
    Center();

    Connect(ID_CHOICELISTADECUENTAS,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&dialogoListadeCuentas::OnChoiceListadeCuentasSelect);
    Connect(ID_LISTCTRLLISTADECUENTAS,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&dialogoListadeCuentas::OnListCtrl1BeginDrag);
    Connect(ID_BUTTONDIALOGOLISTADECUENTASCERRAR,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dialogoListadeCuentas::OnButton1Click);
    //*)
    ListCtrlListaDeCuentas->InsertColumn(0,"Nro Cuenta");
    ListCtrlListaDeCuentas->InsertColumn(1,"Tipo",wxLIST_FORMAT_LEFT,40);
    ListCtrlListaDeCuentas->InsertColumn(2,"Saldo");
    for(int i = 0;i < bancoPtr->clientesActivos.size(); i ++)
        ListarCuentasTodas(bancoPtr->clientesActivos[i],* ListCtrlListaDeCuentas);

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

void dialogoListadeCuentas::OnChoiceListadeCuentasSelect(wxCommandEvent& event)
{
    switch (ChoiceListadeCuentas->GetSelection())
    {
    case 0:
        ListCtrlListaDeCuentas->DeleteAllItems();
        for(int i = 0;i < bancoPtr->clientesActivos.size(); i ++)
            ListarCuentasTodas(bancoPtr->clientesActivos[i],* ListCtrlListaDeCuentas);
        break;
    case 1:
        ListCtrlListaDeCuentas->DeleteAllItems();
        for(int i = 0;i < bancoPtr->clientesActivos.size(); i ++)
            ListarCuentasCero(bancoPtr->clientesActivos[i],* ListCtrlListaDeCuentas);
        break;
    case 2:
        ListCtrlListaDeCuentas->DeleteAllItems();
        for(int i = 0;i < bancoPtr->clientesActivos.size(); i ++)
            ListarCuentasNegativo(bancoPtr->clientesActivos[i],* ListCtrlListaDeCuentas);
        break;
    case 3:
        ListCtrlListaDeCuentas->DeleteAllItems();
        for(int i = 0;i < bancoPtr->clientesActivos.size(); i ++)
            ListarCuentasPositivo(bancoPtr->clientesActivos[i],* ListCtrlListaDeCuentas);
        break;
    default:
        break;
    }
}

void ListarCuentasTodas(Cliente & cliente,wxListCtrl & Lista)
{
    if(cliente.contarCuentasCliente() > 0)
    {
        for(int i = 0; i < cliente.contarCuentasCliente(); i++)
        {
            wxString IDCUENTA;
            IDCUENTA << cliente[i].getdniDuenio();
            wxString auxiliar;
            auxiliar << cliente[i].getnumeroUnico();
            IDCUENTA.append(auxiliar);
            wxString SALDO;
            SALDO << cliente[i].getSaldo();
            SALDO.resize(SALDO.Find(".") + 3 );
            Lista.InsertItem(i,_("Cuenta"));
            Lista.SetItem(i,0,IDCUENTA);
            if(cliente[i].gettipoCuenta() == 0)
            {
                Lista.SetItem(i,1,_("CA"));
            }
            else
                Lista.SetItem(i,1,_("CC"));
            Lista.SetItem(i,2,SALDO);
        }
    }
}
void ListarCuentasCero(Cliente & cliente,wxListCtrl & Lista)
{
    if(cliente.contarCuentasCliente() > 0)
    {
        int indiceLista = 0;
        for(int i = 0; i < cliente.contarCuentasCliente(); i++)
        {
            wxString IDCUENTA;
            IDCUENTA << cliente[i].getdniDuenio();
            wxString auxiliar;
            auxiliar << cliente[i].getnumeroUnico();
            IDCUENTA.append(auxiliar);
            wxString SALDO;
            SALDO << cliente[i].getSaldo();
            SALDO.resize(SALDO.Find(".") + 3 );
            if(cliente[i].getSaldo() == 0.0)
            {
                Lista.InsertItem(indiceLista,_("Cuenta"));
                Lista.SetItem(indiceLista,0,IDCUENTA);
                if(cliente[i].gettipoCuenta() == 0)
                {
                    Lista.SetItem(indiceLista,1,_("CA"));
                }
                else
                    Lista.SetItem(indiceLista,1,_("CC"));
                Lista.SetItem(indiceLista,2,SALDO);
                indiceLista ++;
            }
        }
    }
}

void ListarCuentasNegativo(Cliente & cliente,wxListCtrl & Lista)
{
    if(cliente.contarCuentasCliente() > 0)
    {
        int indiceLista = 0;
        for(int i = 0; i < cliente.contarCuentasCliente(); i++)
        {
            wxString IDCUENTA;
            IDCUENTA << cliente[i].getdniDuenio();
            wxString auxiliar;
            auxiliar << cliente[i].getnumeroUnico();
            IDCUENTA.append(auxiliar);
            wxString SALDO;
            SALDO << cliente[i].getSaldo();
            SALDO.resize(SALDO.Find(".") + 3 );
            if(cliente[i].getSaldo() < 0.0)
            {
                Lista.InsertItem(indiceLista,_("Cuenta"));
                Lista.SetItem(indiceLista,0,IDCUENTA);
                if(cliente[i].gettipoCuenta() == 0)
                {
                    Lista.SetItem(indiceLista,1,_("CA"));
                }
                else
                    Lista.SetItem(indiceLista,1,_("CC"));
                Lista.SetItem(indiceLista,2,SALDO);
                indiceLista ++;
            }
        }
    }
}
void ListarCuentasPositivo(Cliente & cliente,wxListCtrl & Lista)
{
    if(cliente.contarCuentasCliente() > 0)
    {
        int indiceLista = 0;
        for(int i = 0; i < cliente.contarCuentasCliente(); i++)
        {
            wxString IDCUENTA;
            IDCUENTA << cliente[i].getdniDuenio();
            wxString auxiliar;
            auxiliar << cliente[i].getnumeroUnico();
            IDCUENTA.append(auxiliar);
            wxString SALDO;
            SALDO << cliente[i].getSaldo();
            SALDO.resize(SALDO.Find(".") + 3 );
            if(cliente[i].getSaldo() > 0.0)
            {
                Lista.InsertItem(indiceLista,_("Cuenta"));
                Lista.SetItem(indiceLista,0,IDCUENTA);
                if(cliente[i].gettipoCuenta() == 0)
                {
                    Lista.SetItem(indiceLista,1,_("CA"));
                }
                else
                    Lista.SetItem(indiceLista,1,_("CC"));
                Lista.SetItem(indiceLista,2,SALDO);
                indiceLista ++;
            }
        }
    }
}
