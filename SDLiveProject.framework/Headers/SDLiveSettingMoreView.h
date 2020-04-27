//
//  SDLiveSettingMoreView.h
//  SDLiveProject
//
//  Created by ln on 2020/3/18.
//

#import <UIKit/UIKit.h>
#import "SDLiveAnnouncementView.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^SDLiveSwitchActionBlock)(UISwitch *switchControl);
typedef void(^SDLiveSliderActionBlock)(float value);

@interface SDLiveSettingMoreView : UIView

@property(strong, nonatomic) UIButton *switchBtn;
@property(strong, nonatomic) UISwitch *littleswitch;


@property(nonatomic, assign)BOOL isPPTSmall;

@property(nonatomic, copy)SDLiveBtnActionBlock switchActionBlock;
@property(nonatomic, copy)SDLiveSwitchActionBlock smallActionBlock;

@property(nonatomic, copy)SDLiveSliderActionBlock speedValueActionBlock;

@property(assign, nonatomic) BOOL isLiving;


- (void)setRate:(double)rate;

@end

NS_ASSUME_NONNULL_END
