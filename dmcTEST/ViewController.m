//
//  ViewController.m
//  dmcTEST
//
//  Created by dmc on 2021/4/15.
//  Copyright © 2021 dmc. All rights reserved.
//

#import "ViewController.h"
//直播头文件引入
#import <BJLiveUIBase/BJLiveUIBase.h>
//点播头文件引入
#import <BJVideoPlayerUI/BJVideoPlayerUI.h>
#import <BJVideoPlayerCore/BJVAppConfig.h>
#import <BJPlaybackUI/BJPlaybackUI.h>



@interface ViewController ()
@property (nonatomic) BJLRoomViewController *roomViewController;//直播控制器视图
@property (strong, nonatomic) BJPUViewController *playerUIVC;//点播控制器视图
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //设置按钮入口
    UIButton *bigRoomIDButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [bigRoomIDButton setTitle:@"大班课roomidID进入" forState:UIControlStateNormal];
    [self.view addSubview:bigRoomIDButton];
    bigRoomIDButton.frame = CGRectMake(100, 100, 200, 30);
    [bigRoomIDButton addTarget:self action:@selector(pushRommIDBigView) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *bigCodeButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [bigCodeButton setTitle:@"大班课参加吗进入" forState:UIControlStateNormal];
    [self.view addSubview:bigCodeButton];
    bigCodeButton.frame = CGRectMake(100, 200, 200, 30);
    [bigCodeButton addTarget:self action:@selector(pushCodeBigView) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *videoButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [videoButton setTitle:@"回放进入" forState:UIControlStateNormal];
    [self.view addSubview:videoButton];
    videoButton.frame = CGRectMake(100, 300, 200, 30);
    [videoButton addTarget:self action:@selector(pushVideoView) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton *videoPlayeButton = [UIButton buttonWithType:UIButtonTypeSystem];
    [videoPlayeButton setTitle:@"点播进入" forState:UIControlStateNormal];
    [self.view addSubview:videoPlayeButton];
    videoPlayeButton.frame = CGRectMake(100, 400, 200, 30);
    [videoPlayeButton addTarget:self action:@selector(pushVideoPlayeView) forControlEvents:UIControlEventTouchUpInside];
    
    
    // Do any additional setup after loading the view.
}

/*---通过roomID的方式进入直播教室----*/
-(void)pushRommIDBigView{
    
    NSString *domainPrefix = @"e75126400";
    
    [BJLRoom setPrivateDomainPrefix:domainPrefix];//设置专属域名
    
    BJLRoomID *roomID = [[BJLRoomID alloc] init];
    
    roomID.roomID = @"21112571959154"; //教室ID
    
    roomID.apiSign = @"900b63b7ec134d6ede3579fefc06ca02";//签名参数
    
    roomID.user = [BJLUser userWithNumber:@"88888888" name:@"test" groupID:nil avatar:@"https://img.qq1234.org/uploads/allimg/140426/155540J58-13.jpg" role:BJLUserRole_student];//用户信息
    //移动端传递的参数要与后端参与签名的参数一直，否则报错签名错误
    
    BJLRoomViewController *roomViewController =
    [BJLRoomViewController instanceWithRoomType:BJLRoomVCTypeBigClass roomID:roomID];
    /*---小班课更换类型即可
    [BJLRoomViewController instanceWithRoomType:BJLRoomVCTypeSmallClass roomID:roomID];
     ----*/
    [self bjl_presentFullScreenViewController:roomViewController animated:YES completion:nil];
    
}
/*---通过code参加码的方式进入直播教室----*/
-(void)pushCodeBigView{
    
    NSString *domainPrefix = @"e75126400";
    
    [BJLRoom setPrivateDomainPrefix:domainPrefix];//设置专属域名
    
    BJLRoomCode *code = [[BJLRoomCode alloc] init];
    code.code = @"97jqn9";//参加码
    code.userName = @"test";//昵称
    code.userAvatar = nil; //头像
    
    BJLRoomViewController *roomViewController =
    [BJLRoomViewController instanceWithRoomType:BJLRoomVCTypeBigClass roomCode:code];
    
    [self bjl_presentFullScreenViewController:roomViewController animated:YES completion:nil];
    
}

/*---进入回放教室----*/
-(void)pushVideoView{
    
    [[BJVAppConfig sharedInstance] setPrivateDomainPrefix:@"e75126400"];
    //播放配置，可以根据需求设置相关属性
    BJPPlaybackOptions *playbackOptions = [BJPPlaybackOptions new];
    playbackOptions.playerType = BJVPlayerType_AVPlayer;//播放器选择
    playbackOptions.autoplay = YES;//自动播放
    playbackOptions.playTimeRecordEnabled = NO;//动效关闭
    playbackOptions.clipedVersion = -1;
    
    BJPRoomViewController *vc = [BJPRoomViewController onlinePlaybackRoomWithClassID:@"21111142359097"sessionID:nil
        token:@"x5POHfXGQjcmDA1PXVo3-vpogQ_KHyKiYFZzWLvm3QsqqX-_egJAPh8mDN8gQK-eCqdH1zJ1Si0"
        accessKey:nil options:playbackOptions];
    
    [self bjl_presentFullScreenViewController:vc animated:YES completion:nil];
    
}
/*---进入点播----*/
-(void)pushVideoPlayeView{
   
    [[BJVAppConfig sharedInstance] setPrivateDomainPrefix:@"e75126400"];
    self.playerUIVC = [[BJPUViewController alloc] initWithVideoOptions:[BJPUVideoOptions new]];
    [self addChildViewController:self.playerUIVC];
    [self.playerUIVC didMoveToParentViewController:self];
    [self.view addSubview:self.playerUIVC.view];
    [self.playerUIVC playWithVid:@"157819709" token:@"_EMlr2kGSS2iTDSW4wLsitm3G6EI9hbO-c5A80X9vqp0UK8bSBm4VzG5JtrxIFp-"];
    
   
    
}

@end

