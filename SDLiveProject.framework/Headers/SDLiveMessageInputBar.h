//
//  SDLiveMessageInputBar.h
//  MessagingUI
//
//  Created by Martin S. on 28.12.17.
//  Copyright © 2017 Juma. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SDLiveTextView.h"

NS_ASSUME_NONNULL_BEGIN

// Currently Input bar has only one style, but might be extended in the future.
// What "style" in this context means is also up for debate. 
typedef NS_ENUM(NSInteger, SDLiveMessageInputBarStyle) {
	SDLiveMessageInputBarStyleDefault,
	SDLiveMessageInputBarStyleSendAlways,
};

@class SDLiveMessageInputBar;
@protocol SDLiveMessageInputBarDelegate <NSObject>

@optional
// Return a smaller size if you want to enable scrolling
- (CGSize)inputBar:(SDLiveMessageInputBar *)bar replacmentSizeForSize:(CGSize)size oldSize:(CGSize)oldSize;

- (void)inputBar:(SDLiveMessageInputBar *)bar didResizeToSize:(CGSize)size oldSize:(CGSize)oldSize;

@end

IB_DESIGNABLE

/**
A bar to enter your message. If you opt for storyboard, please make sure to connect all outlets in the .m file.
 If you decide for programmatic use of this class, you can modify the contents by accessing the relevant buttons,
 insert new views in the horizontal stack view and modify the textView.

 If the default intrinsic size does not suite your needs, you can either add height constraints or change the relevant
 metrics in the .m file.
 */
@interface SDLiveMessageInputBar : UIView

- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithStyle:(SDLiveMessageInputBarStyle)style NS_DESIGNATED_INITIALIZER;

@property (assign, nonatomic, readonly) SDLiveMessageInputBarStyle style;

// If you want to customize the input bar by simply adding additional views, you should add them to the stack view so they will be positioned appropriately. Beware that if you use Interface builder the stack view wont be used. In that case use the default view.
@property (strong, readonly, nonatomic, nullable) UIStackView *horizontalStackView;

// default is nil. Button will be created if necessary. Can be attached in Interface builder
@property (strong, readonly, nonatomic, nullable) UIButton *rightAccessoryButton;

 // default is nil. Button will be created if necessary. Can be attached in Interface builder
@property (strong, readonly, nonatomic, nullable) UIButton *leftAccessoryButton;

// default is nil. Button will be created if necessary. Can be attached in Interface builder
@property (strong, readonly, nonatomic, nullable) UIButton *sendButton;

@property (strong, readonly, nonatomic) SDLiveTextView *textView;

// Use the delegate to control resizing of the cell
@property (weak, nonatomic) id<SDLiveMessageInputBarDelegate> delegate;

- (void)updateBackgroundIfNeeded;

@end

// The bar broadcast relevant messages like many other UIKit objects
extern NSNotificationName const SDLiveMessageInputBarDidResizeNotification;

extern NSString *const SDLiveMessageInputBarSizeUserInfoKey; // CGSizeValue

NS_ASSUME_NONNULL_END
