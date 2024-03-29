/*
 * libioevent
 *
 * Copyright (C) 2021 FoxInTango <foxintango@yeah.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#ifndef _IO_SOCKET_H_foxintango
#define _IO_SOCKET_H_foxintango

#include <libcpp/libcpp.h>

namespaceBegin(foxintango)

typedef int IO_SOCKET_TYPE;

const IO_SOCKET_TYPE IO_SOCKET_TYPE_UDP     = 0x00000000;
const IO_SOCKET_TYPE IO_SOCKET_TYPE_TCP     = 0x00000001;
const IO_SOCKET_TYPE IO_SOCKET_TYPE_UNIX    = 0x00000010;
const IO_SOCKET_TYPE IO_SOCKET_TYPE_NETLINK = 0x00000100;

const int IO_SOCKET_TLS_FLAG     = 0x10000000;

class IOSocket {
public:
public:
    IOSocket();
   ~IOSocket();
public:
   int read();
   int write();
};
namespaceEnd
#endif
