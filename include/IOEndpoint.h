#ifndef _IO_ENDPOINT_H_
#define _IO_ENDPOINT_H_

#include "IOHandler.h"
#include <libcpp/libcpp.h>

EXTERN_C_BEGIN
namespace foxintango {
    typedef enum _IOEndpointType 
    {
        IOET_UDP_ENDPOINT,
        IOET_TCP_SERVER,
        IOET_TCP_CLIENT,
        IOET_HTTP_SERVEER,
        IOET_HTTP_CLIENT,
        IOET_WS_SERVER,
        IOET_WS_CLIENT
    }IOEndpointType;

    typedef enum _IOEndpointStatus {} IOEndpointStatus;
    typedef struct _IOEndpointModel {} IOEndpointModel;
    class IOEndpointIMPL;
    class foxintangoAPI IOEndpoint {
        private:
            IOEndpointIMPL* impl;
        public:
            IOEndpoint(const IOEndpointModel& model);
           ~IOEndpoint();
        public:
           int appendEventHandler(IOEventHandler* handler);
           int remoteEventHandler(IOEventHandler* handler);
           
           int appendSessionHandler(IOSessionHandler* handler);
           int removeSessionHandler(IOSessionHandler* handler);
        public:
           IOEndpointStatus boot();
           IOEndpointStatus status();
        public:
            int sessionCount();
            
            IOSession* sessionAt(const unsigned int& index);
            IOSession* sessionFrom(const char* ip);
    };
}

EXTERN_C_END
#endif
