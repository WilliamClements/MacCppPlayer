/*
 * Copyright 2018 Autodesk
 */

#pragma once

// IRecorder.hpp

#include "NamespaceAliases.hpp"
#include "ArgsWriter.hpp"
#include "IAgent.hpp"

class IRecorder : public IAgent
{
public:
   IRecorder()
   {}
   virtual ~IRecorder() = 0
   {}

   template<class ITarget, typename... Args>
   void recordCppCall(std::string methodname, std::shared_ptr<const ITarget> pTrackable, Args... args)
   {
      ArgsWriter aw(cppCallStream());
      // Push the api name, then the object
      aw.pushHeader(methodname, pTrackable);
      // Push the arguments, in order
      aw.pushArgs(args...);
      aw.pushCall();
   }
};

