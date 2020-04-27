//
//  SDLPrompView.h
//  MakeFramework
//
//  Created by ln on 2020/3/11.
//  Copyright © 2020 HuangYaqing. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SDLPrompView : UIView

- (void)setLodingImgName:(NSString *)name
                   info :(NSString *)info
                 isAnim : (BOOL) isAnim;

@end

NS_ASSUME_NONNULL_END
