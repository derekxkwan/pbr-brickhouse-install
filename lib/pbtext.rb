require "polybius_sq"

class PbText
  attr_reader :loaded, :size, :len
  
  def initialize(text_path)
    @text_path = text_path
    populate_text(text_path)
    @r = Random.new
    @loaded = false
    @len = 0
    end

  def populate_text
    @texts = IO.readlines(@text_path)
    @size = @texts.size
    end

  def load-path(new_path)
    if new_path != @text_path
      @text_path = new_path
      populate_text
      end
    end
  
  def prep_text
    rand_idx = @r.rand(@size).floor
    @cur = PolybiusSq::encode(@texts[rand_idx])
    @len = @cur.size
    @loaded = true if @len > 0
    end

  def shift_ltr
    if @loaded
      ret = @cur.shift
      @len = @cur.size
      @loaded = false if @len <= 0
      return ret
      end
    end
  
  end

  
