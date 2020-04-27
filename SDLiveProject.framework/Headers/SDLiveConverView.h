//
//  SDLiveConverView.h
//  MakeFramework
//
//  Created by ln on 2020/3/11.
//  Copyright © 2020 HuangYaqing. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class SDLPrompView;
@class SDLiveMenuView;
@class SDLiveAnserQuestionView;

typedef void(^SDLCoverViewHiddenClosures)(BOOL hidden);


@interface SDLiveConverView : UIView

// 菜单功能视图
@property(strong, nonatomic) SDLiveMenuView *menuView;

//状态栏背景视图
@property(strong, nonatomic) UIView *statusBarBackview;
//导航视图 后退按钮
@property(strong, nonatomic) UIView *navigationView;
@property(strong, nonatomic) UIButton *backButton;
@property(strong, nonatomic) UILabel *titlLabel;

/// 隐藏遮罩视图回调
@property(copy, nonatomic) SDLCoverViewHiddenClosures hiddenClosures;


//声音控制条
@property(strong, nonatomic) UIView *voiceControlV;
@property(strong, nonatomic) UIButton *voiceControlBut;
@property(strong, nonatomic) UISlider *voiceControlSlider;

//控制
@property(assign, nonatomic) BOOL isLiving;

- (void)startCoverViewTimerHidden;

- (void)closeVisibleCoverViewTimer;

- (void)hiddenCoverView;

- (void)visibleCoverView;

//改变视图方向
- (void)changeViewOrientation:(BOOL)isHorizontal;

@end

NS_ASSUME_NONNULL_END
