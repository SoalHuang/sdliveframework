//
//  SDLiveChatView.h
//  SDLiveProject
//
//  Created by ln on 2020/3/16.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@class SDLiveIMMessageModel;

@protocol SDLiveChatViewDelegate <NSObject>

@optional
- (void)hitChatView;
@end


/// 消息视图，横竖屏下都会使用这个控件
@interface SDLiveChatView : UIView

/// 设置控件显示是否是垂直或横屏全屏，YES：是竖屏，非全屏；NO：是横屏，全屏。
@property(assign, nonatomic) BOOL isOrientationVertical;

@property(weak, nonatomic) id<SDLiveChatViewDelegate> delegate;

/// 增加消息
/// @param message 增加IM消息
- (void)appendMesage:(SDLiveIMMessageModel *)message;


/// 重新刷新视图。
- (void)reload;

@end

NS_ASSUME_NONNULL_END
