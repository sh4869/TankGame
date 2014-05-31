require 'rubygems'
require 'serialport'
 
@serial_port = "/dev/ttyACM0"
@serial_bps = 9600
 
sp = SerialPort.new(@serial_port,@serial_bps)
 
loop do
  read =  sp.read
  puts read
  sleep(1)
end
