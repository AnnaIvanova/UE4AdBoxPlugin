// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "AdColonyPrivatePCH.h"
#include "AdColonyJavaWrapper.h"
#include "AdColonyComponent.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif

#if PLATFORM_ANDROID
static jmethodID AndroidThunkJava_ShowAdColonyV4VC;
static jmethodID AndroidThunkJava_ShowAdColonyInterstitialVideo;
static jmethodID AndroidThunkJava_AdColonyStatusForZone;

void InitAdColonyJavaMethods()
{
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (FJavaWrapper::GameActivityClassID)
      {
         AndroidThunkJava_ShowAdColonyV4VC = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ShowAdColonyV4VC", "()V", true);
         AndroidThunkJava_ShowAdColonyInterstitialVideo = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ShowAdColonyInterstitialVideo", "()V", true);
         AndroidThunkJava_AdColonyStatusForZone = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_AdColonyStatusForZone", "(Ljava/lang/String;)Ljava/lang/String;", true);
      }
   }
}

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

FString AndroidThunkCpp_AdColonyStatusForZone(FString zone_id)
{
   FString avaliability;
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (AndroidThunkJava_AdColonyStatusForZone)
      {
         jstring ZoneIdArg = Env->NewStringUTF(TCHAR_TO_UTF8(*zone_id));
         jstring res = (jstring)FJavaWrapper::CallObjectMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_AdColonyStatusForZone, ZoneIdArg);
         Env->DeleteLocalRef(ZoneIdArg); 

         const char *avaliabilityString = Env->GetStringUTFChars(res, 0);
         avaliability = FString(avaliabilityString);

         Env->DeleteLocalRef(res);
      }
   }
   return avaliability;
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


//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeOnAdColonyAdStarted();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeOnAdColonyAdStarted(JNIEnv* jenv, jobject thiz, jstring zone_id, jboolean isShown, jboolean isNotShown, jboolean isCanceled, jboolean isNoFill, jboolean isSkipped)
{
   const char* JavaZoneIdString = jenv->GetStringUTFChars(zone_id, 0);
   UAdColonyComponent::OnAdColonyAdStarted_Broadcast(JavaZoneIdString, isShown, isNotShown, isCanceled, isNoFill, isSkipped);
   jenv->ReleaseStringUTFChars(zone_id, JavaZoneIdString);
}

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeOnAdColonyAdAttemptFinished();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeOnAdColonyAdAttemptFinished(JNIEnv* jenv, jobject thiz, jstring zone_id, jboolean isShown, jboolean isNotShown, jboolean isCanceled, jboolean isNoFill, jboolean isSkipped)
{
   const char* JavaZoneIdString = jenv->GetStringUTFChars(zone_id, 0);
   UAdColonyComponent::OnAdColonyAdAttemptFinished_Broadcast(JavaZoneIdString, isShown, isNotShown, isCanceled, isNoFill, isSkipped);
   jenv->ReleaseStringUTFChars(zone_id, JavaZoneIdString);
}

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeOnAdColonyV4VCReward();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeOnAdColonyV4VCReward(JNIEnv* jenv, jobject thiz, jboolean success, jstring name, jint amount)
{
   const char* JavaNameString = jenv->GetStringUTFChars(name, 0);
   UAdColonyComponent::OnAdColonyV4VCReward_Broadcast(success, JavaNameString, amount);
   jenv->ReleaseStringUTFChars(name, JavaNameString);
}

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeOnAdColonyAdAvailabilityChange();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeOnAdColonyAdAvailabilityChange(JNIEnv* jenv, jobject thiz, jboolean available, jstring zone_id)
{
   const char* JavaZoneIdString = jenv->GetStringUTFChars(zone_id, 0);
   UAdColonyComponent::OnAdColonyAdAvailabilityChange_Broadcast(available, JavaZoneIdString);
   jenv->ReleaseStringUTFChars(zone_id, JavaZoneIdString);
}
#endif
