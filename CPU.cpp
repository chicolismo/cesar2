#include "CPU.h"

#include <string>

CPU::CPU() {
    memory_ = new Byte[MEM_SIZE];
    bzero(static_cast<void *>(registers_), 8);
    bzero(static_cast<void *>(memory_), MEM_SIZE);
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
