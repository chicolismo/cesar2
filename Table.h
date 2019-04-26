#ifndef CESAR_TABLE_H
#define CESAR_TABLE_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include "Common.h"

class Table : public wxListCtrl {
protected:
    bool base10_;
    Byte *data_;
    size_t size_;

public:
    Table(wxWindow *parent, wxWindowID id);

    wxString OnGetItemText(long item, long col) const override;

    void SetData(Byte *data, size_t size);

    void SetItem(long item, Byte value);

    void UseBase10(bool use);

    Byte GetItem(long item) const;

    void Refresh();

    virtual void ResizeColumns() = 0;
};


#endif //CESAR_TABLE_H
