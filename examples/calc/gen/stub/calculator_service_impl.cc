/******************************************************************
 * Generated by Hottentot CC Generator
 * Date: 03-12-2015 11:21:04
 * Name: calculator_service_impl.cc
 * Description:
 *   This file contains empty implementation of sample stub.
 ******************************************************************/
 
#include <naeem/hottentot/runtime/utils.h>
 #include <naeem/hottentot/runtime/logger.h>

#include "calculator_service_impl.h"




namespace ir {
namespace ntnaeem {
namespace hottentot {
namespace examples {
namespace calc {
  ::naeem::hottentot::runtime::types::UInt16
  CalculatorServiceImpl::Add(::naeem::hottentot::runtime::types::UInt16 a, ::naeem::hottentot::runtime::types::UInt16 b) {
    ::naeem::hottentot::runtime::Logger::GetOut() << "CalculatorServiceImpl::Add() is called." << std::endl;
    ::naeem::hottentot::runtime::types::UInt16 c;
    c.SetValue(a.GetValue() + b.GetValue());
    return c;
  }
} // END OF NAMESPACE calc
} // END OF NAMESPACE examples
} // END OF NAMESPACE hottentot
} // END OF NAMESPACE ntnaeem
} // END OF NAMESPACE ir