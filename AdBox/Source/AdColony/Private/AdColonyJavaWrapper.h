// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#pragma once

#if PLATFORM_ANDROID
void InitAdColonyJavaMethods();
void AndroidThunkCpp_ShowAdColonyV4VC();
void AndroidThunkCpp_ShowAdColonyInterstitialVideo();
FString AndroidThunkCpp_AdColonyStatusForZone(FString);
#endif