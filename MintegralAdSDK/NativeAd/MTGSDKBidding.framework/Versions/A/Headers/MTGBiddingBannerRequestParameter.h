//
//  MTGBiddingBannerRequestParameter.h
//  MTGSDKBidding
//
//  Created by lee on 2019/10/9.
//  Copyright © 2019 Mintegral. All rights reserved.
//

#import "MTGBiddingRequestParameter.h"
#import <MTGSDK/MTGAdSize.h>

NS_ASSUME_NONNULL_BEGIN
@interface MTGBiddingBannerRequestParameter : MTGBiddingRequestParameter
/**
    banner unit size
 */
@property(nonatomic,assign,readonly)CGSize unitSize;

/**
  Initialize an MTGBiddingBannerRequestParameter object
  @param unitId unitId
  @param basePrice The optional value provided to this method should be double,the requested bid should not be lower than this price if use this value
  @param unitSize banner unit size
 */
- (instancetype)initWithUnitId:(nonnull NSString *) unitId
                     basePrice:(nullable NSNumber *)basePrice
                      unitSize:(CGSize)unitSize;

/**
 Initialize an MTGBiddingBannerRequestParameter object
 @param unitId unitId
 @param basePrice The optional value provided to this method should be double,the requested bid should not be lower than this price if use this value
 @param unitSize MTGBannerSizeTypeFormat
*/
- (instancetype)initWithUnitId:(nonnull NSString *) unitId
                     basePrice:(nullable NSNumber *)basePrice
                bannerSizeType:(MTGBannerSizeType)bannerSizeType;
@end

NS_ASSUME_NONNULL_END
