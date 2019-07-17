Pod::Spec.new do |spec|


  spec.name         = 'MintegralAdSDK'
  spec.version      = '5.5.1'
  spec.summary      = 'Mintegral Network Mobile App Ad SDK'
  spec.homepage     = 'http://cdn-adn.rayjump.com/cdn-adn/v2/markdown_v2/index.html?file=sdk-m_sdk-ios&lang=en'
  spec.description  = <<-DESC   
    Mintegral's  AdSDK allows you to monetize your iOS and Android apps with Mintegral ads.  
                       DESC

  spec.license      = { :type => 'Mintegral', :file => "LICENSE.txt" }
  spec.author             = 'Mintegral'
  spec.social_media_url   = 'https://www.facebook.com/mintegral.official'
  spec.platform     = :ios, '7.0'
  spec.source       = { :git => 'https://github.com/Mintegral-official/MintegralAdSDK-iOS.git', :tag => spec.version}


  spec.libraries = 'sqlite3', 'xml2','z'
  spec.frameworks = 'SystemConfiguration', 'CoreGraphics','Foundation','UIKit','AdSupport','StoreKit','QuartzCore','CoreTelephony','MobileCoreServices','Accelerate','AVFoundation','WebKit'

  spec.requires_arc = true
  spec.user_target_xcconfig =   {'OTHER_LDFLAGS' => ['-lObjC']}




  # ――― Source Code ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  spec.default_subspecs =  'NativeAd'

  spec.subspec 'NativeAd' do |ss|
  ss.ios.deployment_target = '7.0'
  ss.vendored_frameworks = 'MintegralAdSDK/NativeAd/*.framework'
  end

  spec.subspec 'BidNativeAd' do |ss|
  ss.ios.deployment_target = '7.0'
  ss.preserve_paths = "MintegralAdSDK/NativeAd/*.framework"
  ss.vendored_frameworks = 'MintegralAdSDK/NativeAd/MTGSDK.framework', 'MintegralAdSDK/NativeAd/MTGSDKBidding.framework'
  end

 
spec.subspec 'InterstitialVideoAd' do |ss|
  ss.ios.deployment_target = '7.0'
  ss.vendored_frameworks = 'MintegralAdSDK/InterstitialVideoAd/*.framework'
  ss.dependency 'MintegralAdSDK/NativeAd'
end

spec.subspec 'BidInterstitialVideoAd' do |ss|
  ss.ios.deployment_target = '7.0'
  ss.vendored_frameworks = 'MintegralAdSDK/InterstitialVideoAd/*.framework'
  ss.dependency 'MintegralAdSDK/BidNativeAd'
end


spec.subspec 'RewardVideoAd' do |ss|
  ss.ios.deployment_target = '7.0'
  ss.vendored_frameworks = 'MintegralAdSDK/RewardVideoAd/*.framework'
  ss.dependency 'MintegralAdSDK/NativeAd'
end

spec.subspec 'BidRewardVideoAd' do |ss|
  ss.ios.deployment_target = '7.0'
  ss.vendored_frameworks = 'MintegralAdSDK/RewardVideoAd/*.framework'
  ss.dependency 'MintegralAdSDK/BidNativeAd'
end


spec.subspec 'InterstitialAd' do |ss|
  ss.ios.deployment_target = '7.0'
  ss.vendored_frameworks = 'MintegralAdSDK/InterstitialAd/*.framework'
  ss.dependency 'MintegralAdSDK/NativeAd'
end

spec.subspec 'BidInterstitialAd' do |ss|
  ss.ios.deployment_target = '7.0'
  ss.vendored_frameworks = 'MintegralAdSDK/InterstitialAd/*.framework'
  ss.dependency 'MintegralAdSDK/BidNativeAd'
end


spec.subspec 'InterActiveAd' do |ss|
  ss.ios.deployment_target = '7.0'
  ss.vendored_frameworks = 'MintegralAdSDK/InterActive/*.framework'
  ss.dependency 'MintegralAdSDK/NativeAd'
end
  
spec.subspec 'BidInterActiveAd' do |ss|
  ss.ios.deployment_target = '7.0'
  ss.vendored_frameworks = 'MintegralAdSDK/InterActive/*.framework'
  ss.dependency 'MintegralAdSDK/BidNativeAd'
end



 
end
