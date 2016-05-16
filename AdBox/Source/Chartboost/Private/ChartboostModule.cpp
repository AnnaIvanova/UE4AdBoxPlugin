// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "ChartboostPrivatePCH.h"

#if PLATFORM_ANDROID
#include "ChartboostJavaWrapper.h"
#endif

//#include "Misc/AssertionMacros.h"

DEFINE_LOG_CATEGORY(LogChartboost);

class FChartboostModule : public IChartboostModule
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FChartboostModule, Chartboost )

void FChartboostModule::StartupModule()
{
#if PLATFORM_ANDROID
   InitChartboostJavaMethods();
#endif
}

void FChartboostModule::ShutdownModule()
{	
}
