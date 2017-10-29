Pod::Spec.new do |s|
  s.name         = 'Magicians'
  s.version      = '0.0.1'
  s.license      = 'MIT'
  s.summary      = 'An utility extension for interface builder.'
  s.homepage     = 'https://github.com/Alchemistxxd/Magicians'
  s.authors      = { 'Alchemistxxd' => 'the_shadow_xxd@live.com' }
  s.source       = { :git => 'https://github.com/Alchemistxxd/Magicians.git', :tag => "#{s.version}" }

  s.ios.deployment_target = '8.0'
  s.osx.deployment_target = '10.10'
  s.tvos.deployment_target = '9.0'
  s.watchos.deployment_target = '2.0'

  s.source_files = 'Source/*.swift'
end
