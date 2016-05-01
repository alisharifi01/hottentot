/*  The MIT License (MIT)
 *
 *  Copyright (c) 2015 LabCrypto Org.
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

#include <iostream>
#include <fstream>

#include "cc_generator.h"
#include "type_helper.h"

#include "../ds/hot.h"
#include "../ds/service.h"
#include "../ds/method.h"
#include "../ds/module.h"
#include "../ds/argument.h"
#include "../ds/struct.h"
#include "../ds/declaration.h"

#include "../common/os.h"
#include "../common/string_helper.h"
#include "../common/datetime_helper.h"


namespace org {
namespace labcrypto {
namespace hottentot {
namespace generator {
namespace cc {
  void
  CCGenerator::GenerateProxyHeader (
    ::naeem::hottentot::generator::ds::Service *service,
    ::naeem::hottentot::generator::GenerationConfig &generationConfig,
    std::map<std::string, std::string> &templates
  ) {
    std::string indent = generationConfig.GetIndentString();
    /*
     * Making needed variables and assigning values to them
     */
    std::string serviceNameCamelCaseFirstCapital = 
    ::naeem::hottentot::generator::common::StringHelper::MakeCamelCaseFirstCapital(
      service->GetName()) + "Service";
    std::string serviceNameSnakeCase = 
      ::naeem::hottentot::generator::common::StringHelper::MakeSnakeCaseFromCamelCase(
        serviceNameCamelCaseFirstCapital);
    std::string serviceNameScreamingSnakeCase =
      ::naeem::hottentot::generator::common::StringHelper::MakeScreamingSnakeCaseFromCamelCase(serviceNameSnakeCase);
    std::string serviceProxyHeaderFilePath = generationConfig.GetOutDir() + "/proxy/" + serviceNameSnakeCase + "_proxy.h";
    std::string ns = "::" + ::naeem::hottentot::generator::common::StringHelper::Concat( 
                        ::naeem::hottentot::generator::common::StringHelper::Split(
                        service->module_->GetPackage(), '.'), "::");
    /*
     * Making real values
     */
    std::vector<std::string> packageTokens = ::naeem::hottentot::generator::common::StringHelper::Split(
      service->module_->GetPackage(), '.');
    std::string namespacesStart = "";
    for (uint32_t i = 0; i < packageTokens.size(); i++) {
      namespacesStart += "namespace " + 
        ::naeem::hottentot::generator::common::StringHelper::MakeLowerCase(packageTokens[i]) + " {\r\n";
    }
    std::string namespacesEnd = "";
    for (int32_t i = packageTokens.size() - 1; i >= 0; i--) {
      namespacesEnd += "} // END OF NAMESPACE " + packageTokens[i] + "\r\n";
    }
    std::string structClassForwardDeclarations = "";
    for (uint32_t i = 0; i < service->module_->structs_.size(); i++) {
      structClassForwardDeclarations += "class " + service->module_->structs_[i]->GetName() + ";\r\n";
    }
    namespacesStart = ::naeem::hottentot::generator::common::StringHelper::Trim(namespacesStart);
    namespacesEnd = ::naeem::hottentot::generator::common::StringHelper::Trim(namespacesEnd);
    structClassForwardDeclarations = ::naeem::hottentot::generator::common::StringHelper::Trim(structClassForwardDeclarations);
    std::string methodDefs = "";
    for (uint32_t i = 0; i < service->methods_.size(); i++) {
      ::naeem::hottentot::generator::ds::Method *method = service->methods_[i];
      methodDefs += indent + indent + "virtual void " + ::naeem::hottentot::generator::common::StringHelper::MakeFirstCapital(method->GetName()) + "(\r\n";
      for (uint32_t j = 0; j < method->arguments_.size(); j++) {
        methodDefs += indent + indent + indent + TypeHelper::GetCCType(method->arguments_[j]->GetType(), ns) + " &" + method->arguments_[j]->GetVariable();
        if (j == (method->arguments_.size() - 1)) {
          if (!TypeHelper::IsVoid(method->GetReturnType())) {
            methodDefs += ", ";
          }
        } else {
          methodDefs += ", ";
        }
        methodDefs += "\r\n";
      }
      if (!TypeHelper::IsVoid(method->GetReturnType())) {
        methodDefs += indent + indent + indent + TypeHelper::GetCCType(method->GetReturnType(), ns) + " &out\r\n";
      }
      methodDefs += indent + indent + ");\r\n";
    }
    methodDefs = ::naeem::hottentot::generator::common::StringHelper::Trim(methodDefs);
    /*
     * Filling templates with real values
     */
    std::map<std::string, std::string> params;
    params.insert(std::pair<std::string, std::string>("GENERATION_DATE", ::naeem::hottentot::generator::common::DateTimeHelper::GetCurrentDateTime()));
    params.insert(std::pair<std::string, std::string>("FILENAME", serviceNameSnakeCase + "_proxy.h"));
    params.insert(std::pair<std::string, std::string>("NAMESPACES_START", namespacesStart));
    params.insert(std::pair<std::string, std::string>("NAMESPACES_END", namespacesEnd));
    params.insert(std::pair<std::string, std::string>("STRUCT_CLASS_FORWARD_DECLARATIONS", structClassForwardDeclarations));
    params.insert(std::pair<std::string, std::string>("HEADER_GUARD", "_" +
      ::naeem::hottentot::generator::common::StringHelper::MakeScreamingSnakeCase(
        packageTokens) + "__PROXY__" + serviceNameScreamingSnakeCase + "_PROXY_H_"));
    params.insert(std::pair<std::string, std::string>("NAMESPACE","::" + 
      ::naeem::hottentot::generator::common::StringHelper::Concat( 
        ::naeem::hottentot::generator::common::StringHelper::Split(
            service->module_->GetPackage(), '.'), "::")));
    params.insert(std::pair<std::string, std::string>("CAMEL_CASE_FC_SERVICE_NAME", serviceNameCamelCaseFirstCapital));
    params.insert(std::pair<std::string, std::string>("SNAKE_CASE_SERVICE_NAME", serviceNameSnakeCase));
    params.insert(std::pair<std::string, std::string>("SCREAMING_SNAKE_CASE_SERVICE_NAME", serviceNameScreamingSnakeCase));
    params.insert(std::pair<std::string, std::string>("METHOD_DEFS", methodDefs));
    params.insert(std::pair<std::string, std::string>("INDENT", indent));
    std::string proxyHeaderTemplate = templates["proxy_header"];
    for (std::map<std::string, std::string>::iterator it = params.begin();
         it != params.end();
         ++it) {
      proxyHeaderTemplate = 
        ::naeem::hottentot::generator::common::StringHelper::Replace(proxyHeaderTemplate, 
                                                                     "[[[" + it->first + "]]]", 
                                                                     it->second);
    }
    /*
     * Writing final results to files
     */
    std::fstream f;
    f.open(serviceProxyHeaderFilePath.c_str(), std::fstream::out | std::fstream::binary);
    f << proxyHeaderTemplate;
    f.close();
  }
}
}
}
}
}