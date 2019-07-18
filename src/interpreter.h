/*
    Copyright 2019 Hydr8gon

    This file is part of NooDS.

    NooDS is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    NooDS is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with NooDS. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <cstdint>

namespace interpreter
{

typedef struct
{
    uint32_t *registers[16];
    uint32_t *spsr;
    uint32_t cpsr;
    uint32_t registersUsr[16];
    uint32_t registersFiq[7];
    uint32_t registersSvc[2];
    uint32_t registersAbt[2];
    uint32_t registersIrq[2];
    uint32_t registersUnd[2];
    uint32_t spsrFiq, spsrSvc, spsrAbt, spsrIrq, spsrUnd;
    uint32_t *dmasad[4], *dmadad[4], *dmacnt[4];
    uint16_t *tmcnt[4], *timerCounters[4], timerReloads[4], timerScalers[4];
    uint16_t *ipcfifocnt;
    uint16_t *auxspicnt;
    uint32_t *romctrl; uint8_t *romcmdout;
    uint16_t *ime; uint32_t *ie, *irf;
    uint32_t irqRequest;
    bool halt;
    uint8_t type;
} Cpu;

extern Cpu arm9, arm7;

void execute(Cpu *cpu);
void setMode(Cpu *cpu, uint8_t mode);

void init();

}

#endif // INTERPRETER_H
