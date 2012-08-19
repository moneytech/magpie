#include "Object.h"
#include "Natives.h"
#include "VM.h"

namespace magpie
{
  NATIVE(print)
  {
    std::cout << args[0] << std::endl;
    return args[0];
  }

  NATIVE(numPlusNum)
  {
    double c = args[0]->toNumber() + args[1]->toNumber();
    return new NumberObject(c);
  }
  
  NATIVE(stringPlusString)
  {
    return new StringObject(
        String::concat(args[0]->toString(), args[1]->toString()));
  }
  
  NATIVE(numMinusNum)
  {
    double c = args[0]->toNumber() - args[1]->toNumber();
    return new NumberObject(c);
  }
  
  NATIVE(numTimesNum)
  {
    double c = args[0]->toNumber() * args[1]->toNumber();
    return new NumberObject(c);
  }
  
  NATIVE(numDivNum)
  {
    double c = args[0]->toNumber() / args[1]->toNumber();
    return new NumberObject(c);
  }
  
  NATIVE(numLessThanNum)
  {
    return vm.getBool(args[0]->toNumber() < args[1]->toNumber());
  }
  
  NATIVE(numLessThanEqualToNum)
  {
    return vm.getBool(args[0]->toNumber() <= args[1]->toNumber());
  }
  
  NATIVE(numGreaterThanNum)
  {
    return vm.getBool(args[0]->toNumber() > args[1]->toNumber());
  }
  
  NATIVE(numGreaterThanEqualToNum)
  {
    return vm.getBool(args[0]->toNumber() >= args[1]->toNumber());
  }
  
  NATIVE(stringCount)
  {
    double c = args[0]->toString()->length();
    return new NumberObject(c);
  }
  
  NATIVE(numToString)
  {
    double n = args[0]->toNumber();
    return new StringObject(String::format("%g", n));
  }
}
