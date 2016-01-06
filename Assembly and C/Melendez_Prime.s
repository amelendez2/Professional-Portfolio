# prime.s
# Student: Antonio Melendez Date: 09/27/2013
# Determine the first 100 prime numbers
# Print the result.
# Print endl.
# Return.

.text
.globl main

#-------------------------------------------
main:
		# The following lines setup our for loop
	li $t3, 541 						# end of for loop i=541
	li $t4, 1 							# counter of for loop starts at i=1($t4)
loop:
	bgt $t4, $t3, end 					# loops until i<=541, so we need branch if greater than to end
loopbody:
		# Setup before jumping to prime Function
	add $a0, $t4, $zero  				# will send the current value of i($t4) to function
	jal prime							#jumps to function prime
	
	addi $t4, $t4, 1 					# Increment i by 1
	j loop 								# jump back to the top
	
#-----------------------------------------
prime:									# The function Prime
	li $t2, 1							# $t0 = i-1 in our C for loop
	sub $t0, $a0, $t2					# first we save a 1 into $t2 then we subtract from $a0
	li $t1, 2							# j=2, counter of prime's for loop
for:
	bgt $t1, $t0, if					# again we use bgt because our for loop condition is j<=i-1
forbody:
	div $a0, $t1						# Since we need the remainder of i/j first we divide
	mfhi $t2							# Then we take the remainder that we save in $t2
	beq $t2, $zero, returnzero			# Compare it to zero and branch if it's equal

	addi $t1, $t1, 1					# increment the loop and jump back to for
	j for

if:	
	beq $t1, $a0, returnone				# Once prime's for loop reaches the end it checks if i=j
	jr $ra								# If so it jumps to returnone, which will print out the prime number

returnzero:
	jr $ra								# If we get this it goes back to main without printing anything
	
	
returnone:
	li $v0, 1							# Sends value of $a0 to $v0
	syscall								# Prints out current value of $v0
	# Print endl.						
	la $a0, endl 						# Load the address of the string
	li $v0, 4 							# Load the system call number
	syscall
	jr $ra

#-----------------------------------------

end:
	jr $ra
.data
endl: .asciiz "\n"						# Sends to new line after some output
