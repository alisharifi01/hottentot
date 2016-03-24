/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 24-03-2016 11:14:24
 * Name: hello_service_impl.h
 * Description:
 *   This file contains definitions of sample stub.
 ******************************************************************/
 
#ifndef _IR_NTNAEEM_HOTTENTOT_EXAMPLES_TIMEOUT_ON_READ__HELLO_SERVICE_IMPL_H_
#define _IR_NTNAEEM_HOTTENTOT_EXAMPLES_TIMEOUT_ON_READ__HELLO_SERVICE_IMPL_H_

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

#include "../service/abstract_hello_service.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace timeout_on_read {
  class HelloServiceImpl : public ::ir::ntnaeem::hottentot::examples::timeout_on_read::service::AbstractHelloService {
  public:
    HelloServiceImpl() {}
    virtual ~HelloServiceImpl() {}
  public:
    virtual void OnInit();
    virtual void OnShutdown();
    virtual void SayHelloTo(
      ::naeem::hottentot::runtime::types::Utf8String &name, 
      ::naeem::hottentot::runtime::types::Utf8String &out, 
      ::naeem::hottentot::runtime::service::HotContext &hotContext
    );
  };
} // END OF NAMESPACE timeout_on_read
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir

#endif