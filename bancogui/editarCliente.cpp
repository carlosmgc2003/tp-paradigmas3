#include "editarCliente.h"
#include "wx/msgdlg.h"

//(*InternalHeaders(editarCliente)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(editarCliente)
const long editarCliente::ID_STATICTEXT5 = wxNewId();
const long editarCliente::ID_TEXTCTRL3 = wxNewId();
const long editarCliente::ID_STATICTEXT4 = wxNewId();
const long editarCliente::ID_TEXTCTRL4 = wxNewId();
const long editarCliente::ID_STATICTEXT3 = wxNewId();
const long editarCliente::ID_TEXTCTRL5 = wxNewId();
const long editarCliente::ID_STATICTEXT1 = wxNewId();
const long editarCliente::ID_TEXTCTRL1 = wxNewId();
const long editarCliente::ID_STATICTEXT2 = wxNewId();
const long editarCliente::ID_TEXTCTRL2 = wxNewId();
const long editarCliente::ID_BUTTONEDITARCLIENTECANCELAR = wxNewId();
const long editarCliente::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(editarCliente,wxDialog)
    //(*EventTable(editarCliente)
    //*)
END_EVENT_TABLE()

editarCliente::editarCliente(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(editarCliente)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer7;

    Create(parent, id, _("Editar Cliente"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("DNI:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT5"));
    BoxSizer5->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlEditarClienteDNI = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(140,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrlEditarClienteDNI->Disable();
    BoxSizer5->Add(TextCtrlEditarClienteDNI, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Nombre:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT4"));
    BoxSizer6->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlEditarClienteNombre = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(140,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    TextCtrlEditarClienteNombre->Disable();
    BoxSizer6->Add(TextCtrlEditarClienteNombre, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Apellido:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT3"));
    BoxSizer7->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlEditarClienteApellido = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(140,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrlEditarClienteApellido->Disable();
    BoxSizer7->Add(TextCtrlEditarClienteApellido, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Direccion:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlEditarClienteDireccion = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(140,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer2->Add(TextCtrlEditarClienteDireccion, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Telefono:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT2"));
    BoxSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlEditarClienteTelefono = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(140,21), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer3->Add(TextCtrlEditarClienteTelefono, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    ButtonEditarClienteCancelar = new wxButton(this, ID_BUTTONEDITARCLIENTECANCELAR, _("Cancelar"), wxDefaultPosition, wxSize(120,23), 0, wxDefaultValidator, _T("ID_BUTTONEDITARCLIENTECANCELAR"));
    BoxSizer4->Add(ButtonEditarClienteCancelar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ButtonEditarClienteGuardar = new wxButton(this, ID_BUTTON2, _("Guardar"), wxDefaultPosition, wxSize(120,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer4->Add(ButtonEditarClienteGuardar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTONEDITARCLIENTECANCELAR,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editarCliente::OnButtonEditarClienteCancelarClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&editarCliente::OnButtonEditarClienteGuardarClick);
    //*)
}

editarCliente::~editarCliente()
{
    //(*Destroy(editarCliente)
    //*)
}


void editarCliente::OnButton1Click(wxCommandEvent& event)
{
}

void editarCliente::setDialogoApellido(wxString apellido)
{
    apellido.Replace("_"," ");
    TextCtrlEditarClienteApellido->SetValue(apellido);
}

void editarCliente::setDialogoDNI(int dni)
{
    wxString documento;
    documento << dni;
    TextCtrlEditarClienteDNI->SetValue(documento);
}

void editarCliente::setDialogoNombre(wxString nombre)
{
    nombre.Replace("_"," ");
    TextCtrlEditarClienteNombre->SetValue(nombre);
}

void editarCliente::setDialogoTelefono(wxString telefono)
{
    TextCtrlEditarClienteTelefono->SetValue(telefono);
}

void editarCliente::setDialogoDireccion(wxString direccion)
{
    direccion.Replace("_"," ");
    TextCtrlEditarClienteDireccion->SetValue(direccion);
}

wxString editarCliente::getDialogoDireccion()
{
    dialogoDireccion.Replace(" ","_");
    return dialogoDireccion;
}

wxString editarCliente::getDialogoTelefono()
{
    return dialogoTelefono;
}

void editarCliente::OnButtonEditarClienteCancelarClick(wxCommandEvent& event)
{
    Close();
}

void editarCliente::OnButtonEditarClienteGuardarClick(wxCommandEvent& event)
{
    dialogoDireccion = TextCtrlEditarClienteDireccion->GetValue();
    dialogoTelefono = TextCtrlEditarClienteTelefono->GetValue();
    if(dialogoDireccion.size() == 0)
    {
        wxMessageBox(_("No se puede dejar dirección vacio"),_("Error"));
    }
    else
    {
        if(dialogoTelefono.size() == 0)
        {
            wxMessageBox(_("No se puede dejar teléfono vacío"),_("Error"));
        }
        else
            AcceptAndClose();
    }
}
