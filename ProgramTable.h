//
// Created by Carlos Pinheiro on 2019-04-22.
//

#ifndef CESAR_PROGRAMTABLE_H
#define CESAR_PROGRAMTABLE_H

#include "Table.h"

class ProgramTable : public Table {
public:
    ProgramTable(wxWindow *parent, wxWindowID id);

    wxString OnGetItemText(long item, long col) const override;

    void ResizeColumns() override;
};


#endif //CESAR_PROGRAMTABLE_H
