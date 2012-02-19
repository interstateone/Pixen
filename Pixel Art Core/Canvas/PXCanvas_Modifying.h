//
//  PXCanvas_Modifying.h
//  Pixen
//
//  Created by Joe Osborn on 2005.07.31.
//  Copyright 2005 Pixen. All rights reserved.
//

#import "PXCanvas.h"

@interface PXCanvas(Modifying)

- (BOOL)canDrawAtPoint:(NSPoint)aPoint;

- (PXColor)mergedColorAtPoint:(NSPoint)aPoint;
- (PXColor)surfaceColorAtPoint:(NSPoint)aPoint;
- (PXColor)colorAtPoint:(NSPoint)aPoint;

- (void)setColor:(PXColor)color atPoint:(NSPoint)aPoint;
- (void)setColor:(PXColor)color atPoint:(NSPoint)aPoint onLayer:(PXLayer *)layer;
- (void)setColor:(PXColor)color atIndices:(NSArray *)indices updateIn:(NSRect)bounds;
- (void)setColor:(PXColor)color atIndices:(NSArray *)indices updateIn:(NSRect)bounds onLayer:(PXLayer *)layer;

- (void)reduceColorsTo:(int)colors withTransparency:(BOOL)transparency matteColor:(NSColor *)matteColor;
+ (void)reduceColorsInCanvases:(NSArray *)canvases toColorCount:(int)colors
			  withTransparency:(BOOL)transparency matteColor:(NSColor *)matteColor;

- (NSPoint)correct:(NSPoint)aPoint;
- (BOOL)containsPoint:(NSPoint)aPoint;
- (void)rotateByDegrees:(int)degrees;

- (BOOL)wraps;
- (void)setWraps:(BOOL)newWraps;
- (void)setWraps:(BOOL)newWraps suppressRedraw:(BOOL)suppress;

- (void)changedInRect:(NSRect)rect;
- (void)changed;

- (void)flipHorizontally;
- (void)flipVertically;

- (void)clearUndoBuffers;
- (void)registerForUndo;
- (void)registerForUndoWithDrawnPoints:(NSPointerArray *)points oldColors:(PXColorArrayRef)oldColors
							 newColors:(PXColorArrayRef)newColors inLayer:(PXLayer *)layer
							   undoing:(BOOL)undoing;

- (void)replaceColorsAtPoints:(NSPointerArray *)points withColors:(PXColorArrayRef)colors inLayer:(PXLayer *)layer;

- (void)bufferUndoAtPoint:(NSPoint)aPoint fromColor:(PXColor)oldColor toColor:(PXColor)newColor;

- (void)applyImage:(NSImage *)image toLayer:(PXLayer *)layer;

@end
