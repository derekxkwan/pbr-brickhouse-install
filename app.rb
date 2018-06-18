CUR_PATH = File.expand_path('..', __FILE__)
TEXT_SRC = CUR_PATH + "/resources/text_src.txt"

$:.unshift(CUR_PATH)

require 'lib/pblights'
require 'lib/pbsimul'
require 'lib/pbinstall'


threads = []

left_bank = PbLights::Lightbank.new(5)
right_bank = PbLights::Lightbank.new(5)

my_app = PbMainProc.new(TEXT_SRC, left_bank, right_bank)
threads << Thread.new{my_app.run}
threads << Thread.new{InstallSim.new(left_bank, right_bank).show}
threads.each{|t| t.join}
