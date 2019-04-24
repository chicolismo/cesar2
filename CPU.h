//
// Created by Carlos Pinheiro on 2019-04-23.
//

#ifndef CESAR_CPU_H
#define CESAR_CPU_H

#include <strings.h>
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
