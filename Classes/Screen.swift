//
//  Screen.swift
//  bochs
//
//  Created by tll on 2017/1/21.
//
//

import UIKit
class Screen {
    static var screenview:UIImageView!;
    init(){
        
    }
    
    private static let rgbColorSpace = CGColorSpaceCreateDeviceRGB()
    private static let bitmapInfo:CGBitmapInfo = CGBitmapInfo(rawValue: CGImageAlphaInfo.first.rawValue)
    
        public static func imageFromARGB32Bitmap(pixels:[PixelData], width:UInt, height:UInt)->UIImage {
        let bitsPerComponent:UInt = 8
        let bitsPerPixel:UInt = 32
        
        assert(pixels.count == Int(width * height))
        
        var data = pixels // Copy to mutable []
        let providerRef = CGDataProvider(
            data: NSData(bytes: &data, length: data.count * MemoryLayout<PixelData>.size)
        )
        
        let cgim = CGImage(
            width:Int(width),
            height:Int(height),
            bitsPerComponent:Int(bitsPerComponent),
            bitsPerPixel:Int(bitsPerPixel),
            bytesPerRow:Int(width * UInt(MemoryLayout<PixelData>.size)),
            space:rgbColorSpace,
            bitmapInfo:bitmapInfo,
            provider:providerRef!,
            decode:nil,
            shouldInterpolate:true,//You can change this
            intent:CGColorRenderingIntent.defaultIntent
        )
        return UIImage(cgImage: cgim!)
    }
    public static func imageFromARGB32Bitmap(pixels:UnsafeMutablePointer<PixelData>, width:UInt32, height:UInt32)->UIImage {
        var processedPixels:[PixelData] = Array<PixelData>();
        for i in 1...width*height{
            processedPixels.append(pixels[Int(i)]);
        }
        return imageFromARGB32Bitmap(pixels:processedPixels,width:UInt(width),height:UInt(height));
    }

    
    public static func test(){//Call only in main thread
        var pixels:[PixelData] = [];
        for _ in 1...1000{
            pixels.append(PixelData(a:255,r:100,g:100,b:0));
        }
        let image:UIImage = Screen.imageFromARGB32Bitmap(pixels: pixels,width: 100,height: 10);
        screenview!.image = image;
    }
    public static func updateScreen(pixels:UnsafeMutablePointer<PixelData>?,width:UInt32,height:UInt32){
        let image:UIImage = Screen.imageFromARGB32Bitmap(pixels: pixels!,width: width,height: height);
        DispatchQueue.main.async() {
            // Do UI stuff here
            //http://stackoverflow.com/questions/31951704/this-application-is-modifying-the-autolayout-engine-from-a-background-thread-wh
            screenview!.image = image;
        }
        //print("Screen has been updated");
    }
}
