
require 'rubygems'
require 'serialport'

@serial_port_1 = "/dev/ttyACM0"
#@serial_port_2 = "/dev/ttyACM1"
@serial_bps = 9600


sp = SerialPort.new(@serial_port_1,@serial_bps)
#sp2 = SerialPort.new(@serial_port_2,@serial_bps)

def adjust(num)
  if num != "x"
	val = num.to_i
	val = (val / 102).ceil
  end
  return val
end

loop do
  read =  sp.read
  puts read
  #----------------見ないで------------------#
  /R:/ =~ read
  val = $'
  /L:/ =~ val
  rm = $` #右側モーターの値
  val = $'
  /H:/ =~ val
  lm = $` #左側モーターの値 
  val = $'
  /B1:/ =~ val
  hm = $` #砲台のサーボ
  val = $'
  /B2:/ =~ val
  b1 = $` #砲台回転右
  val = $'
  /B3:/ =~ val
  b2 = $` #砲台回転左
  b3 = $' #発射ボタン
  #--------------------------------------------#
  #sp2.write('R')
  #sp2.write(adjust(rm))
  #sp2.write('-')
  #sp2.write('L')
  #sp2.write(adjust(lm))
  #sp2.write('-')
  #sp2.write('H')
  #sp2.write(adjust(hm))
  #sp2.write('-')
  #sp2.write('B')
  #sp2.write(b1)
  #sp2.write(b2)  
  #sp2.write(b3)
  
  puts 'R'
  puts rm
  puts 'L'
  puts lm
  puts 'H'
  puts hm
  puts 'B'
  puts b1
  puts b2
  puts b3
  puts "================="
  sleep(1)
end
