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
#include "IOEndpoint.h"
using namespace foxintango;
#include <iostream>
#include <vector>
#include <map>

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <chrono>
#include <atomic>
#include <fcntl.h>
#include <sys/sendfile.h>
/*
IOEndpoint::IOEndpoint() {
}

IOEndpoint::IOEndpoint(const char* address, const unsigned short port, const IOEndpointType& type) {
}

IOEndpoint::~IOEndpoint() {
}

IOEndpointStatus IOEndpoint::listen() {
    return IOEndpointStatus::IOES_OP_FAILED;
}
IOEndpointStatus IOEndpoint::connect(const char* address, const unsigned short port, const IOEndpointType& type){
    return IOEndpointStatus::IOES_OP_FAILED;
}
IOEndpointStatus IOEndpoint::send(char* buffer, const unsigned int& length){
    return IOEndpointStatus::IOES_OP_FAILED;
}
IOEndpointStatus IOEndpoint::read(char* buffer, const unsigned int& length){
    return IOEndpointStatus::IOES_OP_FAILED;
}
IOEndpointStatus IOEndpoint::readable() {
    return IOEndpointStatus::IOES_UNREADABLE;
}
IOEndpointStatus IOEndpoint::close(){
    return IOEndpointStatus::IOES_OP_OK;
}
*/
