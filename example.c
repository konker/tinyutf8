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

#include <stdio.h>
#include <stdlib.h>
#include "tinyutf8.h"


/*
$   U+0024
¢   U+00a2
€   U+20ac
𐍈   U+10348

,   U+002c
SP  U+0020
*/
int main(int argc, char **argv) {
    printf("Tinyutf8 library: %d, %s, %s\n", argc, argv[1], argv[2]);

    char bytes[] = "$, ¢, €, 𐍈";

    size_t len = tinyutf8_strlen(bytes);

    printf("s: %s\n", bytes);
    printf("strlen: %d\n", len);

    size_t i = 0, cnt = 0;
    while (cnt++ < len) {
        printf("CP(%d): %02x\n", i, tinyutf8_next_codepoint(bytes, &i));
    }
    printf("Goodbye\n");

    return EXIT_SUCCESS;
}
