// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#pragma once

#if PLATFORM_ANDROID
void InitChartboostJavaMethods();

void AndroidThunkCpp_CacheChartboostRewardVideo(const FString& location);
bool AndroidThunkCpp_HasRewardedVideo(const FString& location);
void AndroidThunkCpp_ShowChartboostRewardVideo(const FString& location);
void AndroidThunkCpp_CacheChartboostInterstitial(const FString& location);
bool AndroidThunkCpp_HasInterstitial(const FString& location);
void AndroidThunkCpp_ShowChartboostInterstitial(const FString& location);
#endif