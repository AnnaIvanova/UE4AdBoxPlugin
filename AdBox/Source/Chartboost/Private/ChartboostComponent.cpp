// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "ChartboostPrivatePCH.h"
#include "ChartboostComponent.h"
#if PLATFORM_ANDROID
#include "ChartboostJavaWrapper.h"
#include "Runtime/Core/Public/CoreGlobals.h"
#endif

/*static*/ UChartboostComponent* UChartboostComponent::ActiveComponent = nullptr;

UChartboostComponent::UChartboostComponent(FObjectInitializer const&) { ActiveComponent = this; }
UChartboostComponent::~UChartboostComponent() { ActiveComponent = nullptr; }

void UChartboostComponent::ShowChartboostInterstitial(const FString& location)
{
#if PLATFORM_ANDROID
   AndroidThunkCpp_ShowChartboostInterstitial(location);
#endif
}

bool UChartboostComponent::HasInterstitial(const FString& location)
{
#if PLATFORM_ANDROID
   return AndroidThunkCpp_HasInterstitial(location);
#else
   return false;
#endif
}

void UChartboostComponent::CacheChartboostInterstitial(const FString& location)
{
#if PLATFORM_ANDROID
   AndroidThunkCpp_CacheChartboostInterstitial(location);
#endif
}

void UChartboostComponent::ShowChartboostRewardVideo(const FString& location)
{
#if PLATFORM_ANDROID
   AndroidThunkCpp_ShowChartboostRewardVideo(location);
#endif
}

void UChartboostComponent::CacheChartboostRewardVideo(const FString& location)
{
#if PLATFORM_ANDROID
   AndroidThunkCpp_CacheChartboostRewardVideo(location);
#endif
}

bool UChartboostComponent::HasRewardedVideo(const FString& location)
{
#if PLATFORM_ANDROID
   return AndroidThunkCpp_HasRewardedVideo(location);
#else
   return false;
#endif
}