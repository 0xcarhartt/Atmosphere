/*
 * Copyright (c) 2018-2019 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#pragma once
#include <switch.h>
#include <stratosphere.hpp>

#include "boot_types.hpp"

class Boot {
    public:
        static constexpr u32 GpioPhysicalBase = 0x6000D000;
    public:
        /* Functions for actually booting. */
        static void ChangeGpioVoltageTo1_8v();
        static void SetInitialGpioConfiguration();

        /* Register Utilities. */
        static u32 ReadPmcRegister(u32 phys_addr);
        static void WritePmcRegister(u32 phys_addr, u32 value, u32 mask = UINT32_MAX);
        
        /* GPIO Utilities. */
        static u32 GpioConfigure(u32 gpio_pad_name);
        static u32 GpioSetDirection(u32 gpio_pad_name, GpioDirection dir);
        static u32 GpioSetValue(u32 gpio_pad_name, GpioValue val);
        
        /* SPL Utilities. */
        static HardwareType GetHardwareType();
};
