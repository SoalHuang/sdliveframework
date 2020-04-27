//
//  SDLiveAnnouncementView.h
//  SDLiveProject
//
//  Created by ln on 2020/3/17.
//

#import <UIKit/UIKit.h>
#import "SDLivePublicDefine.h"

NS_ASSUME_NONNULL_BEGIN

@class SDLiveIMAnnounceModel;

@interface SDLiveAnnouncementView : UIView

@property(nonatomic, copy)SDLiveBtnActionBlock closeBlock;

- (void)receiveAnnounce:(SDLiveIMAnnounceModel *)announce;

- (void)orientationChange:(BOOL)isVertical;

@end

NS_ASSUME_NONNULL_END
