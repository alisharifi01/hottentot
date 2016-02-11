/***************************************************************
 * Generated by Hottentot CC Generator
 * Date: 11-02-2016 02:12:01
 * Name: apache_license_manager_service.h
 * Description:
 *   This file contains definition of service interface.
 ***************************************************************/

#ifndef _ORG_APACHE_TESTS__SERVICE__APACHE_LICENSE_MANAGER_SERVICE_H_
#define _ORG_APACHE_TESTS__SERVICE__APACHE_LICENSE_MANAGER_SERVICE_H_

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

#include <naeem/hottentot/runtime/types/primitives.h>
#include <naeem/hottentot/runtime/service/hot_context.h>

#include "../license.h"


namespace org {
namespace apache {
namespace tests {
namespace service {
  class ApacheLicenseManagerService {
  public:
     ApacheLicenseManagerService() {}
     virtual ~ApacheLicenseManagerService() {}
  public:
    virtual void GetThem(
      ::org::apache::tests::set<License> &out, 
      ::naeem::hottentot::runtime::service::HotContext &hotContext
    ) = 0;
    virtual void GetMap(
      ::naeem::hottentot::runtime::types::List< ::naeem::hottentot::runtime::types::Utf8String> &names, 
      ::org::apache::tests::set<map<list<int>,string>> &s, 
      ::org::apache::tests::map<list<Person>,asdasdaasdasdsda> &out, 
      ::naeem::hottentot::runtime::service::HotContext &hotContext
    ) = 0;
  };
} // END OF NAMESPACE service
} // END OF NAMESPACE tests
} // END OF NAMESPACE apache
} // END OF NAMESPACE org

#endif