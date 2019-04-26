//
// Created by Carlos Pinheiro on 2019-04-22.
//

#include "ProgramTable.h"

ProgramTable::ProgramTable(wxWindow *parent, wxWindowID id)
    : Table(parent, id) {

#ifdef _WIN32
    long style = wxLIST_FORMAT_LEFT;
#else
    long style = wxLIST_FORMAT_RIGHT;
#endif
    SetSize(wxSize(380, 500));
    InsertColumn(0, wxT("PC"), style, 30);
    InsertColumn(1, wxT("Endereço"), style, 80);
    InsertColumn(2, wxT("Dado"), style, 80);
    InsertColumn(3, wxT("Mnemônico"), wxLIST_FORMAT_LEFT, 150);
    SetScrollbar(wxHORIZONTAL, 0, 0, 0);
}

wxString ProgramTable::OnGetItemText(long item, long col) const {
    wxString buffer;
    switch (col) {
    case 0:
        buffer.Printf("PC");
        break;
    case 1:
        buffer.Printf("%ld", item);
        break;
    case 2:
        if (base10_) {
            buffer.Printf("%d", data_[item]);
        }
        else {
            buffer.Printf("%02x", data_[item]);
        }
        break;
    case 3:
        buffer.Printf("%s", wxT("Mnemônico goes here"));
        break;
    }
    return buffer;
}

void ProgramTable::ResizeColumns() {
    double width = (static_cast<double>(GetSize().GetWidth()) - 35);
    if (width <= 0) {
        return;
    }
    double q = width / 4;
    SetColumnWidth(0, 30);
    SetColumnWidth(1, std::ceil(q));
    SetColumnWidth(2, std::ceil(q));
    SetColumnWidth(3, std::ceil(2 * q));
    SetScrollbar(wxHORIZONTAL, 0, 0, 0);
}
