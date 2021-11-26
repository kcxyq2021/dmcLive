//
//  BJVNetworkSpeed.h
//  BJVideoPlayerCore
//
//  Created by 辛亚鹏 on 2021/10/18.
//  Copyright © 2021 BaijiaYun. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BJVNetworkSpeed : NSObject

+ (instancetype)networkSpeed;

// 开始监测网速
- (void)start;
// 停止
- (void)stop;
// 每秒网速
@property (nonatomic, readonly) NSString *speedString;

@end

NS_ASSUME_NONNULL_END
