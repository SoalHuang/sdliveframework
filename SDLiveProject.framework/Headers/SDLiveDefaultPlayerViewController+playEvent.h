//
//  SDLiveDefaultPlayerViewController+playEvent.h
//  SDLiveProject
//
//  Created by ln on 2020/3/20.
//


#import "SDLiveDefaultPlayerViewController.h"


NS_ASSUME_NONNULL_BEGIN

@protocol SDLiveManagerDelegate;
@protocol SDLiveIMDelegate;

@interface SDLiveDefaultPlayerViewController  (playEvent) <SDLiveManagerDelegate, SDLiveIMDelegate>
/**
 时间回调

 @param manager SDLiveManager
 @param duration 视频总时长
 @param currentPlayTime 当前播放时长
 @param cachedDuration 已缓存的视频时长
 @param sequence 同步序列
 */
- (void)manager:(SDLiveManager* _Nonnull)manager
       duration:(NSTimeInterval)duration
currentPlayTime:(NSTimeInterval)currentPlayTime
cacheVideoDuration:(NSTimeInterval)cachedDuration
       sequence:(NSTimeInterval)sequence;

/**
 播放器状态回调

 @param manager SDLiveManager
 @param state 状态，包括暂停、加载、播放等状态
 */
- (void)manager:(SDLiveManager* _Nonnull)manager
      playState:(SDLiveMoviePlaybackState)state;

//播放器加载状态回调
- (void)manager:(SDLiveManager* _Nonnull)manager
      loadState:(SDLiveMovieLoadState)state;

//播放器错误回调，播放器播放遇到错误，包括IJKPlayer自身的bug、拉流链接错误等，会触发。
//仅展示不用处理
- (void)manager:(SDLiveManager* _Nonnull)manager
    onPlayError:(NSError* _Nullable)error;

//websocket状态回调，可忽略
- (void)manager:(SDLiveManager* _Nonnull)manager
onWebSocketState:(SDSocketState)state;

//直播/点播场景下，外部传入的token认证失败的错误
- (void)manager:(SDLiveManager* _Nonnull)manager
    authOnError:(NSError* _Nullable)error;

/**
 直播间异常回调

 @param manager SDLiveManager
 @param error 错误对象，userInfo里为附加信息
 */
- (void)manager:(SDLiveManager* _Nonnull)manager
        onError:(NSError* _Nullable)error;

/**
 房间信息回调

 @param manager SDLiveManager
 @param roomInfo 房间信息类，包含房间名称、老师名称等信息
 */
- (void)manager:(SDLiveManager* _Nonnull)manager
       roomInfo:(SDLiveRoomInfo* _Nonnull)roomInfo;

/**
 直播间事件回调

 @param manager SDLiveManager
 @param event 事件，【开始直播、结束直播、暂停直播、恢复直播】
 @param message 附加信息
 */
- (void)managerLiveEventOccur:(SDLiveManager* _Nonnull)manager
                        event:(SDLiveRoomEvent)event
                      message:(NSString* _Nullable)message;

/**
 用户进入/离开直播间事件回调

 @param manager SDLiveManager
 @param event 进入/离开事件
 @param info NSDictionary
 */
- (void)managerLivePeopleEventOccur:(SDLiveManager* _Nonnull)manager
                              event:(SDLiveRoomPeopleEvent)event
                               info:(NSDictionary* _Nullable)info;

//收到教师端发起的随堂考事件
- (void)managerLive:(SDLiveManager* _Nonnull)manager
 beginExamWithPaper:(SDLivePaperModel* _Nullable)paper;


/**
 直播间人数发生变化

 @param manager SDLiveManager
 @param userCount 直播间总人数
 */
- (void)managerLive:(SDLiveManager* _Nonnull)manager
 userCountDidChange:(NSInteger)userCount;

/**
 当前视频流播放类型变化
 UrlSteamType 分为 老师摄像头 共享桌面 共享视频
 @param manager SDLiveManager
 @param type UrlSteamType
 */
- (void)manager:(SDLiveManager* _Nonnull)manager
didChangeStreamUrl:(UrlSteamType)type;

/// 商品推广消息【该方法仅在直播下触发】
/// @param manager SDLiveManager
/// @param goods 商品数组,element为nsdictionary，包含id、name、pictureUrl、locateUrl等key
/// @param operate 0 开启推广，1 关闭推广
-(void)manager:(SDLiveManager* _Nonnull)manager
didReceiveGoods:( NSArray* _Nullable)goods
       operate:(NSInteger)operate;

/// 商品推广消息【该方法仅在点播下触发】
/// @param manager SDLiveManager
/// @param originGoodsInfo 字典数组
/** originGoodsInfo 结构如下
  (
  {
      data =     (
                  {
              id = 19;
              locateUrl = "http://cn.bing.com";
              name = name3;
              pictureUrl = "https://test-sfs-public.shangdejigou.cn/SunlivePromote/aaa3";
          },
                  {
              id = 20;
              locateUrl = "http://cn.bing.com";
              name = name4;
              pictureUrl = "https://test-sfs-public.shangdejigou.cn/SunlivePromote/aaa4";
          }
      );
      lSequence = 1581942366849;
      operate = 1;
  },
  {
      data =     (
                  {
              id = 19;
              locateUrl = "http://cn.bing.com";
              name = name3;
              pictureUrl = "https://test-sfs-public.shangdejigou.cn/SunlivePromote/aaa3";
          },
                  {
              id = 20;
              locateUrl = "http://cn.bing.com";
              name = name4;
              pictureUrl = "https://test-sfs-public.shangdejigou.cn/SunlivePromote/aaa4";
          }
      );
      lSequence = 1581942499606;
      operate = 0;
  }
  )
 */
