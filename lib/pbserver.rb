require 'sinatra'
require 'sinatra/base'
require 'thin'

class PbServer < Sinatra::Base
  attr_accessor :msgs
  
  set :public_folder, File.expand_path('../../static', __FILE__)
  set :views, File.expand_path('../../views', __FILE__)
  set :port, 9000
  set :server, :thin

  def initialize
    super()
    @msgs = []
    end
  
  get "/" do
    File.read(File.join("static", "index.html"))
    end

  post "/submit" do
    @msgs.unshift(params[:message])
    erb :submitted
    end

  run!
  
  end
