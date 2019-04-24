#ifndef CESAR_EXECUTIONPANEL_H
#define CESAR_EXECUTIONPANEL_H

#include <wx/wx.h>
#include "Register.h"

class ExecutionPanel : public wxPanel {
    DigitalDisplay *access_display_;
    DigitalDisplay *instructions_display_;

public:
    ExecutionPanel(wxWindow *parent, wxWindowID id);
};
#endif //CESAR_EXECUTIONPANEL_