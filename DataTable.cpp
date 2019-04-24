#include "DataTable.h"


DataTable::DataTable(wxWindow *parent, wxWindowID id) : Table(parent, id) {
#ifdef _WIN32
    long style = wxLIST_FORMAT_LEFT;
#else
    long style = wxLIST_FORMAT_RIGHT;
#endif
    SetSize(wxSize(110, 500));
    InsertColumn(0, wxT("Endereço"), style, wxLIST_AUTOSIZE);
    InsertColumn(1, wxT("Dado"), style, wxLIST_AUTOSIZE);
    ResizeColumns();
}


wxString DataTable::OnGetItemText(long item, long col) const {
    wxString buffer;
    if (col == 0) {
        buffer.Printf("%ld", item);
    }
    else {
        buffer.Printf("%d", data_[item]);
    }
    return buffer;
}


void DataTable::ResizeColumns() {
    // Barra de rolagem: 15 pixels
    double q = static_cast<double>(GetSize().GetWidth() - 15) / 2.0;
    SetColumnWidth(0, std::ceil(q));
    SetColumnWidth(1, std::ceil(q));
    SetScrollbar(wxHORIZONTAL, 0, 0, 0);
}
