BEGIN{
	fcount1=0
	fcount2=0
	fcount3=0
	fcount4=0
	fcount5=0
	fcount6=0
	fcount7=0
	fcount8=0

	fecount1=0
	fecount2=0
	fecount3=0
	fecount4=0
	fecount5=0
	fecount6=0
	fecount7=0
	fecount8=0
	count=0	
	ocount=0
}
/MA201\(F\)/{
	arr1F[$1]="F grade"
	fcount1++}  
/HS200\(F\)/{arr2F[$1]="F grade"
	fcount2++}  
/CS201\(F\)/{arr3F[$1]="F grade"
	fcount3++}
/CS203\(F\)/{arr4F[$1]="F grade"
	fcount4++}  
/CS205\(F\)/{arr5F[$1]="F grade"
	fcount5++}  
/CS207\(F\)/{arr6F[$1]="F grade"
	fcount6++}  
/CS231\(F\)/{arr7F[$1]="F grade"
	fcount7++}  
/CS233\(F\)/{arr8F[$1]="F grade"
	fcount8++}
/MA201\(FE\)/{fecount1++}  
/HS200\(FE\)/{fecount2++}  
/CS201\(FE\)/{fecount3++}
/CS203\(FE\)/{fecount4++}  
/CS205\(FE\)/{fecount5++}  
/CS207\(FE\)/{fecount6++}  
/CS231\(FE\)/{fecount7++}  
/CS233\(FE\)/{fecount8++}
/MA201\(O\)/{arr1[$1]="O grade"}
/HS200\(O\)/{arr1[$1]="O grade"}
/CS201\(O\)/{arr3[$1]="O grade"}
/CS203\(O\)/{arr4[$1]="O grade"}
/CS205\(O\)/{arr5[$1]="O grade"}
/CS207\(O\)/{arr6[$1]="O grade"}
/CS231\(O\)/{arr7[$1]="O grade"}
/CS233\(O\)/{arr8[$1]="O grade"}

{count++}
END{

print "\nStudents with O grade MA201:"
		for(j in arr1){
			print j " got O-grade"
		}
	print "\nStudents with O grade HS200:"
		for(j in arr2){
			print j " got O-grade"
		}
print "\nStudents with O grade CS201:"
		for(j in arr3){
			print j " got O-grade"
		}
print "\nStudents with O grade CS203:"
		for(j in arr4){
			print j " got O-grade"
		}
print "\nStudents with O grade CS205:"
		for(j in arr5){
			print j " got O-grade"
		}
print "\nStudents with O grade CS207:"
		for(j in arr6){
			print j " got O-grade"
		}
print "\nStudents with O grade CS231:"
		for(j in arr7){
			print j " got O-grade"
		}
print "\nStudents with O grade CS233:"
		for(j in arr8){
			print j " got O-grade"
		}

print "\nStudents with F grade MA201:"
		for(j in arr1F){
			print j " got F-grade"
		}
	print "\nStudents with F grade HS200:"
		for(j in arr2F){
			print j " got F-grade"
		}
print "\nStudents with F grade CS201:"
		for(j in arr3F){
			print j " got F-grade"
		}
print "\nStudents with F grade CS203:"
		for(j in arr4F){
			print j " got F-grade"
		}
print "\nStudents with F grade CS205:"
		for(j in arr5F){
			print j " got F-grade"
		}
print "\nStudents with F grade CS207:"
		for(j in arr6F){
			print j " got F-grade"
		}
print "\nStudents with F grade CS231:"
		for(j in arr7F){
			print j " got F-grade"
		}
print "\nStudents with F grade CS233:"
		for(j in arr8F){
			print j " got F-grade"
		}

	print "Total no of students=" (count-fecount1-fecount2-fecount3-fecount4-fecount5-fecount6-fecount7-fecount8)
	print "Failed in MA201=" (fcount1-fecount1)
	print "pass % of MA201=" (count-fecount1-fcount1)/(count-fecount1) * 100
	print "Failed in HS200=" (fcount2-fecount2)
	print "pass % of HS200=" (count-fecount2-fcount2)/(count-fecount2) * 100
	print "Failed in CS201=" (fcount3-fecount3)
	print "pass % of CS201=" (count-fecount3-fcount3)/(count-fecount3) * 100
	print "Failed in CS203=" (fcount4-fecount4)
	print "pass % of CS203=" (count-fecount4-fcount4)/(count-fecount4) * 100
	print "Failed in CS205=" (fcount5-fecount5)
	print "pass % of CS205=" (count-fecount5-fcount5)/(count-fecount5) * 100
	print "Failed in CS207=" (fcount6-fecount6)
	print "pass % of CS207=" (count-fecount6-fcount6)/(count-fecount6) * 100
	print "Failed in CS231=" (fcount7-fecount7)
	print "pass % of CS231=" (count-fecount7-fcount7)/(count-fecount7) * 100
	print "Failed in CS233=" (fcount8-fecount8)
	print "pass % of CS233=" (count-fecount8-fcount8)/(count-fecount8) * 100
	
}
