//
//  SDLiveMenuView.h
//  SDLiveProject
//
//  Created by ln on 2020/4/1.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SDLiveMenuView : UIView

//播放暂停 按钮 ,  , 进度时间文本视图 , 总时间文本视图 , 进度条视图 , 全屏切换按钮
@property(strong, nonatomic) UIButton *playPauseBut;
@property(strong, nonatomic) UIButton *questionBut; //做题按钮
@property(strong, nonatomic) UILabel *progressLab;
@property(strong, nonatomic) UILabel *totalTimeLab;
@property(strong, nonatomic) UISlider *progressView;

@property(strong, nonatomic) UIButton *changeViewSizeBut;   //横屏 竖屏按钮

//全屏下底部视图
@property(strong, nonatomic) UIView *bottomView;            //全屏底部工具栏
@property(strong, nonatomic) UIButton *keyboardViewBut;     //键盘按钮
@property(strong, nonatomic) UIButton *settingControlBut;   //设置按钮


//总时长 未格式化 秒数
@property(assign, nonatomic) int totalTimeInteger;
//是否可以更改
@property(assign, nonatomic) BOOL isChangeSlider;

- (void)forbidControlButton;

- (void)activeControlButton;

@end

NS_ASSUME_NONNULL_END
