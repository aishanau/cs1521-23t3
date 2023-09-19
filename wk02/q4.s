	.text
main:
	# Store variable x in register $t0 
	# Store variable y in register $t1.

	li	$v0, 4
	la	$a0, prompt 		# load the address of our string into $a0 
	syscall


	li	$v0, 5
	syscall
	move	$t0, $v0


	mul	$t1, $t0, $t0

	li	$v0, 1
	move	$a0, $t1 		# load the address of our string into $a0 
	syscall


	li	$v0, 11
	li	$a0, '\n' 		# load the address of our string into $a0 
	syscall

	li	$v0, 0
	jr	$ra

	.data
prompt:
	.asciiz "Enter a number: "