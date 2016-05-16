// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "AdMobPrivatePCH.h"

#if PLATFORM_ANDROID
#include "AdMobJavaWrapper.h"
#endif

class FAdMob : public IAdMobModule
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FAdMob, AdMob )

void FAdMob::StartupModule()
{
#if PLATFORM_ANDROID
   InitAdMobJavaMethods();
#endif
}

void FAdMob::ShutdownModule()
{	
}