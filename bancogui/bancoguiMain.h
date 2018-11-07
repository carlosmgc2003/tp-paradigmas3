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
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
//*)

#include "banco.hpp"

class bancoguiFrame: public wxFrame
{
    public:

        bancoguiFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~bancoguiFrame();
        Banco CrisNaMa;
        int ClienteSeleccionado;

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
        //*)

        //(*Identifiers(bancoguiFrame)
        static const long ID_LISTACLIENTES;
        static const long ID_BTNCREARCLIENTE;
        static const long ID_BTNEDITARCLIENTE;
        static const long ID_BTNELIMINARCLIENTE;
        static const long ID_LISTACUENTAS;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_PRINCIPAL;
        static const long idMenuQuit;
        static const long ID_MENUITEM1;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM3;
        static const long ID_MENUITEM4;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(bancoguiFrame)
        wxButton* BtnEditarCliente;
        wxButton* BtnEliminarCliente;
        wxButton* ButtonCerrarCuenta;
        wxButton* ButtonDeposito;
        wxButton* ButtonExtraccion;
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
        wxPanel* Principal;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // BANCOGUIMAIN_H
