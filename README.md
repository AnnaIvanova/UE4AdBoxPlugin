# UE4AdBoxPlugin
Plugin that adds AdMob interstitial support for Android platform in UE4 blueprints.

For UE4 starting from 4.10.

Plugin adds blocks:
* PreloadAdInterstitial(AdMobID)
* ShowAdInterstitial(AdMobID)

AdMobID is an index from [Project Settings -> Platforms -> Android -> Ad Mob Ad Unit IDs]

ShowAdInterstitial can be called without calling PreloadAdInterstitial, but in this case it will take time to load data for interstitial.

Please add the following strings to DefaultEngine.ini (not sure that all of them are necessary).

    [OnlineSubsystem]
    DefaultPlatformService=GooglePlay
    
    [OnlineSubsystemGooglePlay.store]
    bSupportsInAppPurchasing=True
    
    [Advertising]
    DefaultProviderName=AndroidAdvertising

Many thanks to Timberlake for this video https://www.youtube.com/watch?v=NWjnPNIWX1s  
