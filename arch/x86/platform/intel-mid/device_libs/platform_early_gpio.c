
/*
 * platform_early_gpio_keys.c:
 *
 * (C) Copyright 2017 Emlid Ltd.
 * Author: Georgii Staroselskii
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/gpio.h>
#include <linux/platform_device.h>
#include <asm/intel-mid.h>
#include <linux/lnw_gpio.h>
#include "platform_early_gpio.h"

static void pin_write(int pin, const char *name)
{
    int ret;

    if ((ret = gpio_request(pin, name)) < 0) {
        goto out_error;
    }

	lnw_gpio_set_alt(pin, LNW_GPIO);

	if ((ret = gpio_direction_output(pin, 1)) < 0) {
        goto out_free;
    }

    gpio_set_value(pin, 1);

	gpio_free(pin);

out_free:
	gpio_free(pin);

out_error:

    return ret;

}

static int __init early_gpio_init(void)
{

    pin_write(182, "gpio_blue");
    pin_write(12, "gpio_red");
    pin_write(13, "gpio_green");

    return 0;

}

device_initcall(early_gpio_init);
