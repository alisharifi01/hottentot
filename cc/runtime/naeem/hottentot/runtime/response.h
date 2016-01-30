/*  The MIT License (MIT)
 *
 *  Copyright (c) 2015 Noavaran Tejarat Gostar NAEEM Co.
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
 
#ifndef _NAEEM_HOTTENTOT_RUNTIME__RESPONSE_H_
#define _NAEEM_HOTTENTOT_RUNTIME__RESPONSE_H_

#include <stdint.h>
#include <vector>


namespace naeem {
  namespace hottentot {
    namespace runtime {
      class Response {
      public:
        Response() {}
        virtual ~Response() {
          delete [] data_;
        }
      public:
        inline uint8_t GetStatusCode() const {
          return statusCode_;
        }
        inline void SetStatusCode(uint8_t statusCode) {
          statusCode_ = statusCode;
        }
        inline unsigned char* GetData() const {
          return data_;
        }
        inline void SetData(unsigned char *data) {
          data_ = data;
        }
        inline uint32_t GetDataLength() const {
          return dataLength_;
        }
        inline void SetDataLength(uint32_t dataLength) {
          dataLength_ = dataLength;
        }
      private:
        /*
         * Success = 0
         * Fault > 0
         */
        uint8_t statusCode_;
        unsigned char *data_;
        uint32_t dataLength_;
      };
    }
  }
}

#endif