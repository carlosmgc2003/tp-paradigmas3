/***************************************************************
 * Name:      bancoguiMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Team C++ (carlosmgc2003@gmail.com)
 * Created:   2018-10-31
 * Copyright: Team C++ (https://github.com/carlosmgc2003/tp-paradigmas3.git)
 * License:
 **************************************************************/
//Cabecera de la aplicacion principal, la que da inicio a todo
#include "bancoguiMain.h"
//Cabecera de la clase banco
#include "banco.hpp"
//Cabeceras de los dialogos asociados a esta ventana principal
#include "crearCliente.h"
#include "editarCliente.h"
#include "DialogoNuevaCuenta.h"
#include "dialogoListadeCuentas.h"
//Cabecera para la validacion de los numeros en los textbox
#include <wx/valnum.h>
//Cabecera que genera los mensajes de alerta al usuario
#include <wx/msgdlg.h>
//(*InternalHeaders(bancoguiFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
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
        //wxbuild << _T("-ANSI build");
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
const long bancoguiFrame::ID_TEXTCTRLCANTDINERO = wxNewId();
const long bancoguiFrame::ID_BUTTONDEPOSITARDINERO = wxNewId();
const long bancoguiFrame::ID_BUTTONEXTRAERDINERO = wxNewId();
const long bancoguiFrame::ID_STATICTEXTTIME = wxNewId();
const long bancoguiFrame::ID_PRINCIPAL = wxNewId();
const long bancoguiFrame::idGuardarEstado = wxNewId();
const long bancoguiFrame::idMenuQuit = wxNewId();
const long bancoguiFrame::id_menuCrearCliente = wxNewId();
const long bancoguiFrame::id_menueditarCliente = wxNewId();
const long bancoguiFrame::id_menueliminarCliente = wxNewId();
const long bancoguiFrame::idMenuAbout = wxNewId();
const long bancoguiFrame::ID_STATUSBAR1 = wxNewId();
const long bancoguiFrame::ID_MESSAGEDIALOG1 = wxNewId();
const long bancoguiFrame::ID_MESSAGEDIALOG2 = wxNewId();
const long bancoguiFrame::ID_MESSAGEDIALOGGUARDAR = wxNewId();
const long bancoguiFrame::ID_TIMERHORA = wxNewId();
//*)

BEGIN_EVENT_TABLE(bancoguiFrame,wxFrame)
    //(*EventTable(bancoguiFrame)
    //*)
END_EVENT_TABLE()

void ListarClientes(Banco &,wxListCtrl &);//Genera los item en la lista de clientes
void ListarCuentas(Cliente &, wxListCtrl &);//Funcion que genera los item en la lista de cuentas
void eliminarGuiones(wxString &);//Funcion que elimina los guiones de los datos recuperados del archivo

int Cuenta::generadorNumeros = 1;


