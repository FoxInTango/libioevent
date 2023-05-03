# libioevent
IO Engine For C++

# On Developing ..

Application
    |
    |
 libioevent-----------------------------------------------------------------------IOFilter----------IOSwitch|IOProxy
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

  # IOFileStream -- mmap splice tee .etc


