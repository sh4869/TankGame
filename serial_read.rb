require 'rubygems'
require 'serialport'
 
@serial_port = "/dev/ttyACM0"
@serial_bps = 9600
 
sp = SerialPort.new(@serial_port,@serial_bps)
 
loop do
  read =  sp.read
  puts read
  /R:/ =~ read
  val = $'
  /L:/ =~ val
  val1 = $`
  val = $'
  /H:/ =~ val
  val2 = $`
  val = $'
  /B1:/ =~ val
  val3 = $`
  val = $'
  /B2:/ =~ val
  val4 = $`
  val = $'
  /B3:/ =~ val
  val5 = $`
  val6 = $'

  puts val1
  puts val2 
  puts val3
  puts val4
  puts val5
  puts val6
  puts "================="
  sleep(1)
end
