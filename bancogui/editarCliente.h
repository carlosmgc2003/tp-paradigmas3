#ifndef EDITARCLIENTE_H
#define EDITARCLIENTE_H

//(*Headers(editarCliente)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class editarCliente: public wxDialog
{
public:

    editarCliente(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~editarCliente();

    void setDialogoDNI(int);
    void setDialogoNombre(wxString);
    void setDialogoApellido(wxString);
    void setDialogoDireccion(wxString);
    void setDialogoTelefono(wxString);
    wxString getDialogoDireccion();
    wxString getDialogoTelefono();

    //(*Declarations(editarCliente)
    wxButton* ButtonEditarClienteCancelar;
    wxButton* ButtonEditarClienteGuardar;
    wxStaticText* StaticText1;
    wxStaticText* StaticText2;
    wxStaticText* StaticText3;
    wxStaticText* StaticText4;
    wxStaticText* StaticText5;
    wxTextCtrl* TextCtrlEditarClienteApellido;
    wxTextCtrl* TextCtrlEditarClienteDNI;
    wxTextCtrl* TextCtrlEditarClienteDireccion;
    wxTextCtrl* TextCtrlEditarClienteNombre;
    wxTextCtrl* TextCtrlEditarClienteTelefono;
    //*)

protected:

    //(*Identifiers(editarCliente)
    static const long ID_STATICTEXT5;
    static const long ID_TEXTCTRL3;
    static const long ID_STATICTEXT4;
    static const long ID_TEXTCTRL4;
    static const long ID_STATICTEXT3;
    static const long ID_TEXTCTRL5;
    static const long ID_STATICTEXT1;
    static const long ID_TEXTCTRL1;
    static const long ID_STATICTEXT2;
    static const long ID_TEXTCTRL2;
    static const long ID_BUTTONEDITARCLIENTECANCELAR;
    static const long ID_BUTTON2;
    //*)

private:

    //(*Handlers(editarCliente)
    void OnButton1Click(wxCommandEvent& event);
    void OnButtonEditarClienteCancelarClick(wxCommandEvent& event);
    void OnButtonEditarClienteGuardarClick(wxCommandEvent& event);
    //*)

    wxString dialogoDni;
    wxString dialogoNombre;
    wxString dialogoApellido;
    wxString dialogoTelefono;
    wxString dialogoDireccion;

    DECLARE_EVENT_TABLE()
};

#endif
