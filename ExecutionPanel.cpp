#include "ExecutionPanel.h"

ExecutionPanel::ExecutionPanel(wxWindow *parent, wxWindowID id) : wxPanel(parent, id) {
    access_display_ = new DigitalDisplay(this, wxID_ANY);
    instructions_display_ = new DigitalDisplay(this, wxID_ANY);

    wxStaticBoxSizer *box_sizer = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Execução:"));
    wxGridSizer *sizer = new wxGridSizer(2, 2, 5, 5);
    SetSizer(box_sizer);

    wxStaticText *access_label = new wxStaticText(this, wxID_ANY, wxT("Acessos:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    wxStaticText *instructions_label = new wxStaticText(this, wxID_ANY, wxT("Instruções:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);
    sizer->Add(access_label, 0, wxALIGN_CENTRE_VERTICAL | wxALIGN_RIGHT | wxRIGHT, 5);
    sizer->Add(access_display_, 0, wxALIGN_CENTRE_VERTICAL | wxALIGN_RIGHT | wxRIGHT, 5);
    sizer->Add(instructions_label, 0, wxALIGN_CENTRE_VERTICAL | wxALIGN_RIGHT | wxRIGHT, 5);
    sizer->Add(instructions_display_, 0, wxALIGN_CENTRE_VERTICAL | wxALIGN_RIGHT | wxRIGHT, 5);
    box_sizer->Add(sizer, 0, 0);
    Fit();
}