/*  The MIT License (MIT)
 *
 *  Copyright (c) 2015 LabCrypto Org.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */
 
#ifndef _ORG_LABCRYPTO_HOTTENTOT_RUNTIME_SERVICE__SERVICE_H_
#define _ORG_LABCRYPTO_HOTTENTOT_RUNTIME_SERVICE__SERVICE_H_

#include <string>

#ifdef __WIN32__
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

#include "request_handler.h"


namespace org {
namespace labcrypto {
namespace hottentot {
namespace runtime {
namespace service {
  class Service {
  public:
    Service() 
      : requestHandler_(0) {
    }
    virtual ~Service() {
      if (requestHandler_) {
        delete requestHandler_;
      }
    }
  public:
    virtual uint32_t GetServiceId() const = 0;
    virtual void OnInit() = 0;
    virtual void OnShutdown() = 0;
    virtual RequestHandler* GetRequestHandler() {
      if (requestHandler_ == 0) {
        requestHandler_ = MakeRequestHandler();
      }
      return requestHandler_;
    }
  protected:
    virtual RequestHandler* MakeRequestHandler() = 0;
  protected:
    RequestHandler *requestHandler_;
  };
}
}
}
}
}

#endif