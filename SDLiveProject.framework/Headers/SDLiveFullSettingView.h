//
//  SDLiveSettingMoreView.h
//  SDLiveProject
//
//  Created by ln on 2020/3/18.
//

#import <UIKit/UIKit.h>
#import "SDLiveAnnouncementView.h"


NS_ASSUME_NONNULL_BEGIN
@class SDLiveSettingMoreView;

typedef void(^SDLiveSwitchActionBlock)(UISwitch *switchControl);

@interface SDLiveFullSettingView : UIView

@property(strong, nonatomic) SDLiveSettingMoreView *otherSettingView;

@property(nonatomic, copy)SDLiveSwitchActionBlock smallActionBlock;

- (void)setIsliving:(BOOL)isLiving;
- (void)setRate:(double)rate;

- (void)setChatView:(BOOL)isShow;

@end

NS_ASSUME_NONNULL_END
