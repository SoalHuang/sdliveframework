//
//  SDLiveChatLeftTableViewCel.h
//  SDLiveProject
//
//  Created by ln on 2020/3/17.
//

#import <UIKit/UIKit.h>
#import "SDLiveIMMessageModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDLiveChatLeftTableViewCell : UITableViewCell

- (void)setCellContentEntity:(SDLiveIMMessageModel *)mesageModel;

@end

NS_ASSUME_NONNULL_END
