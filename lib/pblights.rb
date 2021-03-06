# prototype for lights for now before i actually buy them

# require 'ws2812'

module PbLights

  MAX_BRIGHTNESS = 100
  
  class Light
    attr_reader :id, :address, :brightness
    
    def initialize(id = 0, address = -1)
      @id = id
      
      if address < 0
        @address = id
      else
        @address = address
      end
      
      @color = [255, 255, 255]
      @brightness = 0
    end

    def set_brightness(brightness)
      @brightness = brightness < 0 ? 0 : (brightness > MAX_BRIGHTNESS ? MAX_BRIGHTNESS : brightness)
    end

    def set_color(color)
      @color = color
    end
    
  end

  class Lightbank
    attr_reader :lights, :size
    attr_accessor :rand_on, :grain
    #grain = sleep time in seconds, fade_time is in seconds
    def initialize(n = 5, fade_time = 3.0, grain = 0.01)
      @size = n > 1 ? n.floor : 1
      @lights = Array.new(@size){|x| Light.new(x)}
      @fade_time = fade_time > 0 ? fade_time : 1
      @value = 0
      @fading = false
      @rand_on = true
      @state = Array.new(@size){0}
      @prev_state = Array.new(@size){0}
      @grain = grain
    end

    def fade_brightness
      @fading = true
      diff = @state.each_with_index.map{|x,idx| @grain * MAX_BRIGHTNESS.to_f * (x - @prev_state[idx].to_f)/@fade_time.to_f}
      p [self.object_id, @prev_state, @state, diff]
      @thread = Thread.new do
        cur_i = 0
        lim = (@fade_time/@grain).floor
        while cur_i < lim
          @lights.each_with_index do |light, idx|
            brightval = (MAX_BRIGHTNESS * @prev_state[idx]) + (diff[idx] * cur_i)
            light.set_brightness(brightval)
            end
          cur_i += 1
          sleep @grain
          end
        @prev_state = @state
        @fading = false
        end
      end  

    def set_value(val)
      val = val < 0 ? 0 : (val > @size ? @size : val)
      @state = [1] * val + [0] * (@size - val)
      @state.shuffle! if @rand_on
      if @state != @prev_state
        fade_brightness
      end
    end

    def set_color(color)
      @lights.each{|x| x.set_color(color)}
      end

    def get_brightness
      return @lights.map{|x| x.brightness}
    end

    end
  
end          
          


  
