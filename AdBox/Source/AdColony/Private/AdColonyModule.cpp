// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "AdColonyPrivatePCH.h"
#include "AdColonyModule.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif

#include "Misc/AssertionMacros.h"

DEFINE_LOG_CATEGORY(LogAdColony);

#if PLATFORM_ANDROID
static jmethodID AndroidThunkJava_ShowAdColonyV4VC;
static jmethodID AndroidThunkJava_ShowAdColonyInterstitialVideo;
static jmethodID AndroidThunkJava_GetRewardResultAdColonyV4VC;

void AndroidThunkCpp_ShowAdColonyV4VC()
{
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (AndroidThunkJava_ShowAdColonyV4VC)
      {         
         FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_ShowAdColonyV4VC);         
      }
   }
}

int32 AndroidThunkCpp_GetRewardResultAdColonyV4VC()
{
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (AndroidThunkJava_GetRewardResultAdColonyV4VC)
      {
         //UE_LOG(LogAdColony, Log, TEXT("AndroidThunkJava_GetRewardResultAdColonyV4VC OK"));
         int res = FJavaWrapper::CallIntMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_GetRewardResultAdColonyV4VC);
         //UE_LOG(LogAdColony, Log, TEXT("Reward = %d"), res);
         return res;
      }
      else
      {         
         return -1;
      }        
   }
   else
   {
      return -1;
   }      
}

void AndroidThunkCpp_ShowAdColonyInterstitialVideo()
{
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (AndroidThunkJava_ShowAdColonyInterstitialVideo)
      {
         FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_ShowAdColonyInterstitialVideo);
      }
   }
}
#endif

class FAdColonyModule : public IAdColonyModule
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FAdColonyModule, AdColony )

void FAdColonyModule::StartupModule()
{
#if PLATFORM_ANDROID
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (FJavaWrapper::GameActivityClassID)
      {
         AndroidThunkJava_ShowAdColonyV4VC = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ShowAdColonyV4VC", "()V", true);
         AndroidThunkJava_ShowAdColonyInterstitialVideo = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ShowAdColonyInterstitialVideo", "()V", true);
         AndroidThunkJava_GetRewardResultAdColonyV4VC = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_GetRewardResultAdColonyV4VC", "()I", true);         
      }
   }
#endif
}

void FAdColonyModule::ShutdownModule()
{	
}