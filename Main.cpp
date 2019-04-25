#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-pro-type-static-cast-downcast"

#ifdef WX_PRECOMP
#include <wx/wxprec.h>
#else

#include <wx/wx.h>
#include "MainFrame.h"

#endif

class Application : public wxApp {
public:
    bool OnInit() override;
};


bool Application::OnInit() {
    wxInitAllImageHandlers();
    MainFrame *main_frame = new MainFrame(nullptr, wxID_ANY, wxT("Cesar"));
    SetTopWindow(main_frame);
    main_frame->Show(true);

    return true;
}


IMPLEMENT_APP(Application)

#pragma clang diagnostic pop
