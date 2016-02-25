// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "AdMobInterstitialPrivatePCH.h"
#include "AdInterstitialFunctionLibrary.h"
#include "AdMobInterstitial.h"
#if PLATFORM_ANDROID
#include "Runtime/Core/Public/CoreGlobals.h"
#endif

DEFINE_LOG_CATEGORY(LogAdBox);

UAdInterstitialFunctionLibrary::UAdInterstitialFunctionLibrary(FObjectInitializer const&) {}

void UAdInterstitialFunctionLibrary::ShowAdInterstitial(int32 adID)
{
#if PLATFORM_ANDROID
   extern void AndroidThunkCpp_ShowAdInterstitial(const FString&);
   
   CallAndroidThunkCpp(adID, &AndroidThunkCpp_ShowAdInterstitial);   
#endif
}

void UAdInterstitialFunctionLibrary::PreloadAdInterstitial(int32 adID)
{
#if PLATFORM_ANDROID
   extern void AndroidThunkCpp_PreloadAdInterstitial(const FString&);
      
   CallAndroidThunkCpp(adID, &AndroidThunkCpp_PreloadAdInterstitial);  
#endif
}

void UAdInterstitialFunctionLibrary::CallAndroidThunkCpp(int32 adID, void(*f)(const FString&))
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