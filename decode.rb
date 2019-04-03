require "polybius_sq"

cur_poly = []
File.open("nums.txt").readlines.each do |line|
  if /[^\n|\r]/.match(line).to_a.length > 0
    cur_arr = line.split(' ').collect{|x| Integer(x)}
    cur_poly  = cur_poly + [cur_arr]
  else
    if  cur_poly.length > 0
      print PolybiusSq::decode(cur_poly)
      print "\n"
    end
    cur_poly = []
  end
end
