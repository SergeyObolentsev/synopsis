#ifndef CONNECTION_H
#define CONNECTION_H

#include <string>

namespace synopsis {

class IConnection {

public:
    virtual ~IConnection() {}
    virtual void Open(const std::string & sConnectionStr) = 0;
    virtual void Close() = 0;

};

} //namespace synopsis

#endif // CONNECTION_H
