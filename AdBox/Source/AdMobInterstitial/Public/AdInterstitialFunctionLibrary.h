// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#pragma once
#include "AdInterstitialFunctionLibrary.generated.h"

UCLASS(MinimalAPI)
class UAdInterstitialFunctionLibrary : public UBlueprintFunctionLibrary
{
   GENERATED_UCLASS_BODY()

private:     
   static void CallAndroidThunkCpp(int32 adID, void(*)(const FString&));

public:
      UFUNCTION(BlueprintCallable, Category = "Utilitites|Platform")
      static void ShowAdInterstitial(int32 adID);

      UFUNCTION(BlueprintCallable, Category = "Utilitites|Platform")
      static void PreloadAdInterstitial(int32 adID);
};