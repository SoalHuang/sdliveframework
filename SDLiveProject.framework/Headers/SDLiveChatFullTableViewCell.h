//
//  SDLiveChatFullTableViewCell.h
//  SDLiveProject
//
//  Created by ln on 2020/3/20.
//

#import <UIKit/UIKit.h>
#import "SDLiveIMMessageModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDLiveChatFullTableViewCell : UITableViewCell

- (void)fullChatWithmessageModel:(SDLiveIMMessageModel* )messageModel;

@end

NS_ASSUME_NONNULL_END
