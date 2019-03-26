# ![equation](https://latex.codecogs.com/gif.latex?%5Cdpi%7B300%7D%20%5Ctext%7BFebruary%7D%5C%3B11%5E%7Bth%7D)

This week we continued discussing strategies in response to the evolving rule set.  For example we discussed the feasibility of the main role being the keeper.  Based on previous discussions, we made a 3D model for the base of the robot.  However, we later decided that it would be better to prototype with less expensive and time consuming materials.  Finally, we tested the pixy camera and attempted to test servos but we were not able to get those working failure on the servo shield.


# ![equation](https://latex.codecogs.com/gif.latex?%5Cdpi%7B300%7D%20%5Ctext%7BFebruary%20%7D18%5E%7B%5Ctext%7Bth%7D%7D)

This week we began building a prototype for our robot. We decided for now that our basic design revolves around a tricycle-style, two-wheel drive build. We have a rectangular base with several legos attached on each side with the one regular wheel in the front, and two are DC motor wheels in the back.

In our initial attempt, the back wheels were not properly attached to the base (see first picture), which caused issues with getting the wheels to properly spin. To fix this issue, we decided to cut out a larger foam core base to account for the space in which these wheels would be attached. Small pieces of foam core were placed to stabilize the motor, and the wheels were attached to the base by using multiple screws that went through these layers of foam core.

![img_20190218_163824](https://user-images.githubusercontent.com/36004866/53213578-81b85600-3617-11e9-9874-0bc138cc842e.jpg)
![img_20190218_163813](https://user-images.githubusercontent.com/36004866/53213579-81b85600-3617-11e9-8ab7-240a624eba2b.jpg)
![img_20190218_130742](https://user-images.githubusercontent.com/36004866/53213580-81b85600-3617-11e9-9f90-c3d004d3fdba.jpg)


In addition, we completed our first milestone as we got the robot to move forward! The robot doesn't move in a straight line, but we believe this will be fixed once we build a sturdier base.


Acknowledgments:

Kiara: Worked on building prototype.

Nadim: Worked on building prototype.

Ryan: Found and modified code to get robot to move forward. Also, helped with prototype.

Phil: Fixed our servo shield :) (thank you!!)

# ![equation](https://latex.codecogs.com/gif.latex?%5Cdpi%7B300%7D%20%5Ctext%7BFebruary%7D%20%5C%3B%20%2425%5E%7B%5Ctext%7Bth%7D%7D)

This week we continued adding to the prototype.  We attached a new front wheel to assist with turning, reattached the rear wheels with a sturdier construction, and added IR sensors for collision detection.  With these sensors we were able to write code that would make the robot turn if it saw an object in front of it on either side.  Finally, we began experimenting with RGB sensors and the camera, to try to implement the keeper role.

Milestones 2 and 3 were achieved! The first video was our initial attempt at building a reliable sensor system, but the second video demonstrates its ability to effectively avoid any obstacles in its path.

# ![equation](https://latex.codecogs.com/gif.latex?%5Cdpi%7B300%7D%20%5Ctext%7BMarch%7D%20%5C%3B%20%244%5E%7B%5Ctext%7Bth%7D%7D)

This week we worked on the behavior of the robot.  We originally tried to have multiple color sensors to detect the boundary for the keeper role, however we found that since the Arduino only had one set of pins for the sensor we could not get a reliable range of colors that would work for both sensors.  Instead we decided to have one sensor on the front and turn around once a boundary is detected.  However, we did not have enough time this week to fully tune the constants to ensure the proper behavior occurs every time.  This week we also completed milestone 6 by adding a timed stop system so that during the competition the robot will shut down at the end of the allowed time.


March 25th 

This week we worked exclusively on completing milestones 7 and 8 (need to double-check which numbers), which involved reliably identifying the snitch and quaffles. In order to identify these objects, the robot relied on the Pixy cam to pinpoint the location of orange (snitch) and green (quaffle) objects. The code was written so that the robot would locate and follow the object by rotating itself in place, so that later we can add more code to make the robot move forward while adjusting its position relative to the object. -- stay tuned for videos of the milestones! --

In addition, we worked with the light sensor to create a function that would stop the robot when a light was directed towards it. A slight issue we ran into with the sensor was that the numbers that appeared in the serial monitor were significantly lower than expected, but the issue was resolved by changing the analog port the sensor connected to. 

With regard to the structure of our robot, we exchanged our wheels for a much sturdier set supplied by Nick (thank you!), which made the robot move a little more gracefully and reliably. Yay :) 

Acknowledgments:

Kiara = wrote code to achieve milestones!

