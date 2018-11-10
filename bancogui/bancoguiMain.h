/***************************************************************
 * Name:      bancoguiMain.h
 * Purpose:   Defines Application Frame
 * Author:    Team C++ (carlosmgc2003@gmail.com)
 * Created:   2018-10-31
 * Copyright: Team C++ (https://github.com/carlosmgc2003/tp-paradigmas3.git)
 * License:
 **************************************************************/

#ifndef BANCOGUIMAIN_H
#define BANCOGUIMAIN_H

//(*Headers(bancoguiFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/listctrl.h>
#include <wx/menu.h>
#include <wx/msgdlg.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

#include "banco.hpp"

class bancoguiFrame: public wxFrame
{
    public:

        bancoguiFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~bancoguiFrame();
        Banco CrisNaMa;
        int ClienteSeleccionado;
        int CuentaSeleccionada;

    private:

        //(*Handlers(bancoguiFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnListCtrl1BeginDrag(wxListEvent& event);
        void OnListCtrl1BeginDrag1(wxListEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnBtnEditarClienteClick(wxCommandEvent& event);
        void OnbtnCrearClienteClick(wxCommandEvent& event);
        void OnbtnCrearClienteClick2(wxCommandEvent& event);
        void OnListaClientesItemSelect(wxListEvent& event);
        void OnButton1Click1(wxCommandEvent& event);
        void OnBtnEliminarClienteClick(wxCommandEvent& event);
        void OnButtonNuevaCuentaClick(wxCommandEvent& event);
        void OnListaClientesInsertItem(wxListEvent& event);
        void OnListaCuentasInsertItem(wxListEvent& event);
        void OnListaCuentasItemSelect(wxListEvent& event);
        void OnListaCuentasDeleteAllItems(wxListEvent& event);
        void OnButtonCerrarCuentaClick(wxCommandEvent& event);
        void OnButtonDepositoClick(wxCommandEvent& event);
        void OnTextCtrlCantidadDineroText(wxCommandEvent& event);
        void OnButtonDepositarenCuentaClick(wxCommandEvent& event);
        void OnButtonExtraerdeCuentaClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(bancoguiFrame)
        static const long ID_LISTACLIENTES;
        static const long ID_BTNCREARCLIENTE;
        static const long ID_BTNEDITARCLIENTE;
        static const long ID_BTNELIMINARCLIENTE;
        static const long ID_LISTACUENTAS;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_TEXTCTRLCANTDINERO;
        static const long ID_BUTTONDEPOSITARDINERO;
        static const long ID_BUTTONEXTRAERDINERO;
        static const long ID_PRINCIPAL;
        static const long idMenuQuit;
        static const long id_menuCrearCliente;
        static const long id_menueditarCliente;
        static const long id_menueliminarCliente;
        static const long ID_MENUITEM4;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_MESSAGEDIALOG1;
        static const long ID_MESSAGEDIALOG2;
        //*)

        //(*Declarations(bancoguiFrame)
        wxButton* BtnEditarCliente;
        wxButton* BtnEliminarCliente;
        wxButton* ButtonCerrarCuenta;
        wxButton* ButtonDepositarenCuenta;
        wxButton* ButtonExtraerdeCuenta;
        wxButton* ButtonNuevaCuenta;
        wxButton* btnCrearCliente;
        wxListCtrl* ListaClientes;
        wxListCtrl* ListaCuentas;
        wxMenu* Menu3;
        wxMenu* Menu4;
        wxMenuItem* MenuCrearCliente;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem5;
        wxMenuItem* MenuItem6;
        wxMessageDialog* MessageDialogEliminarCliente;
        wxMessageDialog* MessageDialogEliminarCuenta;
        wxPanel* Principal;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrlCantidadDinero;
        //*)
        float ValorDinero;
        DECLARE_EVENT_TABLE()
};

#endif // BANCOGUIMAIN_H
