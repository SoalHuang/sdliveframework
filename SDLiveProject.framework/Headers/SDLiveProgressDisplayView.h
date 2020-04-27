//
//  SDLiveProressDisplayView.h
//  SDLiveProject
//
//  Created by ln on 2020/3/12.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SDLiveProgressDirection) {
    SDLiveProgressDirectionNone,
    SDLiveProgressDirectionLeft,
    SDLiveProgressDirectionRight,
};

@interface SDLiveProgressDisplayView : UIView

- (void)setProgress:(Float32)progress direction:(SDLiveProgressDirection)direction progressStr:(NSString*) progressStr totalStr: (NSString*)totalStr;

@end

NS_ASSUME_NONNULL_END
