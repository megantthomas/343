(define total 0)
(define totalTax 0)
(define finalTotal 0 )


;function to round the given value to 2 decimal places
(define (roundOff z)
  (let ((power (expt 10 2)))
    (/ (round (* power z)) power)))

;function that displays the title and the instructions and then starts pos method 
(define(startpos)(
	 (let ((title(display "\n\t\t\tScheme Point-of-Sale\n\t\t Exit with -1, See Current Sum with -2\n\n")))
        (+ title (pos 0 0)))
))

;executes the actual pos function
(define (pos finalTotal condition)(

	;if -1 is entered the exiting scequence begins 
    (if(eq? condition -1)
        (begin  	
        		(display "\nSubtotal: $")(display finalTotal)(newline)
        		(display "Tax: $") 
			  	(let ((totalTax(* finalTotal 0.065)))
                	(display (roundOff totalTax))) (newline)
            	(display "Total: $")
            	(let ((totalTax(* finalTotal 0.065)))
                	(let ((totalF(+ finalTotal totalTax)))
                		(display (roundOff totalF))))
           		(newline)(newline)(newline)
           		(exit)	 
        )

        ;if -1 isnt entered  
        (begin

        	;if -2 is entered then the current sum will be printed 
        	(if(eq? condition -2)
        		(begin
        			(display "Current Sum: $")
        			(let ((cSum (display finalTotal)))
                			(
                			 (+ cSum (pos finalTotal 0))(newline)
                			)
                		)	
        			)

        		;if -2 and -1 arent entered we add that value to the sum
        		(begin
            		(display "Enter Value: $")
                	(let ((input(read)))
                		(
                		 (pos (+ condition finalTotal) input)
                		)
                	)	
                )
            )

        )    
    )
    )
)
