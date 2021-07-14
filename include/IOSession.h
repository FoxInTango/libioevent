#ifndef _IO_SESSION_H_
#define _IO_SESSION_H_

#include <libcpp/libcpp.h>

EXTERN_C_BEGIN
namespace foxintango {
    class IOEndpoint;
    typedef enum _IOEndpointStatus {} IOEndpointStatus;
    class foxintangoAPI IOSession {
        private:
            IOEndpoint* endpoint;
        public:
            IOSession();
           ~IOSession();
        public:
           int send(unsigned char* buffer,const unsigned int& length);
    };
}

EXTERN_C_END

#endif
