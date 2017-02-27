/*
 * (C) Copyright 2017 Emlid Ltd.
 * Author: Aleksandr Aleksandrov, <aleksandr.aleksandrov@emlid.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#ifndef _PLATFORM_LTC4156_H_
#define _PLATFORM_LTC4156_H_

extern void __init *ltc4156_platform_data(void *info) __attribute__((weak));

static struct sfi_device_table_entry ltc4156_table_entry = {
    .type = SFI_DEV_TYPE_I2C,
    .host_num = 1,
    .addr = 0x09,
    .irq = -1,
    .max_freq = 400000,
    .name = "ltc4156"
};

static struct devs_id ltc4156_devs_id = {
    .type = SFI_DEV_TYPE_I2C,
    .delay = 0,
    .get_platform_data = &ltc4156_platform_data,
    .device_handler = NULL
};

#endif
