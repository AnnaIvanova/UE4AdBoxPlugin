// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#pragma once
#include "AdColonyComponent.generated.h"

UCLASS(ClassGroup = Advertising, HideCategories = (Activation, "Components|Activation", Collision), meta = (BlueprintSpawnableComponent))
class UAdColonyComponent : public UActorComponent
{
   GENERATED_UCLASS_BODY()
public:
   ~UAdColonyComponent();
   UFUNCTION(BlueprintCallable, Category = "Plugin|AdBox")
   static void ShowAdColonyV4VC();

   UFUNCTION(BlueprintCallable, Category = "Plugin|AdBox")
   static void ShowAdColonyInterstitialVideo();

   UFUNCTION(BlueprintCallable, Category = "Plugin|AdBox")
   static FString AdColonyStatusForZone(FString zone_id);

   DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FAdColonyAdStartedDelegate, FString, zone_id, bool, isShown, bool, isNotShown, bool, isCanceled, bool, isNoFill, bool, isSkipped);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FAdColonyAdAttemptFinishedDelegate, FString, zone_id, bool, isShown, bool, isNotShown, bool, isCanceled, bool, isNoFill, bool, isSkipped);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FAdColonyV4VCRewardDelegate, bool, success, FString, name, int32, amount);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAdColonyAdAvailabilityChangeDelegate, bool, available, FString, zone_id);

   UPROPERTY(BlueprintAssignable)
   FAdColonyAdStartedDelegate AdColonyAdStarted;

   UPROPERTY(BlueprintAssignable)
   FAdColonyAdAttemptFinishedDelegate AdColonyAdAttemptFinished;

   UPROPERTY(BlueprintAssignable)
   FAdColonyV4VCRewardDelegate AdColonyV4VCReward;

   UPROPERTY(BlueprintAssignable)
   FAdColonyAdAvailabilityChangeDelegate AdColonyAdAvailabilityChange;

   static void OnAdColonyAdStarted_Broadcast(FString zone_id, bool isShown, bool isNotShown, bool isCanceled, bool isNoFill, bool isSkipped) {
      ActiveComponent->AdColonyAdStarted.Broadcast(zone_id, isShown, isNotShown, isCanceled, isNoFill, isSkipped);
   }

   static void OnAdColonyAdAttemptFinished_Broadcast(FString zone_id, bool isShown, bool isNotShown, bool isCanceled, bool isNoFill, bool isSkipped) {
      ActiveComponent->AdColonyAdAttemptFinished.Broadcast(zone_id, isShown, isNotShown, isCanceled, isNoFill, isSkipped);
   }

   static void OnAdColonyV4VCReward_Broadcast(bool success, FString name, int32 amount) {
      ActiveComponent->AdColonyV4VCReward.Broadcast(success, name, amount);
   }

   static void OnAdColonyAdAvailabilityChange_Broadcast(bool available, FString zone_id) {
      ActiveComponent->AdColonyAdAvailabilityChange.Broadcast(available, zone_id);
   }

private:
   static UAdColonyComponent* ActiveComponent;
};