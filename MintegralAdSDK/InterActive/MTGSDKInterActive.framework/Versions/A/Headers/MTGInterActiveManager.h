//
//  MTGInterActiveManager.h
//  MTGSDK
//
//  Created by CharkZhang on 2018/5/10.
//  Copyright © 2018年 Mintegral. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MTGInterActiveSDKVersion @"5.7.0"


typedef NS_ENUM(NSInteger, MTGInterActiveResourceType) {
    MTGInterActiveResourceTypePlayable   = 1,
    MTGInterActiveResourceTypeAppwall    = 2,
    MTGInterActiveResourceTypeFinancial  = 3,
    MTGInterActiveResourceTypeTrading    = 4,
};

typedef NS_ENUM(NSInteger,MTGInterActiveStatus) {
    MTGInterActiveStatusNoAds               = 1 << 0,// Unable to show .
    MTGInterActiveStatusMaterialLoading     = 1 << 1,// Can show the ad, but may meet loading indicatorView sometimes .
    MTGInterActiveStatusMaterialCompleted   = 1 << 2,// Be able to show the ad without loading indicatorView .
};



@class MTGCampaign;
@class MTGInterActiveManager;
/**
 *  This protocol defines a listener for ad video load events.
 */
@protocol MTGInterActiveDelegate <NSObject>
@optional

/**
 *  Called when the ad is successfully load , and is ready to be displayed
 */
- (void) onInterActiveLoadSuccess:(MTGInterActiveResourceType)resourceType adManager:(MTGInterActiveManager *_Nonnull)adManager;

/**
 *  Called when the material of ad is successfully load , and is ready to be displayed
 */
- (void) onInterActiveMaterialloadSuccess:(MTGInterActiveResourceType)resourceType adManager:(MTGInterActiveManager *_Nonnull)adManager;

/**
 *  Called when there was an error loading the ad.
 *  @param error       - error object that describes the exact error encountered when loading the ad.
 */
- (void) onInterActiveLoadFailed:(nonnull NSError *)error adManager:(MTGInterActiveManager *_Nonnull)adManager;

/**
 *  Called when the ad display success
 */
- (void) onInterActiveShowSuccess:(MTGInterActiveManager *_Nonnull)adManager;

/**
 *  Called when the ad failed to display for some reason
 *  @param error       - error object that describes the exact error encountered when showing the ad.
 */
- (void) onInterActiveShowFailed:(nonnull NSError *)error adManager:(MTGInterActiveManager *_Nonnull)adManager;

/**
 *  Called when the ad is clicked
 */
- (void) onInterActiveAdClick:(MTGInterActiveManager *_Nonnull)adManager;


/**
 Called when whether the user finished playing the interactive ad or not.

 @param adManager the manager used to show the ad.
 @param completeOrNot If YES, user has finished playing otherwise NO.
 @Attention Only got this callback for `MTGInterActiveResourceTypePlayable` ad. Availabled on 4.8.0 MTGInterActiveSDKVersion or later
 */
- (void)onInterActiveAdManager:(MTGInterActiveManager *_Nonnull)adManager playingComplete:(BOOL)completeOrNot;


/**
 *  Called when the ad has been dismissed from being displayed
 */
- (void) onInterActiveAdDismissed:(MTGInterActiveManager *_Nonnull)adManager;


@end




@interface MTGInterActiveManager : NSObject



@property (nonatomic, weak) id  <MTGInterActiveDelegate> _Nullable delegate;

@property (nonatomic, readonly)   NSString * _Nonnull currentUnitId;

@property (nonatomic, weak)  UIViewController *viewController;



- (nonnull instancetype)initWithUnitID:(nonnull NSString *)unitId
                    withViewController:(nonnull UIViewController *)viewController;

/**
 *
 @method
 
 @abstract  Called when want to load the ads
 */
- (void)loadAd;


/**
 *
 @method
 
 @abstract  Called to check whether be able to show
 */
- (MTGInterActiveStatus)readyStatus;


/**
 *
 @method
 
 @abstract  Called when want to show the ads
 */
- (void)showAd;

/**
 *
 @method
 
 @abstract Called after get 'onInterActiveLoadSuccess:(MTGInterActiveResourceType)resourceType adManager:(MTGInterActiveManager *_Nonnull)adManager',  We will add a entrance icon to the view you passed. Then the user can tap the icon to show the ads view.

 @param view The view to put the entrance icon in.
 @param image The default image of the entrance icon. But the icon you set in our portal will replace the icon you set here.
 
 @discussion The entrance Icon will be exact same size with the view you passed by.
 */
- (void)loadRemoteIconToView:(nonnull UIView *)view withDefaultIconImage:(nullable UIImage *)image;


@end
