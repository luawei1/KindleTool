//
//  kindle_table.h
//  KindleTool
//
//  Copyright (C) 2011-2012  Yifan Lu
//  Copyright (C) 2012-2018  NiLuJe
//  Concept based on an original Python implementation by Igor Skochinsky & Jean-Yves Avenard,
//    cf., http://www.mobileread.com/forums/showthread.php?t=63225
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

// NOTE: Full credit for this implementation goes to Michael S. Zick,
// cf. https://github.com/NiLuJe/KindleTool/pull/6 ;).

/*
   Byte sized look-up tables that implement the Amazon mangle algorithm.
   The look-up tables where generated and tested by: tools/TableGen.lua
*/

#ifndef __KINDLETOOL_TABLE_H
#define __KINDLETOOL_TABLE_H

/*  index by plain, result garbled */
static const uint8_t ptog[] = {
    0x7a, 0x6a, 0x5a, 0x4a, 0x3a, 0x2a, 0x1a, 0x0a,
    0xfa, 0xea, 0xda, 0xca, 0xba, 0xaa, 0x9a, 0x8a,
    0x7b, 0x6b, 0x5b, 0x4b, 0x3b, 0x2b, 0x1b, 0x0b,
    0xfb, 0xeb, 0xdb, 0xcb, 0xbb, 0xab, 0x9b, 0x8b,
    0x78, 0x68, 0x58, 0x48, 0x38, 0x28, 0x18, 0x08,
    0xf8, 0xe8, 0xd8, 0xc8, 0xb8, 0xa8, 0x98, 0x88,
    0x79, 0x69, 0x59, 0x49, 0x39, 0x29, 0x19, 0x09,
    0xf9, 0xe9, 0xd9, 0xc9, 0xb9, 0xa9, 0x99, 0x89,
    0x7e, 0x6e, 0x5e, 0x4e, 0x3e, 0x2e, 0x1e, 0x0e,
    0xfe, 0xee, 0xde, 0xce, 0xbe, 0xae, 0x9e, 0x8e,
    0x7f, 0x6f, 0x5f, 0x4f, 0x3f, 0x2f, 0x1f, 0x0f,
    0xff, 0xef, 0xdf, 0xcf, 0xbf, 0xaf, 0x9f, 0x8f,
    0x7c, 0x6c, 0x5c, 0x4c, 0x3c, 0x2c, 0x1c, 0x0c,
    0xfc, 0xec, 0xdc, 0xcc, 0xbc, 0xac, 0x9c, 0x8c,
    0x7d, 0x6d, 0x5d, 0x4d, 0x3d, 0x2d, 0x1d, 0x0d,
    0xfd, 0xed, 0xdd, 0xcd, 0xbd, 0xad, 0x9d, 0x8d,
    0x72, 0x62, 0x52, 0x42, 0x32, 0x22, 0x12, 0x02,
    0xf2, 0xe2, 0xd2, 0xc2, 0xb2, 0xa2, 0x92, 0x82,
    0x73, 0x63, 0x53, 0x43, 0x33, 0x23, 0x13, 0x03,
    0xf3, 0xe3, 0xd3, 0xc3, 0xb3, 0xa3, 0x93, 0x83,
    0x70, 0x60, 0x50, 0x40, 0x30, 0x20, 0x10, 0x00,
    0xf0, 0xe0, 0xd0, 0xc0, 0xb0, 0xa0, 0x90, 0x80,
    0x71, 0x61, 0x51, 0x41, 0x31, 0x21, 0x11, 0x01,
    0xf1, 0xe1, 0xd1, 0xc1, 0xb1, 0xa1, 0x91, 0x81,
    0x76, 0x66, 0x56, 0x46, 0x36, 0x26, 0x16, 0x06,
    0xf6, 0xe6, 0xd6, 0xc6, 0xb6, 0xa6, 0x96, 0x86,
    0x77, 0x67, 0x57, 0x47, 0x37, 0x27, 0x17, 0x07,
    0xf7, 0xe7, 0xd7, 0xc7, 0xb7, 0xa7, 0x97, 0x87,
    0x74, 0x64, 0x54, 0x44, 0x34, 0x24, 0x14, 0x04,
    0xf4, 0xe4, 0xd4, 0xc4, 0xb4, 0xa4, 0x94, 0x84,
    0x75, 0x65, 0x55, 0x45, 0x35, 0x25, 0x15, 0x05,
    0xf5, 0xe5, 0xd5, 0xc5, 0xb5, 0xa5, 0x95, 0x85
};

