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
