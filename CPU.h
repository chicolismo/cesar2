#ifndef CESAR_CPU_H
#define CESAR_CPU_H

#include <cmath>
#include <algorithm>
#include "Common.h"

class CPU {
    Byte registers_[8]{};
    Byte *memory_;


public:
    CPU();

    Byte *GetMemory() const;

    void SetMemory(Byte *data, size_t size);
};


#endif //CESAR_CPU_H
