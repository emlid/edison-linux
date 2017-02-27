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
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>
#include <linux/gpio.h>

#define LTC4156_NAME "ltc4156"

static void ltc_probe(struct i2c_client *client,
                      const struct i2c_device_id *id);

static const struct i2c_device_id ltc_ids[] = {
    { LTC4156_NAME, 0 },
    { }
};

static struct i2c_driver ltc_driver = {
    .driver = {
        .name   = LTC4156_NAME,
        .owner  = THIS_MODULE,
    },
    .probe      = ltc_probe,
    .id_table   = ltc_ids
};

static void ltc_probe(struct i2c_client *client,
                      const struct i2c_device_id *id)
{
    int ret = i2c_smbus_write_byte_data(client, 0x00, 0x20);

    if (ret < 0) {
        pr_err("ltc4156 probe: write to 0x00, ret=%d\n", ret);
        return ret;
    }

    ret = i2c_smbus_write_byte_data(client, 0x06, 0x00);

    if (ret < 0) {
        pr_err("ltc4156 probe: write to 0x06, ret=%d\n", ret);
    }

    return ret;
}

static int __init ltc_init(void)
{
    int ret = i2c_add_driver(&ltc_driver);

    if (ret < 0) {
        pr_err("failed to init ltc4156: i2c --> %d\n", ret);
        return ret;
    }

    return ret;
}

static void __exit ltc_exit(void)
{
    i2c_del_driver(&ltc_driver);
}

module_init(ltc_init);
module_exit(ltc_exit);

MODULE_LICENSE("GPL");
