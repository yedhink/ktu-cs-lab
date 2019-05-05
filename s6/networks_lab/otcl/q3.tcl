set ns [new Simulator]
$ns color 1 #000fff
$ns color 2 Red

set tr [open sample.tr w]
$ns trace-all $tr

set nm [open first.nam w]
$ns namtrace-all $nm

# set up all the nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

# links bw nodes are duplex
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 1.7Mb 20ms DropTail
$ns duplex-link $n4 $n3 2Mb 10ms DropTail
$ns duplex-link $n5 $n3 2Mb 10ms DropTail

# create cbr and attach upd agent to it
set cbr [new Application/Traffic/CBR]
$cbr set packet_size 1000
$cbr set rate 1mb
$cbr set random false
set udp0 [new Agent/UDP]
$cbr attach-agent $udp0

# attach udp to node1
$ns attach-agent $n1 $udp0

set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0

set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0

set sink0 [new Agent/TCPSink]
$ns attach-agent $n5 $sink0

set null0 [new Agent/Null]
$ns attach-agent $n4 $null0

proc finish {} {
global ns nf
$ns flush-trace 
exec nam first.nam &
puts "complete";exit 0}

$ns connect $tcp0 $sink0
$tcp0 set fid_ 2

$ns connect $udp0 $null0
$udp0 set fid_ 1

$ns at 1.0 "$ftp0 start"
$ns at 4.0 "$ftp0 stop"

$ns at 0.1 "$cbr start"
$ns at 4.0 "$cbr stop"

$ns at 5.0 "finish"
$ns run
