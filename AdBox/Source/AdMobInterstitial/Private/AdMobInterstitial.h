// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#pragma once

#if PLATFORM_ANDROID
void AndroidThunkCpp_ShowAdInterstitial(const FString& AdUnitID);
void AndroidThunkCpp_PreloadAdInterstitial(const FString& AdUnitID);
#endif