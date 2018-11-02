#include "crearCliente.h"

//(*InternalHeaders(crearCliente)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(crearCliente)
//*)

BEGIN_EVENT_TABLE(crearCliente,wxDialog)
	//(*EventTable(crearCliente)
	//*)
END_EVENT_TABLE()

crearCliente::crearCliente(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(crearCliente)
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	//*)
}

crearCliente::~crearCliente()
{
	//(*Destroy(crearCliente)
	//*)
}

