//
//  MTGBool.h
//  MTGSDK
//
//  Created by lee on 2019/7/18.
//  Copyright © 2019 Mintegral. All rights reserved.
//

/**
 Tri-state boolean.
 */
typedef NS_ENUM(NSInteger, MTGBool) {
    /**
     No
     */
    MTGBoolNo = -1,
    
    /**
     Unknown
     */
    MTGBoolUnknown = 0,
    
    /**
     Yes
     */
    MTGBoolYes = 1,
};

