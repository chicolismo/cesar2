#ifndef CESAR_COMMON_H
#define CESAR_COMMON_H

#include <wx/wx.h>
#include <cstdint>

enum {
    ID_OpenFile = 1,
    ID_Base10,
    ID_Base16,
};

using Byte = uint8_t;
using Word = uint16_t;

const int MEM_SIZE{1 << 16};
const int BORDER_SIZE{8};

const int SIDE_PANEL_STYLE = wxCAPTION | wxRESIZE_BORDER | wxFRAME_TOOL_WINDOW;

#endif //CESAR_COMMON_H
