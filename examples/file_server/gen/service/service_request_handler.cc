/****************************************************************************
 * Generated by Hottentot CC Generator
 * Date: 12-01-2016 01:39:45
 * Name: service_request_handler.cc
 * Description:
 *   This file contains implementation of service's request handler class.
 ****************************************************************************/
 
#include <string.h>

#include <naeem/hottentot/runtime/request.h>
#include <naeem/hottentot/runtime/response.h>

#include "service_request_handler.h"
#include "abstract_service.h"
#include "../service.h"




namespace service {
  void 
  ServiceRequestHandler::HandleRequest(::naeem::hottentot::runtime::Request &request, ::naeem::hottentot::runtime::Response &response) {
    if (request.GetMethodId() == 4146670153) {
      ::::service::AbstractService *serviceObject = 
        dynamic_cast< ::::service::AbstractService*>(service_);
      /*
       * Deserialization and making input variables
       */
      ::naeem::hottentot::runtime::types::Utf8String fileName;
      fileName.Deserialize(request.GetArgumentData(0), request.GetArgumentLength(0));
      ::naeem::hottentot::runtime::types::ByteArray content;
      content.Deserialize(request.GetArgumentData(1), request.GetArgumentLength(1));
      /*
       * Calling service method
       */
      :::: result;
      serviceObject->(fileName, content, result);
      /*
       * Serializiation of returned object
       */
      uint32_t serializedDataLength = 0;
      unsigned char *serializedData = result.Serialize(&serializedDataLength);

      response.SetStatusCode(0);
      response.SetData(serializedData);
      response.SetDataLength(serializedDataLength);
      return;
    }
    char errorMessage[] = "Method not found.";
    response.SetStatusCode(1);
    response.SetData((unsigned char*)errorMessage);
    response.SetDataLength(strlen(errorMessage));
  }
} // END OF NAMESPACE service