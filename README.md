# canAbhimanyuCrossChakravyuh

Problem statement: Can Abhimanyu cross the Chakravyuh or not !!

Given:
-	Abhimanyu starts with p power.
-	There are 11 circles with enemy power K1, K2, K3, …, K11.
-	Abhimanyu can skip fighting a times.
-	Abhimanyu can recharge and gain power b times.

More Information about battling:
-	While moving through each circle, if Abhimanyu’s power p  >= Enemies power Ki, he can defeat the enemy. His power is decreases by Ki.
-	If Abhimanyu’s power is less than Ki, he losses the battle unless he skips that enemy using one of his skips (out of a times).
-	Enemies at positions K3 and K7 regenerate once. After the first defeat, they regenerate with half of their initial power. They can also attack from behind while Abhimanyu is battling in next circle.
-	Abhimanyu can recharge his power b times. Since in problem statement it’s not mentioned, so I am assuming recharging restores full power p each time.


Algortihm:
-	Iterate through all 11 circles:
– If Abhimanyu’s power is greater than or equal to enemy’s power i.e. Ki, he defeats the enemy and loses his power equal to Ki. 
– If Abhimanyu’s power is less than the enemy’s, he has two choices:
– Either skip the enemy, if skips are available or Recharge his power, if recharges
	   are available.
	– Loss.

-	For K3 and K7 enemies:
– After Abhimanyu defeats them the first time, they regenerate with half of their initial power.
– They can attack from behind while Abhimanyu is in the next circle, so have to consider these attacks too.

-	At the end if Abhimanyu crosses all the circle with power greater than zero, wins otherwise Loss.

