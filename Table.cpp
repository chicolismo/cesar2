#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-member-init"
#pragma ide diagnostic ignored "hicpp-signed-bitwise"

#include "Table.h"


Table::Table(wxWindow *parent, wxWindowID id)
    : wxListCtrl(parent, id, wxDefaultPosition, wxDefaultSize,
                 wxLC_VIRTUAL | wxLC_REPORT | wxLC_HRULES | wxLC_VRULES) {
#ifdef _WIN32
    int font_size = 10;
#else
    int font_size = 12;
#endif
    SetFont(wxFont(font_size, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    SetItemCount(0);
}


wxString Table::OnGetItemText(long item, long WXUNUSED(col)) const {
    wxString buffer;
    buffer.Printf("%ld", data_[item]);
    return buffer;
}


void Table::SetData(Byte *data, size_t size) {
    data_ = data;
    size_ = size;
    SetItemCount(size);
}


void Table::SetItem(long item, Byte value) {
    data_[item] = value;
    RefreshItem(item);
}


Byte Table::GetItem(long item) const {
    return data_[item];
}


void Table::Refresh() {
    RefreshItems(0, size_ - 1);
}


#pragma clang diagnostic pop