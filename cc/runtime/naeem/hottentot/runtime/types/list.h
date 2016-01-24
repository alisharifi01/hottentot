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
 
#ifndef _NAEEM_HOTTENTOT_RUNTIME__TYPES__LIST_H_
#define _NAEEM_HOTTENTOT_RUNTIME__TYPES__LIST_H_

#include <iostream>
#include <stdexcept>
#include <vector>

#include <stdint.h>

#include "../serializable.h"


namespace naeem {
  namespace hottentot {
    namespace runtime {
      namespace types {
        template<class T>
        class List : public ::naeem::hottentot::runtime::Serializable {
        public:
          List(){
          }
          virtual ~List() {}
        public:
          inline void Add(T *e) {
            elements_.push_back(e);
          }
          inline T* Get(uint32_t i) {
            return elements_[i];
          }
          inline uint32_t Size() {
            return elements_.size();
          }
          inline void Purge() {
            for (uint32_t i = 0; i < elements_.size(); i++) {
              delete elements_[i];
            }
          }
        public:
          inline virtual unsigned char * Serialize(uint32_t *length_ptr) {
            std::vector<uint32_t> lengths;
            std::vector<unsigned char *> datas;
            for (uint32_t i = 0; i < elements_.size(); i++) {
              uint32_t eLength = 0;
              unsigned char *eData = elements_[i]->Serialize(&eLength);
              lengths.push_back(eLength);
              datas.push_back(eData);
            }
            uint32_t length = 0;
            for (uint32_t i = 0; i < lengths.size(); i++) {
              if (lengths[i] <= (128 - 1)) {
                length += 1 + lengths[i];
              } else if (lengths[i] <= (256 * 256 - 1)) {
                length += 3 + lengths[i];
              } else if (lengths[i] <= (256 * 256 * 256 - 1)) {
                length += 4 + lengths[i];
              } /* else if (lengths[i] <= (256 * 256 * 256 * 256 - 1)) {
                length += 5 + lengths[i];
              } */
            }
            uint32_t c = 0;
            unsigned char *data = new unsigned char[length];
            *length_ptr = length;
            for (uint32_t i = 0; i < lengths.size(); i++) {
              if (lengths[i] <= (128 - 1)) {
                data[c] = lengths[i];
                c += 1;
              } else if (lengths[i] <= (256 * 256 - 1)) {
                data[c] = 0x82;
                data[c + 1] = lengths[i] / 256;
                data[c + 2] = lengths[i] % 256;
                c += 3;
              } else if (lengths[i] <= (256 * 256 * 256 - 1)) {
                data[c] = 0x83;
                data[c + 1] = lengths[i] / (256 * 256);
                data[c + 2] = (lengths[i] - data[c + 1] * (256 * 256)) / 256;
                data[c + 3] = lengths[i] % (256 * 256);
                c += 4;
              } /* else if (lengths[i] <= (256 * 256 * 256 * 256 - 1)) {
                data[c] = 0x84;
                data[c + 1] = lengths[i] / (256 * 256 * 256);
                data[c + 2] = (lengths[i] - data[c + 1] * (256 * 256 * 256)) / (256 * 256);
                data[c + 3] = (lengths[i] - data[c + 1] * (256 * 256 * 256) - data[c + 2] * (256 * 256)) / 256;
                data[c + 4] = lengths[i] % (256 * 256 * 256);
                c += 5;
              } */
              for (uint32_t j = 0; j < lengths[i]; j++) {
                data[c++] = datas[i][j];
              }
            }
            if (c != length) {
              std::cout << "List serialization: Inconsistency in serialized array length." << std::endl;
              exit(1);
            }
            return data;
          }
          inline virtual void Deserialize(unsigned char *data,
                                          uint32_t length) {
            uint32_t i = 0;
            while (true) {
              uint32_t elength = 0;
              if ((data[i] & 0x80) == 0) {
                elength = data[i];
                i++;
              } else {
                uint32_t count = data[i] & 0x0f;
                if (count == 2) {
                  elength = data[i + 1] * 256 + data[i + 2];
                  i += 2;
                } else if (count == 3) {
                  elength = data[i + 1] * 256 * 256 + data[i + 2] * 256 + data[i + 3];
                  i += 3;
                }
              }
              T *e = new T;
              e->Deserialize(data + i, elength);
              Add(e);
              i += elength;
              if (i >= length) {
                break;
              }
            }
          }
        private:
          std::vector<T*> elements_;
        };
      }
    }
  }
}

#endif