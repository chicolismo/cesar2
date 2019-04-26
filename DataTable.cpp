#include "DataTable.h"

DataTable::DataTable(wxWindow *parent, wxWindowID id) : Table(parent, id) {
#ifdef _WIN32
    long style = wxLIST_FORMAT_LEFT;
#else
    long style = wxLIST_FORMAT_RIGHT;
#endif
    InsertColumn(0, wxT("Endereço"), style, 80);
    InsertColumn(1, wxT("Dado"), style, 80);
    SetSize(wxSize(200, 500));
    SetScrollbar(wxHORIZONTAL, 0, 0, 0);
}

wxString DataTable::OnGetItemText(long item, long col) const {
    wxString buffer;
    if (col == 0) {
        buffer.Printf("%ld", item);
    } else {
        buffer.Printf("%d", data_[item]);
    }
    return buffer;
}

void DataTable::ResizeColumns() {
    // Barra de rolagem: 15 pixels
    double width = static_cast<double>(GetSize().GetWidth() - 15);
    if (width <= 180) {
        return;
    }
    int w = std::ceil(width / 2);
    SetColumnWidth(0, w);
    SetColumnWidth(1, w);
    // SetScrollbar(wxHORIZONTAL, 0, 0, 0);
}
