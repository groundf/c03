from pybricks.pupdevices import Motor
from pybricks.parameters import Port
from pybricks.tools import wait

# Initialize a motor on port A.
example_motor = Motor(Port.A)

for _ in range(10):
    # Make the motor run clockwise at 500 degrees per second.
    
    example_motor.run(500)
    angle = example_motor.angle()
    speed = example_motor.speed()
    # Print the values.
    print(angle, speed)
    wait(3000)
    # Make the motor run counterclockwise at 500 degrees per second.
    example_motor.run(-500)
    wait(3000)