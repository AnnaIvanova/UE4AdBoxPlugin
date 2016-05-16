// Copyright 2014-1016, 2Scars Games. All Rights Reserved.
#include "ChartboostPrivatePCH.h"
#include "ChartboostJavaWrapper.h"
#include "ChartboostComponent.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif

//#include "Misc/AssertionMacros.h"

#if PLATFORM_ANDROID
static jmethodID AndroidThunkJava_ShowChartboostRewardVideo;
static jmethodID AndroidThunkJava_HasRewardedVideo;
static jmethodID AndroidThunkJava_CacheChartboostRewardVideo;
static jmethodID AndroidThunkJava_ShowChartboostInterstitial;
static jmethodID AndroidThunkJava_HasInterstitial;
static jmethodID AndroidThunkJava_CacheChartboostInterstitial;

void InitChartboostJavaMethods()
{
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (FJavaWrapper::GameActivityClassID)
      {
         AndroidThunkJava_CacheChartboostRewardVideo = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_CacheChartboostRewardVideo", "(Ljava/lang/String;)V", true);
         AndroidThunkJava_HasRewardedVideo = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_HasRewardedVideo", "(Ljava/lang/String;)Z", true);
         AndroidThunkJava_ShowChartboostRewardVideo = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ShowChartboostRewardVideo", "(Ljava/lang/String;)V", true);
         AndroidThunkJava_CacheChartboostInterstitial = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_CacheChartboostInterstitial", "(Ljava/lang/String;)V", true);
         AndroidThunkJava_HasInterstitial = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_HasInterstitial", "(Ljava/lang/String;)Z", true);
         AndroidThunkJava_ShowChartboostInterstitial = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ShowChartboostInterstitial", "(Ljava/lang/String;)V", true);         
      }
   }
}

void AndroidThunkCpp_CacheChartboostRewardVideo(const FString& location)
{
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (AndroidThunkJava_CacheChartboostRewardVideo)
      {
         jstring locationArg = Env->NewStringUTF(TCHAR_TO_UTF8(*location));
         FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_CacheChartboostRewardVideo, locationArg);
         Env->DeleteLocalRef(locationArg);
         UE_LOG(LogChartboost, Log, TEXT("AndroidThunkCpp_CacheChartboostRewardVideo OK"));
      }
   }
}

bool AndroidThunkCpp_HasRewardedVideo(const FString& location)
{
   bool res = false;
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (AndroidThunkJava_HasRewardedVideo)
      {
         jstring locationArg = Env->NewStringUTF(TCHAR_TO_UTF8(*location));
         res = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_HasRewardedVideo, locationArg);
         Env->DeleteLocalRef(locationArg);
         UE_LOG(LogChartboost, Log, TEXT("AndroidThunkCpp_HasRewardedVideo OK"));         
      }
   }

   return res;
}

void AndroidThunkCpp_ShowChartboostRewardVideo(const FString& location)
{
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (AndroidThunkJava_ShowChartboostRewardVideo)
      {    
         jstring locationArg = Env->NewStringUTF(TCHAR_TO_UTF8(*location));
         FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_ShowChartboostRewardVideo, locationArg);
         Env->DeleteLocalRef(locationArg);
         UE_LOG(LogChartboost, Log, TEXT("AndroidThunkCpp_ShowChartboostRewardVideo OK"));
      }
   }
}

void AndroidThunkCpp_ShowChartboostInterstitial(const FString& location)
{
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (AndroidThunkJava_ShowChartboostInterstitial)
      {
         jstring locationArg = Env->NewStringUTF(TCHAR_TO_UTF8(*location));
         FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_ShowChartboostInterstitial, locationArg);
         Env->DeleteLocalRef(locationArg);
      }
   }
}

bool AndroidThunkCpp_HasInterstitial(const FString& location)
{
   bool res = false;
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (AndroidThunkJava_HasInterstitial)
      {
         jstring locationArg = Env->NewStringUTF(TCHAR_TO_UTF8(*location));
         res = FJavaWrapper::CallBooleanMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_HasInterstitial, locationArg);
         Env->DeleteLocalRef(locationArg);
         UE_LOG(LogChartboost, Log, TEXT("AndroidThunkCpp_HasInterstitial OK"));
      }
   }
   return res;
}

