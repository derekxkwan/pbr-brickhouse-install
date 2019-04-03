require "polybius_sq"

word_arr = []
pos_arr = []
cur_pos = 0

File.open("text.txt").readlines.each do |line|
  cur = PolybiusSq::encode(line).flatten
  word_arr = word_arr + cur + [6]
  pos_arr = pos_arr + [cur_pos]
  cur_pos = word_arr.length
  end

print word_arr
print "\n"
print pos_arr
print "\n"
print word_arr.length
print "\n"
print pos_arr.length
print "\n"
