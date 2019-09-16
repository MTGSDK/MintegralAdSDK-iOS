//
//  MTGBannerAdView.h
//  MTGSDK
//
//  Created by lee on 2019/7/9.
//  Copyright © 2019 Mintegral. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MTGSDK/MTGBool.h>
#import "MTGBannerAdViewDelegate.h"

typedef NS_ENUM(NSInteger,MTGBannerSizeType) {
    /*Represents the fixed banner ad size - 320pt by 50pt.*/
    MTGStandardBannerType320x50,
    
    /*Represents the fixed banner ad size - 320pt by 90pt.*/
    MTGLargeBannerType320x90,
    
    /*Represents the fixed banner ad size - 300pt by 250pt.*/
    MTGMediumRectangularBanner300x250,
    
    /*if device height <=720,Represents the fixed banner ad size - 320pt by 50pt;
      if device height > 720,Represents the fixed banner ad size - 728pt by 90pt*/
    MTGSmartBannerType
};

#define MTGBannerSDKVersion @"5.7.1"

@interface MTGBannerAdView : UIView

/**
 Automatic refresh time, the time interval of banner view displaying new ads, is set in the range of 10s~180s.
 If set 0, it will not be refreshed.
 You need to set it before loading ad.
 */
@property(nonatomic,assign) NSInteger autoRefreshTime;

/**
 Whether to show the close button
 MTGBoolNo means off,MTGBoolYes means on
 */
@property(nonatomic,assign) MTGBool showCloseButton;

/**
 unitId
 */
@property(nonatomic,copy,readonly) NSString * _Nonnull unitId;

/**
 the delegate
 */
@property(nonatomic,weak,nullable) id <MTGBannerAdViewDelegate> delegate;

/**
 The current ViewController of display ad.
*/
@property (nonatomic, weak) UIViewController * _Nullable  viewController;

/**
 This is a method to initialize an MTGBannerAdView with the given unit id

 @param adSize The size of the banner view.
 @param unitId The id of the ad unit. You can create your unit id from our Portal.
 @param rootViewController The view controller that will be used to present full screen ads.
 @return
 */
- (nonnull instancetype)initBannerAdViewWithAdSize:(CGSize)adSize
                                            unitId:(nonnull NSString *) unitId
                                rootViewController:(nullable UIViewController *)rootViewController;

/**
 This is a method to initialize an MTGBannerAdView with the given unit id
 
 @param bannerSizeType please refer to enum MTGBannerSizeType.
 @param unitId The id of the ad unit. You can create your unit id from our Portal.
 @param rootViewController The view controller that will be used to present full screen ads.
 @return
 */
- (nonnull instancetype)initBannerAdViewWithBannerSizeType:(MTGBannerSizeType)bannerSizeType
                                            unitId:(nonnull NSString *) unitId
                                rootViewController:(nullable UIViewController *)rootViewController;
/**
 Begin to load banner ads
 */
- (void)loadBannerAd;

/**
Call this method when you want to relase MTGBannerAdView. It's optional.
 
NOTE: After calling this method, if you need to continue using the MTGBannerAdView, you must reinitialize a MTGBannerAdView
 */
- (void)destroyBannerAdView;

@end

