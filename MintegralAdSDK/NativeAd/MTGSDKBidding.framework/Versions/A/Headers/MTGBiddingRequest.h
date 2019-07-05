//
//  MTGBiddingRequest.h
//  MTGSDKBidding
//
//  Created by apple on 2019/4/19.
//  Copyright © 2019 Mintegral. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MTGSDK/MTGSDK.h>
#import "MTGBiddingHeader.h"
#import "MTGBiddingResponse.h"


NS_ASSUME_NONNULL_BEGIN

@interface MTGBiddingRequest : NSObject

/**
 Get Mintegral Bid for current ad unit

 @param basePrice  The optional value provided to this method should be double,the requested bid should not be lower than this price if use this value
 */

+(void)getBidWithUnitId:(nonnull NSString *)unitId basePrice:(nullable NSNumber *)basePrice completionHandler:(void(^)(MTGBiddingResponse *bidResponse))completionHandler;

@end

NS_ASSUME_NONNULL_END
