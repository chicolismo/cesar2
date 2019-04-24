#ifndef CESAR_MAINFRAME_H
#define CESAR_MAINFRAME_H

#include <wx/wx.h>
#include <wx/tglbtn.h>
#include "Table.h"
#include "Common.h"
#include "SidePanel.h"
#include "CPU.h"
#include "Register.h"

class MainFrame : public wxFrame {
    CPU *cpu_;
    Byte *memory_;
    wxVector<SidePanel *> panels_;
    SidePanel *program_panel_;
    SidePanel *data_panel_;
    RegisterPanel *register_panels_[8]{};
public:
    MainFrame(wxWindow *parent, wxWindowID id, const wxString &title);

    void InitMenu();

    void InitRadios();

    void InitRegisters();

    void UpdateTables();

    void OpenFile();

    void UpdatePanelsPositions();

    void OnIconize(wxIconizeEvent &event);

    void OnMove(wxMoveEvent &event);

    void OnOpenFile(wxCommandEvent &event);

    void OnExit(wxCommandEvent &event);

    void OnBaseChange(wxCommandEvent &event);

DECLARE_EVENT_TABLE();
};

#endif //CESAR_MAINFRAME_H
