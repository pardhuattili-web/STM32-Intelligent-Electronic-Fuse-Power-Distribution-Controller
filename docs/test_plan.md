# Test Plan

Software:
- channel ON/OFF transitions
- over-current trip
- thermal trip
- retry path and retry limit
- CAN command parsing
- threshold scaling
- fault bitmap packing

Hardware validation:
- current-trip latency
- ADC calibration
- MOSFET temperature and switching losses
- transient response
- CAN electrical behavior
- load/fault recovery

Do not connect an unprotected prototype directly to an EV traction battery.