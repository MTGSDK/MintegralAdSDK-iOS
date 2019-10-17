//
//  MTGBiddingRequestParameter.h
//  MTGSDKBidding
//
//  Created by Lee on 2019/9/30.
//  Copyright © 2019 Mintegral. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MTGBiddingRequestParameter : NSObject


@property(nonatomic,copy,readonly)NSString *unitId;

@property(nonatomic,readonly)NSNumber *basePrice;

/**
 Initialize an MTGBiddingRequestParameter object
 @param unitId unitId
 @param basePrice The optional value provided to this method should be double,the requested bid should not be lower than this price if use this value
 */
- (instancetype)initWithUnitId:(nonnull NSString *) unitId
                     basePrice:(nullable NSNumber *)basePrice;

@end

NS_ASSUME_NONNULL_END
