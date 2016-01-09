/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 10-01-2016 01:48:55
 * Name: file_service_proxy_builder.h
 * Description:
 *   This file contains definition of the proxy builder class.
 ******************************************************************/

#ifndef _IR_NTNAEEM_HOTTENTOT_EXAMPLES_FILE_SERVER__PROXY__FILE_SERVICE_PROXY_BUILDER_H_
#define _IR_NTNAEEM_HOTTENTOT_EXAMPLES_FILE_SERVER__PROXY__FILE_SERVICE_PROXY_BUILDER_H_

#include <stdint.h>
#include <string>


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace file {
namespace server {
class FileService;
namespace proxy {
  class FileServiceProxyBuilder {
  public:
    static FileService* Create(std::string /* host */, uint32_t /* port */);
    static void Destroy(FileService *);
  };
} // END OF NAMESPACE proxy
} // END OF NAMESPACE server
} // END OF NAMESPACE file
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif