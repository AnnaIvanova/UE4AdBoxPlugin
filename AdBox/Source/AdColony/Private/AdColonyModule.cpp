// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "AdColonyPrivatePCH.h"

#if PLATFORM_ANDROID
#include "AdColonyJavaWrapper.h"
#endif

DEFINE_LOG_CATEGORY(LogAdColony);

class FAdColonyModule : public IAdColonyModule
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FAdColonyModule, AdColony )

void FAdColonyModule::StartupModule()
{
#if PLATFORM_ANDROID
   InitAdColonyJavaMethods();
#endif
}

void FAdColonyModule::ShutdownModule()
{	
}
