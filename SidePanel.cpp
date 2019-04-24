#include "SidePanel.h"
#include "Common.h"


SidePanel::SidePanel(wxWindow *parent, wxWindowID id, const wxString &title)
    : wxFrame(parent, id, title, wxDefaultPosition, wxDefaultSize, SIDE_PANEL_STYLE) {

    label_ = new wxStaticText(
        this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize,
        wxALIGN_RIGHT | wxALIGN_CENTER);

    text_control_ = new wxTextCtrl(
        this, wxID_ANY, wxEmptyString, wxDefaultPosition,
        wxDefaultSize, wxTE_PROCESS_ENTER | wxTE_RIGHT);
}


wxBEGIN_EVENT_TABLE(SidePanel, wxFrame)
        EVT_SIZE(SidePanel::OnSize)
        EVT_LIST_ITEM_SELECTED(wxID_ANY, SidePanel::OnItemSelected)
        EVT_TEXT_ENTER(wxID_ANY, SidePanel::OnTextEnter)
wxEND_EVENT_TABLE()


Table *SidePanel::GetTable() const {
    return table_;
}


void SidePanel::SetTable(Table *table) {
    table_ = table;
}


void SidePanel::SetupLayout() {
    auto *vbox = new wxBoxSizer(wxVERTICAL);
    auto *hbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(table_, 1, wxEXPAND | wxALL, BORDER_SIZE);
    hbox->Add(label_, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, BORDER_SIZE);
    hbox->Add(text_control_, 0, wxALIGN_CENTRE_VERTICAL, 0);
    vbox->Add(hbox, 0, wxALIGN_RIGHT | wxALL, BORDER_SIZE);
    SetSizer(vbox);
    SetClientSize(table_->GetSize());
    vbox->Fit(this);
    Layout();
}


void SidePanel::OnSize(wxSizeEvent &event) {
    table_->ResizeColumns();
    event.Skip();
}


void SidePanel::OnItemSelected(wxListEvent &event) {
}


void SidePanel::OnTextEnter(wxCommandEvent &event) {
}
