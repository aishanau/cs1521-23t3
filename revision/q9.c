

array:
.space 100

out_str:
.asciiz	"Length of the string is: "

main:
	# Store array index in register $t0 
	# Store variable y in register $t1.

	li	$v0, 4
	addi	$v0, $0, 4
	
	# Read a string
	li	$v0, 8
	la	$a0, array
	li	$a1, 100
	syscall
	
	# Finding the end of the array
array_loop_init:
	li	$t0, 0
array_loop_start:
	# While the character at index i is not '\0'
	# Base address + offset!
	la	$t1, array
	add	$t2, $t1, $t0 # Index + base address = location of character
	lb 	$t4, ($t2)
	
	beq 	$t4, '\0', array_loop_end
	beq 	$t4, 0, array_loop_end
	beqz 	$t4, array_loop_end
	
	addi	$t0, 1
	b	array_loop_start
	
array_loop_end:
	# Print length of line
	la	$a0, out_str
	li	$v0, 4
	syscall
	
	move	$a0, $t0
	li	$v0, 1
	syscall
	
	li	$a0, '\n'
	li	$v0, 11
	syscall
	
	li $v0, 0
	jr $ra
    