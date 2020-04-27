//
//  SDLiveDefaultPlayerView.h
//  SDLiveProject
//
//  Created by ln on 2020/3/12.
//

#import <UIKit/UIKit.h>

#import "SDLiveManager.h"

NS_ASSUME_NONNULL_BEGIN

@class SDLiveConverView;
@class SDLiveIMChatRoomModel;
@class SDLiveChatView;
@class SDLiveMessageInputBar;
@class SDLiveHorizontalScrollText;
@class SDLiveAnnouncementView;

@class SDLiveDefaultPlayerViewController;

@protocol SDLiveDefaultPlayerViewControllerDelegate <NSObject>
///  默认播放页面代理
/// @param vc 默认的播放页面
/// @param errorInfo 需在UI上提示的错误信息
- (void)statusShowErrorUI:(SDLiveDefaultPlayerViewController *)vc error: (NSString *)errorInfo;

@end


/// 默认的播放控制器页面
@interface SDLiveDefaultPlayerViewController : UIViewController

@property (nonatomic, weak) id<SDLiveDefaultPlayerViewControllerDelegate> delegate;

@property (nonatomic,assign) BOOL isFirstLogin;
@property (nonatomic,assign) SDVideoType videoType;

//控制
@property(assign, nonatomic) BOOL isLiving;

@property(assign, nonatomic) UrlSteamType type;

@property (nonatomic,strong) SDLiveManager* liveManager;

//直播的用户信息
@property (nonatomic,strong) SDLiveIMChatRoomModel* userModel;

/// ppt视图
@property (nonatomic,strong) UIView* pageView;
/// 直播视图
@property(readonly, nonatomic) UIView *livePlayerView;

//聊天列表视图
@property (nonatomic, readonly) SDLiveChatView * messageChatView;
//聊天输入框视图
@property (nonatomic, readonly) SDLiveMessageInputBar * inputBar;
//控制视图以及遮罩视图
@property(nonatomic, readonly) SDLiveConverView *coverView;

//滚动通知视图
@property (nonatomic, readonly) SDLiveHorizontalScrollText * notifyScrollText;
//公告视图
@property (nonatomic, readonly) SDLiveAnnouncementView *announcementView;


- (instancetype)initWithLiveView:(nonnull UIView *)liveView;

///  增加IM消息
/// @param message 直播、点播消息
- (void)appendMesage:(SDLiveIMMessageModel *)message;

/// 接收到公告消息
/// @param announce 公告消息
- (void)receiveAnnounce:(SDLiveIMAnnounceModel *)announce;

/// 设置视图标题
/// @param title 标题
-(void)setVideoTitle: (NSString *)title;

/// 设置直播视图类型
/// @param type 直播视图类型
- (void)setLiveWindowType:(UrlSteamType)type;

//状态
- (void)setLodingImgName:(NSString *)name info :(NSString *)info;
- (void)setLodingImgName:(NSString *)name
                   info :(NSString *)info
                 isAnim : (BOOL) isAnim;

- (void)statusPause;
- (void)statusPlay;

- (void)removePromptView;

- (void)statusShowError:(NSString *)errorInfo;

- (void)showLoadingBufferView;
//隐藏大菊花转
- (void)hiddenLoadingBufferView;

#pragma mark - Question
- (void)showQuestionType:(int)type optionCount:(int)optionCount answer:(NSString*)answer sequence:(NSNumber* _Nonnull)lSequence;

- (void)showQuestionWarning:(NSNumber *)warningReason sequence:(NSNumber* _Nonnull)lSequence;
@end

NS_ASSUME_NONNULL_END
