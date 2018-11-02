/***************************************************************
 * Name:      bancoguiMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Team C++ (carlosmgc2003@gmail.com)
 * Created:   2018-10-31
 * Copyright: Team C++ (https://github.com/carlosmgc2003/tp-paradigmas3.git)
 * License:
 **************************************************************/

#include "bancoguiMain.h"
#include <wx/msgdlg.h>
#include "banco.hpp"
#include "crearCliente.h"
//(*InternalHeaders(bancoguiFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(bancoguiFrame)
const long bancoguiFrame::ID_LISTACLIENTES = wxNewId();
const long bancoguiFrame::ID_BTNCREARCLIENTE = wxNewId();
const long bancoguiFrame::ID_BTNEDITARCLIENTE = wxNewId();
const long bancoguiFrame::ID_BTNELIMINARCLIENTE = wxNewId();
const long bancoguiFrame::ID_PRINCIPAL = wxNewId();
const long bancoguiFrame::idMenuQuit = wxNewId();
const long bancoguiFrame::ID_MENUITEM1 = wxNewId();
const long bancoguiFrame::ID_MENUITEM2 = wxNewId();
const long bancoguiFrame::ID_MENUITEM3 = wxNewId();
const long bancoguiFrame::ID_MENUITEM4 = wxNewId();
const long bancoguiFrame::idMenuAbout = wxNewId();
const long bancoguiFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(bancoguiFrame,wxFrame)
    //(*EventTable(bancoguiFrame)
    //*)
END_EVENT_TABLE()

void ListarClientes(Banco &,wxListCtrl &);

bancoguiFrame::bancoguiFrame(wxWindow* parent,wxWindowID id)
{
    Banco A;
    A.leerArchivos();
    //(*Initialize(bancoguiFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;

    Create(0, id, _("Banco CrisNaMa"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetMinSize(wxSize(-1,-1));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_DELETE")),wxART_FRAME_ICON));
    	SetIcon(FrameIcon);
    }
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Principal = new wxPanel(this, ID_PRINCIPAL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PRINCIPAL"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Principal, _("Clientes"));
    ListaClientes = new wxListCtrl(Principal, ID_LISTACLIENTES, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTACLIENTES"));
    ListaClientes->SetHelpText(_("Lista de clientes"));
    StaticBoxSizer1->Add(ListaClientes, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Principal, _("Herramientas"));
    btnCrearCliente = new wxButton(Principal, ID_BTNCREARCLIENTE, _("Crear Cliente"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNCREARCLIENTE"));
    btnCrearCliente->SetToolTip(_("Abre el dialogo de crear cliente"));
    StaticBoxSizer2->Add(btnCrearCliente, 1, wxALL|wxEXPAND, 5);
    BtnEditarCliente = new wxButton(Principal, ID_BTNEDITARCLIENTE, _("Editar Cliente"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNEDITARCLIENTE"));
    StaticBoxSizer2->Add(BtnEditarCliente, 1, wxALL|wxEXPAND, 5);
    BtnEliminarCliente = new wxButton(Principal, ID_BTNELIMINARCLIENTE, _("Eliminar Cliente"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNELIMINARCLIENTE"));
    StaticBoxSizer2->Add(BtnEliminarCliente, 1, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Principal, _("Estado Patrimonial"));
    BoxSizer3->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    Principal->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Principal);
    BoxSizer2->SetSizeHints(Principal);
    BoxSizer1->Add(Principal, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Cerrar\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Archivo"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM1, _("&Crear cliente"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, ID_MENUITEM2, _("E&ditar cliente"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    MenuItem5 = new wxMenuItem(Menu3, ID_MENUITEM3, _("&Eliminar cliente"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem5);
    MenuBar1->Append(Menu3, _("Cli&entes"));
    Menu4 = new wxMenu();
    MenuItem6 = new wxMenuItem(Menu4, ID_MENUITEM4, _("Generar..."), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem6);
    MenuBar1->Append(Menu4, _("Rep&orte"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Acerca de Banco\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("A&yuda"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_LISTACLIENTES,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&bancoguiFrame::OnListCtrl1BeginDrag1);
    Connect(ID_BTNCREARCLIENTE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bancoguiFrame::OnbtnCrearClienteClick);
    Connect(ID_BTNEDITARCLIENTE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bancoguiFrame::OnBtnEditarClienteClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bancoguiFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bancoguiFrame::OnAbout);
    //*)
    ListaClientes->InsertColumn(0,"DNI",wxLIST_FORMAT_LEFT,60);
    ListaClientes->InsertColumn(1,"Nombre");
    ListaClientes->InsertColumn(2,"Apellido");
    ListaClientes->InsertColumn(3,"Dirección",wxLIST_FORMAT_LEFT,200);
    ListarClientes(A,* ListaClientes);



}

bancoguiFrame::~bancoguiFrame()
{
    //(*Destroy(bancoguiFrame)
    //*)
}

void bancoguiFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void bancoguiFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void bancoguiFrame::OnListCtrl1BeginDrag(wxListEvent& event)
{

}

void bancoguiFrame::OnListCtrl1BeginDrag1(wxListEvent& event)
{

}
void ListarClientes(Banco & Ban,wxListCtrl & Lista){
    for(int i = 0; i < Ban.clientesActivos.size(); i ++){
        int itemIndex = i;
        //Conversion int to wxString del DNI
        wxString DNI;
        DNI << Ban.clientesActivos[i].getDni();
        Lista.InsertItem(itemIndex,_("col1ItemText"));
        Lista.SetItem(itemIndex,0,DNI);

        Lista.SetItem(itemIndex,1,Ban.clientesActivos[i].getNombre());
        Lista.SetItem(itemIndex,2,Ban.clientesActivos[i].getApellido());
        //Eliminacion de los guiones bajos de la direccion
        wxString DIRECCION(Ban.clientesActivos[i].getDireccion());
        DIRECCION.Replace("_"," ");
        Lista.SetItem(itemIndex,3,DIRECCION);
    }
    return;

}


void bancoguiFrame::OnButton1Click(wxCommandEvent& event)
{
}

void bancoguiFrame::OnBtnEditarClienteClick(wxCommandEvent& event)
{

}

void bancoguiFrame::OnbtnCrearClienteClick(wxCommandEvent& event)
{
    crearCliente * dialogo = new crearCliente(this);
    dialogo->ShowModal();
}

