// This code was auto-generated. Do not modify it.

#include "Engine/Scripting/BinaryModule.h"
#include "SpringArmPlugin.Gen.h"

StaticallyLinkedBinaryModuleInitializer StaticallyLinkedBinaryModuleSpringArmPlugin(GetBinaryModuleSpringArmPlugin);

extern "C" BinaryModule* GetBinaryModuleSpringArmPlugin()
{
    static NativeBinaryModule module("SpringArmPlugin", MAssemblyOptions());
    return &module;
}
