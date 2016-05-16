// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "AdColonyPrivatePCH.h"
#include "AdColonyComponent.h"
#if PLATFORM_ANDROID
#include "AdColonyJavaWrapper.h"
#include "Runtime/Core/Public/CoreGlobals.h"
#endif

/*static*/ UAdColonyComponent* UAdColonyComponent::ActiveComponent = nullptr;

UAdColonyComponent::UAdColonyComponent(FObjectInitializer const&)
{
   ActiveComponent = this;
}

UAdColonyComponent::~UAdColonyComponent()
{
   ActiveComponent = nullptr;
}

void UAdColonyComponent::ShowAdColonyV4VC()
{
#if PLATFORM_ANDROID
   AndroidThunkCpp_ShowAdColonyV4VC();   
#endif
}

void UAdColonyComponent::ShowAdColonyInterstitialVideo()
{
#if PLATFORM_ANDROID
   AndroidThunkCpp_ShowAdColonyInterstitialVideo();
#endif
}

FString UAdColonyComponent::AdColonyStatusForZone(FString zone_id)
{
#if PLATFORM_ANDROID
   return AndroidThunkCpp_AdColonyStatusForZone(zone_id);
#else
   return "";
#endif
}
