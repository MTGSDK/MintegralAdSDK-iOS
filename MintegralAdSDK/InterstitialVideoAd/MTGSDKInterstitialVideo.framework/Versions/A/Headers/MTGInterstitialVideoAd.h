//
//  MTGInterstitialVideoAd.m
//  MTGSDKInterstitialVideo
//
//  Created by Harry on 2019/4/24.
//  Copyright © 2019 Mintegral. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MTGInterstitialVideoSDKVersion @"5.5.0"

@class MTGInterstitialVideoAdManager;
@class MTGBidInterstitialVideoAdManager;

/**
 *  This protocol defines a listener for ad video load events.
 */
@protocol MTGInterstitialVideoDelegate <NSObject>
@optional

/**
 *  Called when the ad is loaded , but not ready to be displayed,need to wait load video
 completely
 */
- (void)onInterstitialAdLoadSuccess:(MTGInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called when the ad is successfully load , and is ready to be displayed
 */
- (void)onInterstitialVideoLoadSuccess:(MTGInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called when there was an error loading the ad.
 *  @param error       - error object that describes the exact error encountered when loading the ad.
 */
- (void)onInterstitialVideoLoadFail:(nonnull NSError *)error adManager:(MTGInterstitialVideoAdManager *_Nonnull)adManager;


/**
 *  Called when the ad display success
 */
- (void)onInterstitialVideoShowSuccess:(MTGInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called when the ad failed to display for some reason
 *  @param error       - error object that describes the exact error encountered when showing the ad.
 */
- (void)onInterstitialVideoShowFail:(nonnull NSError *)error adManager:(MTGInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called only when the ad has a video content, and called when the video play completed
 */
- (void)onInterstitialVideoPlayCompleted:(MTGInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called only when the ad has a endcard content, and called when the endcard show
 */
- (void)onInterstitialVideoEndCardShowSuccess:(MTGInterstitialVideoAdManager *_Nonnull)adManager;


/**
 *  Called when the ad is clicked
 */
- (void)onInterstitialVideoAdClick:(MTGInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called when the ad has been dismissed from being displayed, and control will return to your app
 *  @param converted   - BOOL describing whether the ad has converted
 */
- (void)onInterstitialVideoAdDismissedWithConverted:(BOOL)converted adManager:(MTGInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called when the ad  did closed;
 */
- (void) onInterstitialVideoAdDidClosed:(MTGInterstitialVideoAdManager *_Nonnull)adManager;

@end

@protocol MTGBidInterstitialVideoDelegate <NSObject>
@optional

/**
 *  Called when the ad is loaded , but not ready to be displayed,need to wait load video
 completely
 */
- (void)onInterstitialAdLoadSuccess:(MTGBidInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called when the ad is successfully load , and is ready to be displayed
 */
- (void)onInterstitialVideoLoadSuccess:(MTGBidInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called when there was an error loading the ad.
 *  @param error       - error object that describes the exact error encountered when loading the ad.
 */
- (void)onInterstitialVideoLoadFail:(nonnull NSError *)error adManager:(MTGBidInterstitialVideoAdManager *_Nonnull)adManager;


/**
 *  Called when the ad display success
 */
- (void)onInterstitialVideoShowSuccess:(MTGBidInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called when the ad failed to display for some reason
 *  @param error       - error object that describes the exact error encountered when showing the ad.
 */
- (void)onInterstitialVideoShowFail:(nonnull NSError *)error adManager:(MTGBidInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called only when the ad has a video content, and called when the video play completed
 */
- (void)onInterstitialVideoPlayCompleted:(MTGBidInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called only when the ad has a endcard content, and called when the endcard show
 */
- (void)onInterstitialVideoEndCardShowSuccess:(MTGBidInterstitialVideoAdManager *_Nonnull)adManager;


/**
 *  Called when the ad is clicked
 */
- (void)onInterstitialVideoAdClick:(MTGBidInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called when the ad has been dismissed from being displayed, and control will return to your app
 *  @param converted   - BOOL describing whether the ad has converted
 */
- (void)onInterstitialVideoAdDismissedWithConverted:(BOOL)converted adManager:(MTGBidInterstitialVideoAdManager *_Nonnull)adManager;

/**
 *  Called when the ad  did closed;
 */
- (void) onInterstitialVideoAdDidClosed:(MTGBidInterstitialVideoAdManager *_Nonnull)adManager;


@end
