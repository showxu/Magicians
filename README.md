# Magicians
[![CocoaPods Compatible](https://img.shields.io/cocoapods/v/Magicians.svg)](https://img.shields.io/cocoapods/v/Magicians.svg)
[![Platform](https://img.shields.io/cocoapods/p/Magicians.svg?style=flat)](https://alamofire.github.io/Magicians)
[![Gitter](https://badges.gitter.im/0xxd0/Magicians.svg)](https://gitter.im/0xxd0/Magicians?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge)


Magicians is an utility extension for interface builder by configure object visually. 


- [Extended](#extended)
- [Requirements](#requirements)
- [Communication](#communication)
- [Installation](#installation)
- [License](#license)

## Extended 

- [x] UIView / NSView
- [x] UIScrollView / NSUIScrollView
- [x] UIViewController / NSViewController

## Requirements

- iOS 8.0+ / macOS 10.10+ / tvOS 9.0+ / watchOS 2.0+
- Xcode 8.3+
- Swift 3.2+

## Installation

### CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Cocoa projects. You can install it with the following command:

```bash
$ gem install cocoapods
```

To integrate Magicians into your Xcode project using CocoaPods, specify it in your `Podfile`:

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '11.0'
use_frameworks!

target '<Your Target Name>' do
    pod 'Magicians', '~> 0.0.1'
end
```

Then, run the following command:

```bash
$ pod install
```

## Usage

### Attributes Inspector

Just open the `interface builder` and switch to `attributes inspector`, then configure the object visually.

![Magicians](https://raw.githubusercontent.com/0xxd0/Magicians/master/screenshots/UIView.png)
![Magicians](https://raw.githubusercontent.com/0xxd0/Magicians/master/screenshots/UIScrollView.png)


## Communication

- If you **found a bug**, open an issue.
- If you **have a feature request**, open an issue.
- If you **want to contribute**, submit a pull request.

## License

Magicians is released under the MIT license. [See LICENSE](https://github.com/Alchemistxxd/Magicians/blob/master/LICENSE) for details.
