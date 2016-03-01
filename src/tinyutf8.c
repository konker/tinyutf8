/**
 * libtinyutf8
 *
 * A library for reading and using fonts encoded in the unifont hex format
 *
 * Copyright 2015, Konrad Markus <konker@luxvelocitas.com>
 *
 * This file is part of libtinyutf8
 *
 * libtinyutf8 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libtinyutf8 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libtinyutf8.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Based on code by Jeff Bezanson
   https://github.com/JeffBezanson/cutef8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tinyutf8.h"

/* is c the start of a utf8 sequence? */
#define TINYUTF8_ISUTF(c) (((c) & 0xC0) != 0x80)

static const uint32_t TINYUTF8_OFFSETS_FROM_UTF8[6] = {
    0x00000000UL, 0x00003080UL, 0x000E2080UL,
    0x03C82080UL, 0xFA082080UL, 0x82082080UL
};

size_t tinyutf8_strlen(const char * const bytes) {
    size_t ret = 0;
    size_t i = 0, lasti = 0;
    size_t blen = strlen(bytes);

    while (i < blen) {
        lasti = i;
        while ((signed char)bytes[i] > 0) {
            i++;
        }

        ret += (i - lasti);
        if (bytes[i++] == 0) {
            break;
        }
        (void)(TINYUTF8_ISUTF(bytes[++i]) || TINYUTF8_ISUTF(bytes[++i]) || ++i);
        ret++;
    }

    return ret;
}

uint32_t tinyutf8_next_codepoint(const char * const bytes, size_t *i) {
    uint32_t ch = 0;
    size_t sz = 0;

    do {
        ch <<= 6;
        ch += (unsigned char)bytes[(*i)];
        sz++;
    }
    while (bytes[*i] && (++(*i)) && !TINYUTF8_ISUTF(bytes[*i]));
    ch -= TINYUTF8_OFFSETS_FROM_UTF8[sz-1];

    return ch;
}

