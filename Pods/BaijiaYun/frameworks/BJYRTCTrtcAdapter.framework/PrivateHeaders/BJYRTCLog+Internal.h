//
//  BJYRTCLog+Internal.h
//  BJYRTCEngine
//
//  Created by lw0717 on 2019/9/12.
//  Copyright © 2019 BaiJiaYun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BJYRTCEngine/BJYRTCLog.h>
#import <BJYRTCEngine/BJYRoomOptions.h>

NS_ASSUME_NONNULL_BEGIN

/// Debug log, NSLog + Save
FOUNDATION_EXPORT void BJYRTCDebugLog(NSString *log, ...);
/// function call log, sessionID, log 具体要打印的信息, NSLog + Upload + Save
FOUNDATION_EXPORT void BJYRTCCallLog(NSString *sessionID, NSString *log, ...);

@interface BJYRTCLog ()

@property (nonatomic, strong) BJYRoomOptions *roomOptions;

+ (instancetype)sharedInstance;
+ (void)release;

///
- (void)sendDynamicLogWithSessionID:(NSString *)sessionID feedID:(NSString * __nullable)feedID content:(NSDictionary *)content;

@end

NS_ASSUME_NONNULL_END
