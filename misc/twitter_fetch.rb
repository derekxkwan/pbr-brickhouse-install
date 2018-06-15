require 'twitter'

credz = {}
credz[:c_key], credz[:c_secret] credz=[:a_token], credz=[:a_secret]= IO.readlines(File.expand_path('../twitter_creds.txt', __FILE__))

client = Twitter::REST::Client.new do |config|
  config.consumer_key = credz[:c_key]
  config.consumer_secret = credz[:c_secret]
  config.access_token = credz[:a_token]
  config.access_token_secret = credz[:a_secret]
end


