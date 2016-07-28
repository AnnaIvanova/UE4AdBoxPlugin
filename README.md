# UE4AdBoxPlugin
Plugin that adds **AdMob** interstitial support, **AdColony** interstitial video and reward video support and **Chartboost** interstitial (static and video) and reward video support for Android platform in UE4 blueprints.

For UE4 starting from 4.10.

To use AdColony advertisement you need to create a component - **AdColony Component** and call its corresponding funcions (listed below). To use Chartboost advertisement you need to create a component - **Chartboost Component** and call its corresponding funcions (listed below). There should be **only one** component of AdColony Component type, and, similary, there should be only one component of Chartboost Component type in your application. In other case only the last created component will recieve events from Java. This plugin doesn't provide any check of number of these components. 

**AdMob function library**:
* PreloadAdInterstitial(AdMobID)
* ShowAdInterstitial(AdMobID)

**Chartboost Component functions**:
Event Dispatchers:
* DidCacheInterstitial
* DidFailToLoadInterstitial
* DidDisplayInterstitial
* DidCacheRewardedVideo
* DidFailToLoadRewardedVideo
* DidCompleteRewardedVideo
* DidDismissRewardedVideo
* DidCloseRewardedVideo

Events:
* CacheChartboostInterstitial
* ShowChartboostInterstitial
* CacheChartboostRewardedVideo
* ShowChartboostRewardedVideo

**AdColony Component functions**:
Event Dispatchers:
* AdColonyV4VCReward
* AdColonyAdStarted
* AdColonyAdAttemptFinished

Events:
* AdColonyShowInterstitialVideo
* AdColonyShowV4VC

AdMobID is an index from [Project Settings -> Platforms -> Android -> Ad Mob Ad Unit IDs]
ShowAdInterstitial can be called without calling PreloadAdInterstitial, but in this case it will take time to load data for interstitial.

Please add the following strings to DefaultEngine.ini.

    [OnlineSubsystem]
    DefaultPlatformService=GooglePlay
    
    [OnlineSubsystemGooglePlay.store]
    bSupportsInAppPurchasing=True
    
    [Advertising]
    DefaultProviderName=AndroidAdvertising
   
    [Advertisement]
    AdColonyAppID=app185a7e71e1714831a49ec7
    AdColonyZoneIDInterstitialVideo=vz06e8c32a037749699e7050
    AdColonyZoneIDV4VC=vz1fd5a8b2bf6841a0a4b826
    ChartboostAppID=xxxxxxxxxxxxxxxxxxxxx
    ChartboostAppSignature=yyyyyyyyyyyyyy

Please note that codes in [Advertisement] section are only for testing. They are taken from AdColony examples.

Please chech your build.cs file. The following code should be present.

    if (Target.Platform == UnrealTargetPlatform.Android)
    {
        PrivateDependencyModuleNames.AddRange(new string[] { "OnlineSubsystemGooglePlay", "AndroidAdvertising" });
    }
    PrivateDependencyModuleNames.Add("OnlineSubsystem");

Many thanks to Timberlake for this video https://www.youtube.com/watch?v=NWjnPNIWX1s  

## Plugin Installation

There are two ways to use the plugin:

* In Engine
* In Game

If you are using the plugin in the Engine your steps should be:

1. Download UE4 (version 4.10+) from github and run setup.bat https://github.com/EpicGames/UnrealEngine#windows
1. Copy AdBox folder to the Engine's Plugin folder
1. Regenerate and rebuild the Engine
1. Switch Unreal Engine version of your project to this custom version
1. Start Editor with your project

If you are using the plugin in the Game your steps should be:

1. Game should be a C++ code project
1. Copy AdBox folder to the Game's Plugin folder
1. Generate Visual Studio project files
1. Build your Game
1. Start Editor with your project

You can find details about UE4 plugins here: https://docs.unrealengine.com/latest/INT/Programming/Plugins/index.html
