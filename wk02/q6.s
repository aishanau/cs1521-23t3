	.text
main:
	# Store variable x in register $t0 

	li	$v0, 4
	la	$a0, prompt 		# load the address of our string into $a0 
	syscall


	li	$v0, 5
	syscall
	move	$t0, $v0		# $t0 = x

	ble	$t0, 100, small_big_condition
	bge	$t0, 1000, small_big_condition

medium_condition:
	li	$v0, 4
	la	$a0, medium_str 		# load the address of our string into $a0 
	syscall

	b	end_if
	j	end_if

small_big_condition:
	li	$v0, 4
	la	$a0, small_big_str 		# load the address of our string into $a0 
	syscall


end_if:
return_zero:

	li	$v0, 0
	jr	$ra

	.data
prompt:
	.asciiz "Enter a number: "

small_big_str:
	.asciiz "small/big\n"

medium_str:
	.asciiz "medium\n"