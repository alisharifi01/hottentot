/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 02-05-2016 05:18:41
 * Name: authenticate_service_proxy_builder.h
 * Description:
 *   This file contains definition of the proxy builder class.
 ******************************************************************/

#ifndef _NAEEM_HOTTENTOT_EXAMPLES_AUTH__PROXY__AUTHENTICATE_SERVICE_PROXY_BUILDER_H_
#define _NAEEM_HOTTENTOT_EXAMPLES_AUTH__PROXY__AUTHENTICATE_SERVICE_PROXY_BUILDER_H_

#ifdef _MSC_VER
typedef __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef __int16 int16_t;
typedef unsigned __int16 uint16_t;
typedef __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;
#else
#include <stdint.h>
#endif

#include <string>


namespace naeem {
namespace hottentot {
namespace examples {
namespace auth {
namespace proxy {
class AuthenticateService;
  class AuthenticateServiceProxyBuilder {
  public:
    static AuthenticateService* Create(std::string /* host */, uint32_t /* port */);
    static void Destroy(AuthenticateService *);
  };
} // END OF NAMESPACE proxy
} // END OF NAMESPACE auth
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE naeem

#endif