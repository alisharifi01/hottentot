/***********************************************************************
 * Generated by Hottentot CC Generator
 * Date: 04-12-2015 02:24:28
 * Name: file_service_request_handler.h
 * Description:
 *   This file contains definition of service's request handler class.
 ***********************************************************************/

#ifndef _IR_NTNAEEM_HOTTENTOT_EXAMPLES_FILE_SERVER__SERVICE__FILE_SERVICE_REQUEST_HANDLER_H_
#define _IR_NTNAEEM_HOTTENTOT_EXAMPLES_FILE_SERVER__SERVICE__FILE_SERVICE_REQUEST_HANDLER_H_

#include <stdint.h>
#include <string>

#include <naeem/hottentot/runtime/service/request_handler.h>


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace file {
namespace server {
namespace service {
  class FileServiceRequestHandler : public ::naeem::hottentot::runtime::service::RequestHandler {
  public:
    FileServiceRequestHandler(::naeem::hottentot::runtime::service::Service *service)
      : ::naeem::hottentot::runtime::service::RequestHandler(service) {
    }
    virtual ~FileServiceRequestHandler() {}
  public:
    virtual void HandleRequest(::naeem::hottentot::runtime::Request &   /* Request object */, ::naeem::hottentot::runtime::Response &  /* Response object */);
  };
} // END OF NAMESPACE service
} // END OF NAMESPACE server
} // END OF NAMESPACE file
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif