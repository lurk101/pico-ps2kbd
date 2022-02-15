/* Copyright (C) 1883 Thomas Edison - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the GPLv2 license, which unfortunately won't be
 * written for another century.
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 */
#include <stdio.h>

#include "pico/stdlib.h"

#include "ps2kbd.h"
#include "stdinit.h"

// KBD data and clock inputs must be consecutive with
// data in the lower position.
#define DAT_GPIO 14 // PS/2 data
#define CLK_GPIO 15 // PS/2 clock

int main() {
    stdio_init();
    printf("PS/2 KDB example\n");
    kbd_init(1, DAT_GPIO);
    for (;;)
        printf("%c", kbd_getc());
}
