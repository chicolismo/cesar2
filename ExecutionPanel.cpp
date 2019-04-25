#include "ExecutionPanel.h"

ExecutionPanel::ExecutionPanel(wxWindow *parent, wxWindowID id)
    : wxPanel(parent, id) {

    auto *static_box_sizer = new wxStaticBoxSizer(wxVERTICAL, this, wxT("Execução"));
    auto *static_box = static_box_sizer->GetStaticBox();

    access_display_ = new DigitalDisplay(static_box, wxID_ANY);

    instructions_display_ = new DigitalDisplay(static_box, wxID_ANY);

    auto *access_label = new wxStaticText(static_box, wxID_ANY,
        wxT("Acessos:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);

    auto *instructions_label = new wxStaticText(static_box, wxID_ANY,
        wxT("Instruções:"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT);

    auto *sizer = new wxGridSizer(2, 2, 5, 5);
    sizer->Add(access_label, 0, wxALIGN_RIGHT);
    sizer->Add(access_display_, 0, wxALIGN_RIGHT);
    sizer->Add(instructions_label, 0);
    sizer->Add(instructions_display_, 0);

    static_box_sizer->Add(sizer, 0, wxALL, 5);

    SetSizer(static_box_sizer);
    Fit();
}
