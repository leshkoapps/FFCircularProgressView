//
//  FFCircularProgressBar.h
//  FFCircularProgressBar
//
//  Created by Fabiano Francesconi on 16/07/13.
//  Copyright (c) 2013 Fabiano Francesconi. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#import <CoreGraphics/CoreGraphics.h>


NS_ENUM (NSInteger, FFCircularState){
    FFCircularStateStop = 0,
    FFCircularStateStopSpinning,
    FFCircularStateStopProgress,
    FFCircularStateCompleted,
    FFCircularStateIcon,
};

@interface FFCircularProgressView : UIControl

/**
 * The progress of the view.
 **/
@property (nonatomic, assign) CGFloat progress;

/**
 * The width of the line used to draw the progress view.
 **/
@property (nonatomic, assign) CGFloat lineWidth;

/**
 * The color of the progress view
 */
@property (nonatomic, strong) UIColor *progressColor;

/**
 * The color of the tick view
 */
@property (nonatomic, strong) UIColor *tickColor;

/**
 * Icon view to be rendered instead of default arrow
 */
@property (nonatomic, strong) UIView* iconView;

/**
 * Bezier path to be rendered instead of icon view or default arrow
 */
@property (nonatomic, strong) UIBezierPath* iconPath;

/**
 * Bezier path to be rendered instead of stop view
 */
@property (nonatomic, strong) UIBezierPath* stopIconPath;

/**
 * Make the background layer to spin around its center. This should be called in the main thread.
 */
- (void) startSpinProgressBackgroundLayer;

/**
 * Stop the spinning of the background layer. This should be called in the main thread.
 * WARN: This implementation remove all animations from background layer.
 **/
- (void) stopSpinProgressBackgroundLayer;

@property (nonatomic, readonly, assign) BOOL isSpinning;

@property (nonatomic, assign)enum FFCircularState circularState;


- (UIBezierPath *)downArrowPath;

- (UIBezierPath *)upArrowPath;

- (UIBezierPath *)stopPath;

- (UIBezierPath *)pausePath;

- (UIBezierPath *)playPath;

@end
