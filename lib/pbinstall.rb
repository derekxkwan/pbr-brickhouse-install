
require_relative 'pbtext'

class PbMainProc
  def initialize(text_src, left_bank, right_bank, timeout = 20, ltr_gap = 12.5)
    @left_bank = left_bank
    @right_bank = right_bank
    @pbtext = PbText.new(text_src)
    @pbtext.prep_text
    @timeout = timeout
    @ltr_gap = ltr_gap
    end

  def run
    while true do
      if @pbtext.loaded == false
        @left_bank.set_value(0)
        @right_bank.set_value(0)
        @pbtext.prep_text
        sleep @timeout
      else
        cur_left, cur_right = @pbtext.shift_ltr
        @left_bank.set_value(cur_left)
        @right_bank.set_value(cur_right)
        sleep @ltr_gap
        end
      end
    end
  end
