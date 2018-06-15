require 'sinatra'
require 'sinatra/base'
require 'thin'

class PbServer < Sinatra::Base
  set :public_folder, File.expand_path('../../static', __FILE__)
  set :port, 9000
  set :server, :thin

  get "/" do
    File.read(File.join("static", "index.html"))
    end

  post "/" do
    p params
    end

  run!
  
  end
