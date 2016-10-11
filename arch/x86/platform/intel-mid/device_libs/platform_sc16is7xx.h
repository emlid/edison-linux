/*
 * platform_sc16is7xx.h: sc16is7xx platform data header file
 *
 * (C) Copyright 2016 Emlid Ltd.
 * Author: Georgii Staroselskii <georgii.staroselskii@emlid.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */
#ifndef _PLATFORM_SC16IS7XX_H_
#define _PLATFORM_SC16IS7XX_H_

extern void __init *sc16is7xx_platform_data(void *info) __attribute__((weak));

static struct sfi_device_table_entry sc16is7xx_table_entry = { // <-- This structure is an entry of our very own SFI device table, which will be loaded later
    .type = SFI_DEV_TYPE_I2C,
    .host_num = 6, // <-- The Most Popular I2C Bus on Intel Edison
    .addr = 0x4d, // <-- Address of SC16IS7XX with A0, A1 tied to VSS
    .irq = 15,
    .max_freq = 400000,
    .name = "sc16is7xx", // <-- name of kernel module for handling this device
};

static struct devs_id sc16is7xx_devs_id = { // <-- Just a SFI boilerplate, keep the values consistent over all these places.
    .type = SFI_DEV_TYPE_I2C,
    .delay = 0,
    .get_platform_data = &sc16is7xx_platform_data,
    .device_handler = NULL,
};

#endif
