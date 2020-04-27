//
//  SDLiveMoreButton.h
//  SDLiveProject
//
//  Created by ln on 2020/3/18.
//

#import <UIKit/UIKit.h>
#import "SDLiveAnnouncementView.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDLiveMoreButton : UIButton

- (instancetype)initWithMore;

@property(nonatomic, copy)SDLiveBtnActionBlock actionBlock;

@end

NS_ASSUME_NONNULL_END
