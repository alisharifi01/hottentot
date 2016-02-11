/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 11-02-2016 02:12:01
 * Name: license.h
 * Description:
 *   This file contains definition of License class.
 ***************************************************************/

#ifndef _ORG_APACHE_TESTS__LICENSE_H_
#define _ORG_APACHE_TESTS__LICENSE_H_

#include <string>

#include <naeem/hottentot/runtime/types/primitives.h>
#include <naeem/hottentot/runtime/serializable.h>

#include "enums.h"


namespace org {
namespace apache {
namespace tests {
  class License : public ::naeem::hottentot::runtime::Serializable {
  public:
    License() {}
    License(const License &);
    License(License *);
    virtual ~License() {}
  public:
    inline ::org::apache::tests::int* GetVersion() const {
      return version_;
    }
    inline void SetVersion(::org::apache::tests::int* version) {
      version_ = version;
    }
    inline ::org::apache::tests::map<int,list<string>>* GetL() const {
      return l_;
    }
    inline void SetL(::org::apache::tests::map<int,list<string>>* l) {
      l_ = l;
    }
  public:
    virtual unsigned char * Serialize(uint32_t * /* Pointer to length */);
    virtual void Deserialize(unsigned char * /* Data */, uint32_t /* Data length */);
  private:
    ::org::apache::tests::int* version_;
    ::org::apache::tests::map<int,list<string>>* l_;
  };
} // END OF NAMESPACE tests
} // END OF NAMESPACE apache
} // END OF NAMESPACE org

#endif