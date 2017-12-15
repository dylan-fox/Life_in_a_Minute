## Materials

#### Conveyor Belt

* 1x 2’ x 2’ x 0.75” Piece of wood
* 6x 9” Paint rollers 
* 6x 9” Paint roller cover
* 16” x 44” Gabardine (or other tightly woven fabric)
* 6x 1” T-junction PVC pipe joints
* 12x 1 ¼” Galvanic pipe straps
* 2x Small springs
* 2x 1 ½” Eye hooks
* 6x 1 ½” Zinc S-hooks
* 2x 3/16” by 5 ½” Turnbuckles
* 24x Size 6 ¾” Wood screws
* 2 Continuous servo motors
* 2 Rubber wheels
* 500cm Rubber elastic cord
* 2 - 1”x3”x3” Wood blocks
* 1x Arduino Uno
* 1x 9V Battery pack

#### Target Jars 

* 5 - 180 Servo Motors
* 5 - Laser Cut Lids with 4 holes towards the 
edge(custom fit for jar used)
* 5 - Cylindrical Transparent jars 
* 5 - Popsicle sticks
* 5 - Zipties
* 5 - 3” x 1” cardboard pieces
* 2x Arduino Uno
* 2x 9V Battery pack


#### Receipt printer

* [Adafruit Thermal Receipt Printer Starter Pack] (https://www.adafruit.com/product/600)

#### Other
* Tube or carafe to pour coins out of
* Trash can or other receptacle for conveyor belt to empty into

## Assembly Instructions

#### Assembling the Conveyor Belt
1. Cut wood in half. 
2. Hinge together short end to short end to ensure stability and ease of transport. This forms the base.
3. Drill and screw in eye hooks on far sides of the base, off center.
4. Install the T-junction PVC joints equidistant along the base, ensuring they can rotate slightly towards and away from the two ends. Use the pipe straps and wood screws.
5. Insert the paint roller covers onto the paint rollers and insert these into the end of the PVC joints.
6. Sew the ends of the fabric together and place it over the rollers to form the belt.
7. Using the S hooks, connect the eye hook to the turnbuckles to the springs to the paint rollers. This gives the belt the tension it needs to stay taut. Adjust turnbuckles as necessary.

Assembly so far should look like this:
![conveyor belt construction](https://i.imgur.com/halpl3U.jpg "Conveyor Belt Construction")

#### Powering the Conveyor Belt
1. Turn the two rubber wheels inside out such that the groove is outside
2. Glue each wheel to the head of the servo motor
3. Attach wood blocks near the base of  the first and last servos. The woodblock should be attached such that the servos that would be mounted will be three inches from the wooden base and can rotate freely
4. Glue servos onto the woodblock and check if the they rotate without any obstruction
5. Measure the height between the top of the paint roller and the servo. Cut double the amount of the length from the rubber elastic cord. 
6. Connect the two ends of the cord 
7. Mount the cord over the paint roller and servo such that the paint roller rotates, the servo rotates and the cord doesn’t slip off the paint roller
8. Repeat the same process and mount the cord over the second servo 
9. Check if the conveyor belt rotates

#### Target Jars 
1. Glue the cardboard piece to the rim of the jar where you’d like the place the servo motors. Repeat the same for all the jars
2. Set the servo to rotate for 100 degrees.
3. Attach popsicle stick (using the hot glue gun) to the servo motors such that:
    * the edge of the popsicle stick is on the rotating head.
    * 3/4th length of the popsicle stick moves up and down sweeping a 100 degrees
4. Repeat the same for all the jars
5. Attach the popsicle stick the laser-cut lids and use zip-ties to reinforce them
6. Attach the servo (which now has the popsicle stick and the laser-cut lid) to the cardboard attached to the jar such that the sweeping motion of the lid can open and close the jar. Repeat this step for all jars
7. Reinforce the servos on to the jars with rubber-bands to ensure they stay in place.
8. Since the arduino can power a maximum of 3 servos, user two arduinos to power the 5 servos.
9. Add labels to the jars to indicate each category
