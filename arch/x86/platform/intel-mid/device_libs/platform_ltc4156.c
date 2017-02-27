/*
 * (C) Copyright 2017 Emlid Ltd.
 * Author: Aleksandr Aleksandrov, <aleksandr.aleksandrov@emlid.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <linux/init.h>
#include <linux/gpio.h>
#include <linux/i2c.h>
#include <asm/intel-mid.h>

#include "platform_ltc4156.h"

void __init *ltc4156_platform_data(void *info)
{
    struct i2c_board_info *i2c_info = info;

    if (!info) {
        pr_err("%s: invalid info pointer\n", __func__);
        return NULL;
    }

    strcpy(i2c_info->type, "ltc4156");
    return NULL;
}
