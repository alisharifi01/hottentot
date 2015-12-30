/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 31-12-2015 12:52:35
 * Name: file_service_client.h
 * Description:
 *   This file contains a sample client.
 ******************************************************************/

#include <iostream>

#include <naeem/hottentot/runtime/logger.h>
#include <naeem/hottentot/runtime/proxy/proxy_runtime.h>


#include "../file_service.h"
#include "../proxy/file_service_proxy_builder.h"


int 
main(int argc, char **argv) {
  try {
    ::naeem::hottentot::runtime::Logger::Init();
    std::cout << "Logger is initialized." << std::endl;
    ::naeem::hottentot::runtime::proxy::ProxyRuntime::Init(argc, argv);
    std::cout << "Proxy runtime is initialized." << std::endl;
    ::ir::ntnaeem::hottentot::examples::file::server::FileService *proxy = 
        ::ir::ntnaeem::hottentot::examples::file::server::proxy::FileServiceProxyBuilder::Create("127.0.0.1", 2000);
    std::cout << "Proxy object is created." << std::endl;
    unsigned char data[100];
    for (unsigned int i = 0; i < 100; i++) {
        data[i] = 65 + i % 26;
    }
    ::naeem::hottentot::runtime::types::Utf8String str("1.txt");
    ::naeem::hottentot::runtime::types::ByteArray byteArray(data, 100);
    proxy->UploadFile(&str, &byteArray);
    ::naeem::hottentot::runtime::types::Boolean* result = proxy->FileExists(&str);
    std::cout << "Result is " << result->GetValue() << std::endl;
    ::naeem::hottentot::runtime::types::ByteArray *result2 = proxy->DownloadFile(&str);
    std::cout << "Result2 length is " << result2->GetLength() << std::endl;
    for (unsigned int i = 0; i < result2->GetLength(); i++) {
      std::cout << "Result2[" << i << "]: " << result2->GetValue()[i] << std::endl;
    }
    ::ir::ntnaeem::hottentot::examples::file::server::proxy::FileServiceProxyBuilder::Destroy(proxy);
    std::cout << "Proxy object is destroyed." << std::endl;
    delete result;
    delete result2;
  } catch (...) {
    std::cout << "Error." << std::endl;
    return 1;
  }
  return 0;
}
