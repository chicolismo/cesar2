#include "Register.h"

#include "assets/cesar_0.xpm"
#include "assets/cesar_1.xpm"
#include "assets/cesar_2.xpm"
#include "assets/cesar_3.xpm"
#include "assets/cesar_4.xpm"
#include "assets/cesar_5.xpm"
#include "assets/cesar_6.xpm"
#include "assets/cesar_7.xpm"
#include "assets/cesar_8.xpm"
#include "assets/cesar_9.xpm"
#include "assets/cesar_a.xpm"
#include "assets/cesar_b.xpm"
#include "assets/cesar_c.xpm"
#include "assets/cesar_d.xpm"
#include "assets/cesar_e.xpm"
#include "assets/cesar_f.xpm"
#include "assets/cesar_null.xpm"


DigitalDisplay::DigitalDisplay(wxWindow *parent, wxWindowID id)
        : wxWindow(parent, id, wxDefaultPosition, wxSize(WIDTH, HEIGHT)) {
    display_images_[0] = wxBitmap(cesar_0_xpm);
    display_images_[1] = wxBitmap(cesar_1_xpm);
    display_images_[2] = wxBitmap(cesar_2_xpm);
    display_images_[3] = wxBitmap(cesar_3_xpm);
    display_images_[4] = wxBitmap(cesar_4_xpm);
    display_images_[5] = wxBitmap(cesar_5_xpm);
    display_images_[6] = wxBitmap(cesar_6_xpm);
    display_images_[7] = wxBitmap(cesar_7_xpm);
    display_images_[8] = wxBitmap(cesar_8_xpm);
    display_images_[9] = wxBitmap(cesar_9_xpm);
    display_images_[10] = wxBitmap(cesar_a_xpm);
    display_images_[11] = wxBitmap(cesar_b_xpm);
    display_images_[12] = wxBitmap(cesar_c_xpm);
    display_images_[13] = wxBitmap(cesar_d_xpm);
    display_images_[14] = wxBitmap(cesar_e_xpm);
    display_images_[15] = wxBitmap(cesar_f_xpm);
    display_null_ = wxBitmap(cesar_null_xpm);
}


wxBEGIN_EVENT_TABLE(DigitalDisplay, wxWindow)
                EVT_PAINT(DigitalDisplay::OnPaint)
wxEND_EVENT_TABLE()


void DigitalDisplay::SetValue(Word value) {
    value_ = value;
    PaintNow();
}


void DigitalDisplay::Render(wxDC &dc) {
    dc.SetBrush(*black_brush_);
    dc.DrawRectangle(wxPoint(1, 1), wxSize(WIDTH - 2, HEIGHT - 2));

    dc.SetPen(shadow_pen_);
    dc.DrawLine(0, 0, WIDTH - 2, 0);
    dc.DrawLine(0, 1, 0, HEIGHT - 2);
    dc.SetPen(highlight_pen_);
    dc.DrawLine(0, HEIGHT - 1, WIDTH - 1, HEIGHT - 1);
    dc.DrawLine(WIDTH - 1, 0, WIDTH - 1, HEIGHT - 1);

    int y = 4;
    int x = 60;
    int current_digit = 0;
    Word n = value_;

    do {
        int digit = n % base_;
        dc.DrawBitmap(display_images_[digit], x, y, false);
        x -= DIGIT_OFFSET;
        ++current_digit;
        n /= base_;
    } while (n > 0);

    while (current_digit < NUMBER_OF_DIGITS) {
        dc.DrawBitmap(display_null_, x, y, false);
        x -= DIGIT_OFFSET;
        ++current_digit;
    }
}


void DigitalDisplay::PaintNow() {
    wxClientDC dc(this);
    Render(dc);
}


void DigitalDisplay::OnPaint(wxPaintEvent &event) {
    wxPaintDC dc(this);
    Render(dc);
    event.Skip();
}


Word DigitalDisplay::GetValue() const {
    return value_;
}


void DigitalDisplay::SetBase(int base) {
    base_ = base;
}

// RegisterPanel

RegisterPanel::RegisterPanel(wxWindow *parent, wxWindowID id, const wxString &title) : wxPanel(parent, id) {
    display_ = new DigitalDisplay(this, wxID_ANY);
    wxStaticBoxSizer *sizer = new wxStaticBoxSizer(wxVERTICAL, this, title);
    sizer->Add(display_, 0, wxALIGN_CENTER | wxALL, 5);
    Fit();
    SetSizer(sizer);
}


void RegisterPanel::SetValue(Word value) {
    display_->SetValue(value);
}

