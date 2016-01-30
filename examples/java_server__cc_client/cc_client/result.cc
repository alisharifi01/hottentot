/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 30-01-2016 08:21:47
 * Name: result.cc
 * Description:
 *   This file contains implementation of Result class.
 ******************************************************************/

#include <iostream>
#include <string.h>

#include "result.h"


namespace hotgen {
  unsigned char *
  Result::Serialize(uint32_t *length_ptr) {
    uint32_t totalLength = 0;
    uint32_t length0 = 0;
    unsigned char *data0 = statusCode_.Serialize(&length0);
    totalLength += length0;
    unsigned char *data = new unsigned char[totalLength];
    uint32_t c = 0;
    for (uint32_t i = 0; i < length0; i++) {
      data[c++] = data0[i];
    }
    if (c != totalLength) {
      std::cout << "Struct Serialization: Inconsistency in length of serialized byte array." << std::endl;
      exit(1);
    };
    if (length_ptr) {
      *length_ptr = totalLength;
    }
    return data;
  }
  void
  Result::Deserialize(unsigned char *data, uint32_t length) {
    uint32_t c = 0, elength = 0;
    statusCode_.Deserialize(data + c, 1);
    c += 1;
    if (c != length) {
      std::cout << "Struct Deserialization: Inconsistency in length of deserialized byte array." << std::endl;
      exit(1);
    };
  }
} // END OF NAMESPACE hotgen