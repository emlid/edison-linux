/*
 * platform_sc16is7xx.c: sc16is7xx platform data initilization file
 *
 * (C) Copyright 2016 Emlid Ltd.
 * Author: Georgii Staroselskii <georgii.staroselskii@emlid.com>
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

#include "platform_sc16is7xx.h"


static unsigned long sc16is750_frequency = 14745600ul;

void __init *sc16is7xx_platform_data(void *info)
{
	struct i2c_board_info *i2c_info = info;

	if (!info) {
		pr_err("%s: invalid info pointer\n", __func__);
		return NULL;
	}

	strcpy(i2c_info->type, "sc16is750");

	return &sc16is750_frequency;
}
