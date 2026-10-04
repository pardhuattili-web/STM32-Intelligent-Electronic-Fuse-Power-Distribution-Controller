# Protection Model

Trip conditions:
- current >= trip threshold
- temperature >= thermal threshold

States:
OFF, ARMED, ON, RETRY_WAIT, LATCHED_FAULT.

Over-current faults may retry after cooldown when enabled. Retry attempts are bounded. Thermal faults remain latched in the reference policy.

Thresholds are examples only and must be tuned and validated on the selected power stage.