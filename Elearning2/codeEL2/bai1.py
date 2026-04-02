import turtle
import random
import time

# --- Configuration ---
BAR_WIDTH = 20
BAR_COLOR = "skyblue"
HIGHLIGHT_COLOR = "orange"
SLEEP_TIME = 0.3

# --- Drawing Functions ---
def draw_bars(data, color_positions=None):
    """Draw the bars representing the array."""
    turtle.clear()
    turtle.penup()
    turtle.goto(-len(data) * BAR_WIDTH / 2, 0)
    turtle.pendown()

    for i, value in enumerate(data):
        color = BAR_COLOR
        if color_positions and i in color_positions:
            color = HIGHLIGHT_COLOR
        turtle.fillcolor(color)
        turtle.begin_fill()
        turtle.forward(BAR_WIDTH)
        turtle.left(90)
        turtle.forward(value)
        turtle.left(90)
        turtle.forward(BAR_WIDTH)
        turtle.left(90)
        turtle.forward(value)
        turtle.left(90)
        turtle.end_fill()
        turtle.penup()
        turtle.forward(BAR_WIDTH)
        turtle.pendown()

    turtle.update()

# --- Merge Sort with Animation ---
def merge_sort(data, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(data, left, mid)
        merge_sort(data, mid + 1, right)
        merge(data, left, mid, right)

def merge(data, left, mid, right):
    left_part = data[left:mid + 1]
    right_part = data[mid + 1:right + 1]

    i = j = 0
    k = left

    while i < len(left_part) and j < len(right_part):
        draw_bars(data, color_positions={k})
        time.sleep(SLEEP_TIME)
        if left_part[i] <= right_part[j]:
            data[k] = left_part[i]
            i += 1
        else:
            data[k] = right_part[j]
            j += 1
        k += 1

    while i < len(left_part):
        draw_bars(data, color_positions={k})
        time.sleep(SLEEP_TIME)
        data[k] = left_part[i]
        i += 1
        k += 1

    while j < len(right_part):
        draw_bars(data, color_positions={k})
        time.sleep(SLEEP_TIME)
        data[k] = right_part[j]
        j += 1
        k += 1

# --- Main Program ---
def main():
    turtle.speed(0)
    turtle.hideturtle()
    turtle.tracer(0, 0)  # Disable auto updates for smoother animation

    # Generate random data
    data = [random.randint(20, 150) for _ in range(15)]
    draw_bars(data)
    time.sleep(1)

    merge_sort(data, 0, len(data) - 1)

    draw_bars(data)  # Final sorted array
    turtle.done()

if __name__ == "__main__":
    main()
