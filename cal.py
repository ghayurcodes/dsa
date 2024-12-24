import tkinter as tk
from tkinter import messagebox
from scipy.integrate import quad
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

# Function to model the growth rate
def population_growth_rate(t, rate, exp_factor):
    return rate * np.exp(exp_factor * t)

# Function to compute the integral of the growth rate over the interval [a, b]
def compute_growth():
    try:
        rate = float(entry_rate.get())
        exp_factor = float(entry_exp_factor.get())
        t_start = float(entry_start_time.get())
        t_end = float(entry_end_time.get())
        
        # Integrate the growth rate function using scipy's quad function
        result, _ = quad(lambda t: population_growth_rate(t, rate, exp_factor), t_start, t_end
        
        # Display the result
        messagebox.showinfo("Total Population Increase", f"Total population increase: {result:.2f} individuals")
        
        # Plot the growth rate function over the interval
        t_values = np.linspace(t_start, t_end, 100)
        growth_values = population_growth_rate(t_values, rate, exp_factor)
        
        fig, ax = plt.subplots(figsize=(5, 4))
        ax.plot(t_values, growth_values, label=f"{rate}e^{exp_factor}t")
        ax.fill_between(t_values, growth_values, alpha=0.3)
        ax.set_xlabel("Time (years)")
        ax.set_ylabel("Growth Rate (individuals/year)")
        ax.set_title("Population Growth Rate")
        ax.legend()
        
        # Embed the plot in the Tkinter window
        canvas = FigureCanvasTkAgg(fig, master=root)
        canvas.draw()
        canvas.get_tk_widget().pack()
        
    except ValueError:
        messagebox.showerror("Input Error", "Please enter valid numerical values.")

# Create the main GUI window
root = tk.Tk()
root.title("Population Growth Model")

# Labels and entry fields for inputs
tk.Label(root, text="Initial Growth Rate (individuals/year):").pack()
entry_rate = tk.Entry(root)
entry_rate.pack()

tk.Label(root, text="Exponential Growth Factor:").pack()
entry_exp_factor = tk.Entry(root)
entry_exp_factor.pack()

tk.Label(root, text="Start Time (years):").pack()
entry_start_time = tk.Entry(root)
entry_start_time.pack()

tk.Label(root, text="End Time (years):").pack()
entry_end_time = tk.Entry(root)
entry_end_time.pack()

# Button to compute the growth
btn_compute = tk.Button(root, text="Compute Growth", command=compute_growth)
btn_compute.pack()

# Run the Tkinter event loop
root.mainloop()
