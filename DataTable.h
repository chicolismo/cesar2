//
// Created by Carlos Pinheiro on 2019-04-22.
//

#ifndef CESAR_DATATABLE_H
#define CESAR_DATATABLE_H


#include "Table.h"

class DataTable : public Table {
public:
    DataTable(wxWindow *parent, wxWindowID id);

    wxString OnGetItemText(long item, long col) const override;

    void ResizeColumns() override;
};


#endif //CESAR_DATATABLE_H