void AndroidThunkCpp_CacheChartboostInterstitial(const FString& location)
{
   if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
   {
      if (AndroidThunkJava_CacheChartboostInterstitial)
      {
         jstring locationArg = Env->NewStringUTF(TCHAR_TO_UTF8(*location));
         FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GoogleServicesThis, AndroidThunkJava_CacheChartboostInterstitial, locationArg);
         Env->DeleteLocalRef(locationArg);         
      }
   }
}



//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeDidCacheInterstitial();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeDidCacheInterstitial(JNIEnv* jenv, jobject thiz, jstring location)
{
   const char* JavaLocationString = jenv->GetStringUTFChars(location, 0);
   UChartboostComponent::OnDidCacheInterstitial_Broadcast(JavaLocationString);
   jenv->ReleaseStringUTFChars(location, JavaLocationString);
}

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeDidFailToLoadInterstitial(jstring error);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeDidFailToLoadInterstitial(JNIEnv* jenv, jobject thiz, jstring location, jstring error)
{
   const char* JavaErrorString = jenv->GetStringUTFChars(error, 0);
   const char* JavaLocationString = jenv->GetStringUTFChars(location, 0);
   UChartboostComponent::OnDidFailToLoadInterstitial_Broadcast(JavaLocationString, JavaErrorString);
   //Release the strings
   jenv->ReleaseStringUTFChars(error, JavaErrorString);
   jenv->ReleaseStringUTFChars(location, JavaLocationString);

}

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeDidDisplayInterstitial(int reward);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeDidDisplayInterstitial(JNIEnv* jenv, jobject thiz, jstring location)
{
   const char* JavaLocationString = jenv->GetStringUTFChars(location, 0);
   UChartboostComponent::OnDidDisplayInterstitial_Broadcast(JavaLocationString);
   jenv->ReleaseStringUTFChars(location, JavaLocationString);
}

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeDidCompleteRewardedVideo(int reward);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeDidCompleteRewardedVideo(JNIEnv* jenv, jobject thiz, jstring location, jint reward)
{
   const char* JavaLocationString = jenv->GetStringUTFChars(location, 0);
   UChartboostComponent::OnDidCompleteRewardedVideo_Broadcast(JavaLocationString, reward);
   jenv->ReleaseStringUTFChars(location, JavaLocationString);
}

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeDidCacheRewardedVideo();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeDidCacheRewardedVideo(JNIEnv* jenv, jobject thiz, jstring location)
{
   const char* JavaLocationString = jenv->GetStringUTFChars(location, 0);
   UChartboostComponent::OnDidCacheRewardedVideo_Broadcast(JavaLocationString);
   jenv->ReleaseStringUTFChars(location, JavaLocationString);
}

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeDidFailToLoadRewardedVideo(jstring error);"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeDidFailToLoadRewardedVideo(JNIEnv* jenv, jobject thiz, jstring location, jstring error)
{
   const char* JavaLocationString = jenv->GetStringUTFChars(location, 0);
   const char* JavaErrorString = jenv->GetStringUTFChars(error, 0);
   UChartboostComponent::OnDidFailToLoadRewardedVideo_Broadcast(JavaLocationString, JavaErrorString);
   //Release the strings
   jenv->ReleaseStringUTFChars(error, JavaErrorString);
   jenv->ReleaseStringUTFChars(location, JavaLocationString);   
}

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeDidDismissRewardedVideo();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeDidDismissRewardedVideo(JNIEnv* jenv, jobject thiz, jstring location)
{
   const char* JavaLocationString = jenv->GetStringUTFChars(location, 0);
   UChartboostComponent::OnDidDismissRewardedVideo_Broadcast(JavaLocationString);
   jenv->ReleaseStringUTFChars(location, JavaLocationString);
}

//This function is declared in the Java-defined class, GameActivity.java: "public native void nativeDidCloseRewardedVideo();"
extern "C" void Java_com_epicgames_ue4_GameActivity_nativeDidCloseRewardedVideo(JNIEnv* jenv, jobject thiz, jstring location)
{
   const char* JavaLocationString = jenv->GetStringUTFChars(location, 0);
   UChartboostComponent::OnDidCloseRewardedVideo_Broadcast(JavaLocationString);
   jenv->ReleaseStringUTFChars(location, JavaLocationString);
}
#endif