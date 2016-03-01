// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "AdColonyPrivatePCH.h"
#include "AdColonyFunctionLibrary.h"
#include "AdColonyModule.h"
#if PLATFORM_ANDROID
#include "Runtime/Core/Public/CoreGlobals.h"
#endif

//DEFINE_LOG_CATEGORY(LogAdColony);

UAdColonyFunctionLibrary::UAdColonyFunctionLibrary(FObjectInitializer const&) {}

void UAdColonyFunctionLibrary::ShowAdColonyV4VC()
{
#if PLATFORM_ANDROID
   extern void AndroidThunkCpp_ShowAdColonyV4VC();

   AndroidThunkCpp_ShowAdColonyV4VC();   
#endif
}

void UAdColonyFunctionLibrary::ShowAdColonyInterstitialVideo()
{
#if PLATFORM_ANDROID
   extern void AndroidThunkCpp_ShowAdColonyInterstitialVideo();

   AndroidThunkCpp_ShowAdColonyInterstitialVideo();
#endif
}

int32 UAdColonyFunctionLibrary::GetRewardResultAdColonyV4VC()
{
#if PLATFORM_ANDROID
   extern int32 AndroidThunkCpp_GetRewardResultAdColonyV4VC();

   return AndroidThunkCpp_GetRewardResultAdColonyV4VC();
#else
   return -1;
#endif
}