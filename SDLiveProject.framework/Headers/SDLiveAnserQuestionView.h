//
//  SDLiveAnserQuestionView.h
//  SDLiveProject
//
//  Created by ln on 2020/4/3.
//

#import <UIKit/UIKit.h>
#import "SDLivePublicDefine.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^SDLiveAnserQuestionViewBlock)(UIView *view, NSString *subStr);


@interface SDLiveAnserQuestionView : UIView
@property(nonatomic, copy)SDLiveAnserQuestionViewBlock submitBlock;
@property(nonatomic, copy)SDLiveBtnActionBlock closeBlock;

- (instancetype)initWithType:(int)type optionCount:(int)optionCount answer:(NSString*)answer;

@end

NS_ASSUME_NONNULL_END
