#ifndef PROCESS_H
#define PROCESS_H

#include "emu/cpu.h"

struct process {
    struct cpu_state cpu;

    addr_t start_brk;
    addr_t brk;
};

// current will always give the process that is currently executing
// if I have to stop using __thread, current will become a macro
extern struct process *current;
#define curmem current->cpu.mem

// Creates a new process, returns NULL in case of failure
struct process *process_create(void);

#endif
