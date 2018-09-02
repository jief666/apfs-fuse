/*
	This file is part of apfs-fuse, a read-only implementation of APFS
	(Apple File System) for FUSE.
	Copyright (C) 2017 Simon Gander

	Apfs-fuse is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 2 of the License, or
	(at your option) any later version.

	Apfs-fuse is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with apfs-fuse.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

typedef unsigned char byte_t;
typedef unsigned char apfs_uuid_t[16];

#include <limits.h> // for INT_MAX, etc.
#include <assert.h>

// useful to resolve signed / unsigned warning when it's sure that offset is > 0.
// if off_t isn't long long int on some plateform, might have to #ifdef.
// It should be true for all 64 bits models (ILP32, LP64, LLP64, ILP64) as they all define long long int as 64 bits
//   and most likely, off_t will always be 64 bits on 64 bits plateform, but I'm not sure.
// So far, it's true for Apple 64 bits, linux 32 bits (with _FILE_OFFSET_BITS=64).
#include <stdio.h>
#include <sys/types.h>
typedef unsigned long long int uoff_t;
#if defined(__cpp_static_assert)
	static_assert(sizeof(off_t) == sizeof(uoff_t), "sizeof(off_t) == sizeof(uoff_t)");
#else
	#warning Make sure of sizeof(off_t) == sizeof(uoff_t)
#endif



// Debug level - defined in ApfsContainer.cpp
extern int g_debug;
// Lax mode - defined in ApfsContainer.cpp
extern bool g_lax;

enum DbgFlags
{
	Dbg_Errors = 1,
	Dbg_Info = 2,
	Dbg_Dir = 4,
	Dbg_Cmpfs = 8,
	Dbg_Crypto = 16
};
