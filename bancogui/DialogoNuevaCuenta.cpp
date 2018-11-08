#include "DialogoNuevaCuenta.h"

//(*InternalHeaders(DialogoNuevaCuenta)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(DialogoNuevaCuenta)
const long DialogoNuevaCuenta::ID_STATICTEXT1 = wxNewId();
const long DialogoNuevaCuenta::ID_TEXTCTRL1 = wxNewId();
const long DialogoNuevaCuenta::ID_STATICTEXT2 = wxNewId();
const long DialogoNuevaCuenta::ID_CHOICE1 = wxNewId();
const long DialogoNuevaCuenta::ID_BUTTON1 = wxNewId();
const long DialogoNuevaCuenta::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(DialogoNuevaCuenta,wxDialog)
	//(*EventTable(DialogoNuevaCuenta)
	//*)
END_EVENT_TABLE()

DialogoNuevaCuenta::DialogoNuevaCuenta(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(DialogoNuevaCuenta)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;

	Create(parent, id, _("Crear nueva cuenta"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("ID Cuenta:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextCtrlCrearCuentaIdCuenta = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(140,23), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextCtrlCrearCuentaIdCuenta->Disable();
	BoxSizer2->Add(TextCtrlCrearCuentaIdCuenta, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Tipo de cuenta:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT2"));
	BoxSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ChoiceTipoDeCuenta = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(140,23), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	ChoiceTipoDeCuenta->SetSelection( ChoiceTipoDeCuenta->Append(_("Caja de Ahorro (CA)")) );
	ChoiceTipoDeCuenta->Append(_("Cuenta Corriente (CC)"));
	BoxSizer3->Add(ChoiceTipoDeCuenta, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	ButtonCrearCuentaCancelar = new wxButton(this, ID_BUTTON1, _("Cancelar"), wxDefaultPosition, wxSize(120,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	ButtonCrearCuentaCancelar->SetDefault();
	BoxSizer4->Add(ButtonCrearCuentaCancelar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ButtonCrearCuentaCrear = new wxButton(this, ID_BUTTON2, _("Crear"), wxPoint(120,23), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer4->Add(ButtonCrearCuentaCrear, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);

	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&DialogoNuevaCuenta::OnChoiceTipoDeCuentaSelect);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogoNuevaCuenta::OnButtonCrearCuentaCancelarClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&DialogoNuevaCuenta::OnButtonCrearCuentaCrearClick);
	//*)
}

DialogoNuevaCuenta::~DialogoNuevaCuenta()
{
	//(*Destroy(DialogoNuevaCuenta)
	//*)
}

void DialogoNuevaCuenta::setIdCuenta(wxString id){
    TextCtrlCrearCuentaIdCuenta->SetValue(id);
}




void DialogoNuevaCuenta::OnButtonCrearCuentaCancelarClick(wxCommandEvent& event)
{
    Close();
}


void DialogoNuevaCuenta::OnButtonCrearCuentaCrearClick(wxCommandEvent& event)
{
    dialogoTipoCuenta = ChoiceTipoDeCuenta->GetSelection();
    AcceptAndClose();
}

void DialogoNuevaCuenta::OnChoiceTipoDeCuentaSelect(wxCommandEvent& event)
{
}
