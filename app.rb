CUR_PATH = File.expand_path('..', __FILE__)
TEXT_SRC = CUR_PATH + "/text_src.txt"

$:.unshift(CUR_PATH)

require 'lib/pblights'
require 'lib/pbsimul'
require 'lib/pbtext'


left_bank = PbLights::Lightbank.new(5)
right_bank = PbLights::Lightbank.new(5)

view = Thread.new{InstallSim.new(left_bank, right_bank).show}
view.join
