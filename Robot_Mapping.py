import math
import matplotlib
matplotlib.use("TkAgg")
import requests
import time
import matplotlib.pyplot as plt


plt.ion()
print("Before figure")

fig = plt.figure()

print("After figure")
ax = fig.add_subplot(111)


while True:
    response = requests.get("http://192.168.0.214")

    print(response.text)
    data = response.json()

    heading = data["heading"]

    x = []
    y = []

    for measurement in data["measurements"]:
        servo_angle = measurement["angle"]
        distance = measurement["distance"]

        relative_angle = math.radians(servo_angle - 90)
        real_angle = relative_angle + math.radians(heading)



        x.append(-distance * math.cos(real_angle))
        y.append(distance * math.sin(real_angle))


    print("X:",x)
    print("Y:",y)
    ax.clear()

    ax.scatter(x,y)
    ax.scatter(0,0)
    ax.set_aspect("equal")
    ax.grid(True)
    ax.set_xlabel("X (cm)")
    ax.set_ylabel("Y (cm)")
    ax.set_xlim(-50, 50)
    ax.set_ylim(-50, 50)
    arrow_length = 5
    arrow_heading = math.radians(90-heading)
    arrow_x = -arrow_length * math.cos(math.radians(heading))
    arrow_y = arrow_length * math.sin(math.radians(heading))

    ax.annotate(
        "",
        xy=(arrow_x, arrow_y),
        xytext = (0,0),
        arrowprops = dict(arrowstyle="->",linewidth=2)
    )

    plt.pause(1)





