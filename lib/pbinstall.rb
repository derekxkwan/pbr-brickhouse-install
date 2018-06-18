require 'pbtext'

class PbMainProc
  def initialize(text_src, left_bank, right_bank, timeout = 5, ltr_gap = 5)
    @left_bank = left_bank
    @right_bank = right_bank
    @pbtext = PbText.new(text_src)
    @pbtext.prep_text
    @timeout = 5
    @ltr_gap = 1
    end

  def run
    while true do
      if @pbtext.loaded == false
        @pbtext.prep_text
        sleep @timeout
      else
        cur_left, cur_right = @pbtext.shift_ltr
        @left_bank.set_value(cur_left)
        @right_bank.set_value(cur_right)
        sleep @litr_gap
        end
      end
    end
  end
