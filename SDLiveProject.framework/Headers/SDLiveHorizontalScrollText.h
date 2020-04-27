//
//  SDLiveHorizontalScrollText.h
//  SDLiveHorizontalScrollTextExample
//
//  Created by LiMingjie on 2019/8/22.
//  Copyright © 2019 SDLive. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 描述字符串滚动前端起始位置：
 */
typedef enum {
    SDLiveTextScrollContinuous,     // 从控件内开始连续滚动
    SDLiveTextScrollIntermittent,   // 从控件内开始间断滚动
    SDLiveTextScrollFromOutside,    // 从控件外开始滚动
    SDLiveTextScrollWandering       // 在控件中往返滚动（不受设置方向影响）
}SDLiveTextScrollMode;

/**
 描述字符串移动的方向
 */
typedef enum {
    SDLiveTextScrollMoveLeft,
    SDLiveTextScrollMoveRight
}SDLiveTextScrollMoveDirection;

//只在SDLiveTextScrollFromOutside 模式下，滚动一次结束后的回调
typedef void (^SDLiveHorizontalScrollFinishBlock)(UIView *view);

/// 滚动控件
@interface SDLiveHorizontalScrollText : UIView

@property (nonatomic,copy)   NSString  * text;
@property (nonatomic,copy)   UIFont  * textFont;
@property (nonatomic,copy)   UIColor * textColor;

@property (nonatomic,assign) CGFloat speed;

@property (nonatomic,assign) SDLiveTextScrollMode moveMode;
@property (nonatomic,assign) SDLiveTextScrollMoveDirection moveDirection;

@property (nonatomic,copy) SDLiveHorizontalScrollFinishBlock finishBlock ;


- (void)move;
- (void)stop;

@end

NS_ASSUME_NONNULL_END
