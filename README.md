# SDLiveProject

SDLiveProject 是尚直播的 iOS 端 SDK ，可以观看尚直播平台的直播以及点播，集成方便。

## 功能
- [x] 在线观看直播
- [x] 发送弹幕
- [x] 在线观看点播
- [x] 离线观看点播
- [x] 获取音频文件下载链接
- [x] 在线观看碎片化视频

## 安装条件
- iOS7.0 +
- [CocoaPods](https://cocoapods.org)

## 2.安装
在 `Podfile` 添加
* 持续获取最新版本

```ruby
pod 'SDLiveFramework',:git=>'https://github.com/xingchen-src/sdliveframework.git'
```

* 稳定版本 

```ruby
pod 'SDLiveFramework',:git=>'https://github.com/xingchen-src/sdliveframework.git',:tag=>'1.1.7'
```
 
> **如果主工程有引入欢拓**，请在安装尚直播之后测试欢拓功能是否正常，有问题请联系[尚直播技术人员 huangyaqing@sunlands.com](huangyaqing@sunlands.com)

## 3.使用方法

  ### - 环境配置，在调用初始化方法之前配置

  ```objective-c
  //SDLiveConfigDevelop 开发环境【内部环境】
  //SDLiveConfigQA 测试环境
  //SDLiveConfigProduct 生产环境
  [SDLiveManager setConfigType:SDLiveConfigProduct];
  ```

  ### - 初始化

```objective-c
//初始化环境
[SDLiveManager setConfigType:SDLiveConfigProduct];
//初始化登录实例
SDLiveLoginInfoModel* model =  [[SDLiveLoginInfoModel alloc] init];
model.roomId = 1010;
model.userId = @"userId";
model.userRole = SDLiveUserRoleStudent;
model.userName = @"jack";
model.partnerId = @"partnerId";
model.terminalType = SDLiveClientIOSType;
model.ts = ceil([[NSDate date] timeIntervalSince1970]);
model.userAvatar = @"headUrl";
model.sign = @"xxxxxx";

//初始化直播Manager，如果是点播，则传入SDLiveVideoType
self.liveManager = [[SDLiveManager alloc] initLiveWith:model type:SDVideoLiveType]; 
//配置直播代理
self.liveManager.delegate = self;
//配置弹幕代理
self.liveManager.imDelegate = self;
//对播放器进行布局
[self.view addSubview:self.liveManager.playerView];
//对课件进行布局
[self.view addSubview:self.liveManager.pageView];
 
//播放
[self.liveManager play];
```

### - 基础功能
   
 发送弹幕【直播】

  ```objective-c
  [self.liveManager sendMessage: @"hello,world!"];
  ```
   
  暂停播放【点播】

  ```objective-c
  [self.liveManager pause];
  ```
  
  继续播放【点播】

  ```objective-c
  [self.liveManager resume];
  ```
    
  停止播放，停止之后，无法恢复播放，会释放相关的内存
  一般情况下，在控制器销毁的时候，不用调用该方法
  在SDLiveManager的dealloc方法里，内部会调用该方法

  ```objective-c
  [self.liveManager stop];
  ```
 
  拖拽播放，内部会对time做floor(time)处理，比如上次播放到10s了，这次需要继续在10s处播放【点播】

  ```objective-c
  [self.liveManager dragTo:10];
  ```

  调整倍速，点播下可用【点播】
  
  ```objective-c
  self.liveManager.playSpeed = 1.5;
  ```

### - 主要的直播间代理回调方法`SDLiveManagerDelegate`

```objective-c
/**
 时间回调

 @param manager
 @param duration 视频总时长
 @param currentPlayTime 当前播放时长
 @param cachedDuration 已缓存的视频时长
 */
- (void)manager:(SDLiveManager*)manager
       duration:(NSTimeInterval)duration
currentPlayTime:(NSTimeInterval)currentPlayTime
cacheVideoDuration:(NSTimeInterval)cachedDuration;

/**
 播放器状态回调

 @param manager
 @param state 状态，包括暂停、加载、播放等状态
 */
- (void)manager:(SDLiveManager*)manager
      playState:(SDLiveMoviePlaybackState)state;
 
/**
 房间信息回调

 @param manager
 @param roomInfo 房间信息类，包含房间名称、老师名称等信息
 */
- (void)manager:(SDLiveManager*)manager
       roomInfo:(SDLiveRoomInfo*)roomInfo;
       
/**
 直播间事件回调

 @param manager
 @param event 事件，【开始直播、结束直播、暂停直播、恢复直播】
 @param message 附加信息
 */
- (void)managerLiveEventOccur:(SDLiveManager*)manager
                        event:(SDLiveRoomEvent)event
                      message:(NSString*)message;

/**
 直播间异常回调

 @param manager
 @param error 错误对象，userInfo里为附加信息
 */
- (void)manager:(SDLiveManager*)manager
        onError:(NSError*)error;
```

### - 主要的弹幕代理回调方法`SDLiveIMDelegate`

``` 
 IM 错误码，登录以及发送消息代理返回的 result 变量
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
```

```objective-c
/**
 收到服务端发来的新消息
 
 @param messages 消息列表
 */
-(void)didReceiveMessageList:(NSArray<SDLiveIMMessageModel*>*)messages;

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
 用户批量下线通知，聊天人数变更

 @param number 剩余聊天人数
 */
- (void)didChatRoomBatchOffline:(NSInteger)number;
  
/**
 用户进入、退出聊天室回调，会返回聊天室当前人数、以及退出用户的信息

 @param event SDLiveIMChatRoomEvent
 */
- (void)didRoomUserEvent:(SDLiveIMChatRoomEvent*)event;

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
```



### - 高级功能
#### 离线播放
1. 原理
  - 通过[原生后台下载](https://developer.apple.com/documentation/foundation/url_loading_system/downloading_files_in_the_background)的方式将视频以及事件、图片资源下载到本地。
  - 下载完毕之后，使用点播方式进行播放即可。如果已经离线完毕，SDK会使用离线数据进行播放，否则使用线上数据。
2. 开始下载
  - SDK提供两种方式，一种平台化下载，一种尚直播下载，尚直播的方式在以后会被废弃掉。
  - 如果该直播正在下载中，或者已经下载完毕，或者传入参数错误，则在初始化的时候会返回错误，可以根据对应的`SUNLAND_SDK_DOWNLOAD_LIVE_ERROR`来处理错误。
``` objective-c
  /// 尚直播下载方法 
  NSError* error = [[SDLiveDownloadManager shared] downloadWith:liveId withToken:self.token.text andChannelCode:self.channelCode.text];
  if (error != nil) {
      //handle initial error;
  }

  /// 平台化下载方法 
  NSError* error = [[SDLiveDownloadManager shared] downloadWithPlatInfo:model];
  if (error != nil) {
    //handle initial error;
  }
```
3. ⚠️注意的点, 在`APPDelegate`下的回调`handleEventsForBackgroundURLSession` 里添加该方法。

```objective-c
 - (void)application:(UIApplication *)application handleEventsForBackgroundURLSession:(NSString *)identifier completionHandler:(void (^)(void))completionHandler{
    [[SDLiveDownloadManager shared] handleEventsForBackgroundURLSession:identifier completionHandler:completionHandler];
 }
```

4. 操作方法
  * 暂停
  
  ```objective-c
  /// 暂停下载，如传入的roomId不在下载列表里，不会做任何操作；
/// 对下载已经完毕或者被暂停不生效
/// @param roomId 直播间ID
- (void)pauseWithRoomId:(NSInteger)roomId;
  ```
  * 恢复
```objective-c
/// 恢复下载，如传入的roomId不在下载列表里，不会做任何操作
/// 对下载已经完毕或者被暂停不生效
/// @param roomId 直播间ID
- (void)resumeWithRoomId:(NSInteger)roomId;
```
* 停止
```objective-c
/// 停止下载，如传入的roomId不在下载列表里，不会做任何操作
/// @param roomId 直播间ID
- (void)stopWithRoomId:(NSInteger )roomId;
 ```
* 可以删除掉已经下载完毕的直播
 ```objective-c
/// 删除某个已经完成的下载，可用于清除缓存，如传入的roomId不在下载列表里，不会做任何操作
/// 仅对下载完毕的下载项生效
/// @param roomId 直播间ID
- (void)removeCachesWithRoomId:(NSInteger )roomId;
```

* 获取下载列表，`SDLiveDownloadItem`包含下载状态以及直播间等信息
```objective-c
/// 获取下载列表
- (NSArray<SDLiveDownloadItem *> *)getDownloadList;
```

离线播放代理

```objective-c
/**
 下载代理
 */
@protocol SDLiveDownloadManagerDelegate <NSObject>
/// 下载认证失败
/// @param manager
/// @param roomId 直播间ID
/// @param error 错误信息
- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
                   roomId:(NSInteger)roomId
    authorizationFailed:(NSError *_Nullable)error;

/// 开始下载
/// @param manager
/// @param roomId 直播间ID
- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
      beginDownloadRoomId:(NSInteger)roomId;
  
/// 下载进度变化
/// @param manager SDLiveDownloadManager
/// @param roomId 直播间ID
/// @param downloadSize 已经下载的比特数
/// @param totalSize 该直播间总共比特数
- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
                   roomId:(NSInteger)roomId
         progressChange:(NSInteger)downloadSize
              totalSize:(NSInteger)totalSize;

/// 下载过程中发生错误
/// @param manager SDLiveDownloadManager
/// @param roomId 直播间ID
/// @param error 错误信息
- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
                   roomId:(NSInteger)roomId
          errorOccurred:(NSError *_Nullable)error;
  
/// 下载完成
/// @param manager SDLiveDownloadManager
/// @param roomId 直播间ID
/// @param error 下载完成时可能出现的错误信息
- (void)downloadManager:(SDLiveDownloadManager *_Nonnull)manager
                   roomId:(NSInteger)roomId
               complete:(NSError *_Nullable)error;

@end
```

#### 获取音频文件链接
SDLiveAudioService 类提供音频下载方法
   
```objective-c
/**
 平台化音频下载

 @param model SDLiveLoginInfoModel 平台化参数
 @param complete 返回（downloadUrl，fileSize，error）
 @return 操作成功或失败
 */

- (BOOL)requestAudioInfomationWithPlatInfo:(SDLiveLoginInfoModel *)model
                                  complete:(SDLiveAudioServiceBlock)complete;
```

#### 平台化碎片化初始化方式

```objective-c
/**
 平台化业务方碎片化视频初始化
 @param model SDLiveLoginInfoModel
 @param videoId 短视频ID
 @param extraJson 短视频扩展Json
 @param startSequence 短视频开始sequence
 @param endSequence 短视频结束sequence
 @return SDLiveManager
 */
- (instancetype _Nonnull)initLiveWith:(SDLiveLoginInfoModel* _Nonnull)model
                              videoId:(SDLiveNumber)videoId
                            extraJson:(NSString* _Nonnull)extraJson
                        startSequence:(SDLiveNumber)startSequence
                          endSequence:(SDLiveNumber)endSequence;
```
#### 营销推广商品
修改方法，添加同步序列

````
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
````

新增方法

````
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

````

####抽奖通知
App端主要是抽奖开始和结束通知

```
/// 开始抽奖通知
/// @param manager SDLiveManager
/// @param name 奖品名称
-(void)manager:(SDLiveManager* _Nonnull)manager
didReceiveStartRaffle:( NSString* _Nullable)name;

/// 学员端抽奖结果通知
/// @param manager SDLiveManager
/// @param name 奖品名称
/// @param isSelf 自己是否是中奖用户
-(void)manager:(SDLiveManager* _Nonnull)manager
didReceiveEndRaffle:( NSString* _Nullable)name
winner:(BOOL)isSelf;

```

####答题功能
App端主要是答题开始和答题结束通知，以及发送答题答案接口

```
/// 学员端抽奖结果通知
/// @param manager SDLiveManager
/// @param name 奖品名称
/// @param isSelf 自己是否是中奖用户
-(void)manager:(SDLiveManager* _Nonnull)manager
didReceiveEndRaffle:( NSString* _Nullable)name
winner:(BOOL)isSelf;

///  发给学员的答题信息
/// @param manager SDLiveManager
/// @param questiontype 题目类型。1-单选 2-多选",
/// @param lSequence 请求毫秒级时间戳
/// @param optionCount 选项个数(2-5)",
/// @param answer 排好序的答案ABC..., 无答案传空串
-(void)manager:(SDLiveManager* _Nonnull)manager
didReceiveQuestionType:(NSNumber* _Nonnull)questiontype
      sequence:(NSNumber* _Nonnull)lSequence
   optionCount:(NSNumber* _Nonnull)optionCount
        answer:(NSString* _Nonnull)answer;


///  发送答题答案
/// @param answer 答案，为排好序的字符串，如"BC"
/// @param lSequence 时间戳
- (void)sendQuestionAnser:(NSString* _Nonnull)answer sequence: (NSNumber *_Nonnull)lSequence;
```

#### 默认播放页功能


主要为SDLiveDefaultPlayerViewController相关的接口和功能


#### 环境配置
当前有四套默认的环境与自定义环境的时候与SDLiveConfig一一对应，可以通过枚举赋值。
````objective-c
+ (void)setConfigType:(SDLiveConfig)type;
````
如要自定义环境，可以实现`SDLiveEnvironmentProtocol`协议，然后给`SDLiveEnvironmentService`单例赋值。
````Swift
let env : SDLiveEnvironmentProtocol
SDLiveEnvironmentService.shared.env = env
````
