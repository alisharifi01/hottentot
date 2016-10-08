/***********************************************************************
 * Generated by Hottentot CC Generator
 * Date: 08-10-2016 01:21:15
 * Name: echo_service.h
 * Description:
 *   This file contains definition of the interface used by proxies.
 ***********************************************************************/

#ifndef _IR_NTNAEEM_HOTTENTOT_EXAMPLES_ECHOER__PROXY__ECHO_SERVICE_H_
#define _IR_NTNAEEM_HOTTENTOT_EXAMPLES_ECHOER__PROXY__ECHO_SERVICE_H_

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

#include <org/labcrypto/hottentot/primitives.h>

#include "../request_message.h"
#include "../response_message.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace echoer {
namespace proxy {
  class EchoService {
  public:
     EchoService() {}
     virtual ~EchoService() {}
  public:
    virtual void EchoMessage(
      ::ir::ntnaeem::hottentot::examples::echoer::RequestMessage &req, 
      ::ir::ntnaeem::hottentot::examples::echoer::ResponseMessage &out
    ) = 0;
  };
} // END OF NAMESPACE proxy
} // END OF NAMESPACE echoer
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif