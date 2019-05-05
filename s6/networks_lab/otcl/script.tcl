set ns [new Simulator]
set tr [open sample.tr w]
$ns trace-all $tr
set nm [open first.nam w]
$ns namtrace-all $nm
set n0 [$ns node]
set n1 [$ns node]
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set sink0 [new Agent/TCPSink]
$ns attach-agent $n1 $sink0
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0
proc finish {} {puts "complete";exit 0}
$ns connect $tcp0 $sink0
$ns at 0.5 "$ftp0 start"
$ns at 2.5 "$ftp0 stop"
$ns at 3.0 "finish"
$ns run