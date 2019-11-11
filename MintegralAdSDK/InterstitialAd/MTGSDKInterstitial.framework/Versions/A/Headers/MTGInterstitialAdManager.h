//
//  MTGInterstitialAdManager.h
//  MTGSDK
//
//  Created by CharkZhang on 2016/11/8.
//

#define MTGInterstitialSDKVersion @"5.8.4"

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, MTGInterstitialAdCategory) {
    MTGInterstitial_AD_CATEGORY_ALL  = 0,
    MTGInterstitial_AD_CATEGORY_GAME = 1,
    MTGInterstitial_AD_CATEGORY_APP  = 2,
};

@class MTGInterstitialAdManager;

#pragma mark - MTGInterstitialAdManagerDelegate

/**
 *  This protocol defines a listener for ad Interstitial load events.
 */
@protocol MTGInterstitialAdLoadDelegate <NSObject>

@optional
/**
 *  Sent when the ad is successfully load , and is ready to be displayed
 */
- (void) onInterstitialLoadSuccess DEPRECATED_ATTRIBUTE;
- (void) onInterstitialLoadSuccess:(MTGInterstitialAdManager *_Nonnull)adManager;

/**
 *  Sent when there was an error loading the ad.
 *
 *  @param error An NSError object with information about the failure.
 */
- (void) onInterstitialLoadFail:(nonnull NSError *)error DEPRECATED_ATTRIBUTE;
- (void) onInterstitialLoadFail:(nonnull NSError *)error adManager:(MTGInterstitialAdManager *_Nonnull)adManager;


@end


/**
 *  This protocol defines a listener for ad Interstitial show events.
 */
@protocol MTGInterstitialAdShowDelegate <NSObject>

@optional
/**
 *  Sent when the Interstitial success to open
 */
- (void) onInterstitialShowSuccess DEPRECATED_ATTRIBUTE;
- (void) onInterstitialShowSuccess:(MTGInterstitialAdManager *_Nonnull)adManager;

/**
 *  Sent when the Interstitial failed to open for some reason
 *
 *  @param error An NSError object with information about the failure.
 */
- (void) onInterstitialShowFail:(nonnull NSError *)error DEPRECATED_ATTRIBUTE;
- (void) onInterstitialShowFail:(nonnull NSError *)error adManager:(MTGInterstitialAdManager *_Nonnull)adManager;


/**
 *  Sent when the Interstitial has been clesed from being open, and control will return to your app
 */
- (void) onInterstitialClosed DEPRECATED_ATTRIBUTE;
- (void) onInterstitialClosed:(MTGInterstitialAdManager *_Nonnull)adManager;


/**
 *  Sent after the Interstitial has been clicked by a user.
 */
- (void) onInterstitialAdClick DEPRECATED_ATTRIBUTE;
- (void) onInterstitialAdClick:(MTGInterstitialAdManager *_Nonnull)adManager;




@end



@interface MTGInterstitialAdManager : NSObject


@property (nonatomic, readonly)   NSString * _Nonnull currentUnitId;


/**
 *  Initialize the native ads manager.
 *
 *  @param unitId         The id of the ad unit. You can create your unit id from our Portal.
 *  @param adCategory     Decide what kind of ads you want to retrieve. Games, apps or all of them. The default is All.
 */
- (nonnull instancetype)initWithUnitID:(nonnull NSString *)unitId
                            adCategory:(MTGInterstitialAdCategory)adCategory;

/**
 *  Called when load the Interstitial
 *
 *  @param delegate reference to the object that implements MTGInterstitialAdLoadDelegate protocol; will receive load events for the given unitId.
 */
- (void)loadWithDelegate:(nullable id <MTGInterstitialAdLoadDelegate>) delegate;

/**
 *  Called when show the Interstitial
 *
 *  @param delegate       reference to the object that implements MTGInterstitialAdShowDelegate protocol; will receive show events for the given unitId.
 
 *  @param viewController The UIViewController that will be used to present Interstitial Controller. If not set, it will be the root viewController of your current UIWindow. But it may failed to present our Interstitial controller if your rootViewController is presenting other view controller. So set this property is necessary.

 */
- (void)showWithDelegate:(nullable id <MTGInterstitialAdShowDelegate>)delegate presentingViewController:(nullable UIViewController *)viewController;



@end
