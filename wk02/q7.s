
main:
init_loop:
	li	$t0, 24
start_loop:
	bge	$t0, 42, end_loop

	li	$v0, 1
	move	$a0, $t0 		# load the address of our string into $a0 
	syscall


	li	$v0, 11
	li	$a0, '\n' 		# load the address of our string into $a0 
	syscall

	addi	$t0, $t0, 3
	b	start_loop	

end_loop:

	li	$v0, 0
	jr	$ra