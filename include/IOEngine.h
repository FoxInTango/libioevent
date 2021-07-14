#ifndef _IO_ENGINE_H_
#define _IO_ENGINE_H_
#include "IOEndpoint.h"
#include <libcpp/libcpp.h>
EXTERN_C_BEGIN
namespace foxintango {
    class foxintangoAPI IOEngine {
        public:
            IOEngine() {}
            virtual ~IOEngine() {}
        public:
            virtual IOEndpoint* createEendpoint(const IOEndpointModel& model) = 0;
    };
}
EXTERN_C_END
#endif
