//
//  MTGSDK.h
//  MTGSDK
//
//  Created by Jomy on 15/9/28.
//


#define MTGSDKVersion @"5.5.0"

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MTGSDK/MTGNativeAdManager.h>
#import <MTGSDK/MTGBidNativeAdManager.h>
#import <MTGSDK/MTGCampaign.h>
#import <MTGSDK/MTGTemplate.h>
#import <MTGSDK/MTGFrame.h>
#import <MTGSDK/MTGNativeScrollView.h>
#import <MTGSDK/MTGMediaView.h>
#import <MTGSDK/MTGUserInfo.h>


@interface MTGSDK : NSObject


/**
 * The shared instance of the SDK.
 *
 * @return The SDK singleton.
 */
+ (nonnull instancetype)sharedInstance;

/**
 * Set the AppID and ApiKey.
 *  This must be called after set the authorization of user privacy information collection if you need to keep GDPR terms.
 *  This must be called before any ads are requested .
 *
 * @param appID  T application Id registered on the our portal.
 * @param apiKey The API Key generated on the our Portal.
 */
- (void)setAppID:(nonnull NSString *)appID ApiKey:(nonnull NSString *)apiKey;

/**
 *
 @method
 
 @abstract The method that kicks off the preloading of native ads. It may be called again in the future to refresh the ads manually.
 
 @param unitId The id of the ad unit. You can create your unit id from our Portal.
 
 @param fbPlacementId The Facebook PlacementID is used to request ads from Facebook. You can also set the placementID in our portal. The ID you set in our web portal will replace the ID you set here in future.
 @param numAdsRequested The number of ads you would like to preload. Max number is 10. If you pass any number bigger than 10, it will be reset to 10.
 */
- (void)preloadNativeAdsWithUnitId:(nonnull NSString *)unitId
                     fbPlacementId:(nullable NSString *)fbPlacementId
                forNumAdsRequested:(NSUInteger)numAdsRequested;

/**
 *
 @method
 
 @abstract The method that kicks off the preloading of native ads. It may be called again in the future to refresh the ads manually.
 
 @param unitId The id of the ad unit. You can create your unit id from our Portal.
 
 @param fbPlacementId The Facebook PlacementID is used to request ads from Facebook. You can also set the placementID in our portal. The ID you set in our web portal will replace the ID you set here in future.
 
 @param videoSupport If the support video ads, set videoSupport  to yes.
 
 @param numAdsRequested The number of ads you would like to preload. Max number is 10. If you pass any number bigger than 10, it will be reset to 10.
 */
- (void)preloadNativeAdsWithUnitId:(nonnull NSString *)unitId
                     fbPlacementId:(nullable NSString *)fbPlacementId
                     videoSupport:(BOOL)videoSupport
                forNumAdsRequested:(NSUInteger)numAdsRequested;

/**
 *
 @method
 
 @abstract The method that kicks off the preloading of native ads. It may be called again in the future to refresh the ads manually.
 
 @param unitId The id of the ad unit. You can create your unit id from our Portal.
 @param fbPlacementId The Facebook PlacementID is used to request ads from Facebook. You can also set the placementID in our portal. The ID you set in our web portal will replace the ID you set here in future.
 @param templates This array contains objects of MTGTemplate. See more detail in definition of MTGTemplate.
 @param autoCacheImage If you pass YES, SDK will download the image resource automatically when you get the campaign.
 @param adCategory Decide what kind of ads you want to retrieve. Games, apps or all of them. The default is All.
 */
- (void)preloadNativeAdsWithUnitId:(nonnull NSString *)unitId
                     fbPlacementId:(nullable NSString *)fbPlacementId
                supportedTemplates:(nullable NSArray *)templates
                    autoCacheImage:(BOOL)autoCacheImage
                        adCategory:(MTGAdCategory)adCategory;
/**
 *
 @method
 
 @abstract The method that kicks off the preloading of native frames. It may be called again in the future to refresh the frames manually.
 
 @param unitId The id of the ad unit. You can create your unit id from our Portal.
 @param fbPlacementId The Facebook PlacementID is used to request ads from Facebook. You can also set the placementID in our portal. The ID you set in our web portal will replace the ID you set here in future.
 @param templates This array contains objects of MTGTemplate. See more detail in definition of MTGTemplate.
 @param autoCacheImage If you pass YES, SDK will download the image resource automatically when you get the campaign.
 @param adCategory Decide what kind of ads you want to retrieve. Games, apps or all of them. The default is All.
 @param frameNum The number of frames you would like to preload. Max number is 10. If you pass any number bigger than 10, it will be reset to 10.
 */
- (void)preloadNativeFramesWithUnitId:(nonnull NSString *)unitId
                        fbPlacementId:(nullable NSString *)fbPlacementId
              supportedFrameTemplates:(nullable NSArray *)templates
                       autoCacheImage:(BOOL)autoCacheImage
                           adCategory:(MTGAdCategory)adCategory
                             frameNum:(NSUInteger)frameNum DEPRECATED_ATTRIBUTE;

/**
 *
 @method
 
 @abstract The method that kicks off the preloading of app wall ads. It may be called again in the future to refresh the ads manually.
 
 @param unitId The id of the ad unit. You can create your unit id from our Portal.
 */
- (void)preloadAppWallAdsWithUnitId:(nonnull NSString *)unitId;


@property (nonatomic, assign) BOOL autoSetAudioCategory;

/**
 Set user GDPR authorization information
 
 Set YES to indicate the user's data will be collected otherwise NO. Default to be YES.
 
@abstract According to the GDPR, set method of this property must be called before "setAppID: ApiKey:", or by default will collect user's information.
@Attention Do not mix the usage of `setConsentStatus:` and `setUserPrivateInfoType:agree` simultaneously in your app.
 */
@property (nonatomic, assign) BOOL consentStatus;

- (void)setUserInfo:(nonnull MTGUserInfo *)userInfo;

/**
 Show the privacy consent authorization tips view.
 
 @abstract This method must be called before "setAppID: ApiKey:", Or by default will collect user information.

 @param callback A block that accepts a Bool and an NSError as input parameters. The NSError parameter which provides information on a failed consent update request, the Bool parameter which provides the updated consent status.
 */
- (void)showConsentInfoTips:(nullable void (^)(BOOL consentStatus, NSError *_Nullable error))callback;


/**
 *
 @method Set user GDPR authorization information
 
 @abstract According to the GDPR, this method must be called before "setAppID: ApiKey:", or by default will collect user information;
 
 @param type The type of the data that you want to configure.
 
 @param agree whether this type of data should be collect.
 */
- (void)setUserPrivateInfoType:(MTGUserPrivateType)type agree:(BOOL)agree DEPRECATED_MSG_ATTRIBUTE("Use `[MTGSDK sharedInstance] setConsentStatus:` instead");

/**
 *
 @method
 
 @abstract You can get all status for current 'MTGUserPrivateType' by using this method.
 */
- (MTGUserPrivateTypeInfo *_Nonnull)userPrivateInfo DEPRECATED_MSG_ATTRIBUTE("Use `[MTGSDK sharedInstance] consentStatus` instead");

/**
 *
 @method Show the privacy authorization tips view
 
 @abstract This method must be called before "setAppID: ApiKey:", Or by default will collect user information;
 Authorization tips view is added upon the "window”, don't cover it.
 @param block result block.
 */
- (void)showUserPrivateInfoTips:(MTGUserPrivateInfoTipsResultBlock _Nonnull )block DEPRECATED_MSG_ATTRIBUTE("Use `[MTGSDK sharedInstance] showConsentInfoTips:` instead");


@end
