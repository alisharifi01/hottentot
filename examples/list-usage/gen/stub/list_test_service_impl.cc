/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 06-02-2016 02:44:05
 * Name: list_test_service_impl.cc
 * Description:
 *   This file contains empty implementation of sample stub.
 ******************************************************************/
 
#include <naeem/hottentot/runtime/configuration.h>
#include <naeem/hottentot/runtime/logger.h>
#include <naeem/hottentot/runtime/utils.h>

#include "list_test_service_impl.h"

#include "../message.h"


namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace listtest {
  void
  ListTestServiceImpl::OnInit() {
    // TODO: Called when service is initializing.
  }
  void
  ListTestServiceImpl::OnShutdown() {
    // TODO: Called when service is shutting down.
  }
  void
  ListTestServiceImpl::AddNames(
      ::naeem::hottentot::runtime::types::List< ::naeem::hottentot::runtime::types::Utf8String> &names, 
      ::naeem::hottentot::runtime::service::HotContext &hotContext
  ) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "ListTestServiceImpl::AddNames() is called." << std::endl;
    }
    for (uint32_t i = 0; i < names.Size(); i++) {
      std::cout << "NAME: " << *(names.Get(i)) << std::endl;
    }
  }
  void
  ListTestServiceImpl::GetNames(
      ::naeem::hottentot::runtime::types::List< ::naeem::hottentot::runtime::types::Utf8String> &out, 
      ::naeem::hottentot::runtime::service::HotContext &hotContext
  ) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "ListTestServiceImpl::GetNames() is called." << std::endl;
    }
    ::naeem::hottentot::runtime::types::Utf8String *name1 = 
      new ::naeem::hottentot::runtime::types::Utf8String("Kamran");
    ::naeem::hottentot::runtime::types::Utf8String *name2 =
      new ::naeem::hottentot::runtime::types::Utf8String("Ali");
    ::naeem::hottentot::runtime::types::Utf8String *name3 =
      new ::naeem::hottentot::runtime::types::Utf8String("Ashkan");
    out.Add(name1);
    out.Add(name2);
    out.Add(name3);
    out.Add(name1);
    out.Add(name2);
    out.Add(name3);
  }
  void
  ListTestServiceImpl::GetMessages(
      ::naeem::hottentot::runtime::types::List< ::ir::ntnaeem::hottentot::examples::listtest::Message> &out, 
      ::naeem::hottentot::runtime::service::HotContext &hotContext
  ) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "ListTestServiceImpl::GetMessages() is called." << std::endl;
    }
    // TODO
  }
  void
  ListTestServiceImpl::AddMessage(
      ::ir::ntnaeem::hottentot::examples::listtest::Message &message, 
      ::naeem::hottentot::runtime::service::HotContext &hotContext
  ) {
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "ListTestServiceImpl::AddMessage() is called." << std::endl;
    }
    // TODO
  }
} // END OF NAMESPACE listtest
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir