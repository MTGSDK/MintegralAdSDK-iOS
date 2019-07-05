//
//  MTGBidInterstitialVideoAdManager.h
//  MTGSDKInterstitialVideo
//
//  Created by Harry on 2019/4/24.
//  Copyright © 2019 Mintegral. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "MTGInterstitialVideoAd.h"

@interface MTGBidInterstitialVideoAdManager : NSObject

@property (nonatomic, weak) id  <MTGBidInterstitialVideoDelegate> _Nullable delegate;

@property (nonatomic, readonly)   NSString * _Nonnull currentUnitId;


/**
 * Play the video is mute in the beginning ,defult is NO
 *
 */
@property (nonatomic, assign) BOOL  playVideoMute;



- (nonnull instancetype)initWithUnitID:(nonnull NSString *)unitId delegate:(nullable id<MTGBidInterstitialVideoDelegate>)delegate;


/**
 * Begins loading bidding ad content for the interstitialVideo.
 *
 * You can implement the `onInterstitialVideoLoadSuccess:` and `onInterstitialVideoLoadFail: adManager:` methods of
 * `MTGInterstitialVideoDelegate` if you would like to be notified as loading succeeds or
 * fails.
 * @param bidToken - the token from bid request within MTGBidFramework.
 */
- (void)loadAdWithBidToken:(nonnull NSString *)bidToken;

/** @name Presenting an interstitialVideo Ad */

/**
 * Presents the interstitialVideo ad modally from the specified view controller.
 *
 * @param viewController The view controller that should be used to present the interstitialVideo ad.
 */
- (void)showFromViewController:(UIViewController *_Nonnull)viewController;


/**
 *  Will return whether the given unitId used for bidding is loaded and ready to be shown.
 *
 *  @param unitId - adPositionId value in Self Service
 *
 *  @return - YES if the unitId is loaded and ready to be shown, otherwise NO.
 */
- (BOOL)isVideoReadyToPlay:(nonnull NSString *)unitId;

/**
 *  Clean all the video file cache from the disk.
 */
- (void)cleanAllVideoFileCache;


@end



