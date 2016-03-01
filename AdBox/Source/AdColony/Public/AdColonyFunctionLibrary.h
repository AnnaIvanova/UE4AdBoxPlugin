// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#pragma once
#include "AdColonyFunctionLibrary.generated.h"

UCLASS(MinimalAPI)
class UAdColonyFunctionLibrary : public UBlueprintFunctionLibrary
{
   GENERATED_UCLASS_BODY()
public:
   UFUNCTION(BlueprintCallable, Category = "Utilitites|Platform")
   static void ShowAdColonyV4VC();

   UFUNCTION(BlueprintCallable, Category = "Utilitites|Platform")
   static void ShowAdColonyInterstitialVideo();

   UFUNCTION(BlueprintCallable, Category = "Utilitites|Platform")
   static int32 GetRewardResultAdColonyV4VC();
};