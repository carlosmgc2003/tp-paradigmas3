#ifndef CREARCLIENTE_H
#define CREARCLIENTE_H

//(*Headers(crearCliente)
#include <wx/dialog.h>
//*)

class crearCliente: public wxDialog
{
	public:

		crearCliente(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~crearCliente();

		//(*Declarations(crearCliente)
		//*)

	protected:

		//(*Identifiers(crearCliente)
		//*)

	private:

		//(*Handlers(crearCliente)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