-(void)manager:(SDLiveManager* _Nonnull)manager
didReceiveOriginGoodsInfo:( NSArray* _Nullable)originGoodsInfo;

//事件信息,暂时忽略

- (void)manager:(SDLiveManager* _Nonnull)manager
          event:(id _Nullable)event;


/**
 课件加载回调，加载失败的时候，业务方可以考虑增加重试按钮，重新加载课件
 加载恢复正常的时候，业务方可以隐藏重试按钮

 @param status SDLiveImageLoadStatus
                - SDLiveImageLoadStatusFailed: 加载失败
                - SDLiveImageLoadStatusNormal: 加载恢复正常
 */
-(void)manager:(SDLiveManager* _Nonnull)manager
    didChangeImageStatus:(SDLiveImageLoadStatus)status;
 
/*
 IM 错误码，对应代理返回的 result 变量
 0 : 服务器返回正确；
 1 : 数据库错误；
 2 : 入参错误；
 3 : 直播间不存在；
 4 : json解析错误；
 5 : 直播间不存在改成员；
 6 : 直播间禁言；
 7 : 敏感词屏蔽；
 8 : 非注册用户；
 9 : 用户无操作权限；
 10 : 直播间满员；
 11: 直播间用户被单独禁言
 12： 学生已经被踢出直播间
 13：消息超过长度限制(140汉字)。
 14： 发送消息频率超过最大频率
 15： 第三方签名校验错误
 16： 第三方合作方id不存在
 */

/**
 收到服务端发来的新消息
 
 @param messages 消息列表
 */
-(void)didReceiveMessageList:(NSArray<SDLiveIMMessageModel*>* _Nullable)messages;


/**
 收到服务端发来的公告

 @param announce 公告模型
 */
-(void)didReceiveAnnounce:(SDLiveIMAnnounceModel* _Nonnull)announce;

/**
 聊天室登录成功，返回基本的聊天室信息，如登录人员信息、禁言状态、聊天室人数、登录token等
 用户登录之后会返回部分之前的消息
 当app长链接断开重连的时候，也会调用该方法，所以需要注意登录返回的消息会重复。
 
 @param model SDLiveIMChatRoomModel
 
 @param result 错误码
 */
-(void)didLogin:(SDLiveIMChatRoomModel* _Nonnull)model
    MessageList:(NSArray<SDLiveIMMessageModel*>* _Nullable)messages
     withResult:(NSInteger)result;

/**
 消息发送成功，返回发送成功的消息

 @param message 聊天消息数据
 
 @param result 错误码
 */
-(void)didSendMessage:(SDLiveIMMessageModel* _Nonnull)message
           withResult:(NSInteger)result;

/**
 * 聊天室解散通知，客户端无需重连
 * */
- (void)didChatRoomClose;

/**
 用户批量下线通知，聊天人数变更

 @param number 剩余聊天人数
 */
- (void)didChatRoomBatchOffline:(NSInteger)number;

/**
 用户进入、退出聊天室回调，会返回聊天室当前人数、以及退出用户的信息

 @param event SDLiveIMChatRoomEvent
 */
- (void)didRoomUserEvent:(SDLiveIMChatRoomEvent* _Nonnull)event;

/**
 用户同一时间只会在一个直播间内，重复登录会给前一个连接发送被踢通知看，同时将前一个连接关掉
 客户端收到踢人通知，websocket无需重连，该token用户被踢了

 @param userToken 被挤下线的用户token
 */
- (void)didChatRoomKickOffUser:(NSString* _Nonnull)userToken;

/**
 * 全体禁言，收到禁言/解禁 通知，禁止或允许用户发送信息，
 * status false：不禁言，true：禁言
 * */
- (void)didChatRoomForbiddenStatusChange:(Boolean)status;

/**
 * 个人禁言，收到禁言/解禁 通知，禁止或允许用户发送信息，
 * status false：不禁言，true：禁言
 * */
- (void)didChatRoomDidForbiddenUserTalk:(Boolean)status;

/**
 
 该通知用于老师或者助教更新本地的学员大表和被踢用户列表。
 1. 老师或者助教主动将某个学员踢出直播间, 该通知会发送给被踢人以及其他的老师或者助教。
 2. 老师或者助教主动将某个学员取消踢人状态，该通知会发送给其他老师或者助教。
 @param status false：不禁言，true：禁言
 */
- (void)didChatRoomDidUserBeKickOff:(Boolean)status;


/**
 收到服务端发来的消息体
 错误信息：
 cmd=4，result=14，两秒太频繁了【需提示用户】
 
 @param response 消息体
 */
-(void)didReceiveResponse:(SDLiveIMResponse* _Nonnull)response;
@end

NS_ASSUME_NONNULL_END
