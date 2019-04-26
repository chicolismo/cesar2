//
// Created by Carlos Pinheiro on 2019-04-22.
//

#ifndef CESAR_SIDEPANEL_H
#define CESAR_SIDEPANEL_H

#include "Table.h"
#include <wx/wx.h>
#include <wx/minifram.h>

class SidePanel : public wxFrame {
private:
    Table *table_;
    wxPanel *subpanel_;
    wxStaticText *label_;
    wxTextCtrl *text_control_;

public:
    SidePanel(wxWindow *parent, wxWindowID id, const wxString &title);

    void SetTable(Table *table);

    Table *GetTable() const;

    void SetupLayout();

    // Events
    void OnSize(wxSizeEvent &event);

    void OnItemSelected(wxListEvent &event);

    void OnTextEnter(wxCommandEvent &event);

    wxDECLARE_EVENT_TABLE();
};

#endif // CESAR_SIDEPANEL_H
