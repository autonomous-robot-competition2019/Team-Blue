# ![equation](https://latex.codecogs.com/gif.latex?%5Cdpi%7B300%7D%20%5Ctext%7BFebruary%7D%20%5C%3B%20%2411%5E%7B%5Ctext%7Bth%7D%7D)

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


# ![equation](https://latex.codecogs.com/gif.latex?%5Cdpi%7B300%7D%20%5Ctext%7BMarch%7D%20%5C%3B%20%2425%5E%7B%5Ctext%7Bth%7D%7D)

This week we worked exclusively on completing milestones 7 and 8 (need to double-check which numbers), which involved reliably identifying the snitch and quaffles. In order to identify these objects, the robot relied on the Pixy cam to pinpoint the location of orange (snitch) and green (quaffle) objects. The code was written so that the robot would locate and follow the object by rotating itself in place, so that later we can add more code to make the robot move forward while adjusting its position relative to the object. -- stay tuned for videos of the milestones! --

In addition, we worked with the light sensor to create a function that would stop the robot when a light was directed towards it. A slight issue we ran into with the sensor was that the numbers that appeared in the serial monitor were significantly lower than expected, but the issue was resolved by changing the analog port the sensor connected to.

With regard to the structure of our robot, we exchanged our wheels for a much sturdier set supplied by Nick (thank you!), which made the robot move a little more gracefully and reliably. Yay :)

Acknowledgments:

Kiara: wrote code to achieve milestones!

# ![equation](https://latex.codecogs.com/gif.latex?%5Cdpi%7B300%7D%20%5Ctext%7BApril%7D%20%5C%3B%20%241%5E%7B%5Ctext%7Bst%7D%7D)

This week we continued our work on reliably detecting aspects of the game.  We modified our code for detecting the snitch and quaffles to detect the goals.  The main issue with this was detecting the goal and not detecting the tape that designates the bounds of the arena, since they are the same color. We were able to differentiate between the two by using the fact that the goals are significantly larger than the boundary tape.  Using this condition, we were able to successfully complete milestone 6! (check the folder for a video :D)

Also, this week we worked on our implementation of the keeper role.  We added a large blocking surface and began experimenting with the timing of our code.  However, we determined that because of our prototype base not being rigid enough to properly support our front wheel we could not get consistent behavior for the keeper role.  Because of this we began working on a new 3D model of a base for the robot, which we should finish in the next week.

Acknowledgments:

Ryan & Kiara: worked on figuring out issues and code for goal detection and keeper role

Nadim: worked on modifying structure of robot to block quaffles

# ![equation](https://latex.codecogs.com/gif.latex?%5Cdpi%7B300%7D%20%5Ctext%7BApril%7D%20%5C%3B%20%248%5E%7B%5Ctext%7Bth%7D%7D)


This week we worked on the model for the base of our robot. We gave the dimensions and model to Phil and Carl to create the base out of plexiglass :) At the same time, we also worked on scaling down the size of the structure as we are no longer using the large battery pack. 

We attempted to use the servo shield, but it needed its own source of power and with our breadboard we can easily install servos without the shield. As of right now, we are currently only using the motor shield. Yay. We also found code that enabled us to get the claw finally working! 

Acknowledgments:

Ryan: worked on code for model :D

Kiara: restructured the robot, tried to figure out claw 



# ![equation](https://latex.codecogs.com/gif.latex?%5Cdpi%7B300%7D%20%5Ctext%7BApril%7D%20%5C%3B%20%2415%5E%7B%5Ctext%7Bth%7D%7D)

This week we coordinated with Carl in creating the base and are currently waiting for it to be completed. Since we gave him our wheels for mounting onto the base, we were not able to make a lot of progress on implementing a player role. Instead, we rebuilding the structure of the robot to hold the camera, servo shield, and breadboard. 

We also discussed potential strategies to implement the keeper and seeker roles. For the keeper role, we talked about randomly moving in front of the goals as it would be very difficult for the camera to pick up a flying quaffle and move accordingly. For the seeker role, we talked about using a vertical conveyor belt to collect the quaffle and bring it to a height that would allow it to drop the ball into even the smallest 300 point goal. This has yet to be built... 

Acknowledgements:

Ryan & Kiara: discussions about strategies
Kiara: restructuring the robot

# ![equation](https://latex.codecogs.com/gif.latex?%5Cdpi%7B300%7D%20%5Ctext%7BApril%7D%20%5C%3B%20%2422%5E%7B%5Ctext%7Bnd%7D%7D)

This week we properly implemented the keeper role which makes the robot move back and forth in front of all of the goals for now. The movement is triggered currently when it sees a yellow line, but this will (hopefully) later be modified to start after detecting a robot that is a certain distance away. We have technically completed milestones 5 and 10, which require us to implement a player role and block quaffles, respectively.

We also attempted to incorporate a conveyor belt for the purpose of putting quaffles in the goals, but had lots of difficulties in getting it to work. The belt itself broke after a couple of rotations for unknown reasons. We tried shortening the length of the belt to see if that would allow it to rotate more, but it still quickly became undone. After this adventure with the conveyor belt, we decided against using it for our final design.

In addition, we created a mechanism to capture the snitch with a rectangular foamcore arm which is connected to a servo that lifts it up and down. We are planning to test it next week to see how effectively it can chase/follow the snitch and capture it. The reason we built this was to make it easier to take a wing off. 

Stay tuned for more updates next week! #TeamSBFFs

# ![equation](https://latex.codecogs.com/gif.latex?%5Cdpi%7B300%7D%20%5Ctext%7BApril%7D%20%5C%3B%20%2429%5E%7B%5Ctext%7Bth%7D%7D)

Team SBFFs here for our weekly update :) T-minus two weeks until BattleBo-we mean the Robot Competition! 

Because of the conveyor belt debacle last week, we primarily focused on implementing the behavior needed to capture the snitch this week. We began by modifying the servo set-up on the robot that controlled the rectangular foamcore arm as last week we simply taped the servo on to a red cube that was then taped to the base. So a whole lot of tape, and not a lot of stability. Kiara measured the necessary dimensions for a potential servo holder, while Ryan–our resident 3D model master–quickly created the model that would be printed. 

While the model was being printed, the duo worked on fixed the signatures on the PixyCam to detect the snitch. The main issue that came up was that the robot easily detected the cabinets in the room as the same color as the snitch and would make a beeline for the cabinets. The code was modified so that the robot would only move towards "orange" objects with a specific width and height, which seemed to fix this issue. We added code that would also allow the robot to spin in place ("search_spin") when the snitch was not detected or close enough. In the end, the robot was able to successfully find and follow the snitch around the arena! Robot = 1, Snitch = 0. Now let's hope this works on game day too...

Back to the model. When it was done printing, we immediately noticed a slight error in our calculations. The area that was supposed to hold the servo was a little too small and Kiara forgot to factor in the wire that jutted out from the side of the servo. Both Nadim and Kiara tried their best to cut out a piece of the model to make the servo fit, but to no avail. The internet told us we needed a hot knife to cut through the model–we had neither a knife nor a microwave to follow through with this plan (don't worry we wouldn't, but it was tempting b/c it took a while to print it...). Anyways, we're going to tinker with the 3D model so we can account for the wire and create a little wiggle room for the servo. 

Will Team SBBFs be able to create a 3D model that fits their servo? Will they complete their robot in time? We want to know the answers to these questions too. 

As always, stay tuned next week for updates! 

