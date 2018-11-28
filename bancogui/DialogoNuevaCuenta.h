#ifndef DIALOGONUEVACUENTA_H
#define DIALOGONUEVACUENTA_H

//(*Headers(DialogoNuevaCuenta)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class DialogoNuevaCuenta: public wxDialog
{
public:

    DialogoNuevaCuenta(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~DialogoNuevaCuenta();
    void setIdCuenta(wxString);
    int getTipoCuenta()
    {
        return dialogoTipoCuenta;
    };

    //(*Declarations(DialogoNuevaCuenta)
    wxButton* ButtonCrearCuentaCancelar;
    wxButton* ButtonCrearCuentaCrear;
    wxChoice* ChoiceTipoDeCuenta;
    wxStaticText* StaticText1;
    wxStaticText* StaticText2;
    wxTextCtrl* TextCtrlCrearCuentaIdCuenta;
    //*)

protected:

    //(*Identifiers(DialogoNuevaCuenta)
    static const long ID_STATICTEXT1;
    static const long ID_TEXTCTRL1;
    static const long ID_STATICTEXT2;
    static const long ID_CHOICE1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    //*)

private:

    //(*Handlers(DialogoNuevaCuenta)
    void OnButtonCrearCuentaCancelarClick(wxCommandEvent& event);
    void OnButtonCrearCuentaCrearClick(wxCommandEvent& event);
    void OnChoiceTipoDeCuentaSelect(wxCommandEvent& event);
    //*)

    int dialogoTipoCuenta;
    wxString dialogoIdCuenta;

    DECLARE_EVENT_TABLE()
};

#endif
