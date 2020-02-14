//
//  MTGBidRewardAdManager.h
//  MTGSDKReward
//
//  Created by Harry on 2019/4/10.
//  Copyright © 2019 Mintegral. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MTGRewardAd.h"

@interface MTGBidRewardAdManager : NSObject

/* Play the video mute or not in the beginning, defult is NO */
@property (nonatomic, assign) BOOL  playVideoMute;


/**
 * The shared instance of the video.
 *
 * @return The video singleton.
 */
+ (nonnull instancetype)sharedInstance;

/**
 *  Called when load the video
 *
 *  @param bidToken    - the token from bid request within MTGBidFramework.
 *  @param unitId        - the unitId string of the Ad that was loaded.
 *  @param delegate    - reference to the object that implements MTGRewardAdLoadDelegate protocol; will receive load events for the given unitId.
 */
- (void)loadVideoWithBidToken:(nonnull NSString *)bidToken
                       unitId:(nonnull NSString *)unitId
                     delegate:(nullable id <MTGRewardAdLoadDelegate>)delegate;

/**
 *  Called when show the video
 *
 *  @param unitId         - the unitId string of the Ad that display.
 *  @param rewardId     - the id  about rewardInfo
 *  @param userId         - The user's unique identifier in your system
 *  @param delegate     - reference to the object that implements MTGRewardAdShowDelegate protocol; will receive show events for the given unitId.
 *  @param viewController - UIViewController that shouold be set as the root view controller for the ad
 */
- (void)showVideo:(nonnull NSString *)unitId withRewardId:(nonnull NSString *)rewardId userId:(nullable NSString *)userId delegate:(nullable id <MTGRewardAdShowDelegate>)delegate viewController:(nonnull UIViewController*)viewController;

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


/**
*  Set  alertView text,if you want to change the alertView text.
*
* @param title  alert title
* @param content    alertcontent
* @param confirmText    confirm button text
* @param cancelText     cancel button text
* @param unitId     unitId

 NOTE:called before loadAd
*/
- (void)setAlertWithTitle:(NSString *_Nullable)title
                  content:(NSString *_Nullable)content
              confirmText:(NSString *_Nullable)confirmText
               cancelText:(NSString *_Nullable)cancelText
                   unitId:(NSString *_Nullable)unitId;

@end

