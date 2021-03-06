#include "SidePanel.h"
#include "Common.h"

SidePanel::SidePanel(wxWindow *parent, wxWindowID id, const wxString &title)
    : wxFrame(parent, id, title, wxDefaultPosition, wxDefaultSize,
          wxCAPTION | wxFRAME_FLOAT_ON_PARENT | wxFRAME_TOOL_WINDOW |
              wxRESIZE_BORDER | wxCLIP_CHILDREN) {

    subpanel_ = new wxPanel(this, wxID_ANY);

    label_ = new wxStaticText(subpanel_, wxID_ANY, wxT("0"), wxDefaultPosition,
        wxDefaultSize, wxALIGN_RIGHT);

    text_control_ = new wxTextCtrl(subpanel_, wxID_ANY, wxEmptyString,
        wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxTE_RIGHT);
}

wxBEGIN_EVENT_TABLE(SidePanel, wxFrame)
    // EVT_SIZE(SidePanel::OnSize)
    EVT_LIST_ITEM_SELECTED(wxID_ANY, SidePanel::OnItemSelected)
    EVT_TEXT_ENTER(wxID_ANY, SidePanel::OnTextEnter)
wxEND_EVENT_TABLE()

Table *SidePanel::GetTable() const { return table_; }

void SidePanel::SetTable(Table *table) { table_ = table; }

void SidePanel::SetupLayout() {

    auto *hbox = new wxBoxSizer(wxHORIZONTAL);
    hbox->Add(label_, 0, wxALIGN_CENTRE_VERTICAL | wxRIGHT, BORDER_SIZE);
    hbox->Add(text_control_, 0, wxALIGN_CENTRE_VERTICAL, 0);
    subpanel_->SetSizer(hbox);

    auto *vbox = new wxBoxSizer(wxVERTICAL);
    vbox->Add(table_, 1, wxEXPAND | wxALL, BORDER_SIZE);
    vbox->Add(subpanel_, 0, wxALIGN_RIGHT | wxALL, BORDER_SIZE);
    subpanel_->Fit();
    SetSizer(vbox);
    SetSize(table_->GetSize());
    Layout();
}

void SidePanel::OnSize(wxSizeEvent &event) {
    table_->ResizeColumns();
    event.Skip();
}

void SidePanel::OnItemSelected(wxListEvent &event) {
    long index = event.GetIndex();
    wxString buffer;
    buffer.Printf("%d", table_->GetItem(index));
    text_control_->SetValue(buffer);
    buffer.Printf("%ld", index);
    label_->SetLabelText(buffer);
    label_->SetSize(label_->GetBestSize());
    label_->GetParent()->Layout();
}

void SidePanel::OnTextEnter(wxCommandEvent &event) {}
