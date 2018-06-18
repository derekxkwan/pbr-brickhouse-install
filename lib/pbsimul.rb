require 'gosu'

class InstallSim < Gosu::Window
  W = 1024
  H = 768
  GAP = InstallSim::W * 0.1
  X_BORDER = InstallSim::W * 0.01
  Y_BORDER = InstallSim::H * 0.01
  SPACE = ((InstallSim::W/2.0)-(InstallSim::GAP/2.0+InstallSim::X_BORDER))
  
  RES = File.expand_path('../../resources', __FILE__)
  
  def initialize(left_bank, right_bank)
    super W,H
    self.caption = "Polybius Sim"
    @background_image = Gosu::Image.new(RES + "/dirty-brick-wall.jpg", :tileable => false)
    @n = left_bank.size
    @spacing = InstallSim::SPACE/@n.to_f
    @left_draw = Array.new(@n){Gosu::Color.rgba(255,255,255,255)}
    @right_draw = Array.new(@n){Gosu::Color.rgba(255,255,255,255)}
    @left_bank = left_bank
    @right_bank = right_bank
    end

  def brightness_to_val(brightness)
    return brightness/100.0
    end

  def draw_bank(to_draw, offset = InstallSim::X_BORDER)
    to_draw.each_with_index do |clr,idx|
      cur_x = offset + @spacing * idx
      cur_y = InstallSim::Y_BORDER
      cur_w = @spacing*0.75
      cur_h = InstallSim::H-(2.0*InstallSim::Y_BORDER)
      draw_rect(cur_x, cur_y, cur_w, cur_h, clr)
      end
    end
    
  def update_brightness
    left_bank_vals = @left_bank.get_brightness.map{|x| brightness_to_val(x)}
    right_bank_vals = @right_bank.get_brightness.map{|x| brightness_to_val(x)}
    @left_draw.each_with_index{|x,idx| x.value = left_bank_vals[idx]}
    @right_draw.each_with_index{|x,idx| x.value = right_bank_vals[idx]}
  end
  
  def update
    update_brightness
    end

  

  def draw
    @background_image.draw(0,0,0)
    draw_bank(@left_draw)
    draw_bank(@right_draw, (InstallSim::W+InstallSim::GAP)/2.0) 
    end
  end
