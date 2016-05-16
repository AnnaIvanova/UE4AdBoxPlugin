// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "AdMobPrivatePCH.h"
#include "AdMobFunctionLibrary.h"
#include "AdMobJavaWrapper.h"
#if PLATFORM_ANDROID
#include "Runtime/Core/Public/CoreGlobals.h"
#endif

DEFINE_LOG_CATEGORY(LogAdBox);

UAdMobFunctionLibrary::UAdMobFunctionLibrary(FObjectInitializer const&) {}

void UAdMobFunctionLibrary::ShowAdInterstitial(int32 adID)
{
#if PLATFORM_ANDROID
   CallAndroidThunkCpp(adID, &AndroidThunkCpp_ShowAdInterstitial);   
#endif
}

void UAdMobFunctionLibrary::PreloadAdInterstitial(int32 adID)
{
#if PLATFORM_ANDROID
   CallAndroidThunkCpp(adID, &AndroidThunkCpp_PreloadAdInterstitial);  
#endif
}

void UAdMobFunctionLibrary::CallAndroidThunkCpp(int32 adID, void(*f)(const FString&))
{
#if PLATFORM_ANDROID
   
   TArray<FString> AdUnitIDs;
   int32 count = GConfig->GetArray(TEXT("/Script/AndroidRuntimeSettings.AndroidRuntimeSettings"), TEXT("AdMobAdUnitIDs"), AdUnitIDs, GEngineIni);

   if (count == 0)
   {
      // Fall back to checking old setting
      FString AdUnitID;
      bool found = GConfig->GetString(TEXT("/Script/AndroidRuntimeSettings.AndroidRuntimeSettings"), TEXT("AdMobAdUnitID"), AdUnitID, GEngineIni);
      if (found && !AdUnitID.IsEmpty())
      {
         f(AdUnitID);
      }

      return;
   }

   if (adID >= 0 && adID < count && !AdUnitIDs[adID].IsEmpty())
   {
      f(AdUnitIDs[adID]);
   }
#endif
}