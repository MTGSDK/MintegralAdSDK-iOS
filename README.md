# Mintegral SDKs for iOS

More information can be found at the [Wiki page.](https://dev.mintegral.com/doc/index.html?file=sdk-m_sdk-ios)

## Install a Mintegral SDK using CocoaPods

Mintegral distributes several iOS specific SDKs via CocoaPods.
You can install the CocoaPods tool on OS X by running the following command from
the terminal. Detailed information is available in the [Getting Started
guide](https://guides.cocoapods.org/using/getting-started.html#getting-started).

```
$ sudo gem install cocoapods
```

### Add a Mintegral SDK to your iOS app

CocoaPods is used to install and manage dependencies in existing Xcode projects.

1. Create an Xcode project, and save it to your local machine.
2. Create a file named `Podfile` in your project directory. This file defines
   your project's dependencies, and is commonly referred to as a Podspec.
3. Open `Podfile`, and add your dependencies. A simple Podspec is shown here:

    ```
    platform :ios, '8.0'
    
    #Note: default is using NativeAd Framework
    #pod 'MintegralAdSDK'  
    #Note: or 
    #pod 'MintegralAdSDK/NativeAd'  
    
    #Note: using Bid NativeAd Framework
    #pod 'MintegralAdSDK/BidNativeAd'  
    
    
    #Note: using RewardVideoAd Framework
    pod 'MintegralAdSDK/RewardVideoAd'
    
    #Note: using Bid RewardVideoAd Framework
    pod 'MintegralAdSDK/BidRewardVideoAd'
    
    #Note: using InterstitialVideoAd Framework
    pod 'MintegralAdSDK/InterstitialVideoAd'
    
    #Note: using Bid InterstitialVideoAd Framework
    pod 'MintegralAdSDK/BidInterstitialVideoAd'
    
    #Note: using InterstitialAd Framework
    pod 'MintegralAdSDK/InterstitialAd'
    
    #Note: using InterActiveAd Framework
    pod 'MintegralAdSDK/InterActiveAd'

    #Note: using BannerAd Framework
    pod 'MintegralAdSDK/BannerAd'
    
    #Note: using Bid BannerAd Framework
    pod 'MintegralAdSDK/BidBannerAd'
    
    ```

4. Save the file.
5. Open a terminal and `cd` to the directory containing the Podfile.

    ```
    $ cd <path-to-project>/project/
    ```

6. Run the `pod install` command. This will install the SDKs specified in the
   Podspec, along with any dependencies they may have.

    ```
    $ pod install
    ```

7. Open your app's `.xcworkspace` file to launch Xcode.
   Use this file for all development on your app.
   
   
