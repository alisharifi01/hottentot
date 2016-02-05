/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 05-02-2016 09:34:46
 * Name: authenticate_service_client.h
 * Description:
 *   This file contains a sample client.
 ******************************************************************/

#include <iostream>

#include <naeem/hottentot/runtime/configuration.h>
#include <naeem/hottentot/runtime/logger.h>
#include <naeem/hottentot/runtime/proxy/proxy_runtime.h>

#include "../credential.h"
#include "../user.h"
#include "../token.h"
#include "../authenticate_service.h"
#include "../proxy/authenticate_service_proxy_builder.h"


int 
main(int argc, char **argv) {
  try {
    ::naeem::hottentot::runtime::Logger::Init();  
    ::naeem::hottentot::runtime::proxy::ProxyRuntime::Init(argc, argv);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Proxy runtime is initialized." << std::endl;
    }
    ::naeem::hottentot::examples::auth::AuthenticateService *proxy = 
      ::naeem::hottentot::examples::auth::proxy::AuthenticateServiceProxyBuilder::Create("127.0.0.1", 2000);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Proxy object is created." << std::endl;
    }
    try {
      // ====================================================
      ::naeem::hottentot::examples::auth::Credential credential;
      credential.SetUsername("Admin");
      credential.SetPassword("12345");
      ::naeem::hottentot::examples::auth::Token token;
      proxy->Authenticate(credential, token);
      std::cout << token.GetValue() << std::endl;
      // ====================================================
    } catch (std::runtime_error &e) {
      ::naeem::hottentot::runtime::Logger::GetError() << e.what() << std::endl;
    }
    ::naeem::hottentot::examples::auth::proxy::AuthenticateServiceProxyBuilder::Destroy(proxy);
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Proxy object is destroyed." << std::endl;
    }
    ::naeem::hottentot::runtime::proxy::ProxyRuntime::Shutdown();
    if (::naeem::hottentot::runtime::Configuration::Verbose()) {
      ::naeem::hottentot::runtime::Logger::GetOut() << "Proxy runtime is shutdown." << std::endl;
    }
    ::naeem::hottentot::runtime::Logger::Shutdown();  
  } catch (...) {
    ::naeem::hottentot::runtime::Logger::GetError() << "Error." << std::endl;
    return 1;
  }
  return 0;
}
