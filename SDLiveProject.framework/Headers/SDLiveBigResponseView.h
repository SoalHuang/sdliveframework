//
//  SDLiveBigResponseView.h
//  SDLiveProject
//
//  Created by ln on 2020/3/24.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SDLiveBigResponseViewDelegate <NSObject>

@optional
- (void)responseEnd;
@end

@interface SDLiveBigResponseView : UIView

@property(nonatomic, weak)id<SDLiveBigResponseViewDelegate> delegate;
@end

NS_ASSUME_NONNULL_END
