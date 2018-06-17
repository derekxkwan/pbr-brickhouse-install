$:.unshift(File.expand_path('..', __FILE__))

require 'polybius_sq'
require 'lib/pblights'
require 'lib/pbsimul'

left_bank = PbLights::Lightbank.new(5)
right_bank = PbLights::Lightbank.new(5)

view = Thread.new{InstallSim.new(left_bank, right_bank).show}
view.join
