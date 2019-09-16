//
//  MTGBiddingSDK.h
//  MTGSDKBidding
//
//  Created by Harry on 2019/5/9.
//  Copyright © 2019 Mintegral. All rights reserved.
//

#import <Foundation/Foundation.h>

#define MTGBiddingSDKVersion @"5.7.1"

@interface MTGBiddingSDK : NSObject

/* BuyerUID is required when you decide to request a bid response on your own server. */
+ (NSString *)buyerUID;

@end

