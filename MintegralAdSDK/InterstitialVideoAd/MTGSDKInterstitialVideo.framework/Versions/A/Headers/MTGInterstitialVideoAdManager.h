//
//  MTGInterstitialVideoAdManager.h
//  MTGSDK
//
//  Created by CharkZhang on 2018/4/10.
//  Copyright © 2018年 Mintegral. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MTGInterstitialVideoAd.h"

@interface MTGInterstitialVideoAdManager :  NSObject

@property (nonatomic, weak) id  <MTGInterstitialVideoDelegate> _Nullable delegate;

@property (nonatomic, readonly)   NSString * _Nonnull currentUnitId;


/**
 * Play the video is mute in the beginning ,defult is NO
 *
 */
@property (nonatomic, assign) BOOL  playVideoMute;



- (nonnull instancetype)initWithUnitID:(nonnull NSString *)unitId delegate:(nullable id<MTGInterstitialVideoDelegate>)delegate;


/**
 * Begins loading ad content for the interstitialVideo.
 *
 * You can implement the `onInterstitialVideoLoadSuccess:` and `onInterstitialVideoLoadFail: adManager:` methods of
 * `MTGInterstitialVideoDelegate` if you would like to be notified as loading succeeds or
 * fails.
 */
- (void)loadAd;


/** @name Presenting an interstitialVideo Ad */

/**
 * Presents the interstitialVideo ad modally from the specified view controller.
 *
 * @param viewController The view controller that should be used to present the interstitialVideo ad.
 */
- (void)showFromViewController:(UIViewController *_Nonnull)viewController;

/**
 *  Whether the given unitId is loaded and ready to be shown.
 *
 *  @param unitId - adPositionId value in Self Service.
 *
 *  @return - YES if the unitId is loaded and ready to be shown, otherwise NO.
 */
- (BOOL)isVideoReadyToPlay:(nonnull NSString *)unitId;

/**
 *  Clean all the video file cache from the disk.
 */
- (void)cleanAllVideoFileCache;


@end
