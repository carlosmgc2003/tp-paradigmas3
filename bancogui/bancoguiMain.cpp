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
#include "editarCliente.h"
#include "DialogoNuevaCuenta.h"
//(*InternalHeaders(bancoguiFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/font.h>
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
const long bancoguiFrame::ID_LISTACUENTAS = wxNewId();
const long bancoguiFrame::ID_BUTTON1 = wxNewId();
const long bancoguiFrame::ID_BUTTON2 = wxNewId();
const long bancoguiFrame::ID_BUTTON3 = wxNewId();
const long bancoguiFrame::ID_BUTTON4 = wxNewId();
const long bancoguiFrame::ID_PRINCIPAL = wxNewId();
const long bancoguiFrame::idMenuQuit = wxNewId();
const long bancoguiFrame::id_menuCrearCliente = wxNewId();
const long bancoguiFrame::id_menueditarCliente = wxNewId();
const long bancoguiFrame::id_menueliminarCliente = wxNewId();
const long bancoguiFrame::ID_MENUITEM4 = wxNewId();
const long bancoguiFrame::idMenuAbout = wxNewId();
const long bancoguiFrame::ID_STATUSBAR1 = wxNewId();
const long bancoguiFrame::ID_MESSAGEDIALOG1 = wxNewId();
const long bancoguiFrame::ID_MESSAGEDIALOG2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(bancoguiFrame,wxFrame)
    //(*EventTable(bancoguiFrame)
    //*)
END_EVENT_TABLE()

void ListarClientes(Banco &,wxListCtrl &);
void ListarCuentas(Cliente &, wxListCtrl &);
void eliminarGuiones(wxString &);

int Cuenta::generadorNumeros = 1;

