// *** ADDED BY HEADER FIXUP ***
#include <string>
// *** END ***
#include "crearCliente.h"
#include <wx/msgdlg.h>
#include <wx/valnum.h>

//(*InternalHeaders(crearCliente)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(crearCliente)
const long crearCliente::ID_STATICTEXT1 = wxNewId();
const long crearCliente::ID_TEXTCTRLNUEVOCLIENTEDNI = wxNewId();
const long crearCliente::ID_STATICTEXT2 = wxNewId();
const long crearCliente::ID_TEXTCTRLNUEVOCLIENTENOMBRE = wxNewId();
const long crearCliente::ID_STATICTEXT3 = wxNewId();
const long crearCliente::ID_TEXTCTRLNUEVOCLIENTEAPELLIDO = wxNewId();
const long crearCliente::ID_STATICTEXT4 = wxNewId();
const long crearCliente::ID_TEXTCTRLNUEVOCLIENTEDIRECCION = wxNewId();
const long crearCliente::ID_STATICTEXT5 = wxNewId();
const long crearCliente::ID_TEXTCTRLNUEVOCLIENTETELEFONO = wxNewId();
const long crearCliente::ID_BUTTON1 = wxNewId();
const long crearCliente::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(crearCliente,wxDialog)
    //(*EventTable(crearCliente)
    //*)
END_EVENT_TABLE()

