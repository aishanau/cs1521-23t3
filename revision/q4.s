main:
	li	$t0, 0
	
loop_cond:
	bge	$t0, 42, loop_end
	
	li	$v0, 5
	syscall

loop_incr:
	add	$t0, $t0, $v0
	b 	loop_cond
loop_end:
	
	li	$v0, 1
	move	$a0, $t0
	syscall

	li	$v0, 11
	li	$a0, '\n'
	syscall

	li	$v0, 0
	jr	$ra