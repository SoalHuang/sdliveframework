//
//  SDLivePlayeMutipleLines.h
//  SDLiveProject
//
//  Created by ln on 2020/3/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SDLivePlayeMutipleLinesDelegate <NSObject>

- (void)didSelectRowAtIndexPath:(NSIndexPath *)indexPath rate:(double)rate;

@end


@interface SDLivePlayeMutipleLines : NSObject <UITableViewDelegate, UITableViewDataSource>

@property (weak, nonatomic)id <SDLivePlayeMutipleLinesDelegate> delegate;
//倍速播放数据源

@property(strong, nonatomic) NSArray<NSString *> *mutipleLines;
@property(strong, nonatomic) NSNumber *mutipleCurSelLineIndex;

@end

NS_ASSUME_NONNULL_END
