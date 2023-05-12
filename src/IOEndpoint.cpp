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

inline int platform_bind();
inline int platform_listen();
inline int platform_accept();
inline int platform_connect();
inline int platform_read();
inline int platform_write();
inline int platform_close();
namespaceBegin(foxintango)
struct io_endpoint_model_s {
    bool  initialized;
    int   socket;
    std::string name;
    std::string address;
    unsigned short port;
    IOEndpointType type;
    IOEndpointStatus status;
};
class IOEndpointIMPL {
public:
    io_endpoint_model_s model;
    std::vector<std::string> sessionList;
    std::map<std::string,IOSession*> sessionMap;
public:
    IOEndpointIMPL() {
        model.initialized = false;
    }

    ~IOEndpointIMPL() {
        std::map<std::string, IOSession*>::iterator iter = sessionMap.begin();

        while(iter != sessionMap.end()) {
            delete (*iter).second;
            sessionMap.erase(iter);
            iter ++;
        }
    }
};
namespaceEnd

IOEndpoint::IOEndpoint() {
    this->impl = new IOEndpointIMPL();
}

IOEndpoint::IOEndpoint(const Model& type) {
    this->impl = new IOEndpointIMPL();
}

IOEndpoint::IOEndpoint(const char* address, const unsigned short port, const IOEndpointType& type) {
    this->impl = new IOEndpointIMPL();
}

IOEndpoint::~IOEndpoint() {
    if(this->impl) {
        close();
        delete this->impl;
    }
}

IOEndpointStatus IOEndpoint::listen() {
    if(this->impl && this->impl->model.address.length()){
        // TODO 清理
        struct sockaddr_in listen_addr;
        memset(&listen_addr, 0, sizeof(sockaddr_in));
        if(!this->impl->model.socket) {
            
            listen_addr.sin_port = htons(this->impl->model.port);
            listen_addr.sin_addr.s_addr = inet_addr(this->impl->model.address.c_str());
            switch (this->impl->model.type){
            case IOET_LISTEN_UDP:{
                listen_addr.sin_family = AF_INET;
                this->impl->model.socket = socket(AF_INET, SOCK_DGRAM, 0);
            }break;
            case IOET_LISTEN_TCP:{
                listen_addr.sin_family = AF_INET;
                this->impl->model.socket = socket(AF_INET, SOCK_STREAM, 0);
            }break;
            case IOET_LISTEN_UNIX:{}break;
            case IOET_LISTEN_NETLINK: {}break;
            case IOET_CONNECT_UDP: {
                listen_addr.sin_family = AF_INET;
                this->impl->model.socket = socket(AF_INET, SOCK_DGRAM, 0);
            }break;
            case IOET_CONNECT_TCP: {
                listen_addr.sin_family = AF_INET;
                this->impl->model.socket = socket(AF_INET, SOCK_STREAM, 0);
            }break;
            case IOET_CONNECT_UNIX: {}break;
            case IOET_CONNECT_NETLINK: {}break;
            default:break;
            }
        }
        
        //bind(this->impl->model.socket, (struct sockaddr*)&listen_addr, sizeof(listen_addr));
        //listen(this->impl->model.socket, 0);
    }
    return IOEndpointStatus::IOES_OP_FAILED;
}
IOEndpointStatus IOEndpoint::listen(const char* address, const unsigned short port){
    if (this->impl) {
        // TODO 清理
        this->impl->model.address = address;
        struct sockaddr_in listen_addr;
        memset(&listen_addr, 0, sizeof(sockaddr_in));
        if (!this->impl->model.socket) {

            listen_addr.sin_port = htons(this->impl->model.port);
            listen_addr.sin_addr.s_addr = inet_addr(this->impl->model.address.c_str());
            switch (this->impl->model.type) {
            case IOET_LISTEN_UDP: {
                listen_addr.sin_family = AF_INET;
                this->impl->model.socket = socket(AF_INET, SOCK_DGRAM, 0);
            }break;
            case IOET_LISTEN_TCP: {
                listen_addr.sin_family = AF_INET;
                this->impl->model.socket = socket(AF_INET, SOCK_STREAM, 0);
            }break;
            case IOET_LISTEN_UNIX: {}break;
            case IOET_LISTEN_NETLINK: {}break;
            case IOET_CONNECT_UDP: {
                listen_addr.sin_family = AF_INET;
                this->impl->model.socket = socket(AF_INET, SOCK_DGRAM, 0);
            }break;
            case IOET_CONNECT_TCP: {
                listen_addr.sin_family = AF_INET;
                this->impl->model.socket = socket(AF_INET, SOCK_STREAM, 0);
            }break;
            case IOET_CONNECT_UNIX: {}break;
            case IOET_CONNECT_NETLINK: {}break;
            default:break;
            }
        }

        //bind(this->impl->model.socket, (struct sockaddr*)&listen_addr, sizeof(listen_addr));
        //listen(this->impl->model.socket, 0);
    }
    return IOEndpointStatus::IOES_OP_FAILED;
    return IOEndpointStatus::IOES_OP_FAILED;
}
IOEndpointStatus IOEndpoint::accept(){
    //accept(listen_sock, &remote_address, &remote_count)
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
    if (this->impl) {
        //close(this->impl->model.socket);
        delete this->impl;
    }
    return IOEndpointStatus::IOES_OP_OK;
}