/*  index by garbled, result plain */
static const uint8_t gtop[] = {
    0xa7, 0xb7, 0x87, 0x97, 0xe7, 0xf7, 0xc7, 0xd7,
    0x27, 0x37, 0x07, 0x17, 0x67, 0x77, 0x47, 0x57,
    0xa6, 0xb6, 0x86, 0x96, 0xe6, 0xf6, 0xc6, 0xd6,
    0x26, 0x36, 0x06, 0x16, 0x66, 0x76, 0x46, 0x56,
    0xa5, 0xb5, 0x85, 0x95, 0xe5, 0xf5, 0xc5, 0xd5,
    0x25, 0x35, 0x05, 0x15, 0x65, 0x75, 0x45, 0x55,
    0xa4, 0xb4, 0x84, 0x94, 0xe4, 0xf4, 0xc4, 0xd4,
    0x24, 0x34, 0x04, 0x14, 0x64, 0x74, 0x44, 0x54,
    0xa3, 0xb3, 0x83, 0x93, 0xe3, 0xf3, 0xc3, 0xd3,
    0x23, 0x33, 0x03, 0x13, 0x63, 0x73, 0x43, 0x53,
    0xa2, 0xb2, 0x82, 0x92, 0xe2, 0xf2, 0xc2, 0xd2,
    0x22, 0x32, 0x02, 0x12, 0x62, 0x72, 0x42, 0x52,
    0xa1, 0xb1, 0x81, 0x91, 0xe1, 0xf1, 0xc1, 0xd1,
    0x21, 0x31, 0x01, 0x11, 0x61, 0x71, 0x41, 0x51,
    0xa0, 0xb0, 0x80, 0x90, 0xe0, 0xf0, 0xc0, 0xd0,
    0x20, 0x30, 0x00, 0x10, 0x60, 0x70, 0x40, 0x50,
    0xaf, 0xbf, 0x8f, 0x9f, 0xef, 0xff, 0xcf, 0xdf,
    0x2f, 0x3f, 0x0f, 0x1f, 0x6f, 0x7f, 0x4f, 0x5f,
    0xae, 0xbe, 0x8e, 0x9e, 0xee, 0xfe, 0xce, 0xde,
    0x2e, 0x3e, 0x0e, 0x1e, 0x6e, 0x7e, 0x4e, 0x5e,
    0xad, 0xbd, 0x8d, 0x9d, 0xed, 0xfd, 0xcd, 0xdd,
    0x2d, 0x3d, 0x0d, 0x1d, 0x6d, 0x7d, 0x4d, 0x5d,
    0xac, 0xbc, 0x8c, 0x9c, 0xec, 0xfc, 0xcc, 0xdc,
    0x2c, 0x3c, 0x0c, 0x1c, 0x6c, 0x7c, 0x4c, 0x5c,
    0xab, 0xbb, 0x8b, 0x9b, 0xeb, 0xfb, 0xcb, 0xdb,
    0x2b, 0x3b, 0x0b, 0x1b, 0x6b, 0x7b, 0x4b, 0x5b,
    0xaa, 0xba, 0x8a, 0x9a, 0xea, 0xfa, 0xca, 0xda,
    0x2a, 0x3a, 0x0a, 0x1a, 0x6a, 0x7a, 0x4a, 0x5a,
    0xa9, 0xb9, 0x89, 0x99, 0xe9, 0xf9, 0xc9, 0xd9,
    0x29, 0x39, 0x09, 0x19, 0x69, 0x79, 0x49, 0x59,
    0xa8, 0xb8, 0x88, 0x98, 0xe8, 0xf8, 0xc8, 0xd8,
    0x28, 0x38, 0x08, 0x18, 0x68, 0x78, 0x48, 0x58
};

#endif

// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
