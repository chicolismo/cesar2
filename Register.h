//
// Created by Carlos Pinheiro on 2019-04-23.
//

#ifndef CESAR_REGISTER_H
#define CESAR_REGISTER_H

#include <wx/wx.h>
#include "Common.h"

class DigitalDisplay : public wxWindow {
private:
    static const int DIGIT_WIDTH = 12;
    static const int DIGIT_OFFSET = DIGIT_WIDTH + 2;
    static const int NUMBER_OF_DIGITS = 5;
    static const int WIDTH = 76;
    static const int HEIGHT = 25;
    wxBitmap display_images_[16]{};
    wxBitmap display_null_;
    int base_ = 10;
    Word value_ = 0;
    const wxBrush *black_brush_ = wxBLACK_BRUSH;
    const wxPen highlight_pen_ = wxPen(wxColour(255, 255, 255, 128));
    const wxPen shadow_pen_ = wxPen(wxColour(0, 0, 0, 100));


public:
    DigitalDisplay(wxWindow *parent, wxWindowID id);

    void SetValue(Word value);

    Word GetValue() const;

    void SetBase(int base);

    void PaintNow();

    void OnPaint(wxPaintEvent &event);

protected:
    void Render(wxDC &dc);

public:
wxDECLARE_EVENT_TABLE();
};


class RegisterPanel : public wxPanel {
    DigitalDisplay *display_;
    wxStaticBox *static_box_;

public:
    RegisterPanel(wxWindow *parent, wxWindowID id, const wxString &title);

    void SetValue(Word value);
};

#endif //CESAR_REGISTER_H
