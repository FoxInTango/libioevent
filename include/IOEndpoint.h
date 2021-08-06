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
#ifndef _IO_ENDPOINT_H_
#define _IO_ENDPOINT_H_

#include "IOHandler.h"
#include <libmodel/libmodel.h>
#include <libcpp/libcpp.h>

EXTERN_C_BEGIN
namespaceBegin(foxintango)
typedef enum _IOEndpointType 
{
    IOET_UDP,
    IOET_TCP_SERVER,
    IOET_TCP_CLIENT,
    IOET_HTTP_SERVER,
    IOET_HTTP_CLIENT,
    IOET_WS_SERVER,
    IOET_WS_CLIENT
}IOEndpointType;

typedef enum _IOEndpointStatus {} IOEndpointStatus;
/** Model
 *  {
 *     "type":"",
 *     "listen":{
 *                  "ip":"127.0.0.1",
 *                  "port":"32324"
 *                  }
 *  }
 */
class IOEndpointIMPL;
class foxintangoAPI IOEndpoint {
private:
    IOEndpointIMPL* impl;
public:
    IOEndpoint();
    IOEndpoint(const Model& model);
   ~IOEndpoint();
public:
    int appendEventHandler(IOEventHandler* handler);
    int removeEventHandler(IOEventHandler* handler);
           
    int appendSessionHandler(IOSessionHandler* handler);
    int removeSessionHandler(IOSessionHandler* handler);
public:
    IOEndpointStatus boot();
    IOEndpointStatus status();
public:
    int send(char* buffer,const unsigned int& length);
    int read(char* buffer,const unsigned int& length);
    unsigned int readable();
public:
    int sessionCount();
            
    IOSession* sessionAt(const unsigned int& index);
    IOSession* sessionFrom(const char* ip);
};
namespaceEnd
EXTERN_C_END
#endif
