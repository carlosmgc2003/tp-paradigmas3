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
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class bancoguiFrame: public wxFrame
{
    public:

        bancoguiFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~bancoguiFrame();

    private:

        //(*Handlers(bancoguiFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(bancoguiFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(bancoguiFrame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // BANCOGUIMAIN_H
