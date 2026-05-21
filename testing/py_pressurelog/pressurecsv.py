import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('pressure_log.csv')

plt.figure(figsize=(12, 4))
plt.plot(df['time_ms'] / 1000, df['pressure_kpa'], linewidth=1.2)
plt.axhline(0, color='gray', linestyle='--', linewidth=0.8)
plt.xlabel('Time (s)')
plt.ylabel('Pressure (kPa)')
plt.title('MPXV7002DP — Aspiration Pressure vs. Time')
plt.grid(True, alpha=0.3)
plt.tight_layout()
plt.savefig('pressure_trace.png', dpi=150)
plt.show()