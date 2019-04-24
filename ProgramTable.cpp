//
// Created by Carlos Pinheiro on 2019-04-22.
//

#include "ProgramTable.h"


ProgramTable::ProgramTable(wxWindow *parent, wxWindowID id) : Table(parent, id) {

#ifdef _WIN32
    long style = wxLIST_FORMAT_LEFT;
#else
    long style = wxLIST_FORMAT_RIGHT;
#endif

    SetSize(wxSize(320, 500));
    InsertColumn(0, wxT("PC"), style, wxLIST_AUTOSIZE);
    InsertColumn(1, wxT("Endereço"), style, wxLIST_AUTOSIZE);
    InsertColumn(2, wxT("Dado"), style, wxLIST_AUTOSIZE);
    InsertColumn(3, wxT("Mnemônico"), wxLIST_FORMAT_LEFT, wxLIST_AUTOSIZE);
    ResizeColumns();
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
        buffer.Printf("%d", data_[item]);
        break;
    case 3:
        buffer.Printf("Mnemônico goes here");
        break;
    }
    return buffer;
}


void ProgramTable::ResizeColumns() {
    double q = (static_cast<double>(GetSize().GetWidth()) - 35) / 4;
    SetColumnWidth(0, 20);
    SetColumnWidth(1, std::ceil(q));
    SetColumnWidth(2, std::ceil(q));
    SetColumnWidth(3, std::ceil(2 * q));
    SetScrollbar(wxHORIZONTAL, 0, 0, 0);
}
