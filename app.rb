$:.unshift(File.expand_path('..', __FILE__))

require 'lib/pbserver'

threads = []
threads << Thread.new{PbServer.new()}
