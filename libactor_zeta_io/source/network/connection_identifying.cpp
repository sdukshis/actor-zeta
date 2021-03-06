#include "actor-zeta/network/connection_identifying.hpp"

namespace actor_zeta {
    namespace network {

        connection_identifying::connection_identifying(const type_connect &tc, const std::string &ip_, const int &port_)
                :type_connect_ (tc),ip_(ip_),port_(port_){}

        std::string connection_identifying::to_string() const {
            std::string qq;
            qq.append(std::to_string(type_connect_)).append("://").append(ip_).append(":").append(std::to_string(port_));
            return qq;
        }

        const std::string &connection_identifying::ip() const {
            return ip_;
        }

        const int &connection_identifying::port() const {
            return port_;
        }

        bool connection_identifying::operator==(const connection_identifying &ci) const {
            return (type_connect_ == ci.type_connect_ && ip_ == ci.ip_ && port_ == ci.port_);
        }
    }
}

namespace std {
    std::string to_string(actor_zeta::network::type_connect tc) {
        switch (tc) {
            case actor_zeta::network::type_connect::tcp: {
                return std::string("tcp");
            }

            case actor_zeta::network::type_connect::udp: {
                return std::string("udp");
            }
        }
    }

    std::string to_string(actor_zeta::network::connection_identifying ci) {
        return ci.to_string();
    }
}
