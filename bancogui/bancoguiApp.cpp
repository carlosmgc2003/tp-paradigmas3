/***************************************************************
 * Name:      bancoguiApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Team C++ (carlosmgc2003@gmail.com)
 * Created:   2018-10-31
 * Copyright: Team C++ (https://github.com/carlosmgc2003/tp-paradigmas3.git)
 * License:
 **************************************************************/

#include "bancoguiApp.h"
#include "banco.hpp"


//(*AppHeaders
#include "bancoguiMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(bancoguiApp);

bool bancoguiApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	bancoguiFrame* Frame = new bancoguiFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