/*Constructor de la ventana principal. Hay que tener en cuenta que la instancia del banco es uno de los
atributos de esta ventana por lo cual al construirla se instancia tambien*/
bancoguiFrame::bancoguiFrame(wxWindow* parent,wxWindowID id)
{
    CrisNaMa.leerArchivos();//Leemos los archivos presentes en compañia con el ejecutable. Si no existen nos advierte
    wxString horaActual = wxDateTime::Now().FormatTime();//Cargamos la hora actual para el log.
    wxString fechaActual = wxDateTime::Today().FormatDate();//Cargamos la fecha actual, para el log.
    horayfechaActual = horaActual +" "+fechaActual;//Concatenamos hora yfecha
    CrisNaMa.movimientos << "------------------------------------" << endl;//Linea que muestra que comenzo la ejecucion
    CrisNaMa.movimientos << horayfechaActual << " - " <<"Iniciado programa"<< endl;//Escribe hora y fecha en el log
    wxFloatingPointValidator<float> ValidadorDeDinero(2,&ValorDinero,wxNUM_VAL_ZERO_AS_BLANK);//Instanciamos el validador de numeros
    ValidadorDeDinero.SetRange(0,99999999);//Establecemos el rango de numeros validos en la caja de texto de dinero
    //(*Initialize(bancoguiFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;
    wxBoxSizer* BoxSizer7;
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
    SetClientSize(wxSize(910,570));
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
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Principal, _("Herramientas"));
    btnCrearCliente = new wxButton(Principal, ID_BTNCREARCLIENTE, _("Crear\n Cliente"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNCREARCLIENTE"));
    btnCrearCliente->SetFocus();
    wxFont btnCrearClienteFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    btnCrearCliente->SetFont(btnCrearClienteFont);
    btnCrearCliente->SetToolTip(_("Abre el dialogo de crear cliente"));
    StaticBoxSizer2->Add(btnCrearCliente, 1, wxALL|wxEXPAND, 5);
    BtnEditarCliente = new wxButton(Principal, ID_BTNEDITARCLIENTE, _("Editar\n Cliente"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNEDITARCLIENTE"));
    BtnEditarCliente->Disable();
    wxFont BtnEditarClienteFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    BtnEditarCliente->SetFont(BtnEditarClienteFont);
    BtnEditarCliente->SetToolTip(_("Permite editar telefono y direccion del cliente"));
    StaticBoxSizer2->Add(BtnEditarCliente, 1, wxALL|wxEXPAND, 5);
    BtnEliminarCliente = new wxButton(Principal, ID_BTNELIMINARCLIENTE, _("Eliminar\n Cliente"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BTNELIMINARCLIENTE"));
    BtnEliminarCliente->Disable();
    wxFont BtnEliminarClienteFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    BtnEliminarCliente->SetFont(BtnEliminarClienteFont);
    BtnEliminarCliente->SetToolTip(_("Permite eliminar el cliente seleccionado"));
    StaticBoxSizer2->Add(BtnEliminarCliente, 1, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND, 1);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxVERTICAL, Principal, _("Estado Bancario del Cliente"));
    ListaCuentas = new wxListCtrl(Principal, ID_LISTACUENTAS, wxDefaultPosition, wxDefaultSize, wxLC_REPORT, wxDefaultValidator, _T("ID_LISTACUENTAS"));
    ListaCuentas->SetMinSize(wxSize(-1,-1));
    ListaCuentas->SetMaxSize(wxSize(-1,-1));
    ListaCuentas->SetHelpText(_("Lista de cuentas de cliente"));
    StaticBoxSizer3->Add(ListaCuentas, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    StaticBoxSizer4 = new wxStaticBoxSizer(wxVERTICAL, Principal, _("Cartera"));
    ButtonNuevaCuenta = new wxButton(Principal, ID_BUTTON1, _("Nueva\nCuenta"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    ButtonNuevaCuenta->Disable();
    StaticBoxSizer4->Add(ButtonNuevaCuenta, 1, wxALL|wxEXPAND, 5);
    ButtonCerrarCuenta = new wxButton(Principal, ID_BUTTON2, _("Cerrar\nCuenta"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    ButtonCerrarCuenta->Disable();
    StaticBoxSizer4->Add(ButtonCerrarCuenta, 1, wxALL|wxEXPAND, 5);
    BoxSizer4->Add(StaticBoxSizer4, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer5 = new wxStaticBoxSizer(wxVERTICAL, Principal, _("Caja"));
    BoxSizer5 = new wxBoxSizer(wxVERTICAL);
    TextCtrlCantidadDinero = new wxTextCtrl(Principal, ID_TEXTCTRLCANTDINERO, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE, ValidadorDeDinero, _T("ID_TEXTCTRLCANTDINERO"));
    TextCtrlCantidadDinero->Disable();
    wxFont TextCtrlCantidadDineroFont = wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT);
    if ( !TextCtrlCantidadDineroFont.Ok() ) TextCtrlCantidadDineroFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    TextCtrlCantidadDineroFont.SetPointSize(22);
    TextCtrlCantidadDineroFont.SetWeight(wxFONTWEIGHT_NORMAL);
    TextCtrlCantidadDinero->SetFont(TextCtrlCantidadDineroFont);
    BoxSizer5->Add(TextCtrlCantidadDinero, 1, wxALL|wxSHAPED, 1);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    ButtonDepositarenCuenta = new wxButton(Principal, ID_BUTTONDEPOSITARDINERO, _("Depositar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONDEPOSITARDINERO"));
    ButtonDepositarenCuenta->Disable();
    wxFont ButtonDepositarenCuentaFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    ButtonDepositarenCuenta->SetFont(ButtonDepositarenCuentaFont);
    BoxSizer6->Add(ButtonDepositarenCuenta, 1, wxALL|wxEXPAND, 5);
    ButtonExtraerdeCuenta = new wxButton(Principal, ID_BUTTONEXTRAERDINERO, _("Extraer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTONEXTRAERDINERO"));
    ButtonExtraerdeCuenta->Disable();
    wxFont ButtonExtraerdeCuentaFont(12,wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    ButtonExtraerdeCuenta->SetFont(ButtonExtraerdeCuentaFont);
    BoxSizer6->Add(ButtonExtraerdeCuenta, 1, wxALL|wxEXPAND, 5);
    BoxSizer5->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticBoxSizer5->Add(BoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer4->Add(StaticBoxSizer5, 1, wxALL|wxEXPAND, 5);
    StaticBoxSizer3->Add(BoxSizer4, 1, wxALL|wxEXPAND, 0);
    BoxSizer3->Add(StaticBoxSizer3, 1, wxALL|wxEXPAND, 1);
    BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
    StaticTextTime = new wxStaticText(Principal, ID_STATICTEXTTIME, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXTTIME"));
    wxFont StaticTextTimeFont = wxSystemSettings::GetFont(wxSYS_OEM_FIXED_FONT);
    if ( !StaticTextTimeFont.Ok() ) StaticTextTimeFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    StaticTextTimeFont.SetPointSize(20);
    StaticTextTime->SetFont(StaticTextTimeFont);
    BoxSizer7->Add(StaticTextTime, 1, wxALL|wxEXPAND, 5);
    BoxSizer3->Add(BoxSizer7, 1, wxALL|wxEXPAND, 0);
    BoxSizer2->Add(BoxSizer3, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 5);
    Principal->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Principal);
    BoxSizer2->SetSizeHints(Principal);
    BoxSizer1->Add(Principal, 1, wxALL|wxEXPAND, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, idGuardarEstado, _("Guardar estado\tAlt-F3"), _("Guarda el estado actual del banco en los archivos de testo"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    Menu1->AppendSeparator();
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
    MessageDialogEliminarCliente = new wxMessageDialog(this, _("Esta seguro que desea eliminar este cliente\?"), _("Atencion"), wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION|wxSTAY_ON_TOP, wxDefaultPosition);
    MessageDialogEliminarCuenta = new wxMessageDialog(this, _("¿Está seguro de cerrar esta cuenta\?"), _("Atención"), wxYES_NO|wxNO_DEFAULT|wxICON_QUESTION, wxDefaultPosition);
    MessageDialogGuardar = new wxMessageDialog(this, _("Estado del banco guardado"), _("Guardar"), wxOK|wxICON_EXCLAMATION|wxSTAY_ON_TOP, wxDefaultPosition);
    TimerHora.SetOwner(this, ID_TIMERHORA);
    TimerHora.Start(1000, false);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_LISTACLIENTES,wxEVT_COMMAND_LIST_BEGIN_DRAG,(wxObjectEventFunction)&bancoguiFrame::OnListCtrl1BeginDrag1);
    Connect(ID_LISTACLIENTES,wxEVT_COMMAND_LIST_DELETE_ALL_ITEMS,(wxObjectEventFunction)&bancoguiFrame::OnListaCuentasDeleteAllItems);
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
    Connect(ID_BUTTONDEPOSITARDINERO,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bancoguiFrame::OnButtonDepositarenCuentaClick);
    Connect(ID_BUTTONEXTRAERDINERO,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&bancoguiFrame::OnButtonExtraerdeCuentaClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bancoguiFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&bancoguiFrame::OnAbout);
    Connect(ID_TIMERHORA,wxEVT_TIMER,(wxObjectEventFunction)&bancoguiFrame::OnTimer1Trigger);
    //*)

    /*Estos statement connect permiten conectar lo que hacen botones de la interfaz con los menues para facilitar su implementacion*/
    Connect(id_menuCrearCliente,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction) &bancoguiFrame::OnbtnCrearClienteClick);
    Connect(id_menueditarCliente,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction) &bancoguiFrame::OnBtnEditarClienteClick);
    Connect(id_menueliminarCliente,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction) &bancoguiFrame::OnBtnEliminarClienteClick);

    /*Este connect especial no conecta con un boton si no que directamente con el metodo guardar*/
    Connect(idGuardarEstado,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction) &bancoguiFrame::OnGuardar);

    /*Iniciamos las etiquetas de las columnas de la lista de clientes*/
    ListaClientes->InsertColumn(0,"DNI",wxLIST_FORMAT_LEFT,60);
    ListaClientes->InsertColumn(1,"Nombre");
    ListaClientes->InsertColumn(2,"Apellido");
    ListaClientes->InsertColumn(3,"Direccion",wxLIST_FORMAT_LEFT,200);
    ListaClientes->InsertColumn(4,"Telefono");
    /*Si el vector de clientes tiene elementos*/
    if(CrisNaMa.clientesActivos.size() > 0)
        ListarClientes(CrisNaMa,* ListaClientes);
    ListaCuentas->InsertColumn(0,"Nro Cuenta");
    ListaCuentas->InsertColumn(1,"Tipo",wxLIST_FORMAT_LEFT,40);
    ListaCuentas->InsertColumn(2,"Saldo");
}

bancoguiFrame::~bancoguiFrame()
{
    //Cuando cerramos el programa guardamos los cambios en el disco
    CrisNaMa.escribirEstadoAArchivos();
    //Escribimos hora yfecha de cierre del programa
    CrisNaMa.movimientos << horayfechaActual << " - " <<"Cerrado programa"<< endl;
    CrisNaMa.movimientos << "------------------------------------" << endl;
    //(*Destroy(bancoguiFrame)
    //*)
}

/*Metodo de la opcion cerrar ventana del menu archivo*/
void bancoguiFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

/*Metodo del boton editar cliente de la ventan principal*/
void bancoguiFrame::OnBtnEditarClienteClick(wxCommandEvent& event)
{
    //Instanciamos el dialogo de editar cliente
    editarCliente * dialogo = new editarCliente(this);
    //Le mandamos lo datos de la instancia de cliente marcada en la lista de clientes representada
    //por el numero cliente seleccionado de la ListCtrl
    dialogo->setDialogoApellido(CrisNaMa.clientesActivos[ClienteSeleccionado].getApellido());
    dialogo->setDialogoNombre(CrisNaMa.clientesActivos[ClienteSeleccionado].getNombre());
    dialogo->setDialogoDNI(CrisNaMa.clientesActivos[ClienteSeleccionado].getDni());
    dialogo->setDialogoDireccion(CrisNaMa.clientesActivos[ClienteSeleccionado].getDireccion());
    dialogo->setDialogoTelefono(CrisNaMa.clientesActivos[ClienteSeleccionado].getTelefono());
    //Fin del envio de los datos al dialogo

    //El dialogo se muestra en primer plano, si devuelve un ok (representado por wxID_OK)
    if(dialogo->ShowModal() == wxID_OK){
            //Actualizamos los valores de la instancia de cliente con los valores obtenidos de la caja del dialogo
            CrisNaMa.clientesActivos[ClienteSeleccionado].setDireccion(dialogo->getDialogoDireccion().ToStdString());
            CrisNaMa.clientesActivos[ClienteSeleccionado].setTelefono(dialogo->getDialogoTelefono().ToStdString());
            //Guardamos la fecha y hora de los cambios hechos en el log del programa.
            CrisNaMa.movimientos << horayfechaActual << " - " << "Cliente editado: ";
            CrisNaMa.movimientos << CrisNaMa.clientesActivos[ClienteSeleccionado] << endl;
    }
    //Refrescamos el contenido la lista de clientes
    ListaClientes->DeleteAllItems();
    ListarClientes(CrisNaMa,* ListaClientes);
}


/*Metodo del boton crear cliente de la ventana principal*/
void bancoguiFrame::OnbtnCrearClienteClick(wxCommandEvent& event)
{
    //Creamos una instancia de cliente auxiliar para guardar los datos
    Cliente nuevo;
    //Instanciamos el dialogo de crear cliente
    crearCliente * dialogo = new crearCliente(this);
    //Mostramos el dialogo en primer plano, si se cierra devolviendo ok (representado por wxID_OK)
    if(dialogo->ShowModal() == wxID_OK){
        //Guardamos los datos recabados en el dialogo en la instancia de cliente
        nuevo.setDni(dialogo->getNuevoDni());
        nuevo.setNombre(dialogo->getNuevoNombre().ToStdString());
        nuevo.setApellido(dialogo->getNuevoApellido().ToStdString());
        nuevo.setDireccion(dialogo->getNuevoDireccion().ToStdString());
        nuevo.setTelefono(dialogo->getNuevoTelefono().ToStdString());
        CrisNaMa.clientesActivos.push_back(nuevo);
        //wxMessageBox(_("Cliente Guardado"),_("Felicitaciones!"));
    }
    CrisNaMa.movimientos << horayfechaActual << " - " << "Cliente creado: "<< nuevo << endl;
    ListaClientes->DeleteAllItems();
    ListarClientes(CrisNaMa,* ListaClientes);
}

/*Este metodo se acciona cuando hacemos click sobre un item de la lista de clientes es decir
cuando lo pintamos al cliente al clickerarlo*/
void bancoguiFrame::OnListaClientesItemSelect(wxListEvent& event)
{
    //Guardamos el item clickeado en la variable cliente seleccionado
    ClienteSeleccionado = event.GetIndex();
    //Actualizamos la lista del cuentas con las especificas de ese cliente
    ListarCuentas(CrisNaMa.clientesActivos[ClienteSeleccionado],* ListaCuentas);
    //Si estaban desactivados, activamos los botones que tienen que ver con la seleccion de cliente
    BtnEditarCliente->Enable();
    BtnEliminarCliente->Enable();
    ButtonNuevaCuenta->Enable();
    MenuItem4->Enable();
    MenuItem5->Enable();
}


/*Este metodo se acciona cuando hacemos click en el boton eliminar cliente*/
void bancoguiFrame::OnBtnEliminarClienteClick(wxCommandEvent& event)
{
    //Mostramos el mensaje ¿Esta seguro de eliminar? en primer plano. Si recibimos un Sí representado por wxID_YES
    if(MessageDialogEliminarCliente->ShowModal() == wxID_YES){
        //hallamos la cantidad de dinero total que le queda al cliente depositada en el banco
        float dineroTotal = CrisNaMa.clientesActivos[ClienteSeleccionado].contarDinero();
        //Copiamos la cantidad en una String para despues mostrarla por pantalla
        wxString cantidad;
        cantidad << dineroTotal;
        //Si el dinero total es mayor a 0 le pagamos al cliente, si no le tenemos que cobrar
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
        //Registramos la eliminacion en el archivo de movimientos
        CrisNaMa.movimientos << horayfechaActual << " - " << "Cliente Eliminado: "<< CrisNaMa.clientesActivos[ClienteSeleccionado] << endl;
        //Borramos el cliente del arreglo (esto recompone automaticamente el arreglo).
        CrisNaMa.clientesActivos.erase(CrisNaMa.clientesActivos.begin() + ClienteSeleccionado);
        //Actualizamos la lista de clientes para que se exiba el cambio
        ListaClientes->DeleteAllItems();
        ListarClientes(CrisNaMa,* ListaClientes);
        if(CrisNaMa.clientesActivos.size() == 0){
            ButtonNuevaCuenta->Disable();
            ButtonCerrarCuenta->Disable();
            ButtonExtraerdeCuenta->Disable();
            ButtonDepositarenCuenta->Disable();
            TextCtrlCantidadDinero->Disable();
            ListaCuentas->DeleteAllItems();
        }
    }
}


/*Metodo que se ejecuta cuando se hace click en el boton nueva cuenta*/
void bancoguiFrame::OnButtonNuevaCuentaClick(wxCommandEvent& event)
{
    //Instanciamos el dialogo de nueva cuenta
    DialogoNuevaCuenta * dialogo = new DialogoNuevaCuenta(this);
    //String auxiliar para "armar el nuevo id de cuenta" concatenamos el dni al numero del generador de numeros
    wxString nuevoIdCuenta;
    int IdclienteSolicitante = CrisNaMa.clientesActivos[ClienteSeleccionado].getDni();
    nuevoIdCuenta << IdclienteSolicitante;
    nuevoIdCuenta << Cuenta::generadorNumeros;
    //Le mandamos el nuevo ID al dialogo
    dialogo->setIdCuenta(nuevoIdCuenta);
    //Se muestra el dialogo en primer plano y espera que salga con un OK representado por wxID_OK
    if(dialogo->ShowModal() == wxID_OK){
            //Instanciamos la cuenta y le mandamos los datos que hallamos
            Cuenta nuevaCuenta(IdclienteSolicitante,Cuenta::generadorNumeros,dialogo->getTipoCuenta());
            //Agregamos la cuenta al vector de cuentas del cliente "seleccionado"
            CrisNaMa.clientesActivos[ClienteSeleccionado].agregarCuenta(nuevaCuenta);
            //Registramos el movimiento en el archivos de movimingtos
            CrisNaMa.movimientos << horayfechaActual << " - " << "Cuenta creada: "<< nuevaCuenta << endl;
            //Refrescamos la lista de de cuentas del cliente para mostar los cambios
            ListaCuentas->DeleteAllItems();
            ListarCuentas(CrisNaMa.clientesActivos[ClienteSeleccionado],* ListaCuentas);
    }
}



/*Estos dos metodos siguientes son para actualizar una leyenda en el barra de estado
(barra ingerior del programa que muestran la cantidad total de clientes y de cuentas
 del programa*/

/*Metodo que se ejecuta cuando agregamos un cliente a la lista*/
void bancoguiFrame::OnListaClientesInsertItem(wxListEvent& event)
{
    int CantidadClientes = CrisNaMa.clientesActivos.size();
    int CantidadCuentas = CrisNaMa.cuentasTotalesEnMemoria();
    wxString LEYENDA;
    LEYENDA.Append("Clientes: ");
    LEYENDA << CantidadClientes;
    LEYENDA.Append(" Cuentas: ");
    LEYENDA << CantidadCuentas;
    StatusBar1->SetLabel(LEYENDA);
}

/*Metodo que se ejecuta cuando agregamos una cuenta a la lista del cliente*/
void bancoguiFrame::OnListaCuentasInsertItem(wxListEvent& event)
{
    int CantidadClientes = CrisNaMa.clientesActivos.size();
    int CantidadCuentas = CrisNaMa.cuentasTotalesEnMemoria();
    wxString LEYENDA;
    LEYENDA.Append("Clientes: ");
    LEYENDA << CantidadClientes;
    LEYENDA.Append(" Cuentas: ");
    LEYENDA << CantidadCuentas;
    StatusBar1->SetLabel(LEYENDA);
}

/*Metodo que se acciona al hacer click en una cuenta de la lista activa los botones
necesarios para trabajar con ela cuenta*/
void bancoguiFrame::OnListaCuentasItemSelect(wxListEvent& event)
{
    ButtonCerrarCuenta->Enable();
    ButtonDepositarenCuenta->Enable();
    ButtonExtraerdeCuenta->Enable();
    TextCtrlCantidadDinero->Enable();
    CuentaSeleccionada = event.GetIndex();
}

/*Metodo que se acciona al hacer click en una cuenta de la lista desactiva los botones
que no son necesarios para evitar interacciones incorrectas*/
void bancoguiFrame::OnListaCuentasDeleteAllItems(wxListEvent& event)
{
    if(CrisNaMa.clientesActivos.size() == 0){
        BtnEditarCliente->Disable();
        BtnEliminarCliente->Disable();
    }
    ButtonCerrarCuenta->Disable();
    ButtonDepositarenCuenta->Disable();
    ButtonExtraerdeCuenta->Disable();
    TextCtrlCantidadDinero->Disable();
}


/*Este metodo se ejecuta cuando se hace click en el boton de cerrar la cuenta*/
void bancoguiFrame::OnButtonCerrarCuentaClick(wxCommandEvent& event)
{
    //Se muestra el mensaje de confirmacion en primer plano, si se hace click en si (representado por wxID_YES)
    if(MessageDialogEliminarCuenta->ShowModal() == wxID_YES){
        //Tomamos el saldo de la cuenta
        float saldoRemanente = CrisNaMa.clientesActivos[ClienteSeleccionado][CuentaSeleccionada].getSaldo();
        //Lo guardamos en una wxString
        wxString cantidad;
        cantidad << saldoRemanente;
        //Si el saldo es mayor a 0
        if(saldoRemanente >= 0.0){
            //Se instruye al cajero a pagar al cliente
            wxString RESPUESTA("Debe pagar al cliente $");
            RESPUESTA.Append(cantidad);
            wxMessageBox(RESPUESTA,_("Pague"));
        }
        else{
            //SI no se instruye el cajero a cobrar al cliente
            wxString RESPUESTA("Cobre al cliente la cantidad de $");
            RESPUESTA.Append(cantidad);
            wxMessageBox(RESPUESTA,_("Cobre"));
        }
        //Tomamos el numero de cuenta eliminadad en forma de estring a solo efecto de imprimirlo en el log
        wxString NroCuentaEliminada;
        NroCuentaEliminada << CrisNaMa.clientesActivos[ClienteSeleccionado][CuentaSeleccionada].getdniDuenio();
        NroCuentaEliminada << CrisNaMa.clientesActivos[ClienteSeleccionado][CuentaSeleccionada].getnumeroUnico();
        //Eliminamos la cuenta del vecto de cuenta del cliente
        CrisNaMa.clientesActivos[ClienteSeleccionado].eliminarCuenta(CuentaSeleccionada);
        //Registramos la eliminacion en el archivo de movimientos
        CrisNaMa.movimientos << horayfechaActual << " - " << "Cuenta cerrada: "<< NroCuentaEliminada << endl;
        //Refrescamos la lista de cuentas del cliente para que se reflejen los cambios realizados
        ListaCuentas->DeleteAllItems();
        ListarCuentas(CrisNaMa.clientesActivos[ClienteSeleccionado],* ListaCuentas);

    }
}



/*Metodo que se acciona cuando hacemos click en el boton depositar cuenta cuando previamente
se ha colocado un numero en el textbox correspondiente*/
void bancoguiFrame::OnButtonDepositarenCuentaClick(wxCommandEvent& event)
{
    //Tomamos el valor que tiene la caja
    wxString cadenaObtenida = TextCtrlCantidadDinero->GetValue();
    if(cadenaObtenida.size() == 0){
        wxMessageBox(_("No puede ser nulo el valor a depositar!"),_("Error"));
    }
    //Creamos un auxiliar double para el valor del deposito (tener en cuenta que double es igual a float pero mas preciso
    double deposito;
    //Si la cadena se puede convertir a double (es decir que es un numero valido)
    if(cadenaObtenida.ToDouble(&deposito)){
        //Incrementamos el saldo de la cuenta en la cantidad ingresada
        CrisNaMa.clientesActivos[ClienteSeleccionado][CuentaSeleccionada] += deposito;
        //Generamos el numero de cuenta depositada para escribir en el log concatenando el dni y el numero unico
        wxString NroCuentaDepositada;
        NroCuentaDepositada << CrisNaMa.clientesActivos[ClienteSeleccionado][CuentaSeleccionada].getdniDuenio();
        NroCuentaDepositada << CrisNaMa.clientesActivos[ClienteSeleccionado][CuentaSeleccionada].getnumeroUnico();
        //Registramos el movimiento en el archivo de movimientos
        CrisNaMa.movimientos << horayfechaActual << " - " << "Depositado: $"<< cadenaObtenida <<" en Cuenta: "<< NroCuentaDepositada << endl;
        //Refrescamos la lista para que impacten los cambios realizados
        ListaCuentas->DeleteAllItems();
        ListarCuentas(CrisNaMa.clientesActivos[ClienteSeleccionado], * ListaCuentas);
        //Vaciamos la caja para que quede de nuevo listo para hacer otra operacion
        TextCtrlCantidadDinero->Clear();
    }
    else{
        wxMessageBox(_("No se pudo convertir cadena ingresada!"),_("Error"));
    }

}

/*Metodo que se acciona cuando hacemos click en el boton extraer de la cuenta*/
void bancoguiFrame::OnButtonExtraerdeCuentaClick(wxCommandEvent& event)
{
    //Tomamos el valor de la caja
    wxString cadenaObtenida = TextCtrlCantidadDinero->GetValue();
    if(cadenaObtenida.size() == 0){
        wxMessageBox(_("No puede ser nulo el valor a extraer!"),_("Error"));
    }
    //Creamos una variable double para acumular el valor a extraer
    double extraccion;
    //Si se puede convertir la cadena
    if(cadenaObtenida.ToDouble(&extraccion)){
        //Si tiene fondos suficientes
        if(CrisNaMa.clientesActivos[ClienteSeleccionado][CuentaSeleccionada].autorizarExtraccion(extraccion))
            //Se realiza la extraccion
            CrisNaMa.clientesActivos[ClienteSeleccionado][CuentaSeleccionada] -= extraccion;
        else
            //Si no se advierte al cajero
            wxMessageBox(_("No dispone de suficientes fondos para extraer!"),_("Atencion"));
        //Se refresca la lista de cuentas para reflekar los cambios
        ListaCuentas->DeleteAllItems();
        ListarCuentas(CrisNaMa.clientesActivos[ClienteSeleccionado], * ListaCuentas);
        //Se limpia la caja de texto para que el operador pueda realizar otra transaccion
        TextCtrlCantidadDinero->Clear();
        //Generamos el nro de cuenta sobre la cual trabajamos concatenando dni y numero unico
        wxString NroCuentaExtraida;
        NroCuentaExtraida << CrisNaMa.clientesActivos[ClienteSeleccionado][CuentaSeleccionada].getdniDuenio();
        NroCuentaExtraida << CrisNaMa.clientesActivos[ClienteSeleccionado][CuentaSeleccionada].getnumeroUnico();
        //Escribimos el movimiento en el archivo de movimientos
        CrisNaMa.movimientos << horayfechaActual << " - " << "Extraido: $"<< cadenaObtenida <<" en Cuenta: "<< NroCuentaExtraida << endl;
    }
    else{
        wxMessageBox(_("No se pudo convertir cadena ingresada!"),_("Error"));
    }

}

/*Metodo al cual se invoca al hacer click en guardar estado*/
void bancoguiFrame::OnGuardar(wxCommandEvent& event){
    //Llamamos al método de la clase banco que escribe los cambios de la memoria en el disco
    CrisNaMa.escribirEstadoAArchivos();
    //Advertimos al usuario que el metodo se ejecuto correctamente
    MessageDialogGuardar->ShowModal();
    //Anotamos en el archivo de movimientos que se efectuo el guardado del estado
    CrisNaMa.movimientos << horayfechaActual << " - " <<"Guardado el estado del Banco"<< endl;
}

/*Reloj timer que lleva en cuenta la hora actual para poder realizar el log*/
void bancoguiFrame::OnTimer1Trigger(wxTimerEvent& event)
{
    wxString horaActual = wxDateTime::Now().FormatTime();
    wxString fechaActual = wxDateTime::Today().FormatDate();
    horayfechaActual = horaActual +" "+fechaActual;
    //Mostramos la hora en la pantalla principal
    StaticTextTime->SetLabel(horayfechaActual);
}

/*NO IMPLEMENTADO BOTON PARA MOSTRAR TODAS LAS CUENTAS*/
void bancoguiFrame::OnButtonCuentasActivasClick(wxCommandEvent& event)
{
    dialogoListadeCuentas * dialogo = new dialogoListadeCuentas(this);
    if(dialogo->Show() == wxID_CLOSE){
        dialogo->banco = &CrisNaMa;
    }
}

/*Message Box que muestra a los distinguidos integrantes del grupo de Paradigmas III*/
void bancoguiFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg("CT Nahuel SALAZAR\nTP Cristian FRANCO\nTP Carlos MACEIRA\nFacultad de Ingenieria de Ejército - 2018");
    wxMessageBox(msg, _("Banco"));
}


/*FUNCIONES DE PARADIGMAS ESTRUCTURADO APROVECHANDO LAS CUALIDADES DE C++*/
//Metodo que recibe la direccion de una instancia de banco y la
//direccion de una listCtrl en memoria y lo rellena de items
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


//Funcion que recibe la direccion de una instancia de cliente y la direccion
// de un ListCtrl en memoria y lo carga con items de las cuentas de ese cliente
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
            SALDO.resize(SALDO.Find(".") + 3 );
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


/*Este metodo fue necesario por que al guardar los registros en el archivo .txt con espacios
hacia fallar la lectura de cada renglon. La solucion mas sencilla fue reemplazar los guiones
por espacios y que los unicos caracteres especiales sean los saltos de linea*/
void eliminarGuiones (wxString & cadena){
    if(cadena.find("_") != wxNOT_FOUND)
        cadena.Replace("_"," ");
    return;
}


/*METODO QUE SOBRA, LO PUSO WXSMITH AUTOMATICAMENTE Y LO DEJO AHI
NO BORRAR POR QUE IMPLICA CAMBIAR EL CODIGO PREDEFINIDO*/
void bancoguiFrame::OnListCtrl1BeginDrag(wxListEvent& event){}
void bancoguiFrame::OnListCtrl1BeginDrag1(wxListEvent& event){}
void bancoguiFrame::OnButton1Click1(wxCommandEvent& event){}
void bancoguiFrame::OnButton1Click(wxCommandEvent& event){}
