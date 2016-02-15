/**
 * libtinyutf8
 *
 * A library for reading and using fonts encoded in the unifont hex format
 *
 * Copyright 2016, Konrad Markus <konker@luxvelocitas.com>
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

#ifndef __TINYUTF8_H_
#define __TINYUTF8_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

size_t tinyutf8_strlen(const char * const bytes);
uint32_t tinyutf8_next_codepoint(const char * const bytes, size_t *i);

#ifdef __cplusplus
}
#endif

#endif // __TINYUTF8_H_

