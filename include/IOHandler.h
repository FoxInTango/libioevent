#ifndef _IO_HANDLER_H_
#define _IO_HANDLER_H_
#include <libcpp/libcpp.h>

EXTERN_C_BEGIN
namespace foxintango {
class IOEvent;
class IOSession;
class foxintangoAPI IOEventHandler {
public:
    IOEventHandler(){}
    virtual ~IOEventHandler(){};
public:
    virtual int handleEvent(const IOEvent* event) = 0;
};
    
class foxintangoAPI IOSessionHandler {
public:
    IOSessionHandler();
    virtual ~IOSessionHandler() {};
public:
    virtual int handleSession(const IOSession* session) = 0;
};

}
EXTERN_C_END
#endif
