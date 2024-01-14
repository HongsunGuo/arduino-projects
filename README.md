# arduino projects
Interesting and maybe useful arduino projects for fun and research
# Outline
1. [short trigger to long trigger](#short-trigger-to-long-trigger)

## short trigger to long trigger
Sometimes, you may need to record very short triggering pulses (e.g., 1 µs) as timestamps for offline data alignment. Due to Nyquist's Theorem, you will need a data acquisition (DAQ) card with a sampling rate of more than 2 MS/s, which can be expensive. An alternative solution is to convert the short pulses into longer pulses (e.g., 2 ms duration) so that you can record the signal with a more budget-friendly DAQ board with a sampling rate as low as 1 kHz. The code (/short_trigger_to_long_trigger) and following diagram illustrates how to convert a short trigger to a long one.

<img src='images/short_trigger_to_long_trigger.png' width='600'>
