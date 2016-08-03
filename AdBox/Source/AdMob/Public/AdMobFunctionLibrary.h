// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#pragma once
#include "AdMobFunctionLibrary.generated.h"

UCLASS(MinimalAPI)
class UAdMobFunctionLibrary : public UBlueprintFunctionLibrary
{
   GENERATED_UCLASS_BODY()

private:     
   static void CallAndroidThunkCpp(int32 adID, void(*)(const FString&));

public:
      UFUNCTION(BlueprintCallable, meta = (DisplayName = "Show AdMob Interstitial", CompactNodeTitle = "ShowAdMob", Keywords = "AdBox Advertisement AdMob"), Category = "__AdBox|AdMob")
      static void ShowAdInterstitial(int32 adID);

      UFUNCTION(BlueprintCallable, meta = (DisplayName = "Preload AdMob Interstitial", CompactNodeTitle = "PreloadAdMob", Keywords = "AdBox Advertisement AdMob"), Category = "__AdBox|AdMob")
      static void PreloadAdInterstitial(int32 adID);
};