bancoguiFrame::bancoguiFrame(wxWindow* parent,wxWindowID id)
{
    CrisNaMa.leerArchivos();
    //(*Initialize(bancoguiFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxStaticBoxSizer* StaticBoxSizer5;

    Create(0, id, _("Banco CrisNaMa"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(820,500));
    SetMaxSize(wxSize(-1,-1));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_DELETE")),wxART_FRAME_ICON));
    	SetIcon(FrameIcon);
    }
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Principal = new wxPanel(this, ID_PRINCIPAL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PRINCIPAL"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Principal, _("Clientes"));
    ListaClientes = new wxListCtrl(Principal, ID_LISTACLIENTES, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SORT_ASCENDING, wxDefaultValidator, _T("ID_LISTACLIENTES"));
    ListaClientes->SetHelpText(_("Lista de clientes"));
    StaticBoxSizer1->Add(ListaClientes, 1, wxALL|wxEXPAND, 5);
    BoxSizer2->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxVERTICAL, Principal, _("Herramientas"));
    btnCrearCliente = new wxButton(Principal, ID_BTNCREARCLIENTE, _("Crear Cliente"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNCREARCLIENTE"));
    btnCrearCliente->SetFocus();
    wxFont btnCrearClienteFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    btnCrearCliente->SetFont(btnCrearClienteFont);
    btnCrearCliente->SetToolTip(_("Abre el dialogo de crear cliente"));
    StaticBoxSizer2->Add(btnCrearCliente, 1, wxALL|wxEXPAND, 5);
    BtnEditarCliente = new wxButton(Principal, ID_BTNEDITARCLIENTE, _("Editar Cliente"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNEDITARCLIENTE"));
    BtnEditarCliente->Disable();
    wxFont BtnEditarClienteFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    BtnEditarCliente->SetFont(BtnEditarClienteFont);
    StaticBoxSizer2->Add(BtnEditarCliente, 1, wxALL|wxEXPAND, 5);
    BtnEliminarCliente = new wxButton(Principal, ID_BTNELIMINARCLIENTE, _("Eliminar Cliente"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNELIMINARCLIENTE"));
    BtnEliminarCliente->Disable();
    wxFont BtnEliminarClienteFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    BtnEliminarCliente->SetFont(BtnEliminarClienteFont);
    StaticBoxSizer2->Add(BtnEliminarCliente, 1, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 1);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Principal, _("Estado Bancario del Cliente"));
    ListaCuentas = new wxListCtrl(Principal, ID_LISTACUENTAS, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTACUENTAS"));
    ListaCuentas->SetMinSize(wxSize(-1,-1));
    ListaCuentas->SetMaxSize(wxSize(-1,-1));
    ListaCuentas->SetHelpText(_("Lista de cuentas de cliente"));
    StaticBoxSizer3->Add(ListaCuentas, 1, wxALL|wxEXPAND, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxVERTICAL, Principal, _("Cartera"));
    ButtonNuevaCuenta = new wxButton(Principal, ID_BUTTON1, _("Nueva Cuenta"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    ButtonNuevaCuenta->Disable();
    StaticBoxSizer4->Add(ButtonNuevaCuenta, 1, wxALL|wxEXPAND, 5);
    ButtonCerrarCuenta = new wxButton(Principal, ID_BUTTON2, _("Cerrar Cuenta"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    ButtonCerrarCuenta->Disable();
    StaticBoxSizer4->Add(ButtonCerrarCuenta, 1, wxALL|wxEXPAND, 5);
    BoxSizer4->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, Principal, _("Caja"));
    ButtonDeposito = new wxButton(Principal, ID_BUTTON3, _("Depósito"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    ButtonDeposito->Disable();
    wxFont ButtonDepositoFont(0,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    ButtonDeposito->SetFont(ButtonDepositoFont);
    StaticBoxSizer5->Add(ButtonDeposito, 1, wxALL|wxEXPAND, 5);
    ButtonExtraccion = new wxButton(Principal, ID_BUTTON4, _("Extracción"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    ButtonExtraccion->Disable();
    wxFont ButtonExtraccionFont(0,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    ButtonExtraccion->SetFont(ButtonExtraccionFont);
    StaticBoxSizer5->Add(ButtonExtraccion, 1, wxALL|wxEXPAND, 5);
    BoxSizer4->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer3->Add(BoxSizer4, 1, wxALL|wxEXPAND, 1);
    BoxSizer3->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 1);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
    Principal->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Principal);
    BoxSizer2->SetSizeHints(Principal);
    BoxSizer1->Add(Principal, 1, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Cerrar\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&Archivo"));
    Menu3 = new wxMenu();
    MenuCrearCliente = new wxMenuItem(Menu3, id_menuCrearCliente, _("&Crear cliente"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuCrearCliente);
    MenuItem4 = new wxMenuItem(Menu3, id_menueditarCliente, _("E&ditar cliente"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    MenuItem4->Enable(false);
    MenuItem5 = new wxMenuItem(Menu3, id_menueliminarCliente, _("&Eliminar cliente"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem5);
    MenuItem5->Enable(false);
    MenuBar1->Append(Menu3, _("Cli&entes"));
    Menu4 = new wxMenu();
    MenuItem6 = new wxMenuItem(Menu4, ID_MENUITEM4, _("Generar..."), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(MenuItem6);
    MenuBar1->Append(Menu4, _("Rep&orte"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("Acerca de Banco\tF1"), _("Mostrar informacion acerca de esta aplicación"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("A&yuda"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    MessageDialogEliminarCliente = new wxMessageDialog(this, _("¿Esta seguro que desea eliminar este cliente\?"), _("Atención"), wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION|wxSTAY_ON_TOP, wxDefaultPosition);
    MessageDialogEliminarCuenta = new wxMessageDialog(this, _("¿Está seguro de cerrar esta cuenta\?"), _("Atención"), wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION, wxDefaultPosition);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_LISTACLIENTES,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&bancoguiFrame::OnListCtrl1BeginDrag1);
    Connect(ID_LISTACLIENTES,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&bancoguiFrame::OnListaClientesItemSelect);
    Connect(ID_LISTACLIENTES,wxEVT_COMMAND_LIST_INSERT_ITEM,(wxObjectEventFunction)&bancoguiFrame::OnListaClientesInsertItem);
    Connect(ID_BTNCREARCLIENTE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bancoguiFrame::OnbtnCrearClienteClick);
    Connect(ID_BTNEDITARCLIENTE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bancoguiFrame::OnBtnEditarClienteClick);
    Connect(ID_BTNELIMINARCLIENTE,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bancoguiFrame::OnBtnEliminarClienteClick);
    Connect(ID_LISTACUENTAS,wxEVT_COMMAND_LIST_DELETE_ALL_ITEMS,(wxObjectEventFunction)&bancoguiFrame::OnListaCuentasDeleteAllItems);
    Connect(ID_LISTACUENTAS,wxEVT_COMMAND_LIST_ITEM_SELECTED,(wxObjectEventFunction)&bancoguiFrame::OnListaCuentasItemSelect);
    Connect(ID_LISTACUENTAS,wxEVT_COMMAND_LIST_INSERT_ITEM,(wxObjectEventFunction)&bancoguiFrame::OnListaCuentasInsertItem);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bancoguiFrame::OnButtonNuevaCuentaClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bancoguiFrame::OnButtonCerrarCuentaClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bancoguiFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bancoguiFrame::OnAbout);
    //*)

    Connect(id_menuCrearCliente,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction) &bancoguiFrame::OnbtnCrearClienteClick);
    ListaClientes->InsertColumn(0,"DNI",wxLIST_FORMAT_LEFT,60);
    ListaClientes->InsertColumn(1,"Nombre");
    ListaClientes->InsertColumn(2,"Apellido");
    ListaClientes->InsertColumn(3,"Dirección",wxLIST_FORMAT_LEFT,200);
    ListaClientes->InsertColumn(4,"Teléfono");
    if(CrisNaMa.clientesActivos.size() > 0)
        ListarClientes(CrisNaMa,* ListaClientes);
    ListaCuentas->InsertColumn(0,"Nro Cuenta");
    ListaCuentas->InsertColumn(1,"Tipo",wxLIST_FORMAT_LEFT,40);
    ListaCuentas->InsertColumn(2,"Saldo");
}

bancoguiFrame::~bancoguiFrame()
{
    CrisNaMa.escribirClientes();
    //(*Destroy(bancoguiFrame)
    //*)
}

void bancoguiFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void bancoguiFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg("CT Nahuel SALAZAR\nTP Cristian FRANCO\nTP Carlos MACEIRA\nFacultad de Ingeniería de Ejército - 2018");
    wxMessageBox(msg, _("Banco"));
}

void bancoguiFrame::OnListCtrl1BeginDrag(wxListEvent& event)
{

}

void bancoguiFrame::OnListCtrl1BeginDrag1(wxListEvent& event)
{

}
void ListarClientes(Banco & Ban,wxListCtrl & Lista){
    if(Ban.clientesActivos.size() > 0){
        for(int i = 0; i < Ban.clientesActivos.size(); i ++){
            int itemIndex = i;
            //Conversion int to wxString del DNI
            wxString DNI;
            DNI << Ban.clientesActivos[i].getDni();
            Lista.InsertItem(itemIndex,_("col1ItemText"));
            Lista.SetItem(itemIndex,0,DNI);

            wxString NOMBRE(Ban.clientesActivos[i].getNombre());
            eliminarGuiones(NOMBRE);
            Lista.SetItem(itemIndex,1,NOMBRE);

            wxString APELLIDO(Ban.clientesActivos[i].getApellido());
            eliminarGuiones(APELLIDO);
            Lista.SetItem(itemIndex,2,APELLIDO);

            wxString DIRECCION(Ban.clientesActivos[i].getDireccion());
            eliminarGuiones(DIRECCION);
            Lista.SetItem(itemIndex,3,DIRECCION);

            wxString TELEFONO(Ban.clientesActivos[i].getTelefono());
            Lista.SetItem(itemIndex,4,TELEFONO);
        }
    }
    return;
}

void ListarCuentas(Cliente & cliente,wxListCtrl & Lista){
    if(cliente.contarCuentasCliente() > 0){
        Lista.DeleteAllItems();
        for(int i = 0;i < cliente.contarCuentasCliente(); i++){
            wxString IDCUENTA;
            IDCUENTA << cliente[i].getdniDuenio();
            wxString auxiliar;
            auxiliar << cliente[i].getnumeroUnico();
            IDCUENTA.append(auxiliar);
            wxString SALDO;
            SALDO << cliente[i].getSaldo();
            Lista.InsertItem(i,_("Cuenta"));
            Lista.SetItem(i,0,IDCUENTA);
            if(cliente[i].gettipoCuenta() == 0){
                Lista.SetItem(i,1,_("CA"));
            }
            else
                Lista.SetItem(i,1,_("CC"));
            Lista.SetItem(i,2,SALDO);
        }
    }
    else
        Lista.DeleteAllItems();

}

void eliminarGuiones (wxString & cadena){
    if(cadena.find("_") != wxNOT_FOUND)
        cadena.Replace("_"," ");
    return;
}


void bancoguiFrame::OnButton1Click(wxCommandEvent& event)
{
}

void bancoguiFrame::OnBtnEditarClienteClick(wxCommandEvent& event)
{
    editarCliente * dialogo = new editarCliente(this);
    dialogo->setDialogoApellido(CrisNaMa.clientesActivos[ClienteSeleccionado].getApellido());
    dialogo->setDialogoNombre(CrisNaMa.clientesActivos[ClienteSeleccionado].getNombre());
    dialogo->setDialogoDNI(CrisNaMa.clientesActivos[ClienteSeleccionado].getDni());
    dialogo->setDialogoDireccion(CrisNaMa.clientesActivos[ClienteSeleccionado].getDireccion());
    dialogo->setDialogoTelefono(CrisNaMa.clientesActivos[ClienteSeleccionado].getTelefono());
    if(dialogo->ShowModal() == wxID_OK){
            CrisNaMa.clientesActivos[ClienteSeleccionado].setDireccion(dialogo->getDialogoDireccion().ToStdString());
            CrisNaMa.clientesActivos[ClienteSeleccionado].setTelefono(dialogo->getDialogoTelefono().ToStdString());
            //wxMessageBox(_("Cambios Guardados"),_("Felicitaciones!"));
    }
    ListaClientes->DeleteAllItems();
    ListarClientes(CrisNaMa,* ListaClientes);
}

void bancoguiFrame::OnbtnCrearClienteClick(wxCommandEvent& event)
{
    Cliente nuevo;
    crearCliente * dialogo = new crearCliente(this);
    if(dialogo->ShowModal() == wxID_OK){
        nuevo.setDni(dialogo->getNuevoDni());
        nuevo.setNombre(dialogo->getNuevoNombre().ToStdString());
        nuevo.setApellido(dialogo->getNuevoApellido().ToStdString());
        nuevo.setDireccion(dialogo->getNuevoDireccion().ToStdString());
        nuevo.setTelefono(dialogo->getNuevoTelefono().ToStdString());
        CrisNaMa.clientesActivos.push_back(nuevo);
        wxMessageBox(_("Cliente Guardado"),_("Felicitaciones!"));
    }
    ListaClientes->DeleteAllItems();
    ListarClientes(CrisNaMa,* ListaClientes);
}


void bancoguiFrame::OnListaClientesItemSelect(wxListEvent& event)
{
    ClienteSeleccionado = event.GetIndex();
    ListarCuentas(CrisNaMa.clientesActivos[ClienteSeleccionado],* ListaCuentas);
    BtnEditarCliente->Enable();
    BtnEliminarCliente->Enable();
    ButtonNuevaCuenta->Enable();
}

void bancoguiFrame::OnButton1Click1(wxCommandEvent& event)
{
}

void bancoguiFrame::OnBtnEliminarClienteClick(wxCommandEvent& event)
{
    if(MessageDialogEliminarCliente->ShowModal() == wxID_YES){
        float dineroTotal = CrisNaMa.clientesActivos[ClienteSeleccionado].contarDinero();
        wxString cantidad;
        cantidad << dineroTotal;
        if(dineroTotal >= 0.0){
            wxString RESPUESTA("Debe pagar al cliente $");
            RESPUESTA.Append(cantidad);
            wxMessageBox(RESPUESTA,_("Pague"));
        }
        else{
            wxString RESPUESTA("Cobre al cliente la cantidad de $");
            RESPUESTA.Append(cantidad);
            wxMessageBox(RESPUESTA,_("Cobre"));
        }
        CrisNaMa.clientesActivos.erase(CrisNaMa.clientesActivos.begin() + ClienteSeleccionado);
        ListaClientes->DeleteAllItems();
        ListarClientes(CrisNaMa,* ListaClientes);
    }
}

void bancoguiFrame::OnButtonNuevaCuentaClick(wxCommandEvent& event)
{
    DialogoNuevaCuenta * dialogo = new DialogoNuevaCuenta(this);
    wxString nuevoIdCuenta;
    int IdclienteSolicitante = CrisNaMa.clientesActivos[ClienteSeleccionado].getDni();
    nuevoIdCuenta << IdclienteSolicitante;
    nuevoIdCuenta << Cuenta::generadorNumeros;
    wxMessageBox(nuevoIdCuenta,_("Debug"));
    dialogo->setIdCuenta(nuevoIdCuenta);
    if(dialogo->ShowModal() == wxID_OK){
            Cuenta nuevaCuenta(IdclienteSolicitante,Cuenta::generadorNumeros,dialogo->getTipoCuenta());
            CrisNaMa.clientesActivos[ClienteSeleccionado].agregarCuenta(nuevaCuenta);
            //wxMessageBox(_("Nueva cuenta creada con éxito"),_("Felicitaciones!"));
            ListaCuentas->DeleteAllItems();
            ListarCuentas(CrisNaMa.clientesActivos[ClienteSeleccionado],* ListaCuentas);
    }
}

void bancoguiFrame::OnListaClientesInsertItem(wxListEvent& event)
{
    int CantidadClientes = CrisNaMa.clientesActivos.size();
    int CantidadCuentas = CrisNaMa.cuentasActivas();
    wxString LEYENDA;
    LEYENDA.Append("Clientes: ");
    LEYENDA << CantidadClientes;
    LEYENDA.Append(" Cuentas: ");
    LEYENDA << CantidadCuentas;
    StatusBar1->SetLabel(LEYENDA);
}

void bancoguiFrame::OnListaCuentasInsertItem(wxListEvent& event)
{
    int CantidadClientes = CrisNaMa.clientesActivos.size();
    int CantidadCuentas = CrisNaMa.cuentasActivas();
    wxString LEYENDA;
    LEYENDA.Append("Clientes: ");
    LEYENDA << CantidadClientes;
    LEYENDA.Append(" Cuentas: ");
    LEYENDA << CantidadCuentas;
    StatusBar1->SetLabel(LEYENDA);
}

void bancoguiFrame::OnListaCuentasItemSelect(wxListEvent& event)
{
    ButtonCerrarCuenta->Enable();
    ButtonDeposito->Enable();
    ButtonExtraccion->Enable();
    CuentaSeleccionada = event.GetIndex();

}

void bancoguiFrame::OnListaCuentasDeleteAllItems(wxListEvent& event)
{
    ButtonCerrarCuenta->Disable();
}

void bancoguiFrame::OnButtonCerrarCuentaClick(wxCommandEvent& event)
{
    if(MessageDialogEliminarCuenta->ShowModal() == wxID_YES){
        float saldoRemanente = CrisNaMa.clientesActivos[ClienteSeleccionado][CuentaSeleccionada].getSaldo();
        wxString cantidad;
        cantidad << saldoRemanente;
        if(saldoRemanente >= 0.0){
            wxString RESPUESTA("Debe pagar al cliente $");
            RESPUESTA.Append(cantidad);
            wxMessageBox(RESPUESTA,_("Pague"));
        }
        else{
            wxString RESPUESTA("Cobre al cliente la cantidad de $");
            RESPUESTA.Append(cantidad);
            wxMessageBox(RESPUESTA,_("Cobre"));
        }
        CrisNaMa.clientesActivos[ClienteSeleccionado].eliminarCuenta(CuentaSeleccionada);
        ListaCuentas->DeleteAllItems();
        ListarCuentas(CrisNaMa.clientesActivos[ClienteSeleccionado],* ListaCuentas);
    }
}

