# UE4AdBoxPlugin

Плагин добавляет поддержку межстраничной рекламы **AdMob**, межстраничной видео рекламы и видео рекламы за вознаграждение **AdColony**, а 
также статичной, видео, видео за вознаграждение от **Chartboost** для Андроид платформ в UE4 Blueprints.

Начиная с версии UE4 от 4.10

Чтобы использовать AdColony рекламу вам нужно создать компонент - **AdColony Component** и вызвать его функции 
(перечислены ниже). Чтобы использовать Chartboost рекламу вам нужно создать компонент - **Chartboost Component** и и вызвать его функции
(перечислены ниже). Должен быть **Только один** компонент типа AdColony, и, точно также, должен быть лишь однин из 
компонентов типа Chartboost в вашем приложении. В противном случае только последний созданный компонент будет получать события 
из Java. Этот плагин не обеспечивает проверку количества компонентов.

**AdMob function library:**
* PreloadAdInterstitial(AdMobID)
* ShowAdInterstitial(AdMobID)

**Chartboost Component functions: Event Dispatchers:**
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

**AdColony Component functions: Event Dispatchers:**
* AdColonyV4VCReward
* AdColonyAdStarted
* AdColonyAdAttemptFinished

Events:
* AdColonyShowInterstitialVideo
* AdColonyShowV4VC

Для AdMobID вставте ваш идентификатор рекламного блока(ca-app-pub-################/##########)<br>
[Project Settings -> Platforms -> Android -> Ad Mob Ad Unit IDs]<br>
ShowAdInterstitial может быть вызван без PreloadAdInterstitial, но тогда потребуется время, чтобы загрузить данные для межстраничной рекламы(пердзагрузка).

Добавте строки в ваш **DefaultEngine.ini**<br>
[...\Unreal Projects\имя проекта\Config]<br>
```
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
ChartboostAppSignature=yyyyyyyyyyyyy
```
Обратите внимание, что коды в [Advertisement] предназначены только для тестирования. Они взяты из примеров AdColony.<br>
# Инсталяция
Есть два способа добавленя плагина:
* В движок
* В проект<br>

Если вы хотите использовать плагин в Движке(плагин будет устанавливаться в каждый новый проект), то ваши следующие шаги:
* Скачать исходники движка не ниже версии 4.10 вот отсюда https://github.com/EpicGames/UnrealEngine#windows
* Запустить setup.bat
* Скопировать папку AdBox в папку Plugins вашего Движка [...\Engine\Plugins]
* Пересобрать движок, GenerateProjectFiles->UE4.sln
* Сменить версию движка вашего проекта на версию собранную из исходников <br>[...\Unreal Projects\проект -> проект.uproject -> правый клик мыши -> Switch Unreal Engine version]
* Запустить редактор с вашим проектом

Елси вы хотите использовать плагин только в одном проекте:
* Проект должен быть C++
* Скопировать папку AdBox в папку Plugins вашего проекта (если папки Plugins нет в директории вашего проекта, то ее необходимо создать.)
* Пересобрать файлы Visual Studio вашего проекта (правый клик мыши проект.uproject -> Generate Visual Studio project files)
* Собрать вашу игру
* Запустить редактор с вашим проектом<br>

Больше информации о плагинах можно узнать здесь https://docs.unrealengine.com/latest/INT/Programming/Plugins/index.html

## Если пропал стандартный баннер AdMob:
* Don't panic
* Копируем ниже указанный код в файл build.cs ваше проекта<br>
[...\Unreal Projects\проект\Source\проект\проект.Build.cs]
```
if (Target.Platform == UnrealTargetPlatform.Android)
{
    PrivateDependencyModuleNames.AddRange(new string[] { "OnlineSubsystemGooglePlay", "AndroidAdvertising" });
}
PrivateDependencyModuleNames.Add("OnlineSubsystem");
```
* Пересобираем проект
