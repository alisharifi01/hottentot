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
 
#ifndef _NAEEM_HOTTENTOT_RUNTIME__UTILS_H_
#define _NAEEM_HOTTENTOT_RUNTIME__UTILS_H_

#include <iostream>
#include <iomanip>
#include <stdint.h>

#include "logger.h"


namespace naeem {
  namespace hottentot {
    namespace runtime {
      class Utils {
      public:
        static void PrintArray(std::string label,
                               unsigned char *buffer, 
                               uint32_t length) {
          Logger::GetOut() << label << ":" << std::endl;
          bool newLineInserted = false;
          for (uint32_t i = 0; i < length; i++) {
            newLineInserted = false;
            Logger::GetOut() << std::uppercase << std::hex << "0x" << 
              std::setw(2) << std::setfill ('0') << (unsigned int)buffer[i] << " ";
            if ((i + 1) % 8 == 0) {
              Logger::GetOut() << std::endl;
              newLineInserted = true;
            }
          }
          if (!newLineInserted) {
            Logger::GetOut() << std::endl;
          }
          Logger::GetOut() << std::dec;
        }
      };
    }
  }
}

#endif