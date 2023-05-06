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
    /*
    IOET_UDP         = 0b00000000000000001,
    IOET_TCP_SERVER  = 0b00000000000000010,
    IOET_TCP_CLIENT  = 0b00000000000000100,
    IOET_HTTP_SERVER = 0b00000000000001000,
    IOET_HTTP_CLIENT = 0b00000000000010000,
    IOET_WS_SERVER   = 0b00000000000100000,
    IOET_WS_CLIENT   = 0b00000000001000000,
    IOET_UDP_PROXY   = 0b00000000010000000,
    IOET_TCP_PROXY   = 0b00000000100000000,
    IOET_HTTP_PROXY  = 0b00000001000000000,
    IOET_WS_PROXY    = 0b00000010000000000,
    */
    IOET_LISTEN_UDP,
    IOET_LISTEN_TCP,
    IOET_LISTEN_UNIX,
    IOET_LISTEN_NETLINK,
    IOET_CONNECT
}IOEndpointType;

#define IOET_UDP_STRING         "IOET_UDP"
#define IOET_TCP_SERVER_STRING  "IOET_TCP_SERVER"
#define IOET_TCP_CLIENT_STRING  "IOET_TCP_CLIENT"
#define IOET_HTTP_SERVER_STRING "IOET_HTTP_SERVER"
#define IOET_HTTP_CLIENT_STRING "IOET_HTTP_CLIENT"
#define IOET_WS_SERVER_STRING   "IOET_WS_SERVER"
#define IOET_WS_CLIENT_STRING   "IOET_WS_CLIENT" 

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
struct io_endpoint_model_t {
    IOEndpointType type;
    int socket;
    char* name;
    char* address;
    unsigned short port;
};
class IOEndpointIMPL;
class foxintangoAPI IOEndpoint {
private:
    IOEndpointIMPL* impl;
protected:
    IOEndpointStatus endpointStatus;
public:
    IOEndpoint();
    IOEndpoint(const char* address,const unsigned short port,const IOEndpointType& type);
    IOEndpoint(const Model& model);
    virtual ~IOEndpoint();
public:
    int appendEventHandler(IOEventHandler* handler);
    int removeEventHandler(IOEventHandler* handler);
           
    int appendSessionHandler(IOSessionHandler* handler);
    int removeSessionHandler(IOSessionHandler* handler);
public:
    virtual IOEndpointStatus boot()   = 0;
    virtual IOEndpointStatus stop()   = 0;
    virtual IOEndpointStatus status();
    virtual int getSocket() const;
public:
    virtual int listen(const char* address, const unsigned short port);
    virtual int accept();
    virtual int connect();/********************/
    virtual int send(char* buffer,const unsigned int& length);
    virtual int read(char* buffer,const unsigned int& length);
    virtual unsigned int readable();
protected:
    unsigned int appendSession(IOSession* session,const char* from);
    unsigned int removeSession(IOSession* session);
    unsigned int removeSession(const char* from);
public:
    unsigned int sessionCount();
            
    IOSession* sessionAt(const unsigned int& index);
    IOSession* sessionFrom(const char* from);
};
namespaceEnd
EXTERN_C_END
#endif
