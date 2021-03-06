#include <wx/wfstream.h>

#include "MainFrame.h"
#include "DataTable.h"
#include "SidePanel.h"
#include "ProgramTable.h"
#include "Register.h"
#include "ExecutionPanel.h"
#include "assets/computer.xpm"

MainFrame::MainFrame(wxWindow *parent, wxWindowID id, const wxString &title)
    : wxFrame(parent, id, title, wxDefaultPosition, wxDefaultSize) {

    main_panel_ = new wxPanel(this, wxID_ANY);
    auto *box_sizer = new wxBoxSizer(wxVERTICAL);
    main_panel_->SetSizer(box_sizer);

    cpu_ = new CPU();
    memory_ = cpu_->GetMemory();

    program_panel_ = new SidePanel(this, wxID_ANY, wxT("Programa"));
    auto *program_table = new ProgramTable(program_panel_, wxID_ANY);
    program_table->UseBase10(false);
    program_table->SetData(memory_, MEM_SIZE);
    program_panel_->SetTable(program_table);
    program_panel_->SetupLayout();
    program_panel_->Show();

    data_panel_ = new SidePanel(this, wxID_ANY, wxT("Dados"));
    auto *data_table = new DataTable(data_panel_, wxID_ANY);
    data_table->SetData(memory_, MEM_SIZE);
    data_panel_->SetTable(data_table);
    data_panel_->SetupLayout();
    data_panel_->Show();

    panels_.push_back(program_panel_);
    panels_.push_back(data_panel_);

    InitMenu();
    InitRadios();
    InitRegisters();

    main_panel_->SetBackgroundColour(*wxRED);
    SetClientSize(main_panel_->GetBestSize());
    SetMinSize(GetSize());
    Center();
    UpdatePanelsPositions();
}

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
        EVT_ICONIZE(MainFrame::OnIconize)
        EVT_MOVE(MainFrame::OnMove)
        EVT_MENU(wxID_OPEN, MainFrame::OnOpenFile)
        EVT_MENU(ID_OpenFile, MainFrame::OnOpenFile)
        EVT_MENU(wxID_EXIT, MainFrame::OnExit)
wxEND_EVENT_TABLE()


void MainFrame::InitMenu() {
    auto *file_menu = new wxMenu();
    file_menu->Append(ID_OpenFile, wxT("Abrir...\tCtrl-A"), wxT("Abrir um arquivo de memória"));
    file_menu->AppendSeparator();
    file_menu->Append(wxID_EXIT);

    auto *menu_bar = new wxMenuBar();
    menu_bar->Append(file_menu, wxT("Arquivo"));
    SetMenuBar(menu_bar);
}


void MainFrame::InitRadios() {
}

wxPanel *MainFrame::GetContentPane() const {
    return main_panel_;
}

void MainFrame::InitRegisters() {
    auto *panel = GetContentPane();
    auto *sizer = panel->GetSizer();

    RegisterPanel *r0 = new RegisterPanel(panel, wxID_ANY, wxT("R0:"));
    RegisterPanel *r1 = new RegisterPanel(panel, wxID_ANY, wxT("R1:"));
    RegisterPanel *r2 = new RegisterPanel(panel, wxID_ANY, wxT("R2:"));
    RegisterPanel *r3 = new RegisterPanel(panel, wxID_ANY, wxT("R3:"));
    RegisterPanel *r4 = new RegisterPanel(panel, wxID_ANY, wxT("R4:"));
    RegisterPanel *r5 = new RegisterPanel(panel, wxID_ANY, wxT("R5:"));
    RegisterPanel *r6 = new RegisterPanel(panel, wxID_ANY, wxT("R6: (SP)"));
    RegisterPanel *r7 = new RegisterPanel(panel, wxID_ANY, wxT("R7: (PC)"));

    wxPanel *computer_panel = new wxPanel(panel, wxID_ANY, wxDefaultPosition, wxSize(58, 49), wxBORDER_RAISED);
    wxBitmap computer_image(computer_xpm);
    wxStaticBitmap *computer = new wxStaticBitmap(computer_panel, wxID_ANY, computer_image, wxPoint(18, 9));

    register_panels_[0] = r0;
    register_panels_[1] = r1;
    register_panels_[2] = r2;
    register_panels_[3] = r3;
    register_panels_[4] = r4;
    register_panels_[5] = r5;
    register_panels_[6] = r6;
    register_panels_[7] = r7;

    wxGridSizer *grid = new wxGridSizer(3, 3, 5, 5);
    grid->Add(r0, 0, wxALIGN_CENTER);
    grid->Add(r1, 0, wxALIGN_CENTER);
    grid->Add(r2, 0, wxALIGN_CENTER);
    grid->Add(r3, 0, wxALIGN_CENTER);
    grid->Add(r4, 0, wxALIGN_CENTER);
    grid->Add(r5, 0, wxALIGN_CENTER);
    grid->Add(r6, 0, wxALIGN_CENTER);
    grid->Add(computer_panel, 0, wxEXPAND);
    grid->Add(r7, 0, wxALIGN_CENTER);

    ExecutionPanel *execution_panel = new ExecutionPanel(panel, wxID_ANY);
    wxBoxSizer *horizontal_box = new wxBoxSizer(wxHORIZONTAL);
    horizontal_box->Add(execution_panel, 0);

    sizer->Add(grid, 0, wxALL, 5);
    sizer->Add(horizontal_box, 0, wxALL, 5);
    panel->Fit();
}


void MainFrame::UpdateTables() {
    for (auto &panel : panels_) {
        panel->GetTable()->Refresh();
    }
}


void MainFrame::UpdatePanelsPositions() {
    int x, y, gap = 20;
    GetPosition(&x, &y);
    program_panel_->SetPosition(wxPoint(x - program_panel_->GetSize().GetWidth() - gap, y));
    data_panel_->SetPosition(wxPoint(x + GetSize().GetWidth() + gap, y));
}


void MainFrame::OnIconize(wxIconizeEvent &WXUNUSED(event)) {
    bool iconized = IsIconized();
    for (auto &panel : panels_) {
        panel->Show(!iconized);
    }
}


void MainFrame::OpenFile() {
    wxFileDialog dialog(this, wxFileSelectorPromptStr, wxEmptyString, wxEmptyString,
                        "Arquivos de memória (*.mem)|*.mem", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (dialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    wxFileInputStream input_stream(dialog.GetPath());
    if (!input_stream.IsOk()) {
        wxString error_message;
        error_message.Printf("Não foi possível abrir o arquivo %s", dialog.GetFilename());
        wxLogError(error_message);
        wxMessageBox(error_message, wxT("Aviso"));
        return;
    }

    size_t size = input_stream.GetSize();
    Byte *bytes = new Byte[size];
    input_stream.ReadAll(static_cast<void *>(bytes), size);
    cpu_->SetMemory(bytes, size);
    delete[] bytes;
    UpdateTables();
}


void MainFrame::OnMove(wxMoveEvent &WXUNUSED(event)) {
    UpdatePanelsPositions();
}


void MainFrame::OnOpenFile(wxCommandEvent &event) {
    OpenFile();
}


void MainFrame::OnExit(wxCommandEvent &event) {
    Close();
}


void MainFrame::OnBaseChange(wxCommandEvent &event) {
}
