/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 30-01-2016 08:21:47
 * Name: token.h
 * Description:
 *   This file contains definition of Token class.
 ***************************************************************/

#ifndef _HOTGEN__TOKEN_H_
#define _HOTGEN__TOKEN_H_

#include <string>

#include <naeem/hottentot/runtime/types/primitives.h>
#include <naeem/hottentot/runtime/serializable.h>


namespace hotgen {
  class Token : public ::naeem::hottentot::runtime::Serializable {
  public:
    Token() {}
    ~Token() {}
  public:
    inline ::naeem::hottentot::runtime::types::Utf8String GetValue() const {
      return value_;
    }
    inline void SetValue(::naeem::hottentot::runtime::types::Utf8String value) {
      value_ = value;
    }
    inline ::naeem::hottentot::runtime::types::UInt8 GetId() const {
      return id_;
    }
    inline void SetId(::naeem::hottentot::runtime::types::UInt8 id) {
      id_ = id;
    }
  public:
    virtual unsigned char * Serialize(uint32_t * /* Pointer to length */);
    virtual void Deserialize(unsigned char * /* Data */, uint32_t /* Data length */);
  private:
    ::naeem::hottentot::runtime::types::Utf8String value_;
    ::naeem::hottentot::runtime::types::UInt8 id_;
  };
} // END OF NAMESPACE hotgen

#endif