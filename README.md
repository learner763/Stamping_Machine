**Problem Statement:**

The stamping machine stamps 10
parts in one cycle. The program
cycle starts by a push button S1.
The proximity switch B7 signals
“Part in magazine”. A part is fed
towards the machine by means of Cylinder 1.0, a double solenoid actuated cylinder, and is clamped.
Proximity switches B1 and B2
gives the retracted and extended
position of the Cylinder 1.0,
respectively. After the part has
been clamped, Cylinder 2.0, a
spring return solenoid actuated
cylinder, stamps the part. The
retracted position of the cylinder 2.0 is signaled by a proximity switch B3 and extension by a proximity
switch B4. The Cylinder 2.0 is pressed against the part for 4 seconds so that stamp leaves a good impression
on the part. After this the Cylinder 2.0 is retracted and once it has retracted fully, Cylinder 3.0, a spring
return solenoid actuated cylinder, is actuated to push the part towards the outlet container. The retracted
and extended position of the Cylinder 3.0 is signaled by proximity switches B5 and B6. Once the Cylinder
3.0 has pushed the part and has retracted fully, the Cylinder 1.0 retracts and wait for 2 seconds before
pushing the next part in the clamping position and the process repeats. After 10 parts have been stamped,
the whole machine should rest for 30 seconds before starting the next cycle via push button S1.
Cylinder 1.0 use coil Y1 for clamping or extension and Y2 for unclamping or retracting.
Cylinder 2.0 use coil Y3 for extension.
Cylinder 3.0 use coil Y4 for extension.

**#Solution:**

Soultion to this problem is developed on OpenPLC simulation using Functional Body Diagram and Ladder Diagram.
S