crearCliente::crearCliente(wxWindow* parent,wxWindowID id)
{
    wxIntegerValidator<int> ValidarDNI(&nuevoDni,wxNUM_VAL_THOUSANDS_SEPARATOR);
    ValidarDNI.SetRange(0,99999999);
    //(*Initialize(crearCliente)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer7;

    Create(parent, id, _("Nuevo Cliente"), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_DIALOG_STYLE|wxTAB_TRAVERSAL, _T("id"));
    SetFocus();
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    etiquetaNuevoCliente1 = new wxStaticText(this, ID_STATICTEXT1, _("DNI:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(etiquetaNuevoCliente1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlNuevoClienteDNI = new wxTextCtrl(this, ID_TEXTCTRLNUEVOCLIENTEDNI, wxEmptyString, wxDefaultPosition, wxSize(140,23), 0, ValidarDNI, _T("ID_TEXTCTRLNUEVOCLIENTEDNI"));
    TextCtrlNuevoClienteDNI->SetMaxLength(8);
    BoxSizer2->Add(TextCtrlNuevoClienteDNI, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND|wxSHAPED, 1);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    etiquetaNuevoCliente2 = new wxStaticText(this, ID_STATICTEXT2, _("Nombre:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT2"));
    BoxSizer3->Add(etiquetaNuevoCliente2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlNuevoClienteNombre = new wxTextCtrl(this, ID_TEXTCTRLNUEVOCLIENTENOMBRE, wxEmptyString, wxDefaultPosition, wxSize(140,23), 0, wxDefaultValidator, _T("ID_TEXTCTRLNUEVOCLIENTENOMBRE"));
    TextCtrlNuevoClienteNombre->SetMaxLength(20);
    BoxSizer3->Add(TextCtrlNuevoClienteNombre, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxSHAPED, 1);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    etiquetaNuevoCliente3 = new wxStaticText(this, ID_STATICTEXT3, _("Apellido:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT3"));
    BoxSizer4->Add(etiquetaNuevoCliente3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlNuevoClienteApellido = new wxTextCtrl(this, ID_TEXTCTRLNUEVOCLIENTEAPELLIDO, wxEmptyString, wxDefaultPosition, wxSize(140,23), 0, wxDefaultValidator, _T("ID_TEXTCTRLNUEVOCLIENTEAPELLIDO"));
    TextCtrlNuevoClienteApellido->SetMaxLength(20);
    BoxSizer4->Add(TextCtrlNuevoClienteApellido, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer4, 1, wxALL|wxEXPAND|wxSHAPED, 1);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    etiquetaNuevoCliente4 = new wxStaticText(this, ID_STATICTEXT4, _("Direccion:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT4"));
    BoxSizer5->Add(etiquetaNuevoCliente4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlNuevoClienteDireccion = new wxTextCtrl(this, ID_TEXTCTRLNUEVOCLIENTEDIRECCION, wxEmptyString, wxDefaultPosition, wxSize(140,23), 0, wxDefaultValidator, _T("ID_TEXTCTRLNUEVOCLIENTEDIRECCION"));
    TextCtrlNuevoClienteDireccion->SetMaxLength(50);
    BoxSizer5->Add(TextCtrlNuevoClienteDireccion, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer5, 1, wxALL|wxEXPAND|wxSHAPED, 1);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    etiquetaNuevoCliente5 = new wxStaticText(this, ID_STATICTEXT5, _("Teléfono:"), wxDefaultPosition, wxSize(63,13), wxALIGN_RIGHT, _T("ID_STATICTEXT5"));
    BoxSizer6->Add(etiquetaNuevoCliente5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlNuevoClienteTelefono = new wxTextCtrl(this, ID_TEXTCTRLNUEVOCLIENTETELEFONO, wxEmptyString, wxDefaultPosition, wxSize(140,23), 0, wxDefaultValidator, _T("ID_TEXTCTRLNUEVOCLIENTETELEFONO"));
    BoxSizer6->Add(TextCtrlNuevoClienteTelefono, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer6, 1, wxALL|wxEXPAND|wxSHAPED, 1);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    ButtonNuevoClienteCancelar = new wxButton(this, ID_BUTTON1, _("Cancelar"), wxDefaultPosition, wxSize(120,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    ButtonNuevoClienteCancelar->SetDefault();
    BoxSizer7->Add(ButtonNuevoClienteCancelar, 1, wxALL|wxEXPAND, 5);
    ButtonNuevoClienteGuardar = new wxButton(this, ID_BUTTON2, _("Guardar"), wxDefaultPosition, wxSize(120,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer7->Add(ButtonNuevoClienteGuardar, 1, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_TEXTCTRLNUEVOCLIENTEDNI,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&crearCliente::OnTextCtrlNuevoClienteDNIText);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&crearCliente::OnButtonNuevoClienteCancelarClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&crearCliente::OnButtonNuevoClienteGuardarClick);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&crearCliente::OnInit);
    //*)

}


crearCliente::~crearCliente()
{
    //(*Destroy(crearCliente)
    //*)
}


void crearCliente::OnInit(wxInitDialogEvent& event)
{
}

void crearCliente::OnButtonNuevoClienteCancelarClick(wxCommandEvent& event)
{
    /*Cerrar la ventana sin guardar los cambios*/
    Close();
}

void crearCliente::OnButtonNuevoClienteGuardarClick(wxCommandEvent& event)
{
    /*Cuando hacemos click en guarda los valores de las cajas se pasan a
    los atributos de la clase
    dialogo para ser posteriormente recuperados por la ventana principal*/

    nuevoDni = wxAtoi(TextCtrlNuevoClienteDNI->GetValue());
    nuevoNombre = TextCtrlNuevoClienteNombre->GetValue();
    nuevoApellido = TextCtrlNuevoClienteApellido->GetValue();
    nuevoTelefono = TextCtrlNuevoClienteTelefono->GetValue();
    nuevoDireccion = TextCtrlNuevoClienteDireccion->GetValue();
    if(nuevoDni == 0)
    {
        wxMessageBox(_("El campo DNI no puede estar vacío!"),_("Error!"));
    }
    else if(nuevoNombre.size() == 0)
    {
        wxMessageBox(_("El campo Nombre no puede estar vacío!"),_("Error!"));
    }
    else
    {
        nuevoNombre.Replace(" ","_");
        if(nuevoApellido.size() == 0)
        {
            wxMessageBox(_("El campo Apellido no puede estar vacío!"),_("Error!"));
        }
        else
        {
            nuevoApellido.Replace(" ","_");
            if(nuevoTelefono.size() == 0)
            {
                wxMessageBox(_("El campo Telefono no puede estar vacío!"),_("Error!"));
            }
            else
            {
                nuevoTelefono.Replace(" ","_");
                if(nuevoDireccion.size() == 0)
                {
                    wxMessageBox(_("El campo Dirección no puede estar vacío!"),_("Error!"));
                }
                else
                {
                    nuevoDireccion.Replace(" ","_");
                    AcceptAndClose();
                }
            }
        }
    }
}


void crearCliente::OnTextCtrlNuevoClienteDNIText(wxCommandEvent& event)
{
}
