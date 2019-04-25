#include <strings.h>
#include "CPU.h"

CPU::CPU() {
    memory_ = new Byte[MEM_SIZE];

#ifndef _WIN32
    bzero(static_cast<void *>(registers_), 8);
    bzero(static_cast<void *>(memory_), MEM_SIZE);
#else
    registers_[0] = 0;
    registers_[1] = 0;
    registers_[2] = 0;
    registers_[3] = 0;
    registers_[4] = 0;
    registers_[5] = 0;
    registers_[6] = 0;
    registers_[7] = 0;
    for (int i = 0; i < MEM_SIZE; ++i) {
        memory_[i] = 0;
    }
#endif
}


Byte *CPU::GetMemory() const {
    return memory_;
}


void CPU::SetMemory(Byte *data, size_t size) {
    int offset = size > MEM_SIZE ? size - MEM_SIZE : 0;
    int limit = std::min<size_t>(size, MEM_SIZE);
    for (int i = 0; i < limit; ++i) {
        memory_[i] = data[i + offset];
    }
}
