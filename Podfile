
inhibit_all_warnings!
use_frameworks!

workspace 'Magicians'


target 'iOS Example' do
  project 'Demo/iOS/iOS Example'

  platform :ios, '11.0'

  # Comment the next line if you're not using Swift and don't want to use dynamic frameworks


  # Pods for Magicians iOS

end




pre_install do |installer|
  # Do something fancy!
end

post_install do |installer|
  installer.pods_project.targets.each do |target|
    target.build_configurations.each do |config|
      # config.build_settings['GCC_ENABLE_OBJC_GC'] = 'supported'
    end
  end
end

