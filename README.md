# libioevent
IO Engine For C++

# On Developing ..

Application
    |
    |
 libioevent-----------------------------------------------------------------------IOFilter----------IOSwitch
    |                                                                                                 |
    |                                                                                                 |
  IOEngine                                                                                          IOHandler
    |
    |
  IOProtocolRAW    IOProtocolMTP    IOProtocolHTTP    IOProtocolWS
    |
    |
  IOStreamRAW      IOStreamTLS
    |
    |
  IOEndpointUDP    IOEndpointTCP    IOEndpointUNIX    IOEndpointNETLINK


