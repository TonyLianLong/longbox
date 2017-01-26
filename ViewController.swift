//
//  ViewController.swift
//  air
//
//  Created by Tony on 16/9/14.
//  Copyright © 2016年 Tonylianlong. All rights reserved.
//

import UIKit
@_silgen_name("box_main") func c_box_main(_ home:UnsafePointer<CChar>,_ bundle:UnsafePointer<CChar>)->CInt;
class ViewController: UIViewController, UITextFieldDelegate {
    let textview = UITextField();
    @IBAction func key(_ sender: Any) {
        textview.becomeFirstResponder();
    }
    @IBOutlet var screenview: UIImageView!;
    func textField(_ textField: UITextField, shouldChangeCharactersIn range: NSRange, replacementString string: String) -> Bool {
        if(string == ""){
            sendKey(1,0);
            return false;
        }
        for v in string.unicodeScalars {
            if(v.value > 255){
                continue;//Ignore
            }
            sendKey(0,UInt8(v.value));
        }
        print(string);
        return false;
    }
    
    override func viewDidLoad() {
        super.viewDidLoad();
        textview.text = "a";
        //To ensure DELETE can work
        textview.isHidden = true;
        textview.keyboardType = UIKeyboardType.asciiCapable;
        textview.keyboardAppearance = UIKeyboardAppearance.light;
        textview.autocapitalizationType = UITextAutocapitalizationType.none;
        textview.autocorrectionType = UITextAutocorrectionType.no;
        self.view.addSubview(textview);
        textview.becomeFirstResponder();
        textview.delegate = self;
        //textview.resignFirstResponder();
        //textview.removeFromSuperview();
        let documentPath = NSSearchPathForDirectoriesInDomains(FileManager.SearchPathDirectory.documentDirectory, FileManager.SearchPathDomainMask.userDomainMask, true)[0]
        let bundlePath:String = Bundle.main.bundlePath
        print("Document Path:\(documentPath)\nBundle Path:\(bundlePath)")
        let fileManager = FileManager.default
        let copyfiles = ["file"]
        for filename in copyfiles {
            print("Copying \(filename)...")
            if(!fileManager.fileExists(atPath: documentPath+"/"+filename)){
                do{
                    try fileManager.copyItem(atPath: bundlePath+"/"+filename, toPath: documentPath+"/"+filename)
                }catch{
                    print("Cannot copy file:\(filename)");
                }
            }
        }
        print("Inited")
        Screen.screenview = screenview;
        screenview!.contentMode = UIViewContentMode.scaleAspectFit;
        updateScreen = Screen.updateScreen;
        //Screen.test();
        let queue = DispatchQueue(label: "queue",attributes:DispatchQueue.Attributes.concurrent);
        queue.async(execute: { () -> Void in
            //code here
            c_box_main(documentPath,bundlePath);
            print(Thread.current);
        });
        // Do any additional setup after loading the view, typically from a nib.
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
}
