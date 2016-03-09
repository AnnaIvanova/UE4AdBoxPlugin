# UE4AdBoxPlugin
Plugin that adds **AdMob** interstitial support and **AdColony** interstitial video and reward video support for Android platform in UE4 blueprints.

For UE4 starting from 4.10.

Plugin adds blocks:
* PreloadAdInterstitial(AdMobID)
* ShowAdInterstitial(AdMobID)
* Show Ad Colony Interstitial Video
* Show Ad Colony V4VC
* Get Reward Result Ad Colony V4VC 


AdMobID is an index from [Project Settings -> Platforms -> Android -> Ad Mob Ad Unit IDs]

ShowAdInterstitial can be called without calling PreloadAdInterstitial, but in this case it will take time to load data for interstitial.

Show Ad Colony Interstitial Video block shows AdColony advertising video.
Show Ad Colony V4VC block shows AdColony advertising reward video. You can detect if the user has watched it (and can obtain a reward) by using Get Reward Result Ad Colony V4VC.

Get Reward Result Ad Colony V4VC return values:
* 1 is video was successfully watches
* 0 if it was skiped, canceled or was not shown
* -1 in any other case including case when video has not been complete yet

Please add the following strings to DefaultEngine.ini.

    [OnlineSubsystem]
    DefaultPlatformService=GooglePlay
    
    [OnlineSubsystemGooglePlay.store]
    bSupportsInAppPurchasing=True
    
    [Advertising]
    DefaultProviderName=AndroidAdvertising
    
    [/Script/AndroidRuntimeSettings.AndroidRuntimeSettings]
    AdColonyAppID=app185a7e71e1714831a49ec7
    AdColonyZoneIDInterstitialVideo=vz06e8c32a037749699e7050
    AdColonyZoneIDV4VC=vz1fd5a8b2bf6841a0a4b826

Please note that codes in [/Script/AndroidRuntimeSettings.AndroidRuntimeSettings] section are only for testing. They are taken from AdColony examples.

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
