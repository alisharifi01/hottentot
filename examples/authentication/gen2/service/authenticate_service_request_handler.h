/***********************************************************************
 * Generated by Hottentot CC Generator
 * Date: 06-02-2016 03:48:37
 * Name: authenticate_service_request_handler.h
 * Description:
 *   This file contains definition of service's request handler class.
 ***********************************************************************/

#ifndef _NAEEM_HOTTENTOT_EXAMPLES_AUTH__SERVICE__AUTHENTICATE_SERVICE_REQUEST_HANDLER_H_
#define _NAEEM_HOTTENTOT_EXAMPLES_AUTH__SERVICE__AUTHENTICATE_SERVICE_REQUEST_HANDLER_H_

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

#include <naeem/hottentot/runtime/service/request_handler.h>


namespace naeem {
namespace hottentot {
namespace examples {
namespace auth {
namespace service {
  class AuthenticateServiceRequestHandler : public ::naeem::hottentot::runtime::service::RequestHandler {
  public:
    AuthenticateServiceRequestHandler(::naeem::hottentot::runtime::service::Service *service)
      : ::naeem::hottentot::runtime::service::RequestHandler(service) {
    }
    virtual ~AuthenticateServiceRequestHandler() {}
  public:
    virtual void HandleRequest(::naeem::hottentot::runtime::Request &request,
                                                   ::naeem::hottentot::runtime::Response &response);
  };
} // END OF NAMESPACE service
} // END OF NAMESPACE auth
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE naeem

#endif