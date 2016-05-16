// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "AdMobPrivatePCH.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

static jmethodID AndroidThunkJava_ShowAdInterstitial;
static jmethodID AndroidThunkJava_PreloadAdInterstitial;

void InitAdMobJavaMethods()
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		if (FJavaWrapper::GameActivityClassID)
		{
			AndroidThunkJava_ShowAdInterstitial = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ShowAdInterstitial", "(Ljava/lang/String;)V", true);
			AndroidThunkJava_PreloadAdInterstitial = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_PreloadAdInterstitial", "(Ljava/lang/String;)V", true);
		}
	}
}


// call out to JNI to see if the application was packaged for GearVR
void AndroidThunkCpp_ShowAdInterstitial(const FString& AdUnitID)
{
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
	   if (AndroidThunkJava_ShowAdInterstitial)
      { 
         jstring AdUnitIDArg = Env->NewStringUTF(TCHAR_TO_UTF8(*AdUnitID));
		   FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_ShowAdInterstitial, AdUnitIDArg);
         Env->DeleteLocalRef(AdUnitIDArg);
      }
   }
}

void AndroidThunkCpp_PreloadAdInterstitial(const FString& AdUnitID)
{
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
	{
		if (AndroidThunkJava_PreloadAdInterstitial)
		{
			jstring AdUnitIDArg = Env->NewStringUTF(TCHAR_TO_UTF8(*AdUnitID));
			FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_PreloadAdInterstitial, AdUnitIDArg);
			Env->DeleteLocalRef(AdUnitIDArg);
		}
	}
}
#endif
