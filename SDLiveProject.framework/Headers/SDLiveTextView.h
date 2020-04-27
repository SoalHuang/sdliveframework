
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SDLiveTextViewMaxLengthType){
    SDLiveTextViewMaxLengthTypeCustom = 0,
    SDLiveTextViewMaxLengthTypeDefault = 1,
};

@class SDLiveTextView;

typedef void(^SDLiveTextViewDidChangeBlock)(SDLiveTextView *textView, NSUInteger remainderLength);

IB_DESIGNABLE
@interface SDLiveTextView : UITextView

@property (nonatomic, copy, nullable) IBInspectable NSString *placeHolder;
@property (nonatomic, strong) IBInspectable UIColor *placeHolderColor;

@property (nonatomic, assign) IBInspectable NSUInteger maxStringLength;

// border configure
@property (nonatomic, assign) IBInspectable CGFloat borderWidth;
@property (nonatomic, assign) IBInspectable CGFloat cornerRadius;
@property (nonatomic, strong) IBInspectable UIColor *borderColor;

@property (nonatomic, copy) SDLiveTextViewDidChangeBlock didChangeBlock;

/**
 *  The default value is `UIEdgeInsets(5.0, 7.0, 5.0, 7.0)`.
 */
@property (nonatomic, assign) UIEdgeInsets placeHolderInsets;

@end

NS_ASSUME_NONNULL_END
