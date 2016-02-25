// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "AdMobInterstitialPrivatePCH.h"
#include "AdMobInterstitial.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif

#if PLATFORM_ANDROID
static jmethodID AndroidThunkJava_ShowAdInterstitial;
static jmethodID AndroidThunkJava_PreloadAdInterstitial;

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

class FAdMobInterstitial : public IAdMobInterstitial
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FAdMobInterstitial, AdMobInterstitial )

void FAdMobInterstitial::StartupModule()
{
#if PLATFORM_ANDROID
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (FJavaWrapper::GameActivityClassID)
      {
         AndroidThunkJava_ShowAdInterstitial = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ShowAdInterstitial", "(Ljava/lang/String;)V", true); 
         AndroidThunkJava_PreloadAdInterstitial = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_PreloadAdInterstitial", "(Ljava/lang/String;)V", true);
      }
   }
#endif
}

void FAdMobInterstitial::ShutdownModule()
{	
}