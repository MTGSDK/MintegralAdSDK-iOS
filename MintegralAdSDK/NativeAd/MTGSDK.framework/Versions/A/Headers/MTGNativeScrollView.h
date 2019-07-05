//
//  MTGNativeScrollView.h
//  MTGSDK
//
//  Created by Jomy on 16/1/28.
//

#import <UIKit/UIKit.h>
#import "MTGFrame.h"

__deprecated_msg("Delegate is deprecated.")

/*!
 @protocol MTGNativeScrollViewDelegate
 
 @abstract Messages from MTGNativeScrollView offering ads data to get custom views.
 */

@protocol MTGNativeScrollViewDelegate <NSObject>

/*!
 @method
 
 @abstract When the MTGNativeScrollView need load the custom frame view this message will be sent. Every view you created need to be added on the superview.
 @param superView Every view you created need to be added on the superview.Or they will not be displayed.
 @param nativeFrame You arrange your custom views by reading the ads in the MTGFrame object.
 @param index It indicate the index of the superview in the MTGNativeScrollView.

 */
- (void)customFrameViewWithSuperView:(nonnull UIView *)superView nativeFrame:(nonnull MTGFrame *)nativeFrame atIndex:(NSUInteger)index;

@end

__deprecated_msg("Class is deprecated.")


@interface MTGNativeScrollView : UIView

/*!
 @property
 
 @abstract The delegate
 
 @discussion All delegate method will be called in main thread.
 */
@property (nonatomic, weak, nullable) id <MTGNativeScrollViewDelegate> delegate;

/*!
 @method
 
 @abstract Returns an initialized MTGNativeScrollView.
 @param frame Frame of the MTGNativeScrollView.
 @param unitId The unitId you use to get the frames.
 
 */
- (nonnull MTGNativeScrollView *)initWithFrame:(CGRect)frame unitId:(nonnull NSString *)unitId;

/*!
 @method
 
 @abstract Use this method to pass the frames data to your MTGNativeScrollView. If you don't pass any data, the scrollview will display nothing.
 @param nativeFrames A array contains native frames (MTGFrame).
 
 */
- (void)setDataList:(nonnull NSArray *)nativeFrames;


@end
