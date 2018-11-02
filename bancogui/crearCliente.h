#ifndef CREARCLIENTE_H
#define CREARCLIENTE_H

//(*Headers(crearCliente)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
#include "banco.hpp"

class crearCliente: public wxDialog
{
	public:

		crearCliente(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~crearCliente();

		//(*Declarations(crearCliente)
		wxButton* ButtonNuevoClienteCancelar;
		wxButton* ButtonNuevoClienteGuardar;
		wxStaticText* etiquetaNuevoCliente1;
		wxStaticText* etiquetaNuevoCliente2;
		wxStaticText* etiquetaNuevoCliente3;
		wxStaticText* etiquetaNuevoCliente4;
		wxStaticText* etiquetaNuevoCliente5;
		wxTextCtrl* TextCtrlNuevoClienteApellido;
		wxTextCtrl* TextCtrlNuevoClienteDNI;
		wxTextCtrl* TextCtrlNuevoClienteDireccion;
		wxTextCtrl* TextCtrlNuevoClienteNombre;
		wxTextCtrl* TextCtrlNuevoClienteTelefono;
		//*)

	protected:

		//(*Identifiers(crearCliente)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRLNUEVOCLIENTEDNI;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRLNUEVOCLIENTENOMBRE;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRLNUEVOCLIENTEAPELLIDO;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRLNUEVOCLIENTEDIRECCION;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRLNUEVOCLIENTETELEFONO;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(crearCliente)
		void OnInit(wxInitDialogEvent& event);
		void OnButtonNuevoClienteCancelarClick(wxCommandEvent& event);
		void OnButtonNuevoClienteGuardarClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
