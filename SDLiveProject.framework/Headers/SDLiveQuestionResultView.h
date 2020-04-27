//
//  SDLiveQuestionResultView.h
//  SDLiveProject
//
//  Created by ln on 2020/4/8.
//

#import <UIKit/UIKit.h>
#import "SDLivePublicDefine.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDLiveQuestionResultView : UIView

@property(strong, nonatomic, readonly) UIImageView *imageView;
@property(strong, nonatomic, readonly) UILabel *contentLabel;

@property(nonatomic, copy)SDLiveBtnActionBlock closeBlock;

- (void)setTypeResult: (BOOL)result;

@end

NS_ASSUME_NONNULL_END